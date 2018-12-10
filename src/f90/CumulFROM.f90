cumulTTFromZC_65 = 0
cumulTTFromZC_39 = 0
cumulTTFromZC_91 = 0

IF "Anthesis" in calendarMoments:
    if (SwitchMaize == 0): cumulTTFromZC_65 = cumulTT-calendarCumuls[calendarMoments.index("Anthesis")]

IF "FlagLeafLiguleJustVisible" in calendarMoments:
    if (SwitchMaize == 0): cumulTTFromZC_39 = cumulTT-calendarCumuls[calendarMoments.index("FlagLeafLiguleJustVisible")]

IF "EndGrainFilling"in calendarMoments:
    if (SwitchMaize == 0): cumulTTFromZC_91 = cumulTT-calendarCumuls[calendarMoments.index("FlagLeafLiguleJustVisible")]
