#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>
#include <float.h>

float amplitude(float* data, int length)
{
	float maximum, minimum;
	maximum= -FLT_MAX;
	minimum= FLT_MAX;

	for(int i=0; i<length;i++)
	{
		if(maximum < data[i])
			{
				maximum=data[i];
			}
		if(minimum > data[i])
			{
				minimum=data[i];
			}
	}

}