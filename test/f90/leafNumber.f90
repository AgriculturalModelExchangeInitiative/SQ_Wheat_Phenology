MODULE leafNumberModule
    USE crop2mlModules
    IMPLICIT NONE

CONTAINS

    SUBROUTINE Calculate_LeafNumber(deltaTT,phyllochron,hasFlagLeafLiguleAppeared,&
            switchMaize, atip,leaf_tip_emerg,k_bl, nlim, leafNumber,&
            cumulTTPhenoMaizeAtEmergence, cumulTT,phase, ntip)			
        !inputs
        INTEGER , INTENT(IN):: hasFlagLeafLiguleAppeared, switchMaize
        REAL, INTENT(IN):: deltaTT, atip, leaf_tip_emerg, k_bl, &
            nlim, cumulTT,phase
        !outputs
        REAL, INTENT(INOUT):: leafNumber, cumulTTPhenoMaizeAtEmergence, phyllochron
        REAL, INTENT(OUT) ::  ntip
        REAL :: leafNumber1, abl, nextstartExpTT, tt_lim_lip, tt_bl, bbl, nexttipTT

        leafNumber1 =leafNumber
        ntip=0
        IF ((phase .EQ. 1) .AND. (cumulTTPhenoMaizeAtEmergence .EQ. 0)) THEN
            cumulTTPhenoMaizeAtEmergence = cumulTT
        END IF
        IF ((phase .GE. 1) .AND. (phase .LT. 4)) THEN
            IF (hasFlagLeafLiguleAppeared .EQ. 0) THEN
                IF (switchMaize .EQ. 0) THEN
                    IF (phyllochron .EQ. 0.0) THEN
                        phyllochron = 0.0000001
                    END IF
                    leafNumber = leafNumber1 + MIN(deltaTT / phyllochron, 0.999)
                    ntip=0.0
                ELSE
                    IF (leafNumber1 .LT. leaf_tip_emerg) THEN
                        leafNumber = leaf_tip_emerg
                    ELSE
                        nextstartExpTT = 0
                        nexttipTT = ((leafNumber1 + 1) - leaf_tip_emerg) / atip + cumulTTPhenoMaizeAtEmergence
                        abl = k_bl * atip
                        tt_lim_lip = ((nlim - leaf_tip_emerg) / atip) + cumulTTPhenoMaizeAtEmergence
                        bbl = nlim - (abl * tt_lim_lip)
                        tt_bl = ((leafNumber1 + 1) - bbl) / abl
                        IF (tt_bl .GT. nexttipTT) THEN
                            nextstartExpTT = nexttipTT
                        ELSE
                            nextstartExpTT = tt_bl
                        ENDIF
                        IF (cumulTT .GE. nextstartExpTT) THEN
                            leafNumber = leafNumber1 + 1
                        ELSE
                            leafNumber = leafNumber1
                        END IF
                    END IF
                    ntip = atip * (cumulTT - cumulTTPhenoMaizeAtEmergence) + leaf_tip_emerg
                END IF
            END IF
        END IF
    END SUBROUTINE
END MODULE
