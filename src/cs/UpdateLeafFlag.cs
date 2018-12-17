public class UpdateLeafFlag
{
    public int hasFlagLeafLiguleAppeared;
    public List<string> calendarMoments;
    public List<DateTime> calendarDates;
    public List<double> calendarCumuls;
    public UpdateLeafFlag(int _hasFlagLeafLiguleAppeared,List<string> _calendarMoments,List<DateTime> _calendarDates,List<double> _calendarCumuls)
    {
        hasFlagLeafLiguleAppeared=_hasFlagLeafLiguleAppeared;
        calendarMoments=_calendarMoments;
        calendarDates=_calendarDates;
        calendarCumuls=_calendarCumuls;
    }
}

public static class Estimation_UpdateLeafFlag
{
    public static UpdateLeafFlag CalculateUpdateLeafFlag(double cumulTT,double leafNumber,List<string> calendarMoments,List<DateTime> calendarDates,List<double> calendarCumuls,DateTime currentdate,double finalLeafNumber,int hasFlagLeafLiguleAppeared,double phase)
    {


/*
     UpdateLeafFlag Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: tells if flag leaf has appeared and update the calendar if so
    	
    
*/

        if (phase >= 1 && phase< 4)
        {
            if (leafNumber > 0)
            {
                if (hasFlagLeafLiguleAppeared == 0 && (finalLeafNumber > 0 && leafNumber >= finalLeafNumber))
                {
                    hasFlagLeafLiguleAppeared = 1;
                    if  (calendarMoments.Contains("FlagLeafLiguleJustVisible")==false)
                    {
                        calendarMoments.Add("FlagLeafLiguleJustVisible");
                        calendarCumuls.Add(cumulTT);
                        calendarDates.Add(currentdate);
                    }
                }
            }
            else
                hasFlagLeafLiguleAppeared = 0;
        }
        return new UpdateLeafFlag(hasFlagLeafLiguleAppeared,calendarMoments,calendarDates,calendarCumuls);
    }
}

