import numpy as np 
from copy import copy
from math import *

def fibonacci(n):
    """


    fibonacci function
    Author: Pierre Martre
    Reference:  to write in package
    Institution: INRA Montpellier
    Abstract: see documentation

    """
    value = 0
    b = 1
    for i in range(0,n):
        temp = value
        value = b
        b = temp + b
    return  value
