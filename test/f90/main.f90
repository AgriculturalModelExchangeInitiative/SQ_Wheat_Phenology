program test_different_module
    implicit none
    call test_cumulTTFrom
    call test_IsMomentRegistredZC_39
    call test_leafNumber
    call test_phyllochron
    call test_registerZadock
    call test_shootNumber
    call test_UpdateCalendar
    call test_updateLeafFlag
    call test_updatePhase
    call test_vernalizationProgress
    call test_PhyllSowingDateCorrection

end program

subroutine test_cumulTTFrom
    use CumulTTFROM
    integer::SwitchMaize=0
    real,dimension (6)::calendarCumuls=(/0.0, 112.330110409888,&
        354.582294511779, 741.510096671757, 853.999637026622, 954.59002776961/)
    real :: cumulTT = 972.970888983105
    character(len=200),dimension(6):: calendarMoments

    calendarMoments(1) = 'Sowing'
    calendarMoments(2) = 'Emergence'
    calendarMoments(3) = 'FloralInitiation'
    calendarMoments(4) = 'FlagLeafLiguleJustVisible'
    calendarMoments(5) =  'Heading'
    calendarMoments(6) =  'Anthesis'

    print *, "-----------------------------test_CumulTTFrom------------------------"

    call calculateCumulFROM(cumulTT, calendarMoments, calendarCumuls, SwitchMaize,&
        cumulTTFromZC_39, cumulTTFromZC_65, cumulTTFromZC_91)
    print *, "cumulTTFromZC_39 = ", cumulTTFromZC_39,&
    "cumulTTFromZC_65 = ", cumulTTFromZC_65,&
    "cumulTTFromZC_91 = ", cumulTTFromZC_91

end subroutine

subroutine test_IsMomentRegistredZC_39
    use IsMomentRegistredZC_39Module
    implicit none
    integer::isMomentRegistredZC_39
    character(len=1000),dimension(6):: calendarMoments
    calendarMoments(1) = 'Sowing'
    calendarMoments(2) = 'Emergence'
    calendarMoments(3) = 'FloralInitiation'
    calendarMoments(4) = 'FlagLeafLiguleJustVisible'
    calendarMoments(5) =  'Heading'
    calendarMoments(6) =  'Anthesis'


    print *, "-----------------------------test_IsMomentRegistred------------------------"

    call CalculateIsMomentRegistredZC_39(calendarMoments, isMomentRegistredZC_39)
    print *,"isMomentRegistredZC_39 = ",isMomentRegistredZC_39


end subroutine

subroutine test_leafNumber

    use leafNumberModule
    implicit none
    integer:: HasFlagLeafLiguleAppeared = 0 , SwitchMaize = 0
    real::DeltaTT = 23.5895677277199,phyllochron = 91.2, atip = 10,Leaf_tip_emerg = 10,&
        k_bl = 1.412, Nlim = 6.617,leafNumber = 5.147163833893262,&
        cumulTTPhenoMaizeAtEmergence = 300, cumulTT = 402.042720581446, phase = 3, Ntip

    print *, "-----------------------------test_leafNumber------------------------"


    call CalculateLeafNumber(DeltaTT,phyllochron,HasFlagLeafLiguleAppeared,&
        SwitchMaize, atip,Leaf_tip_emerg,k_bl, Nlim, leafNumber,&
        cumulTTPhenoMaizeAtEmergence, cumulTT,phase, Ntip)

    print *, "leafNumber = ",leafNumber, "Ntip = ", Ntip

end subroutine



subroutine test_phyllochron
    use phyllochronModule
    real:: FixPhyll = 91.2,leafNumber = 0,Lincr = 8,Ldecr = 3,Pdecr = 0.4,&
        Pincr = 1.25, PTQ = 0,GAI = 0.279874189539498,pastMaxAI = 0,&
        Kl = 0.45, aPTQ = 0.842934,PhylPTQ1 = 20, P = 120
    character(10):: choosePhyllUse = 'Default'

    print *, "-----------------------------test_Phyllochron------------------------"


    call calculatePhyllochron(FixPhyll,leafNumber,Lincr,Ldecr,Pdecr,&
        Pincr, PTQ, GAI, pastMaxAI,Kl, aPTQ, PhylPTQ1, P,choosePhyllUse, phyllochron)

    print *, " phyllochron = ", phyllochron, "pastMaxAI", pastMaxAI
