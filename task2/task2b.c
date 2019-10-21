#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>
#include "task2b.h"


/* Part B of Task 2*/


float mean_function(float* data, int length)
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