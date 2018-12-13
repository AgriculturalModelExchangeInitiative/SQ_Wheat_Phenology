module crop2mlModules

contains
    function indice(vectorElem, elem)  ! retrieve the index of an element in a vector
	implicit none
        character(len=*), dimension(:):: vectorElem
        integer::iterator, indice
        character(len=*):: elem
        DO iterator= 1, size(vectorElem)
            IF(vectorElem(iterator)==elem) THEN
                indice = iterator
            END IF
        END DO
        return
    end function indice

    function fibonacci(n)  ! calculate fibonacci number
        integer::n, fibonacci,b=1, i, temp
        fibonacci=0
        do i=0, n-1
            temp = fibonacci;
            fibonacci=b;
            b=temp+b;
        end do
        return

    end function fibonacci

    subroutine AddToList(list, element) ! add an element to a real list numbers
        IMPLICIT NONE
        integer :: i, isize
        real, intent(in) :: element
        real, dimension(:), allocatable, intent(inout) :: list
        real, dimension(:), allocatable :: clist
        if(allocated(list)) then
            isize = size(list)
            allocate(clist(isize+1))
            do i=1,isize
                clist(i) = list(i)
            end do

            clist(isize+1) = element

            deallocate(list)
            call move_alloc(clist, list)

        else
            allocate(list(1))
            list(1) = element
        end if
    end subroutine AddToList

    subroutine AddToListInt(list, element) ! add an element to an int list numbers
        IMPLICIT NONE
        integer :: i, isize
        integer, intent(in) :: element
        integer, dimension(:), allocatable, intent(inout) :: list
        integer, dimension(:), allocatable :: clist
        if(allocated(list)) then
            isize = size(list)
            allocate(clist(isize+1))
            do i=1,isize
                clist(i) = list(i)
            end do

            clist(isize+1) = element

            deallocate(list)
            call move_alloc(clist, list)

        else
            allocate(list(1))
            list(1) = element
        end if
    end subroutine AddToListInt


    subroutine AddToListChar(list, element) ! add an element to a char list number

        IMPLICIT NONE

        integer :: i, isize, l
        character(len=*), intent(in) :: element
        character(len=*), dimension(:), allocatable, intent(inout) :: list
        character(len=65), dimension(:), allocatable :: clist


        if(allocated(list)) then
            isize = size(list)
            allocate(clist(isize+1))
            do i=1,isize
                clist(i) = list(i)
            end do
            clist(isize+1) = element

            deallocate(list)
            call move_alloc(clist, list)

        else
            l=1
            allocate(list(l))
            list(l) = element
            !deallocate(list)
            !print *, element
        end if


    end subroutine AddToListChar


end module
