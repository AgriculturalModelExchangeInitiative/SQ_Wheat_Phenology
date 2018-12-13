module updateCalendarModule
    use crop2mlModules
    implicit none

contains
    subroutine calculateUpdateCalendar( cumulTT,&
        calendarMoments, calendarDates,&
         calendarCumuls,currentdate, phase)

        ! DECLARATION
        real, intent(in)::phase, cumulTT
        character(len=65), intent(in) :: currentdate

        real,dimension (:), intent(inout), allocatable:: calendarCumuls
        character(len=65),dimension(:), intent(inout), allocatable:: calendarMoments, calendarDates


        ! FORTRAN SNIPPETS
        if ((phase >= 1) .AND. (phase < 2) .AND. (ALL(calendarMoments/="Emergence")))then

            call AddToListChar(calendarMoments,"Emergence")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListChar(calendarDates,currentdate)

        else if ((phase >= 2 .AND. phase < 3)  .AND. ( ALL(calendarMoments/="FloralInitiation")  ))then

            call AddToListChar(calendarMoments,"FloralInitiation")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListChar(calendarDates,currentdate)

        else if ((phase >= 3 .AND. phase < 4)  .AND. (ALL(calendarMoments/="Heading")  ))then

            call AddToListChar(calendarMoments,"Heading")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListChar(calendarDates,currentdate)

        else if ((phase == 4)  .AND. (ALL(calendarMoments/="Anthesis" )  ))then

            call AddToListChar(calendarMoments,"Anthesis")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListChar(calendarDates,currentdate)

        else if ((phase == 4.5)  .AND. (ALL(calendarMoments/="EndCellDivision" )  ))then

            call AddToListChar(calendarMoments,"EndCellDivision")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListChar(calendarDates,currentdate)

        else if ((phase >= 5 .AND. phase < 6) .AND. (ALL( calendarMoments/="EndGrainFilling")  ))then

            call AddToListChar(calendarMoments,"EndGrainFilling")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListChar(calendarDates,currentdate)

        else if ((phase >= 6 .AND. phase < 7)  .AND. (ALL(calendarMoments/="Maturity" ) ))then

            call AddToListChar(calendarMoments,"Maturity")
            call AddToList(calendarCumuls,cumulTT)
            call AddToListChar(calendarDates,currentdate)
        end if
    end subroutine
end module
