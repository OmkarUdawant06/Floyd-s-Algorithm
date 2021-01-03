#include <iostream>
#include <iomanip> 
#include <time.h> 
using namespace std;

int A[10][10];
int P[10][10];
int flag;

void floyd_func(int**, int );       //floyd's function
void print(int);                    //print the shortest path using Floyd's
void find_path(int ,int);           //calculate shortest distance if any

void floyd_func(int **mat_A, int n)
{
    int i,j,k;

    //assign A_Matrix and P_Matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n ;j++)
        {
            A[i][j] = mat_A[i][j];
            P[i][j] = 0;
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
    print(n);       //call print fucntion to print solution set
}

void print(int n)
{
    int i,j;

    //Print P_Matrix
    cout<<"P Matrix: \n";
    for (i = 0; i<n; i++) 
    {
        for (j = 0; j<n; j++) 
        {
            cout<<setw(1)<<left<<P[i][j]<<"   ";
        }
        cout<<endl;
    }

    for (i = 0; i < n; i++)
    {
        cout<<"V"<<i+1<<"-Vj:shortest P and length"<<endl;
        for (j = 0; j < n; j++)
        {
            if (i == j)                         //if same vertex print 0
            {
                cout<<" v"<<i + 1<<" v"<<j + 1<<": "<<A[i][j]<<endl;
            }
            else                                //else print path between vertex i and j 
            {
                cout<<" v"<<i + 1<<" ";
                find_path(i,j);                 //find intermediate vertex if any for shortest path
                if(flag == 1)                   //if flag=1 no intermediate vertex
                {
                    cout<<"v"<<j + 1<<": "<<A[i][j]<<endl;
                    flag=0;
                }
                else                            //else intermediate vertex exists so print them
                {
                    cout<<"v"<<j + 1<<": "<<A[i][j]<<endl;
                }
            }
        }
        cout<<endl;
    }
}

void find_path(int i,int j)
{
    flag=0;
    if (P[i][j] == 0)
    {
        flag=1;
        return;
    }
    find_path(i, P[i][j]);
    cout<<"v"<<P[i][j] + 1<<" ";
    find_path(P[i][j],j);
}

int main() 
{
    int n, **mat_A, i, j;
    srand(time(0));                       //initialize rand before use
    n = rand() % (10 - 5 + 1) + 5;        //(generator() % (max - min + 1)) + min
    mat_A = new int *[n+1];
    cout<<"Randomly Selected n: "<<n<<endl;
    
    for (i = 0; i < n; i++) 
    {
        mat_A[i] = new int[n+1];
    }
    for (i = 0; i < n; i++) 
    {
        mat_A[i][i] = 0;
    }
    for (i = 0; i<n; i++) 
    {
        for (j = 1; j<n ; j++) 
        {
            if (i != j) 
            {
                mat_A[i][j] = rand() % n + 1;           //assign random value to AMatrix
                mat_A[j][i] = mat_A[i][j];
            }
        }
    } 

    cout<<"A Matrix: \n";
    for (i = 0; i<n; i++)                       //print AMatrix
    {
        for (j = 0; j<n; j++) 
        {
            cout<<setw(2)<<left<<mat_A[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    floyd_func(mat_A, n);
    return 0;
}