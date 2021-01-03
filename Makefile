CC=g++
TARGET1=floyd
all:
	$(CC) UDAWANT_OMKAR_pa3_floyd.cpp -o $(TARGET1)
clean:
	rm -f *.o *.d *~ $(TARGET1) 
