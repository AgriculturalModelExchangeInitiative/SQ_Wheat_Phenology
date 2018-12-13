
    !use crop2mlModules

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




