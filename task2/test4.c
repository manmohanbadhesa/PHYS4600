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

	float a=1,b=3; //limits of integration
	int i=0; 

	int n=100; //number from Simpson's Rule

	float deltax= (b-a)/n; //delta x for the approximated integral solution

	printf("deltax is: %f \n", deltax);

	float X=0, X1=0, Xn=0, sum1=0, sum2=0; // the Simpson's rule terms up to f of Xn  

	for(i=0;i<n;i++)
	{
		/*X1=0.5*i;
		printf(" \n X1 is: %f", X1);
		*/

		if(i==0)
		{
			X1= 0.5*i;
			printf("X1 is: %f", X1);
		}
		else
			{
				/*
				X= 0.5*i;
				printf("X is: %f", X);
				*/
				if(i%2 == 0)
				{
					sum1 +=  4*0.5*i;
				}
				else
				{
					sum2 += 2*0.5*i;
				}
			
				//printf("\n sum 1 is: %f \n sum2 is: %f ", sum1, sum2);

			}
		
	}

		printf("\n sum 1 is: %f \n sum2 is: %f ", sum1, sum2);

	for(i=n;i<n+1;i++)
	{
		Xn= 0.5*n;
		printf("\n Xn is: %f", Xn);
	}

	float area, sum3;

	sum3= X1 + Xn + sum1, sum2;

	area = sum3* deltax/3;

	printf("\n The area under the function using Simpson's Rule is: %f",area);

} 