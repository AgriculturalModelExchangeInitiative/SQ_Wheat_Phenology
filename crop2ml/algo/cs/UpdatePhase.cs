	
 double phase1, ttFromLastLeafToHeading, appFLN, localDegfm, ttFromLastLeafToAnthesis;
phase1 = phase;				
if (phase1 >= 0.0 && phase1 < 1.0)//SowingToEmergence
{
			//CheckEmergence
	if (switchMaize==0)
	{
		if (cumulTT>= dse)
		{
			phase = 1.0;//Emergence
		}
		else
		{
			phase = phase1;
		}
	}
	else
	{
		if (cumulTT >= dse)
		{
			phase= 1.0;//Emergence
		}
		else
		{
			phase = phase1;
		}
	}
}
else if (phase1 >= 1.0 && phase1 < 2.0)//EmergenceToFloralInitiation
{
	if ((isVernalizable==1 && vernaprog >= 1.0) || (isVernalizable==0))
	{
		if (switchMaize==0)
		{
			if (dayLength > maxDL)
			{
				finalLeafNumber = minFinalNumber;
				hasLastPrimordiumAppeared = 1;						
			}
			else
			{
				appFLN = minFinalNumber + sLDL * (maxDL - dayLength);
						// calculation of final leaf number from dayLength at inflexion plus 2 leaves
				if (appFLN / 2.0 <= leafNumber)
				{
					finalLeafNumber = appFLN;
					hasLastPrimordiumAppeared =1;
				}
				else
				{
					phase = phase1;
				}
			}
			//for Maize phenologystate.hasLastPrimordiumAppeared = true;
		}
		else
		{
			hasLastPrimordiumAppeared = 1;
		}
				//CheckFloralInitiation
		if (hasLastPrimordiumAppeared==1)
		{
			phase = 2.0;//Floralinitiation
		}			
	}
	else
	{
		phase = phase1;
	}
}
else if (phase1 >= 2.0 && phase1 < 4.0)//FloralInitiationToAnthesis
{
	if (isMomentRegistredZC_39==1)
	{
				//calculate the heading date
		if (phase1 < 3.0)
		{
			ttFromLastLeafToHeading = 0.0;
			if(choosePhyllUse=="Default")ttFromLastLeafToHeading =(pFLLAnth - pHEADANTH) * fixPhyll;
			else if (choosePhyllUse == "PTQ") ttFromLastLeafToHeading = (pFLLAnth - pHEADANTH) * phyllochron;
			else if (choosePhyllUse == "Test") ttFromLastLeafToHeading = (pFLLAnth - pHEADANTH) * p;
			if (cumulTTFromZC_39 >= ttFromLastLeafToHeading)
			{
				phase = 3.0;
			}
			else
			{
				phase = phase1;
			}
		}					
				//CheckAnthesis;
		ttFromLastLeafToAnthesis =0.0;
		if (choosePhyllUse == "Default") ttFromLastLeafToAnthesis = pFLLAnth * fixPhyll;
		else if (choosePhyllUse == "PTQ") ttFromLastLeafToAnthesis = pFLLAnth * phyllochron;
		else if (choosePhyllUse == "Test") ttFromLastLeafToAnthesis = pFLLAnth * p;

		if (cumulTTFromZC_39 >= ttFromLastLeafToAnthesis)
		{
				phase = 4.0;//Anthesis
		}
		else
		{
			phase = phase1;
		}
	}
	else
		{
			phase = phase1;
		}		
}
else if (phase1 == 4.0)//AnthesisToEndCellDivision
{
			//CheckEndCellDivision
	if (grainCumulTT >= dcd)
	{
		phase = 4.5;//EndCellDivision
	}
	else
	{
		phase = phase1;
	}
}
else if (phase1 == 4.5)//EndCellDivisionToEndGrainFill
{
			// CheckEndGrainFilling
	if (grainCumulTT >= dgf || gai <= 0.0)
	{
		phase = 5.0;//End of grain filling
	}
	else
	{
		phase = phase1;
	}
}
else if (phase1 >= 5.0 && phase1 < 6.0)//EndGrainFillToMaturity
{
			//CheckMaturity
			///<Comment>To enable ignoring grain maturation duration</Comment>
	localDegfm = degfm;
	if (ignoreGrainMaturation==true) localDegfm = -1;			
	if (cumulTTFromZC_91 >= localDegfm)
	{
		phase = 6.0; //maturity
	}
	else
	{
		phase= phase1;
	}
}
else if (phase1>= 6.0 && phase1 < 7.0)
{
	phase = phase1;
}