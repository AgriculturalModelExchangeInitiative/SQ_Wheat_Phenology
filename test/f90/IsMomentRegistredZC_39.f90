MODULE IsMomentRegistredZC_39Module
    USE Crop2mlModules
    IMPLICIT NONE
CONTAINS
     SUBROUTINE Calculate_IsMomentRegistredZC_39(calendarMoments, isMomentRegistredZC_39)
        !      INPUT VARIABLES:
        CHARACTER(LEN=*),DIMENSION(:), INTENT(IN):: calendarMoments
        !     OUTPUT VARIABLES:
        INTEGER , INTENT(OUT):: isMomentRegistredZC_39

        IF (ANY(calendarMoments=="FlagLeafLiguleJustVisible")) THEN
           isMomentRegistredZC_39 = 1
        ELSE
            isMomentRegistredZC_39 = 0
        ENDIF
    END SUBROUTINE Calculate_IsMomentRegistredZC_39
END MODULE IsMomentRegistredZC_39Module
