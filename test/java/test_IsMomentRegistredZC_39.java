//Test generation'
package pheno2;
import java.util.*;
import java.math.BigDecimal;
import java.util.Arrays;
class test_IsMomentRegistredZC_39
{
    //check wheat model);
    //test_wheat1);

    public static void test_wheat1()
    {
        List<String> calendarMoments = Arrays.asList("Sowing", "Emergence", "FloralInitiation", "FlagLeafLiguleJustVisible", "Heading", "Anthesis");
        IsMomentRegistredZC_39 res0 = Estimation_IsMomentRegistredZC_39.CalculateIsMomentRegistredZC_39(calendarMoments);
        System.out.println(" isMomentRegistredZC_39: "+res0.isMomentRegistredZC_39);
        System.out.println((new BigDecimal(res0.isMomentRegistredZC_39)).equals(new BigDecimal(1)));
    }
}
