#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 



int main()
{
	char letter=57; /* or can assign actual letter by letter= '9'  or   you can assing a new line character letter='\n' the slash means 
	the charcter is important    and if you want to put an actual slash you need to put two of them like //	*/


 	// make the char a pointer
 	char* words= "Hello world"; // there is an extra \0 at the end to tell the array has ended
 	cursor=words;
 	
 	while(cursor != '\0')
 	{
 		printf("%c",cursor );
 	}




}


































