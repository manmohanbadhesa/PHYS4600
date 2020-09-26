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

	int a=1,b=3, i=0; //limits of integration

	int n=100; //number from Simpson's Rule

	float deltax= (b-a)/n; //delta x for the approximated integral solution

	//float f[]=0.5*i;

	float X=0, X1=0, Xn=0, sum1=0, sum2=0; // the Simpson's rule terms up to f of Xn  

	for(i=0;i<101;i++)
	{
		/*X1=0.5*i;
		printf(" \n X1 is: %f", X1);
		*/

		if(i=0)
		{
			X1= 0.5*i;
			printf("X1 is: %f", X1);
		}
		else
			{

				X= 0.5*i;
				printf("X is: %f", X);
				/*
				if(n%2 == 0)
				{
					sum1 +=  0.5*i;
				}
				else
				{
					sum2 += 0.5*i;
				}
				*/
			}
		
	}





} 