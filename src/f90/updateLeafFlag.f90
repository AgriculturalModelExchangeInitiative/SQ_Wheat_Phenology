MODULE updateLeafFlagModule
    USE crop2mlModules
    IMPLICIT NONE
CONTAINS

    SUBROUTINE Calculate_UpdateLeafFlag( cumulTT, leafNumber,&
        calendarMoments, calendarDates, calendarCumuls,currentdate,&
        finalLeafNumber, hasFlagLeafLiguleAppeared, phase)

        ! DECLARATION
        REAL, INTENT(IN)::phase, cumulTT, leafNumber, finalLeafNumber
        CHARACTER(LEN=65), INTENT(IN) :: currentdate
        REAL,DIMENSION (:), INTENT(INOUT), ALLOCATABLE:: calendarCumuls
        CHARACTER(LEN=65),DIMENSION(:), INTENT(INOUT), ALLOCATABLE:: calendarMoments, calendarDates
        INTEGER, INTENT(INOUT):: hasFlagLeafLiguleAppeared

        !Fortran Snippets
        IF ((phase >= 1) .AND. (phase< 4)) THEN
            IF (leafNumber > 0) THEN
                IF ((hasFlagLeafLiguleAppeared == 0) .AND. (finalLeafNumber > 0) .AND. (leafNumber >= finalLeafNumber)) THEN
                    hasFlagLeafLiguleAppeared = 1;
                    IF  (ALL(calendarMoments/="FlagLeafLiguleJustVisible")) THEN
                        CALL AddToListChar(calendarMoments,"FlagLeafLiguleJustVisible")
                        CALL AddToList(calendarCumuls,cumulTT)
                        CALL AddToListChar(calendarDates, currentdate)
                    END IF
                END IF
            ELSE
                hasFlagLeafLiguleAppeared = 0
            END IF
        END IF
    END SUBROUTINE
END MODULE

