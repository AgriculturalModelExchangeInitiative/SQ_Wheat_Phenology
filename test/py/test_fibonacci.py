'Test generation'

from fibonacci import *
from math import *
import numpy as np



def test_test1():
    params= fibonacci(
    n = 6,
     )
    value_estimated = params
    value_computed = 8
    assert (value_estimated == value_computed)