end subroutine


subroutine test_registerZadock
    use registerZadokModule
    use crop2mlModules

    character(len=65)::currentZadokStage = 'MainShootPlus1Tiller'
    character(len=65)::currentdate = '9/4/2007'
    character(len=65) ,dimension(:), allocatable:: calendarMoments
    character(len=65), dimension(:), allocatable ::calendarDates
    real, dimension(:), allocatable :: calendarCumuls

    real ::cumulTT = 354.582294511779 ,  phase = 2,leafNumber = 4.8854219661087575,&
        cumulTTFromZC_65 = 0,Der = 300.0,slopeTSFLN = 0.9,TSFLN = 2.6,intTSFLN = 0.9, &
        FinalLeafNumber = 8.797582013199484
    integer :: hasZadokStageChanged = 0

    call AddToList(calendarCumuls,0.0)
    call AddToList(calendarCumuls,112.330110409888)
    call AddToList(calendarCumuls,157.969706915664)
    call AddToList(calendarCumuls,280.570678654207)


    allocate(calendarDates(1))
    calendarDates(1)="21/03/2007"
    call AddToListChar(calendarDates,"27/03/2007")
    call AddToListChar(calendarDates,"30/03/2007")
    call AddToListChar(calendarDates,"05/04/2007")
    !print *, calendarDates(3)

    allocate(calendarMoments(1))
    calendarMoments(1)="Sowing"
    call AddToListChar(calendarMoments,'Emergence')
    call AddToListChar(calendarMoments, 'EndVernalisation')
    call AddToListChar(calendarMoments,'MainShootPlus1Tiller')

    print *, "-----------------------------test_RegisterZadok------------------------"


    call calculateRegisterZadok(cumulTT,phase,leafNumber,calendarMoments,&
        calendarDates,calendarCumuls,cumulTTFromZC_65, currentdate,Der,&
        slopeTSFLN,TSFLN,intTSFLN, FinalLeafNumber,currentZadokStage,&
        hasZadokStageChanged)

    print *, "hasZadokStageChanged =", hasZadokStageChanged, &
        "currentZadokStage =" ,currentZadokStage

    Do I=1, size(calendarCumuls)
        print *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    End Do

end subroutine

subroutine test_shootNumber
    use shootNumberModule
    use crop2mlModules
    implicit none
    integer :: SowingDensity=288, TillerNumber= 1
    real ::leafNumber= 3.34348137255,TargetFertileShoot=600.0, &
        CanopyShootNumber=288.0, AverageShootNumberPerPlant

    integer, dimension(:) , allocatable  ::  leafTillerNumberArray
    real,dimension(:), allocatable  :: tilleringProfile

    call AddToList(tilleringProfile,288.0)

    call AddToListInt(leafTillerNumberArray, 1)
    call AddToListInt(leafTillerNumberArray, 1)
    call AddToListInt(leafTillerNumberArray, 1)

    print *, "-----------------------------test_ShootNumber------------------------"

    call calculateShootNumber(CanopyShootNumber,leafNumber,SowingDensity,&
        TargetFertileShoot, tilleringProfile,leafTillerNumberArray, TillerNumber, &
        AverageShootNumberPerPlant)

    print *, "CanopyShootNumber =",CanopyShootNumber,"TillerNumber =", TillerNumber &
    , "AverageShootNumberPerPlant = ", AverageShootNumberPerPlant

    print *, "leafTillerNumberArray =" ,leafTillerNumberArray
    print *, "tilleringProfile ", tilleringProfile


end subroutine

