#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>
#include <float.h>





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
	float noise[10];
	

	int length, Lnoise;

	Lnoise= sizeof(noise)/sizeof(noise[0]);
	length= sizeof(y)/sizeof(y[0]);

	


	srand(time(NULL));

	float a,b,c;


	//c=a-b;
	
	//printf("\n a is %f \n b is  %f  \n c is %f ",a,b,c);

	int n=0; 
	for(n=0;n<Lnoise;n++)
		{
			srand(time(NULL));

			a[n]=(float)rand()/(float)RAND_MAX;
			b[n]=(float)rand()/(float)RAND_MAX;

			noise[n]=((float)a-(float)b)/100;

			printf("\n %f",noise[n]);
		}
	


	
	

	/*

	int i=0;
	float maximum, minimum;
	

	maximum= -FLT_MAX;
	minimum= FLT_MAX;

	for(i=0;i<100;i++)
	{
		

		x[i]=2*(M_PI)*i/100.0;
		y[i]=(sin(x[i]))+noise[i];
		
		if(maximum < y[i])
			{
				maximum=y[i];
			}
		if(minimum > y[i])
			{
				minimum=y[i];
			}
			

		printf("\n %f %f",x[i],y[i]);
		//fprintf(task4_input,"\n %f %f",x[i],y[i]);
		
	}

	fclose(task4_input);

		float amplitude;

		amplitude = (maximum-minimum)/2;


		
		printf("\n maximum is %f \n minimum is %f \n amplitude is %f",maximum, minimum, amplitude);
		//return maximum;

		//printf("\n %f",max);
		
 	
*/
	
}































