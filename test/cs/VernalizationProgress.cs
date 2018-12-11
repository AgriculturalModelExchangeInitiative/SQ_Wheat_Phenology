public class VernalizationProgress
{
    public double Vernaprog;
    public double MinFinalNumber;
    public List<string> calendarMoments;
    public List<DateTime> calendarDates;
    public List<double> calendarCumuls;
    public VernalizationProgress(double _Vernaprog,double _MinFinalNumber,List<string> _calendarMoments,List<DateTime> _calendarDates,List<double> _calendarCumuls)
    {
        Vernaprog=_Vernaprog;
        MinFinalNumber=_MinFinalNumber;
        calendarMoments=_calendarMoments;
        calendarDates=_calendarDates;
        calendarCumuls=_calendarCumuls;
    }
}

public static class Estimation_VernalizationProgress
{
    public static VernalizationProgress CalculateVernalizationProgress(double DayLength,double DeltaTT,double cumulTT,double leafNumber,List<string> calendarMoments,List<DateTime> calendarDates,List<double> calendarCumuls,double MinTvern,double IntTvern,double VAI,double VBEE,double MinDL,double MaxDL,double MaxTvern,double PNini,double AMXLFNO,double Vernaprog,DateTime currentdate,int IsVernalizable,double MinFinalNumber)
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
        		double DLverna = Math.Max(MinDL, Math.Min(MaxDL, DayLength));
        		Vernaprog += Math.Max(0, maxVernaProg * (1 + ((IntTvern - TT) / (MaxTvern - IntTvern)) * ((DLverna - MinDL) / (MaxDL - MinDL))));
        	}
        	double primordno = 2.0 * leafNumber + PNini;
        	double minLeafNumber = MinFinalNumber;
        	if (Vernaprog >= 1.0 || primordno >= AMXLFNO)
        	{
        		MinFinalNumber = Math.Max(primordno, MinFinalNumber);
        		calendarMoments.Add("EndVernalisation");
                calendarCumuls.Add(cumulTT) ;
                calendarDates.Add(currentdate);  
        	}
        	else
        	{
        		double potlfno = AMXLFNO - (AMXLFNO - minLeafNumber) * Vernaprog;
        		if (primordno >= potlfno)
        		{
        			MinFinalNumber = Math.Max((potlfno + primordno) / 2.0, MinFinalNumber);	
        			calendarMoments.Add("EndVernalisation");
                	calendarCumuls.Add(cumulTT);
                	calendarDates.Add(currentdate);  					
        			Vernaprog = Math.Max(1, Vernaprog);
        		}
        	}
        }
        return new VernalizationProgress(Vernaprog,MinFinalNumber,calendarMoments,calendarDates,calendarCumuls);
    }
}

