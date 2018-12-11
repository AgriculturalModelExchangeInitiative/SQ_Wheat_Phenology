public class UpdateLeafFlag
{
    public int HasFlagLeafLiguleAppeared;
    public List<string> calendarMoments;
    public List<DateTime> calendarDates;
    public List<double> calendarCumuls;
    public UpdateLeafFlag(int _HasFlagLeafLiguleAppeared,List<string> _calendarMoments,List<DateTime> _calendarDates,List<double> _calendarCumuls)
    {
        HasFlagLeafLiguleAppeared=_HasFlagLeafLiguleAppeared;
        calendarMoments=_calendarMoments;
        calendarDates=_calendarDates;
        calendarCumuls=_calendarCumuls;
    }
}

public static class Estimation_UpdateLeafFlag
{
    public static UpdateLeafFlag CalculateUpdateLeafFlag(double cumulTT,double leafNumber,List<string> calendarMoments,List<DateTime> calendarDates,List<double> calendarCumuls,DateTime currentdate,double FinalLeafNumber,int HasFlagLeafLiguleAppeared,double phase)
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
                if (HasFlagLeafLiguleAppeared == 0 && (FinalLeafNumber > 0 && leafNumber >= FinalLeafNumber))
                {
                    HasFlagLeafLiguleAppeared = 1;
                    if  (calendarMoments.Contains("FlagLeafLiguleJustVisible")==false)
                    {
                        calendarMoments.Add("FlagLeafLiguleJustVisible");
                        calendarCumuls.Add(cumulTT);
                        calendarDates.Add(currentdate);
                    }
                }
            }
            else
                HasFlagLeafLiguleAppeared = 0;
        }
        return new UpdateLeafFlag(HasFlagLeafLiguleAppeared,calendarMoments,calendarDates,calendarCumuls);
    }
}

