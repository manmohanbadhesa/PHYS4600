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


 	//Creating the noise elements


	float x[100];
	float y[100];
	float noise[100];
	float z[100];

	float smooth_sin[100];
	

	int length, Lnoise;

	Lnoise= sizeof(noise)/sizeof(noise[0]);
	length= sizeof(y)/sizeof(y[0]);

	


	srand(time(NULL));

	float a,b;
	

	int i=0;
	
	float maximum, minimum;
	

	maximum= -FLT_MAX;
	minimum= FLT_MAX;

	//the sin function with the noise added

	for(i=0;i<100;i++)
	{
		
			a=(float)rand()/(float)RAND_MAX;
			b=(float)rand()/(float)RAND_MAX;

			noise[i]=((float)a-(float)b)/100;

		x[i]=2*(M_PI)*i/100.0;
		y[i]=(sin(x[i]))+noise[i];

		
			
		

		//finding the maximum and minimum to obtain the amplitude

		if(maximum < y[i])
			{
				maximum=y[i];
			}
		if(minimum > y[i])
			{
				minimum=y[i];
			}

		

		printf("\n %f",y[i]);
		//fprintf(task4_input,"\n %f %f",x[i],y[i]);
		
	}

	
	// smoothing filter



	for(int n=0; n<100; n++)
	{


				
				for(int j=n;j<(n+5);j++)
				{
					z[n] += y[j];
					
				}	
	 			smooth_sin[i]= z[n]/5;
	 			printf("\n \n \n %f",smooth_sin[i]);

	}

	fclose(task4_input);

		float amplitude;
		amplitude = (maximum-minimum)/2;

		
		printf("\n maximum is %f \n minimum is %f \n amplitude is %f",maximum, minimum, amplitude);
		

				
}































