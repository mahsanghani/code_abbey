import numpy as np
from scipy.optimize import minimize, line_search, BFGS, SR1
from numdifftools import Gradient

_small_number = np.sqrt(np.finfo(float).eps)

