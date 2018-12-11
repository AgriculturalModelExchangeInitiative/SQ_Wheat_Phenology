using fibonacci;
public class ShootNumber
{
    public double AverageShootNumberPerPlant;
    public double CanopyShootNumber;
    public List<int> leafTillerNumberArray;
    public List<double> tilleringProfile;
    public int TillerNumber;
    public ShootNumber(double _AverageShootNumberPerPlant,double _CanopyShootNumber,List<int> _leafTillerNumberArray,List<double> _tilleringProfile,int _TillerNumber)
    {
        AverageShootNumberPerPlant=_AverageShootNumberPerPlant;
        CanopyShootNumber=_CanopyShootNumber;
        leafTillerNumberArray=_leafTillerNumberArray;
        tilleringProfile=_tilleringProfile;
        TillerNumber=_TillerNumber;
    }
}

public static class Estimation_ShootNumber
{
    public static ShootNumber CalculateShootNumber(double CanopyShootNumber,double leafNumber,int SowingDensity,double TargetFertileShoot,List<double> tilleringProfile,List<int> leafTillerNumberArray,int TillerNumber)
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
        double AverageShootNumberPerPlant;

        double OldCanopyShootNumber = CanopyShootNumber;
        int EmergedLeaves = (int)Math.Max(1, Math.Ceiling(leafNumber - 1));
        int Shoots = Calculatefibonacci(EmergedLeaves).value;
        CanopyShootNumber = Math.Min(Shoots * SowingDensity, TargetFertileShoot);
        AverageShootNumberPerPlant = CanopyShootNumber / SowingDensity;
        if (CanopyShootNumber != OldCanopyShootNumber)
        {
        	tilleringProfile.Add(CanopyShootNumber - OldCanopyShootNumber);
        }
        TillerNumber = tilleringProfile.Count;
        for (int i = leafTillerNumberArray.Count; i < Math.Ceiling(leafNumber); i++)
        {
        	leafTillerNumberArray.Add(TillerNumber);
        }
        return new ShootNumber(AverageShootNumberPerPlant,CanopyShootNumber,leafTillerNumberArray,tilleringProfile,TillerNumber);
    }
}

