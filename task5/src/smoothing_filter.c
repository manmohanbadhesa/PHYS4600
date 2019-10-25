#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>
#include <float.h>

#include "smoothing_filter.h"




float smoothing_filter(float* rawdata, float* smoothdata, int Length, int window)  
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