PROGRAM testEachModule
    IMPLICIT NONE
    CALL Test_cumulTTFrom
    CALL Test_IsMomentRegistredZC_39
    CALL Test_leafNumber
    CALL Test_phyllochron
    CALL Test_registerZadock
    CALL Test_shootNumber
    CALL Test_UpdateCalendar
    CALL Test_updateLeafFlag
    CALL Test_updatePhase
    CALL Test_vernalizationProgress
    CALL Test_PhyllSowingDateCorrection
END PROGRAM


SUBROUTINE Test_cumulTTFrom
    USE CumulTTFROM
    INTEGER::switchMaize=0
    REAL,DIMENSION (6)::calendarCumuls=(/0.0, 112.330110409888,&
        354.582294511779, 741.510096671757, 853.999637026622, 954.59002776961/)
    REAL :: cumulTT = 972.970888983105
    CHARACTER(LEN=200),DIMENSION(6):: calendarMoments
    calendarMoments(1) = 'Sowing'
    calendarMoments(2) = 'Emergence'
    calendarMoments(3) = 'FloralInitiation'
    calendarMoments(4) = 'FlagLeafLiguleJustVisible'
    calendarMoments(5) =  'Heading'
    calendarMoments(6) =  'Anthesis'
    PRINT *, "-----------------------------test_CumulTTFrom------------------------"
    CALL calculate_CumulFROM(cumulTT, calendarMoments, calendarCumuls, switchMaize,&
        cumulTTFromZC_39, cumulTTFromZC_65, cumulTTFromZC_91)
    PRINT *, "cumulTTFromZC_39 = ", cumulTTFromZC_39,&
    "cumulTTFromZC_65 = ", cumulTTFromZC_65,&
    "cumulTTFromZC_91 = ", cumulTTFromZC_91
END SUBROUTINE


SUBROUTINE test_IsMomentRegistredZC_39
    USE IsMomentRegistredZC_39Module
    IMPLICIT NONE
    INTEGER::isMomentRegistredZC_39
    CHARACTER(LEN=1000),DIMENSION(6):: calendarMoments
    calendarMoments(1) = 'Sowing'
    calendarMoments(2) = 'Emergence'
    calendarMoments(3) = 'FloralInitiation'
    calendarMoments(4) = 'FlagLeafLiguleJustVisible'
    calendarMoments(5) =  'Heading'
    calendarMoments(6) =  'Anthesis'
    PRINT *, "-----------------------------test_IsMomentRegistred------------------------"
    CALL Calculate_IsMomentRegistredZC_39(calendarMoments, isMomentRegistredZC_39)
    PRINT *,"isMomentRegistredZC_39 = ",isMomentRegistredZC_39
END SUBROUTINE


SUBROUTINE test_leafNumber
    USE leafNumberModule
    IMPLICIT NONE
    INTEGER:: hasFlagLeafLiguleAppeared = 0 , switchMaize = 0
    REAL::deltaTT = 23.5895677277199,phyllochron = 91.2, atip = 10,Leaf_tip_emerg = 10,&
        k_bl = 1.412, Nlim = 6.617,leafNumber = 5.147163833893262,&
        cumulTTPhenoMaizeAtEmergence = 300, cumulTT = 402.042720581446, phase = 3, ntip
    PRINT *, "-----------------------------test_leafNumber------------------------"
    CALL Calculate_LeafNumber(deltaTT,phyllochron,hasFlagLeafLiguleAppeared,&
        switchMaize, atip,leaf_tip_emerg,k_bl, nlim, leafNumber,&
       cumulTTPhenoMaizeAtEmergence, cumulTT,phase, ntip)
    PRINT *, "leafNumber = ",leafNumber, "ntip = ", ntip

END SUBROUTINE


SUBROUTINE test_phyllochron
    USE phyllochronModule
    REAL:: fixPhyll = 91.2,leafNumber = 0,lincr = 8,ldecr = 3,pdecr = 0.4,&
        pincr = 1.25, ptq = 0,gai = 0.279874189539498,pastMaxAI = 0,&
        kl = 0.45, aPTQ = 0.842934,phylPTQ1 = 20, p = 120
    CHARACTER(10):: choosePhyllUse = 'Default'
    PRINT *, "-----------------------------test_Phyllochron------------------------"
    CALL Calculate_Phyllochron(fixPhyll,leafNumber,lincr,ldecr,pdecr,&
        pincr, ptq, gai, pastMaxAI,kl, aPTQ, phylPTQ1, p,choosePhyllUse, phyllochron)
    PRINT *, " phyllochron = ", phyllochron, "pastMaxAI", pastMaxAI
