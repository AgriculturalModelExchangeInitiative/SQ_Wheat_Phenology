import package pheno;
 import java.util.List;
 import java.util.ArrayList;
 import java.math.BigDecimal;
public class UpdatePhase
{
    public double FinalLeafNumber;
    public double phase;
    public int hasLastPrimordiumAppeared;
    public UpdatePhase(double _FinalLeafNumber,double _phase,int _hasLastPrimordiumAppeared)
    {
        this.FinalLeafNumber=_FinalLeafNumber;
        this.phase=_phase;
        this.hasLastPrimordiumAppeared=_hasLastPrimordiumAppeared;
    }
}

class Estimation_UpdatePhase
{
    public static UpdatePhase CalculateUpdatePhase(double cumulTT,double leafNumber,double cumulTTFromZC_39,int isMomentRegistredZC_39,double GAI,double GrainCumulTT,double DayLength,double Vernaprog,double MinFinalNumber,double FixPhyll,int IsVernalizable,double Dse,double PFLLAnth,double Dcd,double Dgf,double Degfm,double MaxDL,double SLDL,boolean IgnoreGrainMaturation,double PHEADANTH,int SwitchMaize,String choosePhyllUse,double P,double phase,double cumulTTFromZC_91,double phyllochron,int hasLastPrimordiumAppeared,double FinalLeafNumber)
    {


/*
     UpdatePhase Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: This strategy advances the phase and calculate the final leaf number
    	
    
*/

        double phase1 = phase;
        if (phase1 >= 0 && phase1 < 1)//SowingToEmergence
        {
        			//CheckEmergence
        	if (SwitchMaize==0)
        	{
        		if (cumulTT>= Dse)
        		{
        			phase = 1;//Emergence
        		}
        		else
        		{
        			phase = phase1;
        		}
        	}
        	else
        	{
        		if (cumulTT >= Dse)
        		{
        			phase= 1;//Emergence
        		}
        		else
        		{
        			phase = phase1;
        		}
        	}
        }
        else if (phase1 >= 1 && phase1 < 2)//EmergenceToFloralInitiation
        {
        	if ((IsVernalizable==1 && Vernaprog >= 1) || (IsVernalizable==0))
        	{
        		if (SwitchMaize==0)
        		{
        			if (DayLength > MaxDL)
        			{
        				FinalLeafNumber = MinFinalNumber;
        				hasLastPrimordiumAppeared = 1;
        			}
        			else
        			{
        				double appFLN = MinFinalNumber + SLDL * (MaxDL - DayLength);
        						// calculation of final leaf number from daylength at inflexion plus 2 leaves
        				if (appFLN / 2.0 <= leafNumber)
        				{
        					FinalLeafNumber = appFLN;
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
        			phase = 2;//Floralinitiation
        		}
        	}
        	else
        	{
        		phase = phase1;
        	}
        }
        else if (phase1 >= 2 && phase1 < 4)//FloralInitiationToAnthesis
        {
        	if (isMomentRegistredZC_39==1)
        	{
        				//calculate the heading date
        		if (phase1 < 3)
        		{
        			double ttFromLastLeafToHeading = 0.0;
        			if(choosePhyllUse=="Default")ttFromLastLeafToHeading =(PFLLAnth - PHEADANTH) * FixPhyll;
        			else if (choosePhyllUse == "PTQ") ttFromLastLeafToHeading = (PFLLAnth - PHEADANTH) * phyllochron;
        			else if (choosePhyllUse == "Test") ttFromLastLeafToHeading = (PFLLAnth - PHEADANTH) * P;
        			if (cumulTTFromZC_39 >= ttFromLastLeafToHeading)
        			{
        				phase = 3;
        			}
        			else
        			{
        				phase = phase1;
        			}
        		}					
        				//CheckAnthesis;
        		double ttFromLastLeafToAnthesis =0.0;
        		if (choosePhyllUse == "Default") ttFromLastLeafToAnthesis = PFLLAnth * FixPhyll;
        		else if (choosePhyllUse == "PTQ") ttFromLastLeafToAnthesis = PFLLAnth * phyllochron;
        		else if (choosePhyllUse == "Test") ttFromLastLeafToAnthesis = PFLLAnth * P;
        		if (cumulTTFromZC_39 >= ttFromLastLeafToAnthesis)
        		{
        				phase = 4;//Anthesis
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
        else if (phase1 == 4)//AnthesisToEndCellDivision
        {
        			//CheckEndCellDivision
        	if (GrainCumulTT >= Dcd)
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
        	if (GrainCumulTT >= Dgf || GAI <= 0)
        	{
        		phase = 5;//End of grain filling
        	}
        	else
        	{
        		phase = phase1;
        	}
        }
        else if (phase1 >= 5 && phase1 < 6)//EndGrainFillToMaturity
        {
        			//CheckMaturity
        			///<Comment>To enable ignoring grain maturation duration</Comment>
        	double LocalDegfm = Degfm;
        	if (IgnoreGrainMaturation==true) LocalDegfm = -1;
        	if (cumulTTFromZC_91 >= LocalDegfm)
        	{
        		phase = 6; //maturity
        	}
        	else
        	{
        		phase= phase1;
        	}
        }
        else if (phase1>= 6 && phase1 < 7)
        {
        	phase = phase1;
        }
        return new UpdatePhase(FinalLeafNumber,phase,hasLastPrimordiumAppeared);
    }

}
