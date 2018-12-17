public class VernalizationProgress
{
    public double vernaprog;
    public double minFinalNumber;
    public List<string> calendarMoments;
    public List<DateTime> calendarDates;
    public List<double> calendarCumuls;
    public VernalizationProgress(double _vernaprog,double _minFinalNumber,List<string> _calendarMoments,List<DateTime> _calendarDates,List<double> _calendarCumuls)
    {
        vernaprog=_vernaprog;
        minFinalNumber=_minFinalNumber;
        calendarMoments=_calendarMoments;
        calendarDates=_calendarDates;
        calendarCumuls=_calendarCumuls;
    }
}

public static class Estimation_VernalizationProgress
{
    public static VernalizationProgress CalculateVernalizationProgress(double dayLength,double deltaTT,double cumulTT,double leafNumber,List<string> calendarMoments,List<DateTime> calendarDates,List<double> calendarCumuls,double minTvern,double intTvern,double vAI,double vBEE,double minDL,double maxDL,double maxTvern,double pNini,double aMXLFNO,double vernaprog,DateTime currentdate,int isVernalizable,double minFinalNumber)
    {


/*
     VernalizationProgress Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: Calculate progress (VernaProg) towards vernalization, but there 
        			is no vernalization below minTvern 
        			and above maxTvern . The maximum value of VernaProg is 1.
        			Progress towards full vernalization is a linear function of shoot 
        			temperature (soil temperature until leaf # reach MaxLeafSoil and then
        			 canopy temperature)
    	
    
*/

        if (IsVernalizable==1 && vernaprog < 1)
        {
        	tt = deltaTT; // other sirius versions use previous temperature value
        	if (tt >= minTvern && tt <= intTvern)
        	{
        		vernaprog = vernaprog + vAI * tt + vBEE;
        	}
        	if (tt > intTvern)
        	{
        		double maxVernaProg = vAI * intTvern + vBEE;
        		double DLverna = Math.Max(minDL, Math.Min(maxDL, dayLength));
        		vernaprog += Math.Max(0, maxVernaProg * (1 + ((intTvern - tt) / (maxTvern - intTvern)) * ((dLverna - minDL) / (maxDL - minDL))));
        	}			
        	double primordno = 2.0 * leafNumber + pNini;
        	double minLeafNumber = minFinalNumber;
        	if (vernaprog >= 1.0 || primordno >= aMXLFNO)
        	{
        		MinFinalNumber = Math.Max(primordno, minFinalNumber);
        		calendarMoments.Add("EndVernalisation");
                calendarCumuls.Add(cumulTT) ;
                calendarDates.Add(currentdate);  
        	}
        	else
        	{
        		potlfno = aMXLFNO - (aMXLFNO - minLeafNumber) * vernaprog;
        		if (primordno >= potlfno)
        		{
        			MinFinalNumber = Math.Max((potlfno + primordno) / 2.0, minFinalNumber);	
        			calendarMoments.Add("EndVernalisation");
                	calendarCumuls.Add(cumulTT);
                	calendarDates.Add(currentdate);  					
        			vernaprog = Math.Max(1, vernaprog);
        		}
        	}
        }
        return new VernalizationProgress(vernaprog,minFinalNumber,calendarMoments,calendarDates,calendarCumuls);
    }
}

