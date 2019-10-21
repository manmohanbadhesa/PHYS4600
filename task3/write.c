#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	



// main function to write angle and sin of the angle values to a file

int main()
{
	// opened file and declared it "w" to decalre as writable

	FILE* task3_input;
	task3_input =fopen("task3_data","w");


	// checked to see if file opened

	if(task3_input == NULL) // this it to check if the fill is opened or not
 	{
 		printf("File didn't open");
 		return 0;
 	}


 	// declare the arrays x and y for the values

	float x[100];
	float y[100];

	int i=0;


	// using decalred arrays, gave x the angle and y the sin of the angle
	// used the fprintf to wrwite the array in new lines and as pairs of x and y for the angle and sin(angle)

	for(i=0;i<100;i++)
	{
		x[i]=2*(M_PI)*i/100.0;
		y[i]=sin(x[i]);
		//printf("\n %f %f",x[i],y[i]);
		fprintf(task3_input,"\n %f %f",x[i],y[i]);
	}


	// *** Always important to close the file after using ***

	fclose(task3_input);
 	

	
}
