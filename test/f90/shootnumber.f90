MODULE shootNumberModule
    USE crop2mlModules
    IMPLICIT NONE

CONTAINS
    SUBROUTINE Calculate_ShootNumber(canopyShootNumber,leafNumber,sowingDensity,&
        targetFertileShoot, tilleringProfile,leafTillerNumberArray, tillerNumber, &
        averageShootNumberPerPlant)

        INTEGER, INTENT(IN):: sowingDensity
        REAL, INTENT(IN)::leafNumber,targetFertileShoot
        INTEGER,DIMENSION(:), ALLOCATABLE, INTENT(INOUT) ::  leafTillerNumberArray
        INTEGER, INTENT(INOUT)::tillerNumber
        REAL, INTENT(INOUT):: canopyShootNumber
        REAL, INTENT(OUT):: averageShootNumberPerPlant
        REAL,DIMENSION(:), ALLOCATABLE, INTENT(INOUT) :: tilleringProfile
        REAL::oldcanopyShootNumber, calc
        INTEGER:: emergedLeaves, shoots, I

        oldcanopyShootNumber = canopyShootNumber
        emergedLeaves = INT(MAX(1, CEILING(leafNumber - 1)))
        shoots = fibonacci(emergedLeaves)
        canopyShootNumber = MIN(shoots * sowingDensity, INT(targetFertileShoot))
        averageShootNumberPerPlant = canopyShootNumber / sowingDensity
        IF (canopyShootNumber /= oldcanopyShootNumber) THEN
            CALL AddToList(tilleringProfile,canopyShootNumber - oldcanopyShootNumber)
        END IF
         tillerNumber = SIZE(tilleringProfile)
        DO I=SIZE(leafTillerNumberArray), CEILING(leafNumber)-1
            CALL AddToListInt(leafTillerNumberArray,tillerNumber)
        END DO
    END SUBROUTINE
END MODULE



