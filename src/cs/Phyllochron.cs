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
    public static Phyllochron CalculatePhyllochron(double fixPhyll,double leafNumber,double lincr,double ldecr,double pdecr,double pincr,double ptq,double gai,double pastMaxAI,double kl,double aPTQ,double phylPTQ1,double p,string choosePhyllUse)
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
        	if (leafNumber < ldecr) phyllochron = fixPhyll * pdecr;
        	else if (leafNumber >= ldecr && leafNumber < lincr) phyllochron = fixPhyll;
        	else phyllochron = fixPhyll * pincr;
        }         
        if (choosePhyllUse =="PTQ")
        {
            gai = Math.Max(pastMaxAI,gai);
            pastMaxAI = gai;
            if (gai > 0.0) phyllochron = phylPTQ1 * ((gai * kl) / (1 - Math.Exp(-kl * gai))) / (ptq + aPTQ);
            else phyllochron = phylPTQ1;   
        }        
        if (choosePhyllUse == "Test")
        {
            if (leafNumber < ldecr) phyllochron = p * pdecr;
            else if (leafNumber >= ldecr && leafNumber < lincr)  phyllochron = p;
            else phyllochron = p * pincr;
        }       
        return new Phyllochron(phyllochron,pastMaxAI);
    }
}

