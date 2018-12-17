package pheno2;
import java.util.List; 
import java.util.Date;
public class UpdateLeafFlag
{
    public int hasFlagLeafLiguleAppeared;
    public List<String> calendarMoments;
    public List<Date> calendarDates;
    public List<Double> calendarCumuls;
    public UpdateLeafFlag(int _hasFlagLeafLiguleAppeared,List<String> _calendarMoments,List<Date> _calendarDates,List<Double> _calendarCumuls)
    {
        this.hasFlagLeafLiguleAppeared=_hasFlagLeafLiguleAppeared;
        this.calendarMoments=_calendarMoments;
        this.calendarDates=_calendarDates;
        this.calendarCumuls=_calendarCumuls;
    }
}

class Estimation_UpdateLeafFlag
{
    public static UpdateLeafFlag CalculateUpdateLeafFlag(double cumulTT,double leafNumber,List<String> calendarMoments,List<Date> calendarDates,List<Double> calendarCumuls,Date currentdate,double finalLeafNumber,int hasFlagLeafLiguleAppeared,double phase)
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
                    if  (calendarMoments.contains("FlagLeafLiguleJustVisible")==false)
                    {
                        calendarMoments.add("FlagLeafLiguleJustVisible");
                        calendarCumuls.add(cumulTT);
                        calendarDates.add(currentdate);
                    }
                }
            }
            else
                hasFlagLeafLiguleAppeared = 0;
        }
        return new UpdateLeafFlag(hasFlagLeafLiguleAppeared,calendarMoments,calendarDates,calendarCumuls);
    }

}
