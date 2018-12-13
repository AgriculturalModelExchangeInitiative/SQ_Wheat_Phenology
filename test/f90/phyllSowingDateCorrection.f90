module phyllSowingDateCorrectionModule
    use crop2mlModules

contains
    subroutine calculatePhyllSowingDateCorrection(SowingDay,Latitude,SDsa_sh,Rp,SDws,SDsa_nh,P, FixPhyll)


    real , intent(in)::Latitude,Rp,P
    integer, intent(in):: SowingDay,SDws,SDsa_nh,SDsa_sh
    real, intent(out):: FixPhyll

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

    end subroutine

end module

