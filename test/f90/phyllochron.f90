MODULE phyllochronModule
    USE crop2mlModules
CONTAINS

    SUBROUTINE Calculate_Phyllochron(fixPhyll,leafNumber,lincr,ldecr,pdecr,&
            pincr, ptq, gai, pastMaxAI,kl, aPTQ, phylPTQ1, p,choosePhyllUse, phyllochron)

        REAL , INTENT(IN)::fixPhyll,leafNumber,lincr,ldecr,pdecr,pincr,ptq,&
            kl, aPTQ, phylPTQ1, p
        REAL , INTENT(INOUT):: pastMaxAI, gai
        CHARACTER(LEN=*), INTENT(IN):: choosePhyllUse
        REAL, INTENT(OUT):: phyllochron

        IF (choosePhyllUse .EQ. 'Default') THEN
            IF (leafNumber < ldecr) THEN
                phyllochron = fixPhyll * pdecr
            ELSE IF ((leafNumber >= ldecr) .AND. (leafNumber < lincr)) THEN
                phyllochron = fixPhyll
            ELSE
                phyllochron = fixPhyll * pincr
            END IF
        END IF
        IF (choosePhyllUse .EQ. 'PTQ') THEN
            gai = MAX(pastMaxAI,gai)
            pastMaxAI = gai
            IF (gai > 0.0) THEN
                phyllochron = phylPTQ1 * ((gai * kl) / (1 - EXP(-kl * gai))) / (ptq + aPTQ)
            ELSE
                phyllochron = phylPTQ1
            END IF
        END IF
        IF (choosePhyllUse == 'Test') THEN

            IF (leafNumber < ldecr) THEN
                phyllochron = p * pdecr
            ELSE IF ((leafNumber >= ldecr) .AND. (leafNumber < lincr)) THEN
                phyllochron = p
            ELSE
                phyllochron = p * pincr
            END IF
        END IF
    END SUBROUTINE
END MODULE
