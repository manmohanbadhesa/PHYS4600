#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>

/*float noise()
{
	srand(time(NULL));

	float a,b,c;

	a=(float)rand()/(float)RAND-MAX;
	b=(float)rand()/(float)RAND-MAX;

	c-(float)a-(float)b;









}



*/




int main()
{
	
	FILE* task4_input;
	task4_input =fopen("task4_data","w");

	if(task4_input == NULL) // this it to check if the fill is opened or not
 	{
 		printf("File didn't open");
 		return 0;
 	}

	float x[100];
	float y[100];

	int length;

	length= sizeof(y)/sizeof(y[0]);

	int i=0;


	for(i=0;i<100;i++)
	{
		x[i]=2*(M_PI)*i/100.0;
		y[i]=sin(x[i]);
		//printf("\n %f %f",x[i],y[i]);
		//fprintf(task4_input,"\n %f %f",x[i],y[i]);
	}

	fclose(task4_input);


	float max,min;

	max= y[0];
	min= y[0];

	int n=1;

	for(n=1; n<length; i++)
		{
			if(max < y[n])
			{
				max=y[n];
			}
		}

		printf("\n%f",max);
		return max;

		//printf("\n %f",max);
		
 	

	
}































