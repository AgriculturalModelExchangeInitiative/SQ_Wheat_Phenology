module vernalizationProgressModule
    use crop2mlModules
    implicit none

contains
    subroutine calculateVernalizationProgress( DayLength, DeltaTT, cumulTT, &
            leafNumber,calendarMoments, calendarDates, calendarCumuls, &
            MinTvern, IntTvern, VAI, VBEE, MinDL, MaxDL, MaxTvern, PNini, AMXLFNO, Vernaprog,&
            currentdate, IsVernalizable, MinFinalNumber)

        ! DECLARATION
        real, intent(in)::DayLength, DeltaTT, cumulTT,leafNumber,MinTvern, IntTvern, VAI,&
            VBEE, MinDL, MaxDL, MaxTvern, PNini, AMXLFNO

        character(len=25), intent(in) :: currentdate
        integer, intent(in)::  IsVernalizable

        real,dimension (:), intent(inout), allocatable:: calendarCumuls
        character(len=25),dimension(:), intent(inout), allocatable:: calendarMoments, calendarDates

        real, intent(inout):: Vernaprog, MinFinalNumber

        real:: TT, maxVernaProg, DLverna, primordno, minLeafNumber, potlfno

        ! Fortran Snippets
        if ((IsVernalizable==1) .AND. (Vernaprog < 1)) then
            TT = DeltaTT
            if ((TT >= MinTvern) .AND. (TT <= IntTvern)) then

                Vernaprog = Vernaprog + VAI * TT + VBEE
            end if

            if (TT > IntTvern) then

                maxVernaProg = VAI * IntTvern + VBEE
                DLverna = max(MinDL, min(MaxDL, DayLength))
                Vernaprog =Vernaprog + max(0, int(maxVernaProg * (1 + ((IntTvern - TT) / (MaxTvern - IntTvern))&
                    * ((DLverna - MinDL) / (MaxDL - MinDL)))))
            end if
            primordno = 2.0 * leafNumber + PNini
            minLeafNumber = MinFinalNumber
            if ((Vernaprog >= 1.0) .OR. (primordno >= AMXLFNO)) then

                MinFinalNumber = max(primordno, MinFinalNumber)
                call AddToListChar(calendarMoments, "EndVernalisation")
                call AddToList(calendarCumuls, cumulTT)
                call AddToListChar(calendarDates, currentdate)

            else

                potlfno = AMXLFNO - (AMXLFNO - minLeafNumber) * Vernaprog
                if (primordno >= potlfno) then

                    MinFinalNumber = max((potlfno + primordno) / 2.0, MinFinalNumber)
                    call AddToListChar(calendarMoments,"EndVernalisation")
                    call AddToList(calendarCumuls,cumulTT)
                    call AddToListChar(calendarDates,currentdate)
                    Vernaprog = max(1, int(Vernaprog))
                end if
            end if
        end if
    end subroutine
end module




