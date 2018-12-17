//Test generation'
package pheno2;
import java.math.BigDecimal;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
class test_VernalizationProgress
{
    //check wheat model1);
    //test_wheat1);

    public static void test_wheat1()
    {
        double DayLength = 12.3037621834005;
        double DeltaTT = 20.3429985011972;
        double cumulTT =  112.330110409888;
        double leafNumber = 0;
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
        double MinTvern = 0.0;
        double IntTvern =  11.0;
        double VAI =  0.015;
        double VBEE = 0.01;
        double MinDL = 8.0;
        double MaxDL = 15.0;
        double MaxTvern =  23.0;
        double PNini = 4.0;
        double AMXLFNO = 24.0;
        double Vernaprog =  0.5517254187376879;
        int IsVernalizable = 1;
        double MinFinalNumber = 5.5;

        VernalizationProgress res0 = Estimation_VernalizationProgress.CalculateVernalizationProgress(DayLength,DeltaTT,cumulTT,leafNumber,calendarMoments,calendarDates,calendarCumuls,MinTvern,IntTvern,VAI,VBEE,MinDL,MaxDL,MaxTvern,PNini,AMXLFNO,Vernaprog,currentdate,IsVernalizable,MinFinalNumber);
        System.out.println(" Vernaprog: "+res0.vernaprog+" MinFinalNumber: "+res0.minFinalNumber+" calendarMoments: "+res0.calendarMoments+" calendarDates: "+res0.calendarDates+" calendarCumuls: "+res0.calendarCumuls);

        System.out.println(((new BigDecimal(res0.minFinalNumber)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(5.5)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        List<Date> calendarDates_calc=null ;
        try
        {
            calendarDates_calc = Arrays.asList(format.parse("21/3/2007"));
        }
        catch (ParseException e)
        {
        }
        System.out.println((res0.calendarDates).equals(calendarDates_calc));
        System.out.println(((new BigDecimal(res0.vernaprog)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(0.64)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        System.out.println((res0.calendarMoments).equals(Arrays.asList("Sowing")));
        List<Double> calendarCumuls_est = new ArrayList<>(); // value estimated
        for (int i=0; i<res0.calendarCumuls.size(); i++){
           calendarCumuls_est .add((new BigDecimal(res0.calendarCumuls.get(i)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).doubleValue());
        }
        System.out.println(calendarCumuls_est.equals( Arrays.asList(0.0)));  
     }
}
