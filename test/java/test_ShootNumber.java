//Test generation'
package pheno2;
import java.util.*;
import java.math.BigDecimal;
class test_ShootNumber
{
    //check wheat model1);
    //test_wheat1);

    public static void test_wheat1()
    {
        double canopyShootNumber = 288.0;
        double leafNumber = 3.34348137255;
        int SowingDensity = 288;
        double targetFertileShoot = 600.0;
        List<Double> tilleringProfile = new ArrayList<>();
        tilleringProfile.addAll(Arrays.asList(288.0));
        List<Integer> leafTillerNumberArray =new ArrayList<>();
        leafTillerNumberArray.addAll(Arrays.asList(1, 1, 1));
        int tillerNumber = 1;

        ShootNumber res0 = Estimation_ShootNumber.CalculateShootNumber(canopyShootNumber,leafNumber,SowingDensity,targetFertileShoot,tilleringProfile,leafTillerNumberArray,tillerNumber);
        System.out.println(res0.tillerNumber+" AverageShootNumberPerPlant: "+res0.averageShootNumberPerPlant+" CanopyShootNumber: "+res0.canopyShootNumber+" leafTillerNumberArray: "+res0.leafTillerNumberArray+" tilleringProfile: "+res0.tilleringProfile+" TillerNumber: ");

        System.out.println((res0.leafTillerNumberArray).equals(Arrays.asList(1, 1, 1, 2)));
        System.out.println((tillerNumber==2));
        System.out.println(((new BigDecimal(res0.averageShootNumberPerPlant)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(2)).setScale(2, BigDecimal.ROUND_HALF_DOWN)));
        
        List<Double> tilleringProfile_est = new ArrayList<>();
        for (int i=0; i<res0.tilleringProfile.size(); i++){
           tilleringProfile_est.add((new BigDecimal(res0.tilleringProfile.get(i)).setScale(2, BigDecimal.ROUND_HALF_DOWN)).doubleValue());
        }
        System.out.println(tilleringProfile_est.equals( Arrays.asList(288.0, 288.0)));
        System.out.println(((new BigDecimal(res0.canopyShootNumber)).setScale(1, BigDecimal.ROUND_HALF_DOWN)).equals((new BigDecimal(576)).setScale(1, BigDecimal.ROUND_HALF_DOWN)));
    }
}
