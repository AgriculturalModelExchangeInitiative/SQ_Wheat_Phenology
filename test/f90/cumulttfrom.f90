
program phenology

    integer::SwitchMaize=0
    real,dimension (2)::calendarCumuls=(20)
    character(len=100),dimension(2):: calendarMoments = ("Anthesis")
    real:: cumulTTFromZC_65, cumulTTFromZC_39, cumulTTFromZC_91

    call CumulFROM(calendarMoments, calendarCumuls, SwitchMaize,cumulTTFromZC_65, cumulTTFromZC_39, cumulTTFromZC_91)

contains

    SUBROUTINE CumulFROM( calendarMoments, calendarCumuls, SwitchMaize,cumulTTFromZC_65, cumulTTFromZC_39, cumulTTFromZC_91) ! iutput


    !     INPUT VARIABLES:
    INTEGER SwitchMaize
    real,dimension (:):: calendarCumuls
    character,dimension(:):: calendarMoments
    integer indice

    !     OUTPUT VARIABLES:

    real:: cumulTTFromZC_65
    real:: cumulTTFromZC_39
    real:: cumulTTFromZC_91


    IF(ANY(calendarMoments=="Anthesis")) THEN
        IF (SwitchMaize==0) THEN
            indice = int(FINDLOC(calendarMoments,"Anthesis",1))
            cumulTTFromZC_65 = calendarCumuls(int(FINDLOC(calendarMoments,"Anthesis",1)))
            print *, cumulTTFromZC_65
        END IF
    END IF

    IF(ANY(calendarMoments=="FlagLeafLiguleJustVisible")) THEN
        IF (SwitchMaize==0) THEN
            cumulTTFromZC_39 = calendarCumuls(int(FINDLOC(calendarMoments,"FlagLeafLiguleJustVisible",1)))
            print *, cumulTTFromZC_39
        END IF
    END IF

    IF(ANY(calendarMoments=="FlagLeafLiguleJustVisible")) THEN
        IF (SwitchMaize==0) THEN
            cumulTTFromZC_91 = calendarCumuls(int(FINDLOC(calendarMoments,"FlagLeafLiguleJustVisible",1)))
            print *, umulTTFromZC_91
        END IF
    END IF
    RETURN
    end subroutine CumulFROM

end program


