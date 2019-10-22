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



ViStatus get_curve(ViSession handle, char* dataBuffer, int npoints )
				{
					viWrite(scopeHandle,"CURV?\n",6,&resultCount);
					viRead(scopeHandle,dataBuffer,npoints,&resultCount);
					status= viRead(handle, dataBuffer, npoints);
					return status;
				}

*/

void main(int argc, char** argv)
{
	unsigned char resultBuffer[256];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];

	int y;

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

				
				viWrite(scopeHandle,"CURV?\n",6,&resultCount);
				viRead(scopeHandle,dataBuffer,2500,&resultCount);

				for(int i = 0; i<200; i++)
				{
					y = dataBuffer[i];
					printf("\nRaw = %x,  Read = %d",y,y);
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


	//printf("\n \n Currently the volts per division is  %s", ret);


	
	float volts_bits;
	sscanf(ret,"%f", &volts_bits);
	printf("\n  volts per bits is %f", volts_bits);

	for(int n=0;n<20;n++)
	{
		
	}
	

	
}


/*

ViSession scopeHandle;
ViSession FGHandle;



viFindRsrc(defaultRM, "USB[0-9]::0x0699?*INSTR",........, description);
viOpen(defaultRM, description, ....., &scopeHandle);

viFindRsrc(defaultRM, "USB[0-9]::0x1AB1?*INSTR",........, description);
viOpen(defaultRM, description, ....., &FGHandle);


*/