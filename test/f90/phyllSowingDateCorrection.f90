MODULE phyllSowingDateCorrectionModule
    USE crop2mlModules
CONTAINS

    SUBROUTINE Calculate_PhyllSowingDateCorrection(sowingDay,latitude,sDsa_sh,rp,sDws,sDsa_nh,p, fixPhyll)

        REAL , INTENT(IN)::latitude,rp,p
        INTEGER, INTENT(IN):: sowingDay,sDws,sDsa_nh,sDsa_sh
        REAL, INTENT(OUT):: fixPhyll

        IF (latitude < 0) THEN
            IF (sowingDay > sDsa_sh) THEN
                fixPhyll = p * (1 - rp * MIN(sowingDay - sDsa_sh, sDws))
            ELSE
                fixPhyll = p
            END IF
        ELSE
            IF (sowingDay < sDsa_nh) THEN
                fixPhyll = p * (1 - rp * MIN(sowingDay, sDws))
            ELSE
                fixPhyll = p
            END IF
        END IF
    END SUBROUTINE
END MODULE