END SUBROUTINE


SUBROUTINE test_registerZadock
    USE registerZadokModule
    USE crop2mlModules

    CHARACTER(LEN=65)::currentZadokStage = 'MainShootPlus1Tiller'
    CHARACTER(LEN=65)::currentdate = '9/4/2007'
    CHARACTER(LEN=65) ,DIMENSION(:), ALLOCATABLE:: calendarMoments
    CHARACTER(LEN=65), DIMENSION(:), ALLOCATABLE ::calendarDates
    REAL, DIMENSION(:), ALLOCATABLE :: calendarCumuls
    REAL ::cumulTT = 354.582294511779 ,  phase = 2,leafNumber = 4.8854219661087575,&
        cumulTTFromZC_65 = 0,Der = 300.0,slopeTSFLN = 0.9,intTSFLN = 2.6, &
        finalLeafNumber = 8.797582013199484
    INTEGER :: hasZadokStageChanged = 0

    CALL AddToList(calendarCumuls,0.0)
    CALL AddToList(calendarCumuls,112.330110409888)
    CALL AddToList(calendarCumuls,157.969706915664)
    CALL AddToList(calendarCumuls,280.570678654207)

    ALLOCATE(calendarDates(1))
    calendarDates(1)="21/03/2007"
    CALL AddToListChar(calendarDates,"27/03/2007")
    CALL AddToListChar(calendarDates,"30/03/2007")
    CALL AddToListChar(calendarDates,"05/04/2007")
    !print *, calendarDates(3)

    ALLOCATE(calendarMoments(1))
    calendarMoments(1)="Sowing"
    CALL AddToListChar(calendarMoments,'Emergence')
    CALL AddToListChar(calendarMoments, 'EndVernalisation')
    CALL AddToListChar(calendarMoments,'MainShootPlus1Tiller')

    PRINT *, "-----------------------------test_RegisterZadok------------------------"
    CALL Calculate_RegisterZadok(cumulTT,phase,leafNumber,calendarMoments,&
        calendarDates,calendarCumuls,cumulTTFromZC_65, currentdate,Der,&
        slopeTSFLN,intTSFLN, finalLeafNumber,currentZadokStage,&
       hasZadokStageChanged)
    PRINT *, "hasZadokStageChanged =", hasZadokStageChanged, &
        "currentZadokStage =" ,currentZadokStage
    DO I=1, SIZE(calendarCumuls)
        PRINT *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    END DO
END SUBROUTINE

SUBROUTINE test_shootNumber
    USE shootNumberModule
    USE crop2mlModules
    IMPLICIT NONE
    INTEGER :: sowingDensity=288, tillerNumber= 1
    REAL ::leafNumber= 3.34348137255,TargetFertileShoot=600.0, &
        canopyShootNumber=288.0, averageShootNumberPerPlant
    INTEGER, DIMENSION(:) , ALLOCATABLE  ::  leafTillerNumberArray
    REAL,DIMENSION(:), ALLOCATABLE  :: tilleringProfile

    CALL AddToList(tilleringProfile,288.0)

    CALL AddToListInt(leafTillerNumberArray, 1)
    CALL AddToListInt(leafTillerNumberArray, 1)
    CALL AddToListInt(leafTillerNumberArray, 1)
	
    PRINT *, "-----------------------------test_ShootNumber------------------------"
    CALL Calculate_ShootNumber(canopyShootNumber,leafNumber,sowingDensity,&
        TargetFertileShoot, tilleringProfile,leafTillerNumberArray, tillerNumber, &
        averageShootNumberPerPlant)
    PRINT *, "canopyShootNumber =",canopyShootNumber,"tillerNumber =", tillerNumber &
    , "averageShootNumberPerPlant = ", averageShootNumberPerPlant
    PRINT *, "leafTillerNumberArray =" ,leafTillerNumberArray
    PRINT *, "tilleringProfile ", tilleringProfile
END SUBROUTINE

