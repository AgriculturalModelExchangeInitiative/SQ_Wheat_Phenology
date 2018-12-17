//Test generation'
package pheno2;
import java.math.BigDecimal;
class test_LeafNumber
{
    //check wheat model1);
    //test_wheat1);

    public static void test_wheat1()
    {
        double DeltaTT = 23.5895677277199;
        double phyllochron = 91.2;
        int HasFlagLeafLiguleAppeared = 0;
        int SwitchMaize = 0;
        double atip = 10;
        double Leaf_tip_emerg = 10;
        double k_bl = 1.412;
        double Nlim = 6.617;
        double leafNumber = 5.147163833893262;
        double cumulTTPhenoMaizeAtEmergence = 300;
        double cumulTT = 402.042720581446;
        double phase = 3;

        LeafNumber res0 = Estimation_LeafNumber.CalculateLeafNumber(DeltaTT,phyllochron,HasFlagLeafLiguleAppeared,SwitchMaize,atip,Leaf_tip_emerg,k_bl,Nlim,leafNumber,cumulTTPhenoMaizeAtEmergence,cumulTT,phase);
        System.out.println(" leafNumber: "+res0.leafNumber+" Ntip: "+res0.ntip);

        System.out.println(((new BigDecimal(res0.leafNumber)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(5.41)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        System.out.println(((new BigDecimal(res0.ntip)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(0)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
    }
}
