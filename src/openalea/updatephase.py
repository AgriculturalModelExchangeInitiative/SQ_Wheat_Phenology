import numpy as np 
from copy import copy
from math import *

def updatephase(cumulTT=354.582294512,
                leafNumber=4.62051162186,
                cumulTTFromZC_39=0.0,
                isMomentRegistredZC_39=0,
                GAI=0.325519628514,
                GrainCumulTT=0.0,
                DayLength=12.7433275303,
                Vernaprog=1.05325268296,
                MinFinalNumber=6.87941041399,
                FixPhyll=91.2,
                IsVernalizable=1,
                Dse=105.0,
                PFLLAnth=2.22,
                Dcd=100.0,
                Dgf=450.0,
                Degfm=0.0,
                MaxDL=15.0,
                SLDL=0.85,
                IgnoreGrainMaturation=False,
                PHEADANTH=1.0,
                SwitchMaize=0,
                choosePhyllUse='Default',
                P=120.0,
                phase=1.0,
                cumulTTFromZC_91=0.0,
                phyllochron=91.2,
                hasLastPrimordiumAppeared=0,
                FinalLeafNumber=0.0):
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
        if (SwitchMaize==0):
            if (cumulTT >= Dse):
                phase = 1#Emergence
            else:
                phase = phase1
        else:
            if (cumulTT >= Dse):
                phase= 1#Emergence
            else:
                phase = phase1
    elif (phase1 >= 1 and phase1 < 2):#EmergenceToFloralInitiation
        if ((IsVernalizable==1 and Vernaprog >= 1) or (IsVernalizable==0)):
            if (SwitchMaize==0):
                if (DayLength > MaxDL):
                    FinalLeafNumber = MinFinalNumber
                    hasLastPrimordiumAppeared = 1
                else:
                    appFLN = MinFinalNumber + SLDL * (MaxDL - DayLength)
                        # calculation of final leaf number from daylength at inflexion plus 2 leaves
                    if (appFLN / 2.0 <= leafNumber):
                        FinalLeafNumber = appFLN
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
                if(choosePhyllUse=="Default"): ttFromLastLeafToHeading =(PFLLAnth - PHEADANTH) * FixPhyll
                elif (choosePhyllUse == "PTQ"): ttFromLastLeafToHeading = (PFLLAnth - PHEADANTH) * phyllochron
                elif (choosePhyllUse == "Test"): ttFromLastLeafToHeading = (PFLLAnth - PHEADANTH) * P
                if (cumulTTFromZC_39 >= ttFromLastLeafToHeading):
                        phase = 3
                else:
                    phase = phase1
            else:
                phase = phase1
                        #CheckAnthesis;
            ttFromLastLeafToAnthesis =0.0
            if (choosePhyllUse == "Default"): ttFromLastLeafToAnthesis = PFLLAnth * FixPhyll
            elif (choosePhyllUse == "PTQ"): ttFromLastLeafToAnthesis = PFLLAnth * phyllochron
            elif (choosePhyllUse == "Test"): ttFromLastLeafToAnthesis = PFLLAnth * P
            if (cumulTTFromZC_39 >= ttFromLastLeafToAnthesis):
                phase = 4#Anthesis
        else:
            phase = phase1
    elif (phase1 == 4):#AnthesisToEndCellDivision
                    #CheckEndCellDivision
        if (GrainCumulTT >= Dcd):
            phase = 4.5#EndCellDivision
        else:
            phase = phase1
    elif (phase1 == 4.5):#EndCellDivisionToEndGrainFill
                    # CheckEndGrainFilling
        if (GrainCumulTT >= Dgf or GAI <= 0):
            phase = 5#End of grain filling
        else:
            phase = phase1
    elif (phase1 >= 5 and phase1 < 6):#EndGrainFillToMaturity
                    #CheckMaturity
                    #/<Comment>To enable ignoring grain maturation duration</Comment>
        LocalDegfm = Degfm
        if (IgnoreGrainMaturation==True): LocalDegfm = -1
        if (cumulTTFromZC_91 >= LocalDegfm ):
            phase = 6 #maturity
        else:
            phase= phase1
    elif (phase1>= 6 and phase1 < 7):
        phase = phase1
    return  FinalLeafNumber, phase, hasLastPrimordiumAppeared
