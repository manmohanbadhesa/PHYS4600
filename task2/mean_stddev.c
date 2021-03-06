
#include "task2b.h"

#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	

float mean_function(float* , int);
float std_dev(float* data, int length);


/* function to calculate stddev and mean together*/

int main()
{
	float data [] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};
	int length;
	length= sizeof(data)/sizeof(data[0]);
	float mean;
	float stddev;

	mean = mean_function(data,length);
	stddev= std_dev(data, length);


	// Prints mean and stddev of the data set provided 

	printf("\nMean = %f", mean);
	printf("\nStandard deviation = %f", stddev);
	printf("\nMean = %d", length);

	
	return 0;  
}