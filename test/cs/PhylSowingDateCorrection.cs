public class PhylSowingDateCorrection
{
    public double FixPhyll;
    public PhylSowingDateCorrection(double _FixPhyll)
    {
        FixPhyll=_FixPhyll;
    }
}

public static class Estimation_PhylSowingDateCorrection
{
    public static PhylSowingDateCorrection CalculatePhylSowingDateCorrection(int SowingDay,double Latitude,int SDsa_sh,double Rp,int SDws,int SDsa_nh,double P)
    {


/*
     PhylSowingDateCorrection Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: Correction of the Phyllochron Varietal parameter according to sowing date 
    
*/
        double FixPhyll;

        if (Latitude < 0)
        {
        	if (SowingDay > SDsa_sh)
        	{
        		FixPhyll = P * (1 - Rp * Math.Min(SowingDay - SDsa_sh, SDws));
        	}
        	else FixPhyll = P;
        }
        else
        {
        	if (SowingDay < SDsa_nh)
        	{
        		FixPhyll = P * (1 - Rp * Math.Min(SowingDay, SDws));
        	}
        	else FixPhyll = P;
        }
        return new PhylSowingDateCorrection(FixPhyll);
    }
}

