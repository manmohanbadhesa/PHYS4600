#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	

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
 	
 	

 	

}