
    !use crop2mlModules


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


