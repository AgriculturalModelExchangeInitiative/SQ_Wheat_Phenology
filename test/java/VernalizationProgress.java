import package pheno;
 import java.util.List;
 import java.util.ArrayList;
 import java.math.BigDecimal;
public class VernalizationProgress
{
    public double Vernaprog;
    public double MinFinalNumber;
    public List<String> calendarMoments;
    public List<Date> calendarDates;
    public List<Double> calendarCumuls;
    public VernalizationProgress(double _Vernaprog,double _MinFinalNumber,List<String> _calendarMoments,List<Date> _calendarDates,List<Double> _calendarCumuls)
    {
        this.Vernaprog=_Vernaprog;
        this.MinFinalNumber=_MinFinalNumber;
        this.calendarMoments=_calendarMoments;
        this.calendarDates=_calendarDates;
        this.calendarCumuls=_calendarCumuls;
    }
}

class Estimation_VernalizationProgress
{
    public static VernalizationProgress CalculateVernalizationProgress(double DayLength,double DeltaTT,double cumulTT,double leafNumber,List<String> calendarMoments,List<Date> calendarDates,List<Double> calendarCumuls,double MinTvern,double IntTvern,double VAI,double VBEE,double MinDL,double MaxDL,double MaxTvern,double PNini,double AMXLFNO,double Vernaprog,Date currentdate,int IsVernalizable,double MinFinalNumber)
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

        if (IsVernalizable==1 && Vernaprog < 1)
        {
        	double TT = DeltaTT; // other sirius versions use previous temperature value
        	if (TT >= MinTvern && TT <= IntTvern)
        	{
        		Vernaprog = Vernaprog + VAI * TT + VBEE;
        	}
        	if (TT > IntTvern)
        	{
        		double maxVernaProg = VAI * IntTvern + VBEE;
        		double DLverna = Math.max(MinDL, Math.min(MaxDL, DayLength));
        		Vernaprog += Math.max(0, maxVernaProg * (1 + ((IntTvern - TT) / (MaxTvern - IntTvern)) * ((DLverna - MinDL) / (MaxDL - MinDL))));
        	}
        	double primordno = 2.0 * leafNumber + PNini;
        	double minLeafNumber = MinFinalNumber;
        	if (Vernaprog >= 1.0 || primordno >= AMXLFNO)
        	{
        		MinFinalNumber = Math.max(primordno, MinFinalNumber);
        		calendarMoments.add("EndVernalisation");
                calendarCumuls.add(cumulTT) ;
                calendarDates.add(currentdate);  
        	}
        	else
        	{
        		double potlfno = AMXLFNO - (AMXLFNO - minLeafNumber) * Vernaprog;
        		if (primordno >= potlfno)
        		{
        			MinFinalNumber = Math.max((potlfno + primordno) / 2.0, MinFinalNumber);	
        			calendarMoments.add("EndVernalisation");
                	calendarCumuls.add(cumulTT);
                	calendarDates.add(currentdate);  					
        			Vernaprog = Math.max(1, Vernaprog);
        		}
        	}
        }
        return new VernalizationProgress(Vernaprog,MinFinalNumber,calendarMoments,calendarDates,calendarCumuls);
    }

}
