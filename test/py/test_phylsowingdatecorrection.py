'Test generation'

from phylsowingdatecorrection import *
from math import *
import numpy as np



def test_test_wheat1():
    params= phylsowingdatecorrection(
    p = 120,
    sowingDay = 80,
    rp = 0.003,
    sDws = 90,
    latitude = 33.069,
    sDsa_nh = 200,
    sDsa_sh = 151,
     )
    fixPhyll_estimated = round(params, 2)
    fixPhyll_computed = 91.2
    assert (fixPhyll_estimated == fixPhyll_computed)