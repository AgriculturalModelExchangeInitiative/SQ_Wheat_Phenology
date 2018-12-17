//Test generation'
package pheno2;
import java.text.ParseException;
import java.util.Arrays;
import java.util.*;
import java.util.List;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.text.SimpleDateFormat;
class test_RegisterZadok
{
    //check wheat model1);
    //test_wheat1);
    public static void test_wheat1()
    {
        double cumulTT = 354.582294511779;
        double phase = 2;
        double leafNumber = 4.8854219661087575;
        List<String> calendarMoments = new ArrayList<>();
        calendarMoments.addAll(Arrays.asList("Sowing","Emergence","EndVernalisation","MainShootPlus1Tiller"));
        SimpleDateFormat format=new SimpleDateFormat("dd/MM/yyyy");
        List<Date> calendarDates=new ArrayList<>() ;
        try
        {
            calendarDates.addAll(Arrays.asList(format.parse("21/3/2007"),format.parse("27/3/2007"),format.parse("30/3/2007"),format.parse("5/4/2007")));
        }
        catch (ParseException e)
        {
        }
        List<Double> calendarCumuls = new ArrayList<>();
        calendarCumuls.addAll(Arrays.asList( 0.0, 112.330110409888,157.969706915664, 280.570678654207));
        double cumulTTFromZC_65 = 0;
        Date currentdate=null ;
        try
        {
        currentdate = format.parse("9/4/2007");
        }
        catch (ParseException e)
        {
        }
        double Der = 300.0;
        double slopeTSFLN = 0.9;
        double intTSFLN = 2.6;
        double FinalLeafNumber = 8.797582013199484;
        String currentZadokStage = "MainShootPlus1Tiller";
        int hasZadokStageChanged = 0;

        RegisterZadok res0 = Estimation_RegisterZadok.CalculateRegisterZadok(cumulTT,phase,leafNumber,calendarMoments,calendarDates,calendarCumuls,cumulTTFromZC_65,currentdate,Der,slopeTSFLN,intTSFLN,FinalLeafNumber,currentZadokStage,hasZadokStageChanged);
        System.out.println(" hasZadokStageChanged: "+res0.hasZadokStageChanged+" currentZadokStage: "+res0.currentZadokStage+" calendarMoments: "+res0.calendarMoments+" calendarDates: "+res0.calendarDates+" calendarCumuls: "+res0.calendarCumuls);

        System.out.println(res0.hasZadokStageChanged==0);
        
        List<Date> calendarDates_calc=null ;
        try
        {
            calendarDates_calc = Arrays.asList(format.parse("21/3/2007"),format.parse("27/3/2007"),format.parse("30/3/2007"),format.parse("5/4/2007"));
        }
        catch (ParseException e)
        {
        }        
        System.out.println((res0.calendarDates).equals(calendarDates_calc));
        List<Double> calendarCumuls_est = new ArrayList<>();
        for (int i=0; i<res0.calendarCumuls.size(); i++){
           calendarCumuls_est .add((new BigDecimal(res0.calendarCumuls.get(i)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).doubleValue());
        }
        System.out.println(calendarCumuls_est.equals( Arrays.asList(0.0, 112.33,157.97, 280.57)));
        System.out.println((res0.calendarMoments).equals(Arrays.asList("Sowing","Emergence","EndVernalisation","MainShootPlus1Tiller")));
        System.out.println((res0.currentZadokStage).equals("MainShootPlus1Tiller"));
    }
}