SUBROUTINE test_UpdateCalendar
    USE updateCalendarModule
    USE crop2mlModules

    CHARACTER(LEN=65)::currentdate = '27/3/2007'
    CHARACTER(LEN=65) ,DIMENSION(:), ALLOCATABLE:: calendarMoments
    CHARACTER(LEN=65), DIMENSION(:), ALLOCATABLE ::calendarDates
    REAL, DIMENSION(:), ALLOCATABLE :: calendarCumuls

    REAL ::cumulTT = 112.330110409888 ,  phase = 1
    CALL AddToList(calendarCumuls,0.0)

    ALLOCATE(calendarDates(1))
    calendarDates(1)="21/03/2007"
	
    ALLOCATE(calendarMoments(1))
    calendarMoments(1)="Sowing"

    PRINT *, "-----------------------------test_UpdateCalendar------------------------"
    CALL Calculate_UpdateCalendar( cumulTT,&
        calendarMoments, calendarDates,&
        calendarCumuls,currentdate, phase)
    PRINT *, "phase =", phase
    DO I=1, SIZE(calendarCumuls)
        PRINT *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    END DO
END SUBROUTINE

SUBROUTINE test_updateLeafFlag
    USE updateLeafFlagModule
    USE crop2mlModules

    CHARACTER(LEN=65)::currentdate = '29/4/2007'
    CHARACTER(LEN=65) ,DIMENSION(:), ALLOCATABLE:: calendarMoments
    CHARACTER(LEN=65), DIMENSION(:), ALLOCATABLE ::calendarDates
    REAL, DIMENSION(:), ALLOCATABLE :: calendarCumuls
    REAL ::cumulTT = 741.510096671757 ,  phase = 3, leafNumber = 8.919453833361189,&
        finalLeafNumber = 8.797582013199484
    INTEGER:: hasFlagLeafLiguleAppeared = 0

    CALL AddToList(calendarCumuls,0.0)
    CALL AddToList(calendarCumuls,112.330110409888)
    CALL AddToList(calendarCumuls,157.969706915664)
    CALL AddToList(calendarCumuls,280.570678654207)
    CALL AddToList(calendarCumuls,354.582294511779)
    CALL AddToList(calendarCumuls,378.453152853726)
    CALL AddToList(calendarCumuls,402.042720581446)
    CALL AddToList(calendarCumuls,424.98704708663)
    CALL AddToList(calendarCumuls,467.23305195298)
    CALL AddToList(calendarCumuls,487.544313430698)
    CALL AddToList(calendarCumuls,560.665248444002)
    CALL AddToList(calendarCumuls,646.389617338974)

    ALLOCATE(calendarDates(1))
    calendarDates(1)="21/03/2007"
    CALL AddToListChar(calendarDates,"27/3/2007")
    CALL AddToListChar(calendarDates,"30/3/2007")
    CALL AddToListChar(calendarDates,"5/4/2007")
    CALL AddToListChar(calendarDates,"9/4/2007")
    CALL AddToListChar(calendarDates,"10/4/2007")
    CALL AddToListChar(calendarDates,"11/4/2007")
    CALL AddToListChar(calendarDates,"12/4/2007")
    CALL AddToListChar(calendarDates,"14/4/2007")
    CALL AddToListChar(calendarDates,"15/4/2007")
    CALL AddToListChar(calendarDates,"19/4/2007")
    CALL AddToListChar(calendarDates,"24/4/2007")

    ALLOCATE(calendarMoments(1))
    calendarMoments(1)="Sowing"
    CALL AddToListChar(calendarMoments,"Emergence")
    CALL AddToListChar(calendarMoments,"EndVernalisation")
    CALL AddToListChar(calendarMoments,"MainShootPlus1Tiller")
    CALL AddToListChar(calendarMoments,"FloralInitiation")
    CALL AddToListChar(calendarMoments,"MainShootPlus2Tiller")
    CALL AddToListChar(calendarMoments,"TerminalSpikelet")
    CALL AddToListChar(calendarMoments,"PseudoStemErection")
    CALL AddToListChar(calendarMoments,"MainShootPlus3Tiller")
    CALL AddToListChar(calendarMoments,"1stNodeDetectable")
    CALL AddToListChar(calendarMoments,"2ndNodeDetectable")
    CALL AddToListChar(calendarMoments, "FlagLeafJustVisible")
    PRINT *, "------------------------- Test updateLeafFlag---------------"
    CALL Calculate_UpdateLeafFlag( cumulTT, leafNumber,&
        calendarMoments, calendarDates, calendarCumuls,currentdate,&
        finalLeafNumber, hasFlagLeafLiguleAppeared, phase)
    PRINT *, "hasFlagLeafLiguleAppeared =", hasFlagLeafLiguleAppeared
    PRINT *, "calendarCumuls, CalendarDates,    CalendarMoments"
    DO I=1, SIZE(calendarCumuls)
        PRINT *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    END DO
END SUBROUTINE test_updateLeafFlag


