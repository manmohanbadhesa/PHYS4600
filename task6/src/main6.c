#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include <string.h>



ViStatus set_frequency(ViSession handle, float frequency, ViUInt32 resultCount)
				{

					char command[36] ;
					sprintf(command,":SOUR1:FREQ %E\n", frequency);
					ViStatus status = viWrite(handle, command, strlen(command), &resultCount);
					return status;
				}





void main()
{


	unsigned char resultBuffer[256];

	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, FGHandle, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];

	status = viOpenDefaultRM(&defaultRM);

			if(status == VI_SUCCESS)
			{
					status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR", &resourceList, &num_inst, description);
				
				if(status == VI_SUCCESS)
					{

						status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle);

						if(status == VI_SUCCESS)
							{
								printf("\nOpened %s\n",description);
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
	

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR", &resourceList, &num_inst, description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&FGHandle);


			if(status == VI_SUCCESS)
			{

				printf("\nOpened %s\n",description);

				/*   MOST OF CODE GOES HERE  */


				viWrite(FGHandle,"*IDN?\n",6,&resultCount);
				viRead(FGHandle,resultBuffer,256,&resultCount);

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer );

				viWrite(FGHandle,":SOUR1:APPL:SIN 500,2.5,1,90\n",29,&resultCount);

				viWrite(FGHandle,":OUTP1 ON\n",10,&resultCount);
			



				for(int i=0; i<5; i++)
				{
					set_frequency(FGHandle, 1500.0*i, resultCount);




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

}