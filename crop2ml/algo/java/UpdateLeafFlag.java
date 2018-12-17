if (phase >= 1 && phase< 4)
{
    if (leafNumber > 0)
    {
        if (hasFlagLeafLiguleAppeared == 0 && (finalLeafNumber > 0 && leafNumber >= finalLeafNumber))
        {
            hasFlagLeafLiguleAppeared = 1;
            if  (calendarMoments.contains("FlagLeafLiguleJustVisible")==false)
            {
                calendarMoments.add("FlagLeafLiguleJustVisible");
                calendarCumuls.add(cumulTT);
                calendarDates.add(currentdate);
            }
        }
    }
    else
        hasFlagLeafLiguleAppeared = 0;
}


    
