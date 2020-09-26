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
	int n[101];
	int sum=0, k;

	for(k=0;k<102;k++)
	{
		n[k]=k;
		sum += n[k] ;

	}

	printf("\n The sum of integral numbers from 0 to 100 is: %d", sum);
}