def fibonacci(int N):
    cdef int a = 0
    cdef int b = 1
    cdef i, temp
    for i in range(0,N):
        temp = a
        a = b
        b = temp + b
    return a