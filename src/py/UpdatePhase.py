import numpy as np 
from copy import copy
from math import *

def updatephase(cumulTT=354.582294512,
                leafNumber=4.62051162186,
                cumulTTFromZC_39=0.0,
                isMomentRegistredZC_39=0,
                gai=0.325519628514,
                grainCumulTT=0.0,
                dayLength=12.7433275303,
                vernaprog=1.05325268296,
                minFinalNumber=6.87941041399,
                fixPhyll=91.2,
                isVernalizable=1,
                dse=105.0,
                pFLLAnth=2.22,
                dcd=100.0,
                dgf=450.0,
                degfm=0.0,
                maxDL=15.0,
                sLDL=0.85,
                ignoreGrainMaturation=False,
                pHEADANTH=1.0,
                switchMaize=0,
                choosePhyllUse='Default',
                p=120.0,
                phase=1.0,
                cumulTTFromZC_91=0.0,
                phyllochron=91.2,
                hasLastPrimordiumAppeared=0):
    """


    UpdatePhase Model
    Author: Pierre MARTRE
    Reference: Modeling development phase in the 
                Wheat Simulation Model SiriusQuality.
                See documentation at http://www1.clermont.inra.fr/siriusquality/?page_id=427
    Institution: INRA Montpellier
    Abstract: This strategy advances the phase and calculate the final leaf number
    	

    """
    phase1 = phase
    if (phase1 >= 0 and phase1 < 1):
        if (switchMaize==0):
            if (cumulTT >= dse):
                phase = 1#Emergence
            else:
                phase = phase1
        else:
            if (cumulTT >= dse):
                phase= 1#Emergence
            else:
                phase = phase1               
    elif (phase1 >= 1 and phase1 < 2):#EmergenceToFloralInitiation
        if ((isVernalizable==1 and vernaprog >= 1) or (isVernalizable==0)):
            if (switchMaize==0):
                if (dayLength > maxDL):
                    finalLeafNumber = minFinalNumber
                    hasLastPrimordiumAppeared = 1
                else:
                    appFLN = minFinalNumber + sLDL * (maxDL - dayLength)                    
                        # calculation of final leaf number from daylength at inflexion plus 2 leaves
                    if (appFLN / 2.0 <= leafNumber):
                        finalLeafNumber = appFLN
                        hasLastPrimordiumAppeared =1
                    else:
                        phase = phase1
            else:
                hasLastPrimordiumAppeared = 1
                #CheckFloralInitiation
            if (hasLastPrimordiumAppeared==1):              
                    phase = 2#Floralinitiation             
        else:
            phase = phase1   
    elif (phase1 >= 2 and phase1 < 4):#FloralInitiationToAnthesis
        if (isMomentRegistredZC_39==1):
                      #calculate the heading date
            if (phase1 < 3):
                ttFromLastLeafToHeading = 0.0
                if(choosePhyllUse=="Default"): ttFromLastLeafToHeading =(pFLLAnth - pHEADANTH) * fixPhyll
                elif (choosePhyllUse == "PTQ"): ttFromLastLeafToHeading = (pFLLAnth - pHEADANTH) * phyllochron
                elif (choosePhyllUse == "Test"): ttFromLastLeafToHeading = (pFLLAnth - pHEADANTH) * p
                if (cumulTTFromZC_39 >= ttFromLastLeafToHeading):
                        phase = 3
                else:
                    phase = phase1
            else:
                phase = phase1                          
                        #CheckAnthesis;
            ttFromLastLeafToAnthesis =0.0
            if (choosePhyllUse == "Default"): ttFromLastLeafToAnthesis = pFLLAnth * fixPhyll
            elif (choosePhyllUse == "PTQ"): ttFromLastLeafToAnthesis = pFLLAnth * phyllochron
            elif (choosePhyllUse == "Test"): ttFromLastLeafToAnthesis = pFLLAnth * p      
            if (cumulTTFromZC_39 >= ttFromLastLeafToAnthesis):
                phase = 4#Anthesis           
        else:
            phase = phase1            
    elif (phase1 == 4):#AnthesisToEndCellDivision          
                    #CheckEndCellDivision
        if (grainCumulTT >= dcd):             
            phase = 4.5#EndCellDivision           
        else:           
            phase = phase1                  
    elif (phase1 == 4.5):#EndCellDivisionToEndGrainFill    
                    # CheckEndGrainFilling
        if (grainCumulTT >= dgf or gai <= 0):          
            phase = 5#End of grain filling        
        else:         
            phase = phase1      
    elif (phase1 >= 5 and phase1 < 6):#EndGrainFillToMaturity
                    #CheckMaturity
                    #/<Comment>To enable ignoring grain maturation duration</Comment>
        localDegfm = degfm
        if (ignoreGrainMaturation==True): localDegfm = -1       
        if (cumulTTFromZC_91 >= localDegfm ):        
            phase = 6 #maturity               
        else:        
            phase= phase1     
    elif (phase1>= 6 and phase1 < 7):     
        phase = phase1
    return  finalLeafNumber, phase, hasLastPrimordiumAppeared
