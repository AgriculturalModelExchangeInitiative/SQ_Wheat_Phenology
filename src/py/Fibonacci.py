def fibonacci(N):
    a = 0
    b = 1
    for i in range(0,N):
        temp = a
        a = b
        b = temp + b
    return a