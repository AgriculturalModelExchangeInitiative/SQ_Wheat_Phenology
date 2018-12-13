module leafNumberModule
    use crop2mlModules
    implicit none

contains

    subroutine CalculateLeafNumber(DeltaTT,phyllochron,HasFlagLeafLiguleAppeared,&
        SwitchMaize, atip,Leaf_tip_emerg,k_bl, Nlim, leafNumber,&
       cumulTTPhenoMaizeAtEmergence, cumulTT,phase, Ntip)
    !inputs
    integer , intent(in):: HasFlagLeafLiguleAppeared, SwitchMaize
    real, intent(in):: DeltaTT, atip, Leaf_tip_emerg, k_bl, &
    Nlim, cumulTT,phase
    !outputs
    real, intent(inout):: leafNumber, cumulTTPhenoMaizeAtEmergence, phyllochron
    real, intent(out) ::  Ntip

    real :: leafNumber1, abl, nextstartExpTT, tt_lim_lip, tt_bl, bbl, nexttipTT


    leafNumber1 =leafNumber
    Ntip=0
    if ((phase .EQ. 1) .AND. (cumulTTPhenoMaizeAtEmergence .EQ. 0)) then
        cumulTTPhenoMaizeAtEmergence = cumulTT
    end if
    if ((phase .GE. 1) .AND. (phase .LT. 4)) then
        if (HasFlagLeafLiguleAppeared .EQ. 0) then
            if (SwitchMaize .EQ. 0) then
                if (phyllochron .EQ. 0.0) then
                    phyllochron = 0.0000001
                END IF
                leafNumber = leafNumber1 + min(DeltaTT / phyllochron, 0.999)
                Ntip=0.0
            else
                if (leafNumber1 .LT. Leaf_tip_emerg) then
                    leafNumber = Leaf_tip_emerg
                else
                    nextstartExpTT = 0
                    nexttipTT = ((leafNumber1 + 1) - Leaf_tip_emerg) / atip + cumulTTPhenoMaizeAtEmergence
                    abl = k_bl * atip
                    tt_lim_lip = ((Nlim - Leaf_tip_emerg) / atip) + cumulTTPhenoMaizeAtEmergence
                    bbl = Nlim - (abl * tt_lim_lip)
                    tt_bl = ((leafNumber1 + 1) - bbl) / abl
                    if (tt_bl .GT. nexttipTT) then
                        nextstartExpTT = nexttipTT
                    else
                        nextstartExpTT = tt_bl
                    ENDIF
                    if (cumulTT .GE. nextstartExpTT) then
                        leafNumber = leafNumber1 + 1
                    else
                        leafNumber = leafNumber1
                    END IF
                END IF
                Ntip = atip * (cumulTT - cumulTTPhenoMaizeAtEmergence) + Leaf_tip_emerg
            END IF
        END IF
    END IF
    end subroutine

end module
