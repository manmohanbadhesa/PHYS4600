#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 



//How to create functions



/*int divide(int a, int b)
{
	int c=a/b;

	return c; // allows the below function to use variable c 
}


// the function below does not have access to any variables from the above function and vice versa
int main()
{
	int x=5;
	int y=3;
	int z;

	z= divide(x,y);
	printf("\n%d",z);
}*/


// Adding pointers



/*int divide(int a, int b, int* d)
{
	int c=a/b;
	*d=a%b;


	return c; // allows the below function to use variable c 
}


// the function below does not have access to any variables from the above function and vice versa


int main()
{
	int x=5;
	int y=3;
	int z;
	int rem;


	z= divide(x,y,&rem);
	printf("%d remainder %d",z, rem);
}*/



// How to add arrays to different functions as inputs and outputs


int divide_list(int* inp, int divisor, int* outp, int len)
{
	int i=0;
	for(i=0; i<len;i++)
	{
		outp[i] = inp[i]/divisor;

	}
}

int main()
{
	int a[]={1,2,3,5};
	int b[4];

	divide_list(a,2,b,4);


	int i=0;
	int c;
	for(i=0;i<4;i++)
	{
		c=b[i];
		printf("\n%d",c);
	}
	
}












/*int main()
{
	int array[]= {12,14,16,18};

	//printf("%d",array[2]);
	int* cursor=array;
	int i=0;

	for(i=0;i<4;i++)
	{
		printf("\n%d",*cursor);
		cursor ++;

	}

}*/