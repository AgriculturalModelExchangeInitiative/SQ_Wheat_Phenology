import package pheno;
 import java.util.List;
 import java.util.ArrayList;
 import java.math.BigDecimal;
public class ShootNumber
{
    public double AverageShootNumberPerPlant;
    public double CanopyShootNumber;
    public List<Integer> leafTillerNumberArray;
    public List<Double> tilleringProfile;
    public int TillerNumber;
    public ShootNumber(double _AverageShootNumberPerPlant,double _CanopyShootNumber,List<Integer> _leafTillerNumberArray,List<Double> _tilleringProfile,int _TillerNumber)
    {
        this.AverageShootNumberPerPlant=_AverageShootNumberPerPlant;
        this.CanopyShootNumber=_CanopyShootNumber;
        this.leafTillerNumberArray=_leafTillerNumberArray;
        this.tilleringProfile=_tilleringProfile;
        this.TillerNumber=_TillerNumber;
    }
}

class Estimation_ShootNumber
{
    public static ShootNumber CalculateShootNumber(double CanopyShootNumber,double leafNumber,int SowingDensity,double TargetFertileShoot,List<Double> tilleringProfile,List<Integer> leafTillerNumberArray,int TillerNumber)
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
        int EmergedLeaves = (int)Math.max(1, Math.ceil(leafNumber - 1));
        int Shoots = fibonacci(EmergedLeaves);
        CanopyShootNumber = Math.min(Shoots * SowingDensity, TargetFertileShoot);
        AverageShootNumberPerPlant = CanopyShootNumber / SowingDensity;
        if (CanopyShootNumber != OldCanopyShootNumber)
        {
        	tilleringProfile.add(CanopyShootNumber - OldCanopyShootNumber);
        }
        TillerNumber = tilleringProfile.size();
        for (int i = leafTillerNumberArray.size(); i < Math.ceil(leafNumber); i++)
        {
        	leafTillerNumberArray.add(TillerNumber);
        }
        return new ShootNumber(AverageShootNumberPerPlant,CanopyShootNumber,leafTillerNumberArray,tilleringProfile,TillerNumber);
    }

}
