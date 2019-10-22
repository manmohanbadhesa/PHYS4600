#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>
#include <float.h>


float smoothing_filter(float* rawdata, float* smoothdata, int Length, int window);


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
	float smooth;
	float noise[100];
	
	int window;

	window =5;
	float smooth_sin[100];

	


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

		
	
	}
	

	smooth= smoothing_filter(y,smooth_sin,length, window);


	for(int k=0; k<(length-(window-1));k++)
	{		
		printf("\n %f    %f", smooth_sin[k], y[k]);
	}
	

	//fclose(task4_input);


		//calculating the amplitude by adding max and min and dividing by two 

		float amplitude;
		amplitude = (maximum-minimum)/2;

		// outputting the max, min, and ampltude 
		printf("\n maximum is %f \n minimum is %f \n amplitude is %f",maximum, minimum, amplitude);



}
	
/*
	JAMES: This is good as far as it goes. But it would be more useful if your function had the option
	to actually enter the length of the data and your window for smoothing to the function.
*/




	// smoothing filter
float smoothing_filter(float* rawdata, float* smoothdata, int Length, int window)  /*TRY: (float* data, int data_length, int window_length) */
{	
	
	float m;
	int n=0;
	float z[Length];


	for(n=0; n<(Length-(window-1)); n++)
	{
				m=0;
				for(int j=n;j<(n+window);j++)
				{
					m += rawdata[j];
				}	
				z[n]=m ;
	 			smoothdata[n]= z[n]/window;
	 			//printf("\n %f      %f",z[n],smooth_sin[n]);

	}
	
}
















/*

	
		float smoothed_values[100];
		
		smoothed_values[i] = smoothing_filter(y);
		printf("\n  %f",smoothed_values[i]);
		//printf("\n %f",y[i]);
		//fprintf(task4_input,"\n %f %f",x[i],y[i]);



*/


















