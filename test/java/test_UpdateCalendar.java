//Test generation'
package pheno2;
import java.util.*;
import java.math.BigDecimal;
import java.text.ParseException;
import java.text.SimpleDateFormat;
class test_UpdateCalendar
{    //check wheat model);
    //test_wheat1);

    public static void test_wheat1()
    {
        double cumulTT =  112.330110409888;
        List<String> calendarMoments = new ArrayList<>();
        calendarMoments.addAll(Arrays.asList("Sowing"));
        SimpleDateFormat format=new SimpleDateFormat("dd/MM/yyyy");
        List<Date> calendarDates=new ArrayList<>() ;
        try
        {
            calendarDates.addAll(Arrays.asList(format.parse("21/3/2007")));
        }
        catch (ParseException e)
        {
        }
        List<Double> calendarCumuls = new ArrayList<>();
        calendarCumuls.addAll(Arrays.asList( 0.0));
        Date currentdate=null ;
        try
        {
        currentdate = format.parse("27/3/2007");
        }
        catch (ParseException e)
        {
        }
        int phase = 1;

        UpdateCalendar res0 = Estimation_UpdateCalendar.CalculateUpdateCalendar(cumulTT,calendarMoments,calendarDates,calendarCumuls,currentdate,phase);
        System.out.println(" calendarMoments: "+res0.calendarMoments+" calendarDates: "+res0.calendarDates+" calendarCumuls: "+res0.calendarCumuls);
        List<Date> calendarDates_calc=null ;
        try
        {
            calendarDates_calc = Arrays.asList(format.parse("21/3/2007"),format.parse("27/3/2007"));
        }
        catch (ParseException e)
        {
        }
        System.out.println((res0.calendarDates).equals(calendarDates_calc));
        List<Double> calendarCumuls_est = new ArrayList<>();
        for (int i=0; i<res0.calendarCumuls.size(); i++){
           calendarCumuls_est .add((new BigDecimal(res0.calendarCumuls.get(i)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).doubleValue());
        }
        System.out.println(calendarCumuls_est.equals( Arrays.asList(0.0, 112.33)));
        System.out.println((res0.calendarMoments).equals(Arrays.asList("Sowing","Emergence")));
    }
}
