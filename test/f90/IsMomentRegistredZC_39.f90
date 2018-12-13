module IsMomentRegistredZC_39Module
    use crop2mlModules
    implicit none


contains
     subroutine CalculateIsMomentRegistredZC_39(calendarMoments, isMomentRegistredZC_39)

        !      INPUT VARIABLES:

        character(len=*),dimension(:), intent(in):: calendarMoments

        !     OUTPUT VARIABLES:

        integer , intent(out):: isMomentRegistredZC_39


        if (ANY(calendarMoments=="FlagLeafLiguleJustVisible"))then

           isMomentRegistredZC_39 = 1

        else
            isMomentRegistredZC_39 = 0
        endif

    end subroutine CalculateIsMomentRegistredZC_39

end module
