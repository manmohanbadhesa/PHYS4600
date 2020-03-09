#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>

// sprintf gives first variable a string in the middle the value after the comma
/*

ViStatus set_voltage(ViSession handle, float volts)
				{

					char command[36] ;
					sprintf(command,"CH1:SCALE %E\n", volts);
					ViStatus status = viWrite(handle, command, strlen(command), &resultCount);
					return status;
				}

*/



// never need to declare variables that are already in the argument


ViStatus get_curve(ViSession handle, char* databuffer, int npoints )
				{
					

					ViUInt32 resultCount;
					ViStatus status = VI_SUCCESS;

					viWrite(handle,"CURV?\n",6,&resultCount);
					status= viRead(handle,databuffer,npoints,&resultCount);
					return status;
				}



float smoothing_filter(float* rawdata, float* smoothdata, int Length, int window);
float amplitude(float* data, int length);

void main(int argc, char** argv)
{
	int datapoints=2500;
	unsigned char resultBuffer[256];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[datapoints];

	

	int y[2500];

	float smoothed[2500];


	int lsb;
	int msb;

	status = viOpenDefaultRM(&defaultRM);

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR",	&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer );

				viWrite(scopeHandle,"DAT:SOU CH1\n",12,&resultCount);

				
				get_curve(scopeHandle, dataBuffer, 2500);
				

							
				for(int i = 0; i<2500; i++)
				{
					y[i] = dataBuffer[i];
					//printf("\nRaw = %x,  Read = %d",y[i],y[i]);

				}
			}
			else
			{
				printf("\nFailed to open %s",description);
			}
		}
		else
		{
			printf("\nCouldn't find any instruments");
		}
	}
	else
	{
		printf("\nFailed to open defaultRM");
	}

	



	//getting the current setting of the volts per division on the oscope

	char ret[10];
	viWrite (scopeHandle,"CH1:SCA?\n",9,&resultCount);
	viRead(scopeHandle,ret,10,&resultCount );


	// getting the main time base

	char time[10];
	viWrite (scopeHandle,"HORizontal:MAIn?\n",17,&resultCount);
	viRead(scopeHandle,time,10,&resultCount );

	//printf("\n \n Currently the volts per division is  %s", ret);


				
	float volts_div, volts_bits;
	sscanf(ret,"%f", &volts_div);
	volts_bits= volts_div/(256/10);
	printf("\n  volts per bits is %f %f", volts_bits, volts_div);
	printf("\n time division is %f", time);
	float z[2500];

	for(int n=0;n<2500;n++)
	{
		z[n]= y[n]*volts_bits;
		//printf("\n volatage is =%f",z[n]);
	}

	


	// smooth the data using the filter from task4

	smoothing_filter(z,smoothed,2500,10);


	// printing the smooth data

/*
		for(int k=0; k<(2500-(10-1));k++)
			{		
				printf("\n %f    %f", smoothed[k], z[k]);
			}

*/			


	// getting the amplitude of the smoothed data

	float amplitude_smoothed;
	amplitude_smoothed= amplitude(smoothed,2500);

	printf("\n The amplitude is %f", amplitude_smoothed);

	
}


/*

ViSession scopeHandle;
ViSession FGHandle;



viFindRsrc(defaultRM, "USB[0-9]::0x0699?*INSTR",........, description);
viOpen(defaultRM, description, ....., &scopeHandle);

viFindRsrc(defaultRM, "USB[0-9]::0x1AB1?*INSTR",........, description);
viOpen(defaultRM, description, ....., &FGHandle);


*/