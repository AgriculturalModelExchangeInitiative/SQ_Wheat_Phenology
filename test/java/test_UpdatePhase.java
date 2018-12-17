//Test generation'
package pheno2;
import java.math.BigDecimal;
class test_UpdatePhase
{
    //check model1);
    //test_wheat1);

    public static void test_wheat1()
    {
        double cumulTT = 354.582294511779;
        double leafNumber =  4.620511621863958;
        double cumulTTFromZC_39 = 0;
        int isMomentRegistredZC_39 = 0;
        double GAI = 0.3255196285135;
        double GrainCumulTT = 0;
        double DayLength = 12.7433275303389;
        double Vernaprog =  1.0532526829571554;
        double MinFinalNumber = 6.879410413987549;
        double FixPhyll = 91.2;
        int IsVernalizable = 1;
        double Dse = 105;
        double PFLLAnth = 2.22;
        double Dcd = 100;
        double Dgf = 450;
        double Degfm = 0;
        double MaxDL = 15;
        double SLDL = 0.85;
        boolean IgnoreGrainMaturation = false;
        double PHEADANTH = 1;
        int SwitchMaize = 0;
        String choosePhyllUse = "Default";
        double P = 120;
        double phase = 1;
        double cumulTTFromZC_91 = 0;
        double phyllochron = 91.2;
        int hasLastPrimordiumAppeared = 0;
        double FinalLeafNumber = 0;

        UpdatePhase res0 = Estimation_UpdatePhase.CalculateUpdatePhase(cumulTT,leafNumber,cumulTTFromZC_39,isMomentRegistredZC_39,GAI,GrainCumulTT,DayLength,Vernaprog,MinFinalNumber,FixPhyll,IsVernalizable,Dse,PFLLAnth,Dcd,Dgf,Degfm,MaxDL,SLDL,IgnoreGrainMaturation,PHEADANTH,SwitchMaize,choosePhyllUse,P,phase,cumulTTFromZC_91,phyllochron,hasLastPrimordiumAppeared,FinalLeafNumber);
        System.out.println(" FinalLeafNumber: "+res0.finalLeafNumber+" phase: "+res0.phase+" hasLastPrimordiumAppeared: "+res0.hasLastPrimordiumAppeared);

        System.out.println(((new BigDecimal(res0.phase)).setScale(1, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(2)).setScale(1, BigDecimal.ROUND_HALF_DOWN)));
        System.out.println(((new BigDecimal(res0.finalLeafNumber)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(8.80)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        System.out.println(res0.hasLastPrimordiumAppeared==1);
    }
}
