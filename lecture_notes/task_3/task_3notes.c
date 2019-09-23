#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 



int main()
{
	
//using the char 

	/*

	char letter=57;  or can assign actual letter by letter= '9'  or   you can assing a new line character letter='\n' the slash means 
	the charcter is important    and if you want to put an actual slash you need to put two of them like //	

	*/


 // make the char a pointer
 	/*

 	char* words= "Hello world"; // there is an extra \0 at the end to tell the array has ended
 	cursor=words;
 	
 	while(*cursor != '\0')  // or you could do a do while loop which you add in the beginning and it does the loop once and then checks the while condition
 	{
 		printf("%c",*cursor );
 		cursor++;
 	}

 	*/


 	/*char words2[13];
 	this does not add a \0 at the end of an array*/


 //the printf function

 	/*

 	char* words="hello world";

 	printf(words);

 	*/


// using the string, int and floats
 	/*

 	char* string= "hello world";
 	int x=5;
 	float y=3.1415;
 	char a= 'a';

 	//format specifiers
 	printf("This is an int %d float = %0.2f char = %c ",x,y,a );

 	printf("Copy of string %s",string);

 	*/




//using the scanf
	/*

	char* string= "hello world";
 	int x=5;
 	float y=3.1415;
 	char a= 'a';
 	float inputx;
 	
 	*/



 	int correct;
 		printf("Please enter a number\n");
 	do
 	{
 		
 	 	correct=scanf("%f",&inputx);
 	 	if(correct==0)
 	 		{
 	 			printf("wrong human! Please enter numbers only.\n");
 	 		}
 		fflush(stdin);
 	}

 		
 	while(correct !=1);

 	





// Clask Task
 	/*

 	do
 	{
 		
 		scanf("%f",&inputx);
 		if (correct==0)
 		{
 			printf("\n wrong human");
 		}
 		printf("\nPlease enter a number");
 	}
 	while(correct != 1);





 	printf("\ninput was %f",inputx);

 	*/

 


 //format specifiers
 	/*	

 	printf("This is an int %d float = %0.2f char = %c ",x,y,a );
 	printf("\ninput was %f",inputx);
 	printf("\nCopy of string %s",string);

 	*/





//sprints

	/*  
		-printf/scanf: to/from console
 		- sprintf/sscanf: to/from string
 		-viptrinf/viscanf:
 		-fprintf/fscanf: to/from files
	


 	char a[65];
 	char b= "Number %f";
 	char c= "2.74 1.87";

 	sscanf(c, "%f %f", &x,&y);

 	sprintf(a, "Number %f",x);
 	sprintf(a,b,x);

	*/

 	
 	float x;
 	float y;

 	File * input_file;
 	


 	input_file= fopen("data.dat","r"); //many different ways to open a file second quotation refers to that

 	if(input_file != NULL) // this it to check if the fill is opened or not
 	{
 		fscanf(input_file,"%f %f",&x,&y);

 		fclose(input_file); // always close a file after opening it
 	}
 	



 	input_file= fopen("hello.txt","w");

 	fprintf(input_file, " Hello from x %f and y %f",x,y );

 	fclose(input_file);


}

/*TASK3
	produce a sin wave 
































