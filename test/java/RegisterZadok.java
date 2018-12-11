import package pheno;
 import java.util.List;
 import java.util.ArrayList;
 import java.math.BigDecimal;
public class RegisterZadok
{
    public int hasZadokStageChanged;
    public String currentZadokStage;
    public List<String> calendarMoments;
    public List<Date> calendarDates;
    public List<Double> calendarCumuls;
    public RegisterZadok(int _hasZadokStageChanged,String _currentZadokStage,List<String> _calendarMoments,List<Date> _calendarDates,List<Double> _calendarCumuls)
    {
        this.hasZadokStageChanged=_hasZadokStageChanged;
        this.currentZadokStage=_currentZadokStage;
        this.calendarMoments=_calendarMoments;
        this.calendarDates=_calendarDates;
        this.calendarCumuls=_calendarCumuls;
    }
}

class Estimation_RegisterZadok
{
    public static RegisterZadok CalculateRegisterZadok(double cumulTT,double phase,double leafNumber,List<String> calendarMoments,List<Date> calendarDates,List<Double> calendarCumuls,double cumulTTFromZC_65,Date currentdate,double Der,double slopeTSFLN,double TSFLN,double intTSFLN,double FinalLeafNumber,String currentZadokStage,int hasZadokStageChanged)
    {


/*
     RegisterZadok Model

    Author: 
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Instituton: INRA/LEPSE Montpellier
    Abstract: Record the zadok stage in the calendar
    	
    
*/

        int roundedFinalLeafNumber = (int)(FinalLeafNumber+0.5);
        if (leafNumber>=4 && calendarMoments.contains("MainShootPlus1Tiller")==false)
        {
            calendarMoments.add("MainShootPlus1Tiller");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MainShootPlus1Tiller";
        }
        else if (leafNumber>=5 && calendarMoments.contains("MainShootPlus2Tiller")==false)
        {
            calendarMoments.add("MainShootPlus2Tiller");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MainShootPlus2Tiller";
        }
        else if (leafNumber>=6 && calendarMoments.contains("MainShootPlus3Tiller")==false)
        {
            calendarMoments.add("MainShootPlus3Tiller");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MainShootPlus3Tiller";
        }        
        else if (FinalLeafNumber > 0 && leafNumber>=(slopeTSFLN * FinalLeafNumber - intTSFLN) &&  calendarMoments.contains("TerminalSpikelet")==false)
        {
            calendarMoments.add("TerminalSpikelet");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "TerminalSpikelet";
        }        
        else if ((leafNumber >= (roundedFinalLeafNumber-4) && (roundedFinalLeafNumber-4) > 0) && calendarMoments.contains("PseudoStemErection")==false)
        {
            calendarMoments.add("PseudoStemErection");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "PseudoStemErection";
        }
        else if ((leafNumber >= (roundedFinalLeafNumber-3) && (roundedFinalLeafNumber-3) > 0) && calendarMoments.contains("1stNodeDetectable")==false)
        {
            calendarMoments.add("1stNodeDetectable");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "1stNodeDetectable";
        }
        else if ((leafNumber >= (roundedFinalLeafNumber-2) && (roundedFinalLeafNumber-2) > 0) &&  calendarMoments.contains("2ndNodeDetectable")==false)
        {
            calendarMoments.add("2ndNodeDetectable");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "2ndNodeDetectable";
        }    
        else if ((leafNumber >= (roundedFinalLeafNumber-1) && (roundedFinalLeafNumber-1) > 0) && calendarMoments.contains("FlagLeafJustVisible")==false)
        {
            calendarMoments.add("FlagLeafJustVisible");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "FlagLeafJustVisible";
        }
        else if ((calendarMoments.contains("MidGrainFilling")==false) && phase == 4.5 && cumulTTFromZC_65 >= Der)
        {
            calendarMoments.add("MidGrainFilling");
            calendarCumuls.add(cumulTT);
            calendarDates.add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MidGrainFilling" ;                
        }
        else
            hasZadokStageChanged = 0;
        return new RegisterZadok(hasZadokStageChanged,currentZadokStage,calendarMoments,calendarDates,calendarCumuls);
    }

}
