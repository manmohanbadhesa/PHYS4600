#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	/* Program to do some trig */
		
		float angle;
		float hypot=12;
		

		//angle = 0.7;

		float opp[30];
		int i;


		for(i=0; i<30; i++)
		{
			angle = (M_PI/2)*(i/30.0);
			opp[i]=hypot*sin(angle);
			printf("\nOpposite side= %f cm",opp[i]);
		}


		


		//printf("Opposite side= %f",opp); // the %f keeps a space for the number and places the number that is after the comma in the bracket
		//if you want to add a percent in print u have to write two percent symbols %%
		return 0;
}











