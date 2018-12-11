public class Phyllochron
{
    public double phyllochron;
    public double pastMaxAI;
    public Phyllochron(double _phyllochron,double _pastMaxAI)
    {
        phyllochron=_phyllochron;
        pastMaxAI=_pastMaxAI;
    }
}

public static class Estimation_Phyllochron
{
    public static Phyllochron CalculatePhyllochron(double FixPhyll,double leafNumber,double Lincr,double Ldecr,double Pdecr,double Pincr,double LAI,double PTQ,double GAI,double pastMaxAI,double Kl,double aPTQ,double PhylPTQ1,double P,string choosePhyllUse)
    {


/*
     Phyllochron Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: Calculate different types of phyllochron 
    
*/
        double phyllochron;

        phyllochron=0;
        if (choosePhyllUse =="Default")
        {
        	if (leafNumber < Ldecr) phyllochron = FixPhyll * Pdecr;
        	else if (leafNumber >= Ldecr && leafNumber < Lincr) phyllochron = FixPhyll;
        	else phyllochron = FixPhyll * Pincr;
        }        
        if (choosePhyllUse =="PTQ")
        {
            GAI = Math.Max(pastMaxAI,GAI);
            pastMaxAI = GAI;
            if (GAI > 0.0) phyllochron = PhylPTQ1 * ((GAI * Kl) / (1 - Math.Exp(-Kl * GAI))) / (PTQ + aPTQ);
            else phyllochron = PhylPTQ1;
        }        
        if (choosePhyllUse == "Test")
        {
            if (leafNumber < Ldecr) phyllochron = P * Pdecr;
            else if (leafNumber >= Ldecr && leafNumber < Lincr)  phyllochron = P;
            else phyllochron = P * Pincr;
        }       
        return new Phyllochron(phyllochron,pastMaxAI);
    }
}

