#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	



/*void main(int argc, char** argv)
{
	
	
	int i=0;
	for(i=0;i<argc;i++)
	{
		printf("\n%s",argv[i]);
	}

	//return0;

	

	FILE* inputfile;
	inputfile =fopen(argv[1]);
}*/


//check end of file by
// if (fscanf("%f %f",&x,&y)!=eof)

int main()
{
	
	FILE* task3_input;
	task3_input =fopen("task3_data","w");

	if(task3_input == NULL) // this it to check if the fill is opened or not
 	{
 		printf("File didn't open");
 		return 0;
 	}

	float x[100];
	float y[100];

	int i=0;


	for(i=0;i<100;i++)
	{
		x[i]=2*(M_PI)*i/100.0;
		y[i]=sin(x[i]);
		//printf("\n %f %f",x[i],y[i]);
		fprintf(task3_input,"\n %f %f",x[i],y[i]);
	}

	fclose(task3_input);
 	

	
}
