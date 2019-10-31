#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>



void main()
{

	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession fgdefault, FGHandle;
	ViChar description[VI_FIND_BUFLEN];

	status = viOpenDefaultRM(&defaultRM);

	

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(fgdefault,"USB[0-9]::?*INSTR", &resourceList, &num_inst, description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(fgdefault,description,	VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{

				printf("\nOpened %s\n",description);























}