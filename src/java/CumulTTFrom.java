package pheno2;
import java.util.List;
public class CumulTTFrom
{
    public double cumulTTFromZC_65;
    public double cumulTTFromZC_39;
    public double cumulTTFromZC_91;
    public CumulTTFrom(double _cumulTTFromZC_65,double _cumulTTFromZC_39,double _cumulTTFromZC_91)
    {
        this.cumulTTFromZC_65=_cumulTTFromZC_65;
        this.cumulTTFromZC_39=_cumulTTFromZC_39;
        this.cumulTTFromZC_91=_cumulTTFromZC_91;
    }
}

class Estimation_CumulTTFrom
{
    public static CumulTTFrom CalculateCumulTTFrom(List<String> calendarMoments,List<Double> calendarCumuls,int switchMaize,double cumulTT)
    {


/*
     CumulTTFrom Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA Montpellier
    Abstract: Calculate CumulTT 
    
*/
        double cumulTTFromZC_65;
        double cumulTTFromZC_39;
        double cumulTTFromZC_91;

        cumulTTFromZC_65 = 0.0D;
        cumulTTFromZC_39 = 0.0D;
        cumulTTFromZC_91 = 0.0D;
        if (calendarMoments.contains("Anthesis")){
            if (switchMaize == 0)
                cumulTTFromZC_65 = cumulTT-calendarCumuls.get(calendarMoments.indexOf("Anthesis"));
        }    
        if (calendarMoments.contains("FlagLeafLiguleJustVisible")){
            if (switchMaize == 0)
                cumulTTFromZC_39 = cumulTT-calendarCumuls.get(calendarMoments.indexOf("FlagLeafLiguleJustVisible"));
        }   
        if (calendarMoments.contains("EndGrainFilling")){
            if (switchMaize == 0)
                cumulTTFromZC_91 = cumulTT-calendarCumuls.get(calendarMoments.indexOf("FlagLeafLiguleJustVisible"));
        }
        return new CumulTTFrom(cumulTTFromZC_65,cumulTTFromZC_39,cumulTTFromZC_91);
    }

}
