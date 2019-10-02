#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>
#include <float.h>
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
	float maximum, minimum;
	maximum= -FLT_MAX;
	minimum= FLT_MAX;

	for(i=0;i<100;i++)
	{
		x[i]=2*(M_PI)*i/100.0;
		y[i]=sin(x[i]);
		
		if(maximum < y[i])
			{
				maximum=y[i];
			}
		if(minimum > y[i])
			{
				minimum=y[i];
			}
			

		//printf("\n %f %f",x[i],y[i]);
		//fprintf(task4_input,"\n %f %f",x[i],y[i]);
		
	}

	fclose(task4_input);

		float amplitude;

		amplitude = (maximum-minimum)/2;


		
		printf("\n maximum is %f \n minimum is %f \n amplitude is %f",maximum, minimum, amplitude);
		//return maximum;

		//printf("\n %f",max);
		
 	

	
}































