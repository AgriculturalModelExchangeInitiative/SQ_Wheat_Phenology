public class LeafNumber
{
    public double leafNumber;
    public double Ntip;
    public LeafNumber(double _leafNumber,double _Ntip)
    {
        leafNumber=_leafNumber;
        Ntip=_Ntip;
    }
}

public static class Estimation_LeafNumber
{
    public static LeafNumber CalculateLeafNumber(double DeltaTT,double phyllochron,int HasFlagLeafLiguleAppeared,int SwitchMaize,double atip,double Leaf_tip_emerg,double k_bl,double Nlim,double leafNumber,double cumulTTPhenoMaizeAtEmergence,double cumulTT,double phase)
    {


/*
     CalculateLeafNumber Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: calculate leaf number. LeafNumber increase is caped at one more leaf per day
    
*/
        double Ntip;

        Ntip = 0;
        double leafNumber1;
        leafNumber1 =leafNumber;
        if (phase == 1 && cumulTTPhenoMaizeAtEmergence == 0)
        {
        	cumulTTPhenoMaizeAtEmergence = cumulTT;
        }
        if (phase >= 1 && phase< 4)
        {
        	if (HasFlagLeafLiguleAppeared==0)//sowingToAnthesis
        	{
        		if (SwitchMaize==0)
        		{
        			if (phyllochron == 0.0)
        			{
        				phyllochron = 0.0000001;
        			}
        			leafNumber = leafNumber1 + Math.Min(DeltaTT / phyllochron, 0.999);
        		}
        		else
        		{
        			if (leafNumber1 < Leaf_tip_emerg)
        			{
        				leafNumber = Leaf_tip_emerg;
        			}
        			else
        			{
        				double nextstartExpTT = 0;
        				double nexttipTT = ((leafNumber1 + 1) - Leaf_tip_emerg) / atip + cumulTTPhenoMaizeAtEmergence;
        				double abl = k_bl * atip;
        				double tt_lim_lip = ((Nlim - Leaf_tip_emerg) / atip) + cumulTTPhenoMaizeAtEmergence;
        				double bbl = Nlim - (abl * tt_lim_lip);
        				double tt_bl = ((leafNumber1 + 1) - bbl) / abl;
        				if (tt_bl > nexttipTT)
        				{
        					nextstartExpTT = nexttipTT;
        				}
        				else
        				{
        					nextstartExpTT = tt_bl;
        				}
        				if (cumulTT>= nextstartExpTT)
        				{
        					leafNumber = leafNumber1 + 1;
        				}
        				else
        				{
        					leafNumber = leafNumber1;
        				}
        			}
        			Ntip = atip * (cumulTT - cumulTTPhenoMaizeAtEmergence) + Leaf_tip_emerg;
        		}
        	}
        }
        return new LeafNumber(leafNumber,Ntip);
    }
}

