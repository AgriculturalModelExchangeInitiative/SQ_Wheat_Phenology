package pheno2;
public class PhylSowingDateCorrection
{
    public double fixPhyll;
    public PhylSowingDateCorrection(double _fixPhyll)
    {
        this.fixPhyll=_fixPhyll;
    }
}

class Estimation_PhylSowingDateCorrection
{
    public static PhylSowingDateCorrection CalculatePhylSowingDateCorrection(int sowingDay,double latitude,int sDsa_sh,double rp,int sDws,int sDsa_nh,double p)
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
        double fixPhyll;

        if (latitude < 0)
        {
        	if (sowingDay > sDsa_sh)
        	{
        		fixPhyll = p * (1 - rp * Math.min(sowingDay - sDsa_sh, sDws));
        	}
        	else fixPhyll = p;
        }
        else
        {
        	if (sowingDay < sDsa_nh)
        	{
        		fixPhyll = p * (1 - rp * Math.min(sowingDay, sDws));
        	}
        	else fixPhyll = p;
        }
        return new PhylSowingDateCorrection(fixPhyll);
    }

}
