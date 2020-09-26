#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
                         Main application
 */
int main()
{
   // SYSTEM_Initialize();

	float a=0.5,sum;
	int k; 


	for(k=0;k<21; k++)
	{
		
		sum += pow(a,k);
	}

	printf("The sum is: %f", sum);

	//return  sum
}