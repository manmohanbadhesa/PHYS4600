#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>
#include <float.h>


float smoothing_filter(float* data);


int main()
{
	
	FILE* task4_input;
	task4_input =fopen("task4_data","w");

	// this it to check if the fill is opened or not


	if(task4_input == NULL) 
 	{
 		printf("File didn't open");
 		return 0;
 	}


 	//Creating the noise elements

	float x[100];
	float y[100];
	float noise[100];

	


	//lengths of the arrays 

	int length, Lnoise;
	Lnoise= sizeof(noise)/sizeof(noise[0]);
	length= sizeof(y)/sizeof(y[0]);

	

	// the srand(time(NULL)) creates a new list of random numbers everytime in order to avoid using the same random number list everytime
	// making it a function of time uses the time of the computer and therefore gurantees a new list of random numbers
	srand(time(NULL));

	
	
	//used the FLT_MAX as the min and max initally because this is the max value of a floating number that can be produced in C.
	/* the negative of the max number is the lowest maximum produced by C, used as the maximum in order to make any first 
	value in an array the maximum and then compared to the next value */
	float maximum, minimum;
	maximum= -FLT_MAX;
	minimum= FLT_MAX;



	//the sin function with the noise added
	int i=0;
	float a,b;
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

		
		float smoothed_values[100];
		
		smoothed_values[i] = smoothing_filter(y);
		printf("\n  %f",smoothed_values[i]);
		//printf("\n %f",y[i]);
		//fprintf(task4_input,"\n %f %f",x[i],y[i]);
		
	}
	



	//fclose(task4_input);


		//calculating the amplitude by adding max and min and dividing by two 

		float amplitude;
		amplitude = (maximum-minimum)/2;

		// outputting the max, min, and ampltude 
		printf("\n maximum is %f \n minimum is %f \n amplitude is %f",maximum, minimum, amplitude);



}
	



	// smoothing filter
float smoothing_filter(float* data)
{	
	
	float m;
	int n=0;
	float z[100];

	float smooth_sin[100];

	for(n=0; n<100; n++)
	{
			
				for(int j=n;j<(n+5);j++)
				{
					m += data[j];
				}	
				z[n]=m ;
	 			smooth_sin[n]= z[n]/5;
	 			//printf("\n %f      %f",z[n],smooth_sin[n]);

	}
	return smooth_sin[n];
}































