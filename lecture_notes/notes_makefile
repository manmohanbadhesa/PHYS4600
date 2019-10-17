//Lecture Sept 26 2019



#main.o: main.c 
#	gcc -c -o main.o main.c

//MakeFile


OBJ=main.o statistics.o
program: $(OBJ)

TARGET=program


#if you do this: it complies each c file into an object file

%.o: %.c
	gcc -c -o $@  $<



#this links the object into an executable 
$(TARGET): $(OBJ)
	gcc -o $@ $^





#program: main.o statistics.o    # this checks the program and then if there are any changes to main.o and statistics.o 
#	gcc -o program main.o statistics.o     # if there are changes, then it compiles them


























