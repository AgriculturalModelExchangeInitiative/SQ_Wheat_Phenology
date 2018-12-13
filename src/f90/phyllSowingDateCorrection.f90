
    !use crop2mlModules

    if (Latitude < 0) then
        if (SowingDay > SDsa_sh) then
            FixPhyll = P * (1 - Rp * min(SowingDay - SDsa_sh, SDws))
        else
            FixPhyll = P
        end if
    else
        if (SowingDay < SDsa_nh) then
            FixPhyll = P * (1 - Rp * min(SowingDay, SDws))
        else
            FixPhyll = P
        end if
    end if



