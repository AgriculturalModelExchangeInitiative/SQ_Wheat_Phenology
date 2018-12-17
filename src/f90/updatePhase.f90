MODULE updatePhaseModule
    USE crop2mlModules
    IMPLICIT NONE
CONTAINS

    SUBROUTINE Calculate_UpdatePhase( cumulTT, leafNumber, cumulTTFromZC_39,&
            isMomentRegistredZC_39, gai, grainCumulTT, dayLength, vernaprog,&
            minFinalNumber, fixPhyll,isVernalizable, dse, pFLLAnth,&
            dcd, dgf, degfm, maxDL, sLDL, ignoreGrainMaturation,&
            pHEADANTH,switchMaize,choosePhyllUse, p, phase, &
            cumulTTFromZC_91, phyllochron,hasLastPrimordiumAppeared, &
            finalLeafNumber)

        ! DECLARATION
        REAL, INTENT(IN):: cumulTT,p, leafNumber, cumulTTFromZC_39,cumulTTFromZC_91, &
            gai,grainCumulTT,  dayLength, vernaprog,minFinalNumber, fixPhyll, phyllochron,pHEADANTH, &
            dse, pFLLAnth, dcd, dgf, degfm, maxDL, sLDL
        CHARACTER(LEN=65), INTENT(IN) :: choosePhyllUse
        INTEGER, INTENT(IN)::  isMomentRegistredZC_39, isVernalizable, switchMaize
        LOGICAL, INTENT(IN)::ignoreGrainMaturation
        INTEGER, INTENT(INOUT):: hasLastPrimordiumAppeared
        REAL, INTENT(INOUT):: Phase
        REAL, INTENT(OUT)::finalLeafNumber
        REAL:: phase1, appFLN, ttFromLastLeafToHeading, localDegfm, ttFromLastLeafToAnthesis

        phase1 = phase
        IF ((phase1 >= 0) .AND. (phase1 < 1))THEN
            IF (switchMaize==0)THEN
                IF (cumulTT>= dse) THEN
                    phase = 1
                ELSE
                    phase = phase1
                END IF
            ELSE
                IF (cumulTT >= dse) THEN
                    phase= 1;
                ELSE
                    phase = phase1
                END IF
            END IF
        ELSE IF ((phase1 >= 1) .AND. (phase1 < 2)) THEN
            IF ((isVernalizable==1 .AND. vernaprog >= 1) .OR. (isVernalizable==0)) THEN
                IF (switchMaize==0) THEN
                    IF (dayLength > maxDL) THEN
                        finalLeafNumber = minFinalNumber
                        hasLastPrimordiumAppeared = 1
                    ELSE
                        appFLN = minFinalNumber + sLDL * (maxDL - dayLength)
                        !calculation of final leaf number from dayLength at inflexion plus 2 leaves
                        IF ((appFLN / 2.0) <= leafNumber) THEN
                            finalLeafNumber = appFLN;
                            hasLastPrimordiumAppeared =1
                        ELSE
                            phase = phase1
                        END IF
                    END IF
                ELSE
                    hasLastPrimordiumAppeared = 1
                END IF
                IF (hasLastPrimordiumAppeared==1) THEN
                    phase = 2
                END IF
            ELSE
                phase = phase1
            END IF
        ELSE IF ((phase1 >= 2) .AND. (phase1 < 4)) THEN
            IF (isMomentRegistredZC_39==1) THEN
                IF (phase1 < 3) THEN
                    ttFromLastLeafToHeading = 0.0
                    IF(choosePhyllUse=="Default") THEN
                        ttFromLastLeafToHeading =(pFLLAnth - pHEADANTH) * fixPhyll
                    ELSE IF (choosePhyllUse == "PTQ") THEN
                        ttFromLastLeafToHeading = (pFLLAnth - pHEADANTH) * phyllochron;
                    ELSE IF (choosePhyllUse == "Test")  THEN
                        ttFromLastLeafToHeading = (pFLLAnth - pHEADANTH) * p
                    END IF
                    IF (cumulTTFromZC_39 >= ttFromLastLeafToHeading) THEN
                        phase = 3
                    ELSE
                        phase = phase1
                    END IF
                END IF
                ttFromLastLeafToAnthesis =0.0;
                IF (choosePhyllUse == "Default") THEN
                    ttFromLastLeafToAnthesis = pFLLAnth * fixPhyll
                ELSE IF (choosePhyllUse == "PTQ") THEN
                    ttFromLastLeafToAnthesis = pFLLAnth * phyllochron
                ELSE IF (choosePhyllUse == "Test") THEN
                    ttFromLastLeafToAnthesis = pFLLAnth * p
                END IF
                IF (cumulTTFromZC_39 >= ttFromLastLeafToAnthesis) THEN
                    phase = 4
                ELSE
                    phase = phase1
                END IF
            ELSE
                phase = phase1
            END IF
        ELSE IF (phase1 == 4) THEN
            IF (grainCumulTT >= dcd) THEN
                phase = 4.5
            ELSE
                phase = phase1
            END IF

        ELSE IF (phase1 == 4.5) THEN
            IF ((grainCumulTT >= dgf) .OR. (gai <= 0)) THEN
                phase = 5
            ELSE
                phase = phase1
            END IF
        ELSE IF ((phase1 >= 5) .AND. (phase1 < 6)) THEN
            localDegfm = degfm
            IF (ignoreGrainMaturation .EQV. .TRUE.) THEN
                localDegfm = -1
            END IF
            IF (cumulTTFromZC_91 >= localDegfm) THEN
                phase = 6
            ELSE
                phase= phase1
            END IF
        ELSE IF ((phase1>= 6) .AND. (phase1 < 7)) THEN
            phase = phase1
        END IF
    END SUBROUTINE
END MODULE



