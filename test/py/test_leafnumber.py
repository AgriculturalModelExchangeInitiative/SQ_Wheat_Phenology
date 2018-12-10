'Test generation'

from leafnumber import *
from math import *
import numpy as np



def test_test_wheat1():
    params= leafnumber(
    phase = 3,
    leafNumber = 5.147163833893262,
    Leaf_tip_emerg = 10,
    phyllochron = 91.2,
    SwitchMaize = 0,
     )
    leafNumber_estimated = round(params[0], 2)
    leafNumber_computed = 5.41
    assert (leafNumber_estimated == leafNumber_computed)
    Ntip_estimated = round(params[1], 2)
    Ntip_computed = 0
    assert (Ntip_estimated == Ntip_computed)