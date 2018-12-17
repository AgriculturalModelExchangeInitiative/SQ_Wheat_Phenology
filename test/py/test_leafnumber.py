'Test generation'

from leafnumber import *
from math import *
import numpy as np



def test_test_wheat1():
    params= leafnumber(
    phase = 3,
    leafNumber = 5.147163833893262,
    leaf_tip_emerg = 10,
    phyllochron = 91.2,
    switchMaize = 0,
     )
    leafNumber_estimated = round(params[0], 2)
    leafNumber_computed = 5.41
    assert (leafNumber_estimated == leafNumber_computed)
    ntip_estimated = round(params[1], 2)
    ntip_computed = 0
    assert (ntip_estimated == ntip_computed)