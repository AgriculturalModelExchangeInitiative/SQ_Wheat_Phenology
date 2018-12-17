'Test generation'

from phyllochron import *
from math import *
import numpy as np



def test_test_wheat1():
    params= phyllochron(
    pincr = 1.25,
    gai = 0.279874189539498,
    ldecr = 3,
    fixPhyll = 91.2,
    lincr = 8,
    pdecr = 0.4,
     )
    phyllochron_estimated = round(params[0], 2)
    phyllochron_computed = 36.48
    assert (phyllochron_estimated == phyllochron_computed)
    pastMaxAI_estimated = round(params[1], 2)
    pastMaxAI_computed = 0
    assert (pastMaxAI_estimated == pastMaxAI_computed)