module CumulTTfrom
    use crop2mlModules


contains
     subroutine calculateCumulFROM(cumulTT, calendarMoments, calendarCumuls, SwitchMaize,&
        cumulTTFromZC_39, cumulTTFromZC_65, cumulTTFromZC_91)

        !      INPUT VARIABLES:
        integer, intent(in):: SwitchMaize
        real, intent(in):: cumulTT
        real,dimension (:), intent(in):: calendarCumuls
        character(len=*),dimension(:), intent(in):: calendarMoments

        !     OUTPUT VARIABLES:

        real, intent(out):: cumulTTFromZC_39, cumulTTFromZC_65, cumulTTFromZC_91

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

    end subroutine


end module
