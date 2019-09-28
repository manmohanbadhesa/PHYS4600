
#include "Task_2.h"

#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 




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





