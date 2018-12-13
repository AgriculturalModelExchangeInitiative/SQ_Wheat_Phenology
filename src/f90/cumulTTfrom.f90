
    !use crop2mlModules


        cumulTTFromZC_39=0
        cumulTTFromZC_65=0
        cumulTTFromZC_91 =0

        IF(ANY(calendarMoments=="Anthesis")) THEN
            IF (SwitchMaize==0) THEN
                cumulTTFromZC_65 = cumulTT - calendarCumuls(indice(calendarMoments,"Anthesis"))

            END IF
        END IF

        IF(ANY(calendarMoments=="FlagLeafLiguleJustVisible")) THEN
            IF (SwitchMaize==0) THEN
                cumulTTFromZC_39 = cumulTT - calendarCumuls(indice(calendarMoments,"FlagLeafLiguleJustVisible"))

            END IF
        END IF

        IF(ANY(calendarMoments=="EndGrainFilling")) THEN
            IF (SwitchMaize==0) THEN
                cumulTTFromZC_91 = cumulTT-calendarCumuls(indice(calendarMoments,"EndGrainFilling"))

            END IF
        END IF

