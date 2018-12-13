    !use crop2mlModules

    if (choosePhyllUse .EQ. 'Default') then
        if (leafNumber < Ldecr) then
            phyllochron = FixPhyll * Pdecr
        else if ((leafNumber >= Ldecr) .AND. (leafNumber < Lincr)) then
            phyllochron = FixPhyll
        else
            phyllochron = FixPhyll * Pincr
        end if
    end if

    if (choosePhyllUse .EQ. 'PTQ') then
        GAI = MAX(pastMaxAI,GAI)
        pastMaxAI = GAI
        if (GAI > 0.0) then
            phyllochron = PhylPTQ1 * ((GAI * Kl) / (1 - EXP(-Kl * GAI))) / (PTQ + aPTQ)
        else
            phyllochron = PhylPTQ1
        end if
    end if


    if (choosePhyllUse == 'Test') then

        if (leafNumber < Ldecr) then
            phyllochron = P * Pdecr
        else if ((leafNumber >= Ldecr) .AND. (leafNumber < Lincr)) then
            phyllochron = P
        else
            phyllochron = P * Pincr
        end if
    end if

