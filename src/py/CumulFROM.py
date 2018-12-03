   
cumulTTFromAnthesis = 0
cumulTTFromFlagLeafLiguleJustVisible = 0
cumulTTFromEndGrainFilling = 0
        
if "Anthesis" in calendarMoments:
    if (SwitchMaize == 0): cumulTTFromAnthesis = cumulTT-calendarCumuls[calendarMoments.index("Anthesis")]
     
if "FlagLeafLiguleJustVisible" in calendarMoments:
    if (SwitchMaize == 0): cumulTTFromFlagLeafLiguleJustVisible = cumulTT-calendarCumuls[calendarMoments.index("FlagLeafLiguleJustVisible")]
    
if "EndGrainFilling"in calendarMoments:
    if (SwitchMaize == 0): cumulTTFromEndGrainFilling = cumulTT-calendarCumuls[calendarMoments.index("FlagLeafLiguleJustVisible")]
