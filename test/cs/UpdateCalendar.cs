public class UpdateCalendar
{
    public List<string> calendarMoments;
    public List<DateTime> calendarDates;
    public List<double> calendarCumuls;
    public UpdateCalendar(List<string> _calendarMoments,List<DateTime> _calendarDates,List<double> _calendarCumuls)
    {
        calendarMoments=_calendarMoments;
        calendarDates=_calendarDates;
        calendarCumuls=_calendarCumuls;
    }
}

public static class Estimation_UpdateCalendar
{
    public static UpdateCalendar CalculateUpdateCalendar(double cumulTT,List<string> calendarMoments,List<DateTime> calendarDates,List<double> calendarCumuls,DateTime currentdate,int phase)
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

        if ((phase >= 1 && phase < 2) && (calendarMoments.Contains("Emergence")==false ))
        {
            calendarMoments.Add("Emergence");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
        }
        else if ((phase >= 2 && phase < 3)  && ( calendarMoments.Contains("FloralInitiation")==false  ))
        {
            calendarMoments.Add("FloralInitiation") ;
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
        }
        else if ((phase >= 3 && phase < 4)  && (calendarMoments.Contains("Heading")==false  ))
        {
            calendarMoments.Add("Heading");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
        }
        else if ((phase == 4)  && (calendarMoments.Contains("Anthesis" )==false  ))
        {
            calendarMoments.Add("Anthesis");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
        }
        else if ((phase == 4.5)  && (calendarMoments.Contains("EndCellDivision" )==false  ))
        {
            calendarMoments.Add("EndCellDivision");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
        }
        else if ((phase >= 5 && phase < 6) && ( calendarMoments.Contains("EndGrainFilling")==false  ))
        {
            calendarMoments.Add("EndGrainFilling");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
        }
        else if ((phase >= 6 && phase < 7)  && (calendarMoments.Contains("Maturity" )==false ))
        {
            calendarMoments.Add("Maturity");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
        }
        return new UpdateCalendar(calendarMoments,calendarDates,calendarCumuls);
    }
}

