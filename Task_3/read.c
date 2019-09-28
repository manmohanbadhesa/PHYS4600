#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	

#include "Task_2.h"

float mean_function(float* , int);
float std_dev(float* data, int length);


int main()
{
	FILE* task3_input;
	task3_input =fopen("task3_data","r");

	if(task3_input == NULL) // this it to check if the fill is opened or not
 	{
 		printf("File didn't open");
 		return 0;
 	}

 	float x[100];
 	float y[100];

 	int n=0;
 	for(n=0;n<100;n++)
 	{
 		fscanf(task3_input,"\n%f %f",&x[n],&y[n]);
 		printf("\n%f %f",x[n],y[n]);
 	}
 	int lengthy;
 	

 	lengthy=sizeof(y)/sizeof(y[0]);

 	printf("\n %d",lengthy);

 	float meany, stddev;

 	meany = mean_function(y,lengthy);
 	stddev= std_dev(y, lengthy);

 	printf("\nMean of Sin function is= %f", meany);
 	printf("\nStandard deviation of sin is= %f", stddev);

 }

/* float mean_function(float* data, int length)
{
	float sum = 0;
	

	int n;
	for(n=0;n<length;n++)
	{
		sum += data[n];
	} 
	return sum/length;
}


float std_dev(float* data, int length)
{
	
	float sum2= 0;
	float mean2;
	mean2= mean_function(data,length);
	int i; 
	int n;
	
	
	for(i=0;i<length;i++)
		{
			sum2 += pow((mean2-data[i]),2);
		}

	return sqrt(sum2/(length-1));	


}
*/