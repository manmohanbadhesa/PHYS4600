#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>

float noise()
{
	srand(time(NULL));

	float a,b,c;

	a=(float)rand()/(float)RAND-MAX;
	b=(float)rand()/(float)RAND-MAX;

	c-(float)a-(float)b;





	printf("%f\n%f\n%f",a,b,c);



}









float sin_function()
{
	
	FILE* task3_input;
	task3_input =fopen("task4_data","w");

	if(task3_input == NULL) // this it to check if the fill is opened or not
 	{
 		printf("File didn't open");
 		return 0;
 	}

	float x[100];
	float y[100];

	int i=0;


	for(i=0;i<100;i++)
	{
		x[i]=2*(M_PI)*i/100.0;
		y[i]=sin(x[i]);
		//printf("\n %f %f",x[i],y[i]);
		fprintf(task4_input,"\n %f %f",x[i],y[i]);
	}

	fclose(task3_input);


	float max,min;

	max= data[0];
	min= data{0};

	int i=1;

	for(i=1; i<length; i++)
		{
			if(max<data[i])
			{
				
			}
		}

 	

	
}































