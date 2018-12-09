if choosePhyllUse =="Default":
    if (leafNumber < Ldecr): phyllochron = FixPhyll * Pdecr
    elif (leafNumber >= Ldecr and leafNumber < Lincr): phyllochron = FixPhyll
    else: phyllochron = FixPhyll * Pincr
        
 
if choosePhyllUse =="PTQ":
    pastMaxAI1 = pastMaxAI
    GAI = max(pastMaxAI1,GAI)
    pastMaxAI = GAI
    if (GAI > 0.0): phyllochron = PhylPTQ1 * ((GAI * Kl) / (1 - exp(-Kl * GAI))) / (PTQ + aPTQ)
    else: phyllochron = PhylPTQ1
     
        
if choosePhyllUse == "Test":
    if (leafNumber < Ldecr): phyllochron = P * Pdecr
    elif (leafNumber >= Ldecr and leafNumber < Lincr): phyllochron = P
    else: phyllochron = P * Pincr
        

    
 
