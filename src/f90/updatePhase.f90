
    !use crop2mlModules
        real:: phase1, appFLN, ttFromLastLeafToHeading, LocalDegfm, ttFromLastLeafToAnthesis

        phase1 = phase;
        if ((phase1 >= 0) .AND. (phase1 < 1))then
            if (SwitchMaize==0)then
                if (cumulTT>= Dse) then
                    phase = 1
                else
                    phase = phase1
                end if
            else
                if (cumulTT >= Dse) then
                    phase= 1;
                else
                    phase = phase1
                end if
            end if
        else if ((phase1 >= 1) .AND. (phase1 < 2)) then
            if ((IsVernalizable==1 .AND. Vernaprog >= 1) .OR. (IsVernalizable==0)) then

                if (SwitchMaize==0) then

                    if (DayLength > MaxDL) then

                        FinalLeafNumber = MinFinalNumber
                        hasLastPrimordiumAppeared = 1

                    else
                        appFLN = MinFinalNumber + SLDL * (MaxDL - DayLength)
                        !calculation of final leaf number from daylength at inflexion plus 2 leaves
                        if ((appFLN / 2.0) <= leafNumber) then

                            FinalLeafNumber = appFLN;
                            hasLastPrimordiumAppeared =1

                        else

                            phase = phase1
                        end if
                    end if

                else

                    hasLastPrimordiumAppeared = 1
                end if

                if (hasLastPrimordiumAppeared==1) then

                    phase = 2
                end if


            else

                phase = phase1

            end if


        else if ((phase1 >= 2) .AND. (phase1 < 4)) then

            if (isMomentRegistredZC_39==1) then

                if (phase1 < 3) then

                    ttFromLastLeafToHeading = 0.0
                    if(choosePhyllUse=="Default") then
                        ttFromLastLeafToHeading =(PFLLAnth - PHEADANTH) * FixPhyll
                    else if (choosePhyllUse == "PTQ") then
                        ttFromLastLeafToHeading = (PFLLAnth - PHEADANTH) * phyllochron;
                    else if (choosePhyllUse == "Test")  then
                        ttFromLastLeafToHeading = (PFLLAnth - PHEADANTH) * P
                    end if
                    if (cumulTTFromZC_39 >= ttFromLastLeafToHeading) then

                        phase = 3

                    else

                        phase = phase1
                    end if
                end if


                ttFromLastLeafToAnthesis =0.0;
                if (choosePhyllUse == "Default") then
                    ttFromLastLeafToAnthesis = PFLLAnth * FixPhyll
                else if (choosePhyllUse == "PTQ") then
                    ttFromLastLeafToAnthesis = PFLLAnth * phyllochron
                else if (choosePhyllUse == "Test") then
                    ttFromLastLeafToAnthesis = PFLLAnth * P
                end if
                if (cumulTTFromZC_39 >= ttFromLastLeafToAnthesis) then

                    phase = 4

                else

                    phase = phase1
                end if


            else

                phase = phase1
            end if


        else if (phase1 == 4) then

            if (GrainCumulTT >= Dcd) then

                phase = 4.5

            else

                phase = phase1
            end if


        else if (phase1 == 4.5) then

            if ((GrainCumulTT >= Dgf) .OR. (GAI <= 0)) then

                phase = 5

            else

                phase = phase1
            end if


        else if ((phase1 >= 5) .AND. (phase1 < 6)) then


            LocalDegfm = Degfm
            if (IgnoreGrainMaturation .eqv. .TRUE.) then
                LocalDegfm = -1
            end if
            if (cumulTTFromZC_91 >= LocalDegfm) then

                phase = 6

            else

                phase= phase1
            end if


        else if ((phase1>= 6) .AND. (phase1 < 7)) then
            phase = phase1
        end if


