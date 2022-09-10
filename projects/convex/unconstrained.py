import numpy as np
from scipy.optimize import minimize, line_search, BFGS, SR1
from numdifftools import Gradient

_small_number = np.sqrt(np.finfo(float).eps)

class DescentAlgorithm:

    def __init__(self, fun,
                 gradient=None,
                 hess=None,
                 nd={},
                 wolfe_c1=1e-4,
                 wolfe_c2=0.1,
                 x_tol=1e-6,
                 f_tol=1e-6,
                 max_iter=50,
                 save_history=False):
        """
        Solver for Gradient-based Descent Algorithms.
        Parameters
        ----------

        fun : callable
            Objective function ``f(x, *args)`` of minimization problem.

        gradient : callable or None, optional
            Gradient of objective function ``gradient(x, *args)``
            of minimization problem. If None, numdifftools Gradient is created. Defaults to None.

        hess : callable or HessianUpdateStrategy, optional
            Hessian of the objective function.
            In Newton method, should be provided as ``hess(x, *args)``, whereas in QuasiNewton methods
            it should be a scipy.optimize.HessianUpdateStrategy instance, Defaults to None.

        nd : dict, optional
            Keyword arguments passed to numdifftools is gradient is not provided.
            Defaults to {}.

        wolfe_c1 : float, optional
            Wolfe line search c1. Defaults to 1e-4.

        wolfe_c2 : float, optional
            Wolfe line search c2. Defaults to 0.1.

        x_tol : float, optional
            Tolerance for advance in x. Defaults to 1e-6.

        f_tol : float, optional
            Tolerance for advance in f(x). Defaults to 1e-6.

        max_iter : int, optional
            Max iterations. Defaults to 50.

        save_history : bool, optional
            Either of not to store history of iterations. Defaults to False.
        """

        self.fun = fun

        if gradient is None:
            self.gradient = Gradient(fun, **nd)
        else:
            self.gradient = gradient

        self.hess = hess
        self.wolfe_coefs = wolfe_c1, wolfe_c2
        self.x_tol = x_tol
        self.f_tol = f_tol
        self.max_iter = max_iter
        self.save_history = save_history
        self.history = []

