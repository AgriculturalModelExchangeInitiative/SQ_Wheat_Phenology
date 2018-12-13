module updateLeafFlagModule
    use crop2mlModules
    implicit none

contains
    subroutine calculateUpdateLeafFlag( cumulTT, leafNumber,&
        calendarMoments, calendarDates, calendarCumuls,currentdate,&
        FinalLeafNumber, HasFlagLeafLiguleAppeared, phase)

        ! DECLARATION
        real, intent(in)::phase, cumulTT, leafNumber, FinalLeafNumber
        character(len=65), intent(in) :: currentdate

        real,dimension (:), intent(inout), allocatable:: calendarCumuls
        character(len=65),dimension(:), intent(inout), allocatable:: calendarMoments, calendarDates

        integer, intent(inout):: HasFlagLeafLiguleAppeared


        !Fortran Snippets
        if ((phase >= 1) .AND. (phase< 4)) then

            if (leafNumber > 0) then

                if ((HasFlagLeafLiguleAppeared == 0) .AND. (FinalLeafNumber > 0) .AND. (leafNumber >= FinalLeafNumber)) then

                    HasFlagLeafLiguleAppeared = 1;
                    if  (ALL(calendarMoments/="FlagLeafLiguleJustVisible")) then

                        call AddToListChar(calendarMoments,"FlagLeafLiguleJustVisible")
                        call AddToList(calendarCumuls,cumulTT)
                        call AddToListChar(calendarDates, currentdate)
                    end if
                end if

            else
                HasFlagLeafLiguleAppeared = 0
            end if
        end if


    end subroutine
end module