subroutine test_UpdateCalendar
    use updateCalendarModule
    use crop2mlModules

    character(len=65)::currentdate = '27/3/2007'
    character(len=65) ,dimension(:), allocatable:: calendarMoments
    character(len=65), dimension(:), allocatable ::calendarDates
    real, dimension(:), allocatable :: calendarCumuls

    real ::cumulTT = 112.330110409888 ,  phase = 1
    call AddToList(calendarCumuls,0.0)

    allocate(calendarDates(1))
    calendarDates(1)="21/03/2007"

    allocate(calendarMoments(1))
    calendarMoments(1)="Sowing"


    print *, "-----------------------------test_UpdateCalendar------------------------"

    call calculateUpdateCalendar( cumulTT,&
        calendarMoments, calendarDates,&
        calendarCumuls,currentdate, phase)

    print *, "phase =", phase
    Do I=1, size(calendarCumuls)
        print *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    End Do


end subroutine

subroutine test_updateLeafFlag
    use updateLeafFlagModule
    use crop2mlModules

    character(len=65)::currentdate = '29/4/2007'
    character(len=65) ,dimension(:), allocatable:: calendarMoments
    character(len=65), dimension(:), allocatable ::calendarDates
    real, dimension(:), allocatable :: calendarCumuls

    real ::cumulTT = 741.510096671757 ,  phase = 3, leafNumber = 8.919453833361189,&
        FinalLeafNumber = 8.797582013199484
    integer:: HasFlagLeafLiguleAppeared = 0

    call AddToList(calendarCumuls,0.0)
    call AddToList(calendarCumuls,112.330110409888)
    call AddToList(calendarCumuls,157.969706915664)
    call AddToList(calendarCumuls,280.570678654207)
    call AddToList(calendarCumuls,354.582294511779)
    call AddToList(calendarCumuls,378.453152853726)
    call AddToList(calendarCumuls,402.042720581446)
    call AddToList(calendarCumuls,424.98704708663)
    call AddToList(calendarCumuls,467.23305195298)
    call AddToList(calendarCumuls,487.544313430698)
    call AddToList(calendarCumuls,560.665248444002)
    call AddToList(calendarCumuls,646.389617338974)

    allocate(calendarDates(1))
    calendarDates(1)="21/03/2007"
    call AddToListChar(calendarDates,"27/3/2007")
    call AddToListChar(calendarDates,"30/3/2007")
    call AddToListChar(calendarDates,"5/4/2007")
    call AddToListChar(calendarDates,"9/4/2007")
    call AddToListChar(calendarDates,"10/4/2007")
    call AddToListChar(calendarDates,"11/4/2007")
    call AddToListChar(calendarDates,"12/4/2007")
    call AddToListChar(calendarDates,"14/4/2007")
    call AddToListChar(calendarDates,"15/4/2007")
    call AddToListChar(calendarDates,"19/4/2007")
    call AddToListChar(calendarDates,"24/4/2007")

    allocate(calendarMoments(1))
    calendarMoments(1)="Sowing"
    call AddToListChar(calendarMoments,"Emergence")
    call AddToListChar(calendarMoments,"EndVernalisation")
    call AddToListChar(calendarMoments,"MainShootPlus1Tiller")
    call AddToListChar(calendarMoments,"FloralInitiation")
    call AddToListChar(calendarMoments,"MainShootPlus2Tiller")
    call AddToListChar(calendarMoments,"TerminalSpikelet")
    call AddToListChar(calendarMoments,"PseudoStemErection")
    call AddToListChar(calendarMoments,"MainShootPlus3Tiller")
    call AddToListChar(calendarMoments,"1stNodeDetectable")
    call AddToListChar(calendarMoments,"2ndNodeDetectable")
    call AddToListChar(calendarMoments, "FlagLeafJustVisible")

    print *, "------------------------- Test updateLeafFlag---------------"

    call calculateUpdateLeafFlag( cumulTT, leafNumber,&
        calendarMoments, calendarDates, calendarCumuls,currentdate,&
        FinalLeafNumber, HasFlagLeafLiguleAppeared, phase)

    print *, "HasFlagLeafLiguleAppeared =", HasFlagLeafLiguleAppeared

    print *, "calendarCumuls, CalendarDates,    CalendarMoments"
    Do I=1, size(calendarCumuls)
        print *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    End Do

end subroutine test_updateLeafFlag

