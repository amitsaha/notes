from __future__ import print_function
import math

class Point():

    def __init__(self, point):
        self.point = point

    def __str__(self):
        return 'Point: {0}'.format(str(self.point))

    def __sub__(self, other):
        s=0
        for x1,x2 in zip(self.point, other.point):
            s = s + (x1-x2)**2

        return math.sqrt(s)
