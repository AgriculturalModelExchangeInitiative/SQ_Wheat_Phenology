public class ShootNumber
{
    public double averageShootNumberPerPlant;
    public double canopyShootNumber;
    public List<int> leafTillerNumberArray;
    public List<double> tilleringProfile;
    public int tillerNumber;
    public ShootNumber(double _averageShootNumberPerPlant,double _canopyShootNumber,List<int> _leafTillerNumberArray,List<double> _tilleringProfile,int _tillerNumber)
    {
        averageShootNumberPerPlant=_averageShootNumberPerPlant;
        canopyShootNumber=_canopyShootNumber;
        leafTillerNumberArray=_leafTillerNumberArray;
        tilleringProfile=_tilleringProfile;
        tillerNumber=_tillerNumber;
    }
}

public static class Estimation_ShootNumber
{
    public static ShootNumber CalculateShootNumber(double canopyShootNumber,double leafNumber,int sowingDensity,double targetFertileShoot,List<double> tilleringProfile,List<int> leafTillerNumberArray,int tillerNumber)
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

        double oldCanopyShootNumber;
        int emergedLeaves, shoots, i;
        oldCanopyShootNumber = canopyShootNumber;
        emergedLeaves = (int)Math.Max(1, Math.Ceiling(leafNumber - 1));
        shoots = fibonacci(emergedLeaves);
        canopyShootNumber = Math.Min(Shoots * sowingDensity, targetFertileShoot);
        AverageShootNumberPerPlant = canopyShootNumber / sowingDensity;
        if (canopyShootNumber != oldCanopyShootNumber)
        {
        	tilleringProfile.Add(canopyShootNumber - oldCanopyShootNumber);
        }		
        tillerNumber = tilleringProfile.Count;		
        for (i = leafTillerNumberArray.Count; i < Math.Ceiling(leafNumber); i++)
        {
        	leafTillerNumberArray.Add(tillerNumber);
        }
        return new ShootNumber(averageShootNumberPerPlant,canopyShootNumber,leafTillerNumberArray,tilleringProfile,tillerNumber);
    }
}

