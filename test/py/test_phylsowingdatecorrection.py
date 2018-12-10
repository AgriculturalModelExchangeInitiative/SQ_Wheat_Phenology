'Test generation'

from phylsowingdatecorrection import *
from math import *
import numpy as np



def test_test_wheat1():
    params= phylsowingdatecorrection(
    P = 120,
    SowingDay = 80,
    Rp = 0.003,
    SDws = 90,
    Latitude = 33.069,
    SDsa_nh = 200,
    SDsa_sh = 151,
     )
    FixPhyll_estimated = round(params, 2)
    FixPhyll_computed = 91.2
    assert (FixPhyll_estimated == FixPhyll_computed)