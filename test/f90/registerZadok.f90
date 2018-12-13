module registerZadokModule
    use crop2mlModules

contains
    subroutine calculateRegisterZadok(cumulTT,phase,leafNumber,calendarMoments,&
            calendarDates,calendarCumuls,cumulTTFromZC_65, currentdate,Der,&
            slopeTSFLN,TSFLN,intTSFLN, FinalLeafNumber,currentZadokStage,&
            hasZadokStageChanged)


        real , intent(in)::cumulTT,phase,leafNumber, &
            cumulTTFromZC_65,slopeTSFLN,TSFLN,intTSFLN, FinalLeafNumber ,Der
        integer, intent(inout):: hasZadokStageChanged

        real,dimension (:), intent(inout), allocatable:: calendarCumuls
        character(len=65),dimension(:), intent(inout), allocatable:: calendarMoments, calendarDates
        character(len=65), intent(in) :: currentdate
        character(len=65), intent(out):: currentZadokStage

        integer::  roundedFinalLeafNumber


        roundedFinalLeafNumber = int(FinalLeafNumber+0.5)
        if ((leafNumber>=4) .AND. (ALL(calendarMoments/="MainShootPlus1Tiller"))) then

            call AddToListchar(calendarMoments,"MainShootPlus1Tiller")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "MainShootPlus1Tiller"

        else if ((leafNumber>=5 ).AND. (ALL(calendarMoments/="MainShootPlus2Tiller"))) then

            call AddToListchar(calendarMoments,"MainShootPlus2Tiller")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "MainShootPlus2Tiller"

        else if ((leafNumber>=6) .AND. (ALL(calendarMoments/="MainShootPlus3Tiller"))) then

            call AddToListchar(calendarMoments,"MainShootPlus3Tiller")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "MainShootPlus3Tiller"

        else if ((FinalLeafNumber > 0 ).AND. (leafNumber>=(slopeTSFLN * FinalLeafNumber - intTSFLN)) .AND. &
            (ALL(calendarMoments/="TerminalSpikelet"))) then

            call AddToListchar(calendarMoments,"TerminalSpikelet")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "TerminalSpikelet"

        else if ((leafNumber >= (roundedFinalLeafNumber-4)) .AND. ((roundedFinalLeafNumber-4) > 0) .AND. &
            (ALL(calendarMoments/="PseudoStemErection"))) then

            call AddToListchar(calendarMoments,"PseudoStemErection")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "PseudoStemErection"

        else if ((leafNumber >= (roundedFinalLeafNumber-3)) .AND. ((roundedFinalLeafNumber-3) > 0) .AND. &
            (ALL(calendarMoments/="1stNodeDetectable"))) then

            call AddToListchar(calendarMoments,"1stNodeDetectable")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "1stNodeDetectable"

        else if ((leafNumber >= (roundedFinalLeafNumber-2)) .AND. ((roundedFinalLeafNumber-2) > 0) .AND.  &
            (ALL(calendarMoments/="2ndNodeDetectable"))) then

            call AddToListchar(calendarMoments,"2ndNodeDetectable")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "2ndNodeDetectable"

        else if ((leafNumber >= (roundedFinalLeafNumber-1)) .AND. ((roundedFinalLeafNumber-1) > 0) .AND. &
            (ALL(calendarMoments/="FlagLeafJustVisible"))) then

            call AddToListchar(calendarMoments,"FlagLeafJustVisible")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "FlagLeafJustVisible"

        else if ((ALL(calendarMoments/="MidGrainFilling")) .AND. (phase == 4.5) .AND. &
            (cumulTTFromZC_65 >= Der))   then

            call AddToListchar(calendarMoments,"MidGrainFilling")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListchar(calendarDates, currentdate)
            hasZadokStageChanged = 1
            currentZadokStage = "MidGrainFilling"

        else
            hasZadokStageChanged = 0


        end if



    end subroutine

end module