subroutine test_updatePhase

    use updatePhaseModule
    use crop2mlModules
    implicit none

    real:: cumulTT = 354.582294511779, leafNumber =  4.620511621863958, &
        cumulTTFromZC_39 = 0, GAI = 0.3255196285135,&
        GrainCumulTT = 0, DayLength = 12.7433275303389, Vernaprog =  1.0532526829571554, &
        MinFinalNumber = 6.879410413987549, FixPhyll = 91.2,Dse = 105,PFLLAnth = 2.22,&
        Dcd = 100,Dgf = 450, Degfm = 0, MaxDL = 15,SLDL = 0.85, PHEADANTH = 1,&
        P = 120,phase = 1,cumulTTFromZC_91 = 0, phyllochron = 91.2, FinalLeafNumber

    integer::IsVernalizable = 1,hasLastPrimordiumAppeared = 0,SwitchMaize = 0, isMomentRegistredZC_39 = 0
    logical:: IgnoreGrainMaturation = .FALSE.
    character(65) :: choosePhyllUse = "Default"

    print *, "---------------------------- test updatePhase----------------------"

    call calculateUpdatePhase(cumulTT, leafNumber, cumulTTFromZC_39,&
        isMomentRegistredZC_39, GAI, GrainCumulTT, DayLength, Vernaprog,&
        MinFinalNumber, FixPhyll,IsVernalizable, Dse, PFLLAnth,&
        Dcd, Dgf, Degfm, MaxDL, SLDL, IgnoreGrainMaturation,&
        PHEADANTH,SwitchMaize,choosePhyllUse, P, phase, &
        cumulTTFromZC_91, phyllochron,hasLastPrimordiumAppeared, &
        FinalLeafNumber)
    print *, "FinalLeafNumber =  ", FinalLeafNumber
    print *, "Phase =  ", phase
    print *, "hasLastPrimordiumAppeared=  ", hasLastPrimordiumAppeared


end subroutine

subroutine test_vernalizationProgress
    use crop2mlModules
    use vernalizationProgressModule

    real::DayLength = 12.3037621834005,DeltaTT = 20.3429985011972,&
        cumulTT =  112.330110409888,leafNumber = 0,MinTvern = 0.0,&
        IntTvern =  11.0, VAI =  0.015,VBEE = 0.01, MinDL = 8.0,MaxDL = 15.0, &
        MaxTvern =  23.0,PNini = 4.0, AMXLFNO = 24.0, Vernaprog =  0.5517254187376879,&
        MinFinalNumber = 5.5

    integer::IsVernalizable =1
    character(len=25)::currentdate = '27/3/2007'
    character(len=25) ,dimension(:), allocatable:: calendarMoments
    character(len=25), dimension(:), allocatable ::calendarDates
    real, dimension(:), allocatable :: calendarCumuls

    call AddToList(calendarCumuls,0.0)

    allocate(calendarDates(1))
    calendarDates(1)="21/03/2007"

    allocate(calendarMoments(1))
    calendarMoments(1)="Sowing"

    print *, "------------------------- test_vernalizationProgress----------------"
    call calculateVernalizationProgress(DayLength, DeltaTT, cumulTT, &
        leafNumber,calendarMoments, calendarDates, calendarCumuls, &
        MinTvern, IntTvern, VAI, VBEE, MinDL, MaxDL, MaxTvern, PNini, AMXLFNO, Vernaprog,&
         currentdate, IsVernalizable, MinFinalNumber)

    print *, "MinFinalNumber  = ", MinFinalNumber
    print *, "VernaProg = ", Vernaprog

    Do I=1, size(calendarCumuls)
        print *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    End Do

end subroutine

subroutine test_PhyllSowingDateCorrection
    use phyllSowingDateCorrectionModule
    implicit none

    integer::SowingDay = 80,SDws = 90, SDsa_sh = 151, SDsa_nh = 200
    real:: Latitude = 33.069,  Rp = 0.003, P = 120, FixPhyll

    print *, "------------------------ test_phyllSowingDateCorrection------------------"

    call calculatePhyllSowingDateCorrection(SowingDay,Latitude,SDsa_sh,Rp,SDws,SDsa_nh,P, FixPhyll)

    print *,  "FixPhyll = ", FixPhyll

end subroutine
