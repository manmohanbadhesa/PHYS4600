#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	/* Program to do some trig */
		
		float angle;
		float hypot=12;
		

		//angle = 0.7;

		float opp;
		opp=hypot*sin(angle);

		for(angle=0; angle<M_PI/2; angle+=M_PI/20)
		{
			opp=hypot*sin(angle);
			printf("\nOpposite side= %f cm",opp);
		}


		


		//printf("Opposite side= %f",opp); // the %f keeps a space for the number and places the number that is after the comma in the bracket
		//if you want to add a percent in print u have to write two percent symbols %%
		return 0;
}











