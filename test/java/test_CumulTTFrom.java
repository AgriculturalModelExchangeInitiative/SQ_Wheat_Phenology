//Test generation'
package pheno2;
import java.math.BigDecimal;
import java.util.List; 
import java.util.*;
class test_CumulTTfrom
{
    //check wheat model);
    //test_wheat1);

    public static void test_wheat1()
    {
    //check wheat model  test_wheat1);
        List<String>calendarMoments= Arrays.asList("Sowing", "Emergence", "FloralInitiation", "FlagLeafLiguleJustVisible", "Heading", "Anthesis");
        List<Double> calendarCumuls = Arrays.asList(0.0, 112.330110409888, 354.582294511779, 741.510096671757, 853.999637026622, 954.59002776961);
        int switchMaize = 0;
        double cumulTT = 972.970888983105;

        CumulTTFrom res0 = Estimation_CumulTTFrom.CalculateCumulTTFrom(calendarMoments,calendarCumuls,switchMaize,cumulTT);
        System.out.println(" cumulTTFromZC_65: "+res0.cumulTTFromZC_65+" cumulTTFromZC_39: "+res0.cumulTTFromZC_39+" cumulTTFromZC_91: "+res0.cumulTTFromZC_91);

        System.out.println(((new BigDecimal(res0.cumulTTFromZC_91)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(0)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        System.out.println(((new BigDecimal(res0.cumulTTFromZC_65)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(18.38)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        System.out.println(((new BigDecimal(res0.cumulTTFromZC_39)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(231.46)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
    }
}
