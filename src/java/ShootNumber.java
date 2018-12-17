package pheno2;
import java.util.List;
public class ShootNumber
{
    public double averageShootNumberPerPlant;
    public double canopyShootNumber;
    public List<Integer> leafTillerNumberArray;
    public List<Double> tilleringProfile;
    public int tillerNumber;
    public ShootNumber(double _averageShootNumberPerPlant,double _canopyShootNumber,List<Integer> _leafTillerNumberArray,List<Double> _tilleringProfile,int _tillerNumber)
    {
        this.averageShootNumberPerPlant=_averageShootNumberPerPlant;
        this.canopyShootNumber=_canopyShootNumber;
        this.leafTillerNumberArray=_leafTillerNumberArray;
        this.tilleringProfile=_tilleringProfile;
        this.tillerNumber=_tillerNumber;
    }
}

class Estimation_ShootNumber
{
    public static ShootNumber CalculateShootNumber(double canopyShootNumber,double leafNumber,int sowingDensity,double targetFertileShoot,List<Double> tilleringProfile,List<Integer> leafTillerNumberArray,int tillerNumber)
    {


/*
     CalculateShootNumber Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA/LEPSE Montpellier
    Abstract: calculate the shoot number and update the related variables if needed
    
*/
        double averageShootNumberPerPlant;

        int emergedLeaves, shoots;
        double oldCanopyShootNumber;
        oldCanopyShootNumber = canopyShootNumber;
        emergedLeaves = (int)Math.max(1, Math.ceil(leafNumber - 1));
        shoots = Estimation_fibonacci.Calculatefibonacci(emergedLeaves).value;
        canopyShootNumber = Math.min(shoots * sowingDensity, targetFertileShoot);
        averageShootNumberPerPlant = canopyShootNumber / sowingDensity;
        if (canopyShootNumber != oldCanopyShootNumber)
        {
        	tilleringProfile.add(canopyShootNumber - oldCanopyShootNumber);
        }		
        tillerNumber = tilleringProfile.size();		
        for (int i = leafTillerNumberArray.size(); i < Math.ceil(leafNumber); i++)
        {
        	leafTillerNumberArray.add(tillerNumber);
        }
        return new ShootNumber(averageShootNumberPerPlant,canopyShootNumber,leafTillerNumberArray,tilleringProfile,tillerNumber);
    }

}
