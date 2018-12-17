package pheno2;
import java.util.List; 
import java.util.Date;
public class VernalizationProgress
{
    public double vernaprog;
    public double minFinalNumber;
    public List<String> calendarMoments;
    public List<Date> calendarDates;
    public List<Double> calendarCumuls;
    public VernalizationProgress(double _vernaprog,double _minFinalNumber,List<String> _calendarMoments,List<Date> _calendarDates,List<Double> _calendarCumuls)
    {
        this.vernaprog=_vernaprog;
        this.minFinalNumber=_minFinalNumber;
        this.calendarMoments=_calendarMoments;
        this.calendarDates=_calendarDates;
        this.calendarCumuls=_calendarCumuls;
    }
}

class Estimation_VernalizationProgress
{
    public static VernalizationProgress CalculateVernalizationProgress(double dayLength,double deltaTT,double cumulTT,double leafNumber,List<String> calendarMoments,List<Date> calendarDates,List<Double> calendarCumuls,double minTvern,double intTvern,double vAI,double vBEE,double minDL,double maxDL,double maxTvern,double pNini,double aMXLFNO,double vernaprog,Date currentdate,int isVernalizable,double minFinalNumber)
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

        if (isVernalizable==1 && vernaprog < 1)
        {
        	double tt = deltaTT; // other sirius versions use previous temperature value
        	if (tt >= minTvern && tt <= intTvern)
        	{
        		vernaprog = vernaprog + vAI * tt + vBEE;
        	}
        	if (tt > intTvern)
        	{
        		double maxVernaProg = vAI * intTvern + vBEE;
        		double dLverna = Math.max(minDL, Math.min(maxDL, dayLength));
        		vernaprog += Math.max(0, maxVernaProg * (1 + ((intTvern - tt) / (maxTvern - intTvern)) * ((dLverna - minDL) / (maxDL - minDL))));
        	}			
        	double primordno = 2.0 * leafNumber + pNini;
        	double minLeafNumber = minFinalNumber;
        	if (vernaprog >= 1.0 || primordno >= aMXLFNO)
        	{
        		minFinalNumber = Math.max(primordno, minFinalNumber);
        		calendarMoments.add("EndVernalisation");
                calendarCumuls.add(cumulTT) ;
                calendarDates.add(currentdate);  
        	}
        	else
        	{
        		double potlfno = aMXLFNO - (aMXLFNO - minLeafNumber) * vernaprog;
        		if (primordno >= potlfno)
        		{
        			minFinalNumber = Math.max((potlfno + primordno) / 2.0, minFinalNumber);	
        			calendarMoments.add("EndVernalisation");
                	calendarCumuls.add(cumulTT);
                	calendarDates.add(currentdate);  					
        			vernaprog = Math.max(1, vernaprog);
        		}
        	}
        }
        return new VernalizationProgress(vernaprog,minFinalNumber,calendarMoments,calendarDates,calendarCumuls);
    }

}
