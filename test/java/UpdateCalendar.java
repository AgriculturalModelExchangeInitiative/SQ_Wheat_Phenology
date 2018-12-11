import package pheno;
 import java.util.List;
 import java.util.ArrayList;
 import java.math.BigDecimal;
public class UpdateCalendar
{
    public List<String> calendarMoments;
    public List<Date> calendarDates;
    public List<Double> calendarCumuls;
    public UpdateCalendar(List<String> _calendarMoments,List<Date> _calendarDates,List<Double> _calendarCumuls)
    {
        this.calendarMoments=_calendarMoments;
        this.calendarDates=_calendarDates;
        this.calendarCumuls=_calendarCumuls;
    }
}

class Estimation_UpdateCalendar
{
    public static UpdateCalendar CalculateUpdateCalendar(double cumulTT,List<String> calendarMoments,List<Date> calendarDates,List<Double> calendarCumuls,Date currentdate,int phase)
    {


/*
     Calendar Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: Lists containing for each stage the date it occurs as well as a copy of all types of cumulated thermal times 
    
*/

        if ((phase >= 1 && phase < 2) && (calendarMoments.contains("Emergence")==false ))
        {
            calendarMoments.add("Emergence");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
        }
        else if ((phase >= 2 && phase < 3)  && ( calendarMoments.contains("FloralInitiation")==false  ))
        {
            calendarMoments.add("FloralInitiation") ;
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
        }
        else if ((phase >= 3 && phase < 4)  && (calendarMoments.contains("Heading")==false  ))
        {
            calendarMoments.add("Heading");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
        }
        else if ((phase == 4)  && (calendarMoments.contains("Anthesis" )==false  ))
        {
            calendarMoments.add("Anthesis");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
        }
        else if ((phase == 4.5)  && (calendarMoments.contains("EndCellDivision" )==false  ))
        {
            calendarMoments.add("EndCellDivision");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
        }
        else if ((phase >= 5 && phase < 6) && ( calendarMoments.contains("EndGrainFilling")==false  ))
        {
            calendarMoments.add("EndGrainFilling");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
        }
        else if ((phase >= 6 && phase < 7)  && (calendarMoments.contains("Maturity" )==false ))
        {
            calendarMoments.add("Maturity");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
        }
        return new UpdateCalendar(calendarMoments,calendarDates,calendarCumuls);
    }

}