SUBROUTINE test_updatePhase

    USE updatePhaseModule
    USE crop2mlModules
    IMPLICIT NONE
    REAL:: cumulTT = 354.582294511779, leafNumber =  4.620511621863958, &
        cumulTTFromZC_39 = 0, gai = 0.3255196285135,&
        grainCumulTT = 0, dayLength = 12.7433275303389, vernaprog =  1.0532526829571554, &
        minFinalNumber = 6.879410413987549, fixPhyll = 91.2,dse = 105,PFLLAnth = 2.22,&
        Dcd = 100,Dgf = 450, Degfm = 0, maxDL = 15,SLDL = 0.85, pHEADANTH = 1,&
        p = 120,phase = 1,cumulTTFromZC_91 = 0, phyllochron = 91.2, finalLeafNumber
    INTEGER::isVernalizable = 1,hasLastPrimordiumAppeared = 0,switchMaize = 0, isMomentRegistredZC_39 = 0
    LOGICAL:: ignoreGrainMaturation = .FALSE.
    CHARACTER(65) :: choosePhyllUse = "Default"
    PRINT *, "---------------------------- test updatePhase----------------------"
    CALL Calculate_UpdatePhase(cumulTT, leafNumber, cumulTTFromZC_39,&
        isMomentRegistredZC_39, gai, grainCumulTT, dayLength, vernaprog,&
        minFinalNumber, fixPhyll,isVernalizable, dse, PFLLAnth,&
        Dcd, Dgf, Degfm, maxDL, SLDL, ignoreGrainMaturation,&
        pHEADANTH,switchMaize,choosePhyllUse, p, phase, &
        cumulTTFromZC_91, phyllochron,hasLastPrimordiumAppeared, &
        finalLeafNumber)
    PRINT *, "finalLeafNumber =  ", finalLeafNumber
    PRINT *, "Phase =  ", phase
    PRINT *, "hasLastPrimordiumAppeared=  ", hasLastPrimordiumAppeared
END SUBROUTINE

SUBROUTINE test_vernalizationProgress
    USE crop2mlModules
    USE vernalizationProgressModule
    REAL::dayLength = 12.3037621834005,deltaTT = 20.3429985011972,&
        cumulTT =  112.330110409888,leafNumber = 0,minTvern = 0.0,&
        intTvern =  11.0, vAI =  0.015,vBEE = 0.01, minDL = 8.0,maxDL = 15.0, &
        maxTvern =  23.0,pNini = 4.0, aMXLFNO = 24.0, vernaprog =  0.5517254187376879,&
        minFinalNumber = 5.5
    INTEGER::isVernalizable =1
    CHARACTER(LEN=25)::currentdate = '27/3/2007'
    CHARACTER(LEN=25) ,DIMENSION(:), ALLOCATABLE:: calendarMoments
    CHARACTER(LEN=25), DIMENSION(:), ALLOCATABLE ::calendarDates
    REAL, DIMENSION(:), ALLOCATABLE :: calendarCumuls
    CALL AddToList(calendarCumuls,0.0)
    ALLOCATE(calendarDates(1))
    calendarDates(1)="21/03/2007"
    ALLOCATE(calendarMoments(1))
    calendarMoments(1)="Sowing"
    PRINT *, "------------------------- test_vernalizationProgress----------------"
    CALL Calculate_VernalizationProgress(dayLength, deltaTT, cumulTT, &
        leafNumber,calendarMoments, calendarDates, calendarCumuls, &
        minTvern, intTvern, vAI, vBEE, minDL, maxDL, maxTvern, pNini, aMXLFNO, vernaprog,&
         currentdate, isVernalizable, minFinalNumber)
    PRINT *, "minFinalNumber  = ", minFinalNumber
    PRINT *, "vernaprog = ", vernaprog
    DO I=1, SIZE(calendarCumuls)
        PRINT *, calendarCumuls(I), calendarDates(I), calendarMoments(I)
    END DO
END SUBROUTINE

SUBROUTINE test_PhyllSowingDateCorrection
    USE phyllSowingDateCorrectionModule
	IMPLICIT NONE
    INTEGER::sowingDay = 80,sDws = 90, sDsa_sh = 151, sDsa_nh = 200
    REAL:: latitude = 33.069,  rp = 0.003, p = 120, fixPhyll
    PRINT *, "------------------------ test_phyllSowingDateCorrection------------------"
    CALL Calculate_PhyllSowingDateCorrection(sowingDay,latitude,sDsa_sh,rp,sDws,sDsa_nh,p, fixPhyll)
    PRINT *,  "fixPhyll = ", fixPhyll
END SUBROUTINE
