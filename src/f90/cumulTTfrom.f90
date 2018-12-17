MODULE CumulTTfrom
    USE Crop2mlModules
CONTAINS

    SUBROUTINE Calculate_CumulFROM(cumulTT, calendarMoments, calendarCumuls, switchMaize,&
            cumulTTFromZC_39, cumulTTFromZC_65, cumulTTFromZC_91)
        !      INPUT VARIABLES:
        INTEGER, INTENT(IN):: switchMaize
        REAL, INTENT(IN):: cumulTT
        REAL,DIMENSION (:), INTENT(IN):: calendarCumuls
        CHARACTER(LEN=*),DIMENSION(:), INTENT(IN):: calendarMoments
        !     OUTPUT VARIABLES:
        REAL, INTENT(OUT):: cumulTTFromZC_39, cumulTTFromZC_65, cumulTTFromZC_91
        cumulTTFromZC_39=0
        cumulTTFromZC_65=0
        cumulTTFromZC_91 =0

        IF(ANY(calendarMoments=="Anthesis")) THEN
            IF (switchMaize==0) THEN
                cumulTTFromZC_65 = cumulTT - calendarCumuls(indice(calendarMoments,"Anthesis"))
            END IF
        END IF
        IF(ANY(calendarMoments=="FlagLeafLiguleJustVisible")) THEN
            IF (switchMaize==0) THEN
                cumulTTFromZC_39 = cumulTT - calendarCumuls(indice(calendarMoments,"FlagLeafLiguleJustVisible"))
            END IF
        END IF
        IF(ANY(calendarMoments=="EndGrainFilling")) THEN
            IF (switchMaize==0) THEN
                cumulTTFromZC_91 = cumulTT-calendarCumuls(indice(calendarMoments,"EndGrainFilling"))
            END IF
        END IF
    END SUBROUTINE
END MODULE
