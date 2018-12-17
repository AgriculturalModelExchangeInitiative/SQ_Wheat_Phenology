//Test generation'
package pheno2;
import java.math.BigDecimal;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
class test_UpdateLeafFlag
{
    //check wheat model1);
    //test_wheat1);

    public static void test_wheat1()
    {
        double cumulTT = 741.510096671757;
        double leafNumber = 8.919453833361189;
        List<String> calendarMoments = new ArrayList<>();
        calendarMoments.addAll(Arrays.asList("Sowing", "Emergence", "EndVernalisation", "MainShootPlus1Tiller", "FloralInitiation", "MainShootPlus2Tiller", "TerminalSpikelet", "PseudoStemErection", "MainShootPlus3Tiller", "1stNodeDetectable", "2ndNodeDetectable", "FlagLeafJustVisible"));
        SimpleDateFormat format=new SimpleDateFormat("dd/MM/yyyy");
        List<Date> calendarDates=new ArrayList<>() ;
        try
        {
            calendarDates.addAll(Arrays.asList(format.parse("21/3/2007"),format.parse("27/3/2007"),format.parse("30/3/2007"),format.parse("5/4/2007"),format.parse("9/4/2007"), format.parse("10/4/2007"), format.parse("11/4/2007"), format.parse("12/4/2007"), format.parse("14/4/2007"), format.parse("15/4/2007"), format.parse("19/4/2007"), format.parse("24/4/2007")));
        }
        catch (ParseException e)
        {
        }
        List<Double> calendarCumuls = new ArrayList<>();
        calendarCumuls.addAll(Arrays.asList(0.0, 112.330110409888, 157.969706915664, 280.570678654207, 354.582294511779, 378.453152853726, 402.042720581446, 424.98704708663, 467.23305195298, 487.544313430698, 560.665248444002, 646.389617338974));
                Date currentdate=null ;
        try
        {
        currentdate = format.parse("29/4/2007");
        }
        catch (ParseException e)
        {
        }
        double finalLeafNumber = 8.797582013199484;
        int hasFlagLeafLiguleAppeared = 0;
        double phase = 3;

        UpdateLeafFlag res0 = Estimation_UpdateLeafFlag.CalculateUpdateLeafFlag(cumulTT,leafNumber,calendarMoments,calendarDates,calendarCumuls,currentdate,finalLeafNumber,hasFlagLeafLiguleAppeared,phase);
        System.out.println(" HasFlagLeafLiguleAppeared: "+res0.hasFlagLeafLiguleAppeared+" calendarMoments: "+res0.calendarMoments+" calendarDates: "+res0.calendarDates+" calendarCumuls: "+res0.calendarCumuls);

        List<Date> calendarDates_calc=null ;
        try
        {
            calendarDates_calc = Arrays.asList(format.parse("21/3/2007"),format.parse("27/3/2007"),format.parse("30/3/2007"),format.parse("5/4/2007"),format.parse("9/4/2007"), format.parse("10/4/2007"), format.parse("11/4/2007"), format.parse("12/4/2007"), format.parse("14/4/2007"), format.parse("15/4/2007"), format.parse("19/4/2007"), format.parse("24/4/2007"), format.parse("29/4/2007"));
        }
        catch (ParseException e)
        {
        }        
        System.out.println((res0.calendarDates).equals(calendarDates_calc));

        List<Double> calendarCumuls_est = new ArrayList<>();
        for (int i=0; i<res0.calendarCumuls.size(); i++){
           calendarCumuls_est .add((new BigDecimal(res0.calendarCumuls.get(i)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).doubleValue());
        }
        System.out.println(calendarCumuls_est.equals( Arrays.asList(0.0, 112.33, 157.97, 280.57, 354.58, 378.45, 402.04, 424.99, 467.23, 487.54, 560.67, 646.39, 741.51)));
        System.out.println((res0.calendarMoments).equals(Arrays.asList("Sowing", "Emergence", "EndVernalisation", "MainShootPlus1Tiller", "FloralInitiation", "MainShootPlus2Tiller", "TerminalSpikelet", "PseudoStemErection", "MainShootPlus3Tiller", "1stNodeDetectable", "2ndNodeDetectable", "FlagLeafJustVisible", "FlagLeafLiguleJustVisible")));
        System.out.println(res0.hasFlagLeafLiguleAppeared==1);
    }
}
