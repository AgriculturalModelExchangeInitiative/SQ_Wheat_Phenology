//Test generation'
package pheno2;  
import java.math.BigDecimal;
class test_Phyllochron
{
    //check wheat model);
    //test_wheat1);

    @SuppressWarnings("empty-statement")
    public static void test_wheat1()
    {
        double fixPhyll = 91.2;
        double leafNumber = 0;
        double lincr = 8;
        double ldecr = 3;
        double pdecr = 0.4;
        double pincr = 1.25;
        double lai = 0;
        double ptq = 0;
        double gai = 0.279874189539498;
        double pastMaxAI = 0;
        double kl = 0.45;
        double aPTQ = 0.842934;
        double phylPTQ1 = 20;
        double p = 120;
        String choosePhyllUse = "Default";

        Phyllochron res0 = Estimation_Phyllochron.CalculatePhyllochron(fixPhyll,leafNumber,lincr,ldecr,pdecr, pincr, ptq,gai, pastMaxAI, kl,aPTQ, phylPTQ1, p,choosePhyllUse);
        System.out.println(" phyllochron: "+res0.phyllochron+" pastMaxAI: "+res0.pastMaxAI);

        System.out.println(((new BigDecimal(res0.pastMaxAI)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(0)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        System.out.println(((new BigDecimal(res0.phyllochron)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(36.48)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
    }
}
