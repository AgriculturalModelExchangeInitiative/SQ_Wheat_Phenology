import package pheno;
 import java.util.List;
 import java.util.ArrayList;
 import java.math.BigDecimal;
public class UpdateLeafFlag
{
    public int HasFlagLeafLiguleAppeared;
    public List<String> calendarMoments;
    public List<Date> calendarDates;
    public List<Double> calendarCumuls;
    public UpdateLeafFlag(int _HasFlagLeafLiguleAppeared,List<String> _calendarMoments,List<Date> _calendarDates,List<Double> _calendarCumuls)
    {
        this.HasFlagLeafLiguleAppeared=_HasFlagLeafLiguleAppeared;
        this.calendarMoments=_calendarMoments;
        this.calendarDates=_calendarDates;
        this.calendarCumuls=_calendarCumuls;
    }
}

class Estimation_UpdateLeafFlag
{
    public static UpdateLeafFlag CalculateUpdateLeafFlag(double cumulTT,double leafNumber,List<String> calendarMoments,List<Date> calendarDates,List<Double> calendarCumuls,Date currentdate,double FinalLeafNumber,int HasFlagLeafLiguleAppeared,double phase)
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
            else:
                HasFlagLeafLiguleAppeared = 0;
        }
        return new UpdateLeafFlag(HasFlagLeafLiguleAppeared,calendarMoments,calendarDates,calendarCumuls);
    }

}
