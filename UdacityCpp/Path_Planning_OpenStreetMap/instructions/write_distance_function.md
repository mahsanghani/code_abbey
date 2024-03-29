As you write A\* search, it will be useful to be able to find the distance between two nodes. This will allow the search
algorithm to find the closest node to the current node. In this exercise, you will write a utility function that finds
the distance between two `RouteModel::Node` objects.

To complete this exercise:

1. Add a `distance` declaration to the `RouteModel::Node` class. This method should take a `Node` object as the
   argument, and it should return a `float`. The `distance` method shouldn't change the object being passed, so you can
   make it a `const` method (add const after the function name).
2. Return the euclidean distance from the current node to the node passed in. Note that for points $(x_1, y_1)$ and $(
   x_2, y_2)$, the euclidean distance is given by $\sqrt((x_1 - x_2)^2 + (y_1 - y_2)^2)$.