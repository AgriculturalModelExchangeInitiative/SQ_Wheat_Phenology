if (phase >= 1 && phase< 4)
{
    if (leafNumber > 0)
    {
        if (HasFlagLeafLiguleAppeared == 0 && (FinalLeafNumber > 0 && leafNumber >= FinalLeafNumber))
        {
            HasFlagLeafLiguleAppeared = 1;
            if  (calendarMoments.Contains("FlagLeafLiguleJustVisible")==false)
            {
                calendarMoments.Add("FlagLeafLiguleJustVisible");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
        }
    }
    else:
        HasFlagLeafLiguleAppeared = 0;
}


    
