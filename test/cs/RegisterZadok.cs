public class RegisterZadok
{
    public int hasZadokStageChanged;
    public string currentZadokStage;
    public List<string> calendarMoments;
    public List<DateTime> calendarDates;
    public List<double> calendarCumuls;
    public RegisterZadok(int _hasZadokStageChanged,string _currentZadokStage,List<string> _calendarMoments,List<DateTime> _calendarDates,List<double> _calendarCumuls)
    {
        hasZadokStageChanged=_hasZadokStageChanged;
        currentZadokStage=_currentZadokStage;
        calendarMoments=_calendarMoments;
        calendarDates=_calendarDates;
        calendarCumuls=_calendarCumuls;
    }
}

public static class Estimation_RegisterZadok
{
    public static RegisterZadok CalculateRegisterZadok(double cumulTT,double phase,double leafNumber,List<string> calendarMoments,List<DateTime> calendarDates,List<double> calendarCumuls,double cumulTTFromZC_65,DateTime currentdate,double Der,double slopeTSFLN,double TSFLN,double intTSFLN,double FinalLeafNumber,string currentZadokStage,int hasZadokStageChanged)
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
        if (leafNumber>=4 && calendarMoments.Contains("MainShootPlus1Tiller")==false)
        {
            calendarMoments.Add("MainShootPlus1Tiller");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MainShootPlus1Tiller";
        }
        else if (leafNumber>=5 && calendarMoments.Contains("MainShootPlus2Tiller")==false)
        {
            calendarMoments.Add("MainShootPlus2Tiller");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MainShootPlus2Tiller";
        }
        else if (leafNumber>=6 && calendarMoments.Contains("MainShootPlus3Tiller")==false)
        {
            calendarMoments.Add("MainShootPlus3Tiller");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MainShootPlus3Tiller";
        }        
        else if (FinalLeafNumber > 0 && leafNumber>=(slopeTSFLN * FinalLeafNumber - intTSFLN) &&  calendarMoments.Contains("TerminalSpikelet")==false)
        {
            calendarMoments.Add("TerminalSpikelet");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "TerminalSpikelet";
        }        
        else if ((leafNumber >= (roundedFinalLeafNumber-4) && (roundedFinalLeafNumber-4) > 0) && calendarMoments.Contains("PseudoStemErection")==false)
        {
            calendarMoments.Add("PseudoStemErection");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "PseudoStemErection";
        }
        else if ((leafNumber >= (roundedFinalLeafNumber-3) && (roundedFinalLeafNumber-3) > 0) && calendarMoments.Contains("1stNodeDetectable")==false)
        {
            calendarMoments.Add("1stNodeDetectable");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "1stNodeDetectable";
        }
        else if ((leafNumber >= (roundedFinalLeafNumber-2) && (roundedFinalLeafNumber-2) > 0) &&  calendarMoments.Contains("2ndNodeDetectable")==false)
        {
            calendarMoments.Add("2ndNodeDetectable");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "2ndNodeDetectable";
        }    
        else if ((leafNumber >= (roundedFinalLeafNumber-1) && (roundedFinalLeafNumber-1) > 0) && calendarMoments.Contains("FlagLeafJustVisible")==false)
        {
            calendarMoments.Add("FlagLeafJustVisible");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "FlagLeafJustVisible";
        }
        else if ((calendarMoments.Contains("MidGrainFilling")==false) && phase == 4.5 && cumulTTFromZC_65 >= Der)
        {
            calendarMoments.Add("MidGrainFilling");
            calendarCumuls.Add(cumulTT);
            calendarDates.Add(currentdate);
            hasZadokStageChanged = 1;
            currentZadokStage = "MidGrainFilling" ;                
        }
        else
            hasZadokStageChanged = 0;
        return new RegisterZadok(hasZadokStageChanged,currentZadokStage,calendarMoments,calendarDates,calendarCumuls);
    }
}

