module shootNumberModule
    use crop2mlModules
    implicit none

contains
    subroutine calculateShootNumber(CanopyShootNumber,leafNumber,SowingDensity,&
        TargetFertileShoot, tilleringProfile,leafTillerNumberArray, TillerNumber, &
        AverageShootNumberPerPlant)

        integer, intent(in):: SowingDensity
        real, intent(in)::leafNumber,TargetFertileShoot


        integer,dimension(:), allocatable, intent(inout) ::  leafTillerNumberArray

        integer, intent(inout)::TillerNumber
        real, intent(inout):: CanopyShootNumber
        real, intent(out):: AverageShootNumberPerPlant
        real,dimension(:), allocatable, intent(inout) :: tilleringProfile

        real::OldCanopyShootNumber, calc
        integer:: EmergedLeaves, Shoots, I

        OldCanopyShootNumber = CanopyShootNumber


        EmergedLeaves = int(max(1, ceiling(leafNumber - 1)))

        Shoots = fibonacci(EmergedLeaves)

        CanopyShootNumber = min(Shoots * SowingDensity, int(TargetFertileShoot))
        AverageShootNumberPerPlant = CanopyShootNumber / SowingDensity

        if (CanopyShootNumber /= OldCanopyShootNumber) then
            calc = CanopyShootNumber - OldCanopyShootNumber
            call AddToList(tilleringProfile,calc)

         end if
         TillerNumber = size(tilleringProfile)


        Do I=size(leafTillerNumberArray), ceiling(leafNumber)-1
            call AddToListInt(leafTillerNumberArray,TillerNumber)
        End Do
    end subroutine
end module



