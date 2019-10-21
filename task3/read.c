#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	

#include "meanstd.h"


// defined functions from meanstd in order to use them in this program

float mean_function(float* , int);
float std_dev(float* data, int length);


// main function to read sin values from a file

int main()
{

	//open a file and declare it a "r" to decalre reading only
	FILE* task3_input;
	task3_input =fopen("task3_data","r");


	
	// this it to check if the fill is opened or not

	if(task3_input == NULL) 
 	{
 		printf("File didn't open");
 		return 0;
 	}

 	

 	float x[100];
 	float y[100];



 	// reading the opened file "task3_data"
 	// scanning for floats in the file using fscanf
 	// the function scans for exact match ie. spaces have to be exactly as in the file
 	// the scanned values are added the the x and y arrays defined above

 	int n=0;
 	for(n=0;n<100;n++)
 	{
 		fscanf(task3_input,"\n%f %f",&x[n],&y[n]);
 		printf("\n%f %f",x[n],y[n]);
 	}
 	int lengthy;
 	

 	lengthy=sizeof(y)/sizeof(y[0]);



 	//was printing length of array as a test
 	//printf("\n %d",lengthy);

 	float meany, stddev;


 	// using the mean and stddev funcitons from the meanstd file to calculate
 	meany = mean_function(y,lengthy);
 	stddev= std_dev(y, lengthy);

 	printf("\nMean of Sin function is= %f", meany);
 	printf("\nStandard deviation of sin is= %f", stddev);

 	//  ****End of Writing and Read \ing program, confirmed results using the following funciton below  ****

 }







 // the functions were copied here to compare results with already working program  //

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