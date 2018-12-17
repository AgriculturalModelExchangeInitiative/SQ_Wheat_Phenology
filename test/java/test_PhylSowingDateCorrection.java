//Test generation'
package pheno2;
import java.math.BigDecimal;
import java.util.*;
class test_PhylSowingDateCorrection
{
    //check wheat model1);
    //test_wheat1);

    public static void test_wheat1()
    {
        int SowingDay = 80;
        double Latitude = 33.069;
        int SDsa_sh = 151;
        double Rp = 0.003;
        int SDws = 90;
        int SDsa_nh = 200;
        double P = 120;

        PhylSowingDateCorrection res0 = Estimation_PhylSowingDateCorrection.CalculatePhylSowingDateCorrection(SowingDay,Latitude,SDsa_sh,Rp,SDws,SDsa_nh,P);
        System.out.println(" FixPhyll: "+res0.fixPhyll);
        System.out.println(((new BigDecimal(res0.fixPhyll)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(91.2)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
    }
}
