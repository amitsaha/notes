Python classes: basics beyond the absolute basics
-------------------------------------------------

In this article, I will discuss a couple of things about Python's
classes assuming you know what the following does::

    class Point():

        def __init__(self, point):
            self.point = point


To refresh, we define a class ``Point`` which we will use to represent the
co-ordinates of a point in space. We can create an instance of this
class representing a point as follows::

    p1 = Point((1,2,3))

There are two things which you must note:

- I assume that that the point is in a three dimensional space
- You describe the point as a `tuple` (no particular reason)

And you can define `methods` to do stuff with these points (such as
finding the euclidean distance between two points, and such),
etc. You know all of that. Let's start with the things you may not
know.

.. note::

   I am using a Python 3 interactive session. The final program will
   however work on both Python 2 and Python 3.

Informative representation of your point
========================================

Let's get back to creating the representation of a point using the
above class: ``p1=Point((1,2,3))``. Let's see what ``print(p1)`` gives us::

    >>> print(p1)
    <__main__.Point object at 0x7fb123e67dd0>

So it tells us that ``p1`` is a Point object and few other things
which you can ignore. This is exactly what is, an object of ``Point``
class, but *to* Python. What is it to you or your program's user? It
is a point in space. Can we tell the user something more useful? We
sure can. We will have to define a special method, ``__str__()`` in
our class. This is how it will look after adding the method to ``class
Point``::

    class Point():

        def __init__(self, point):
            self.point = point

        def __str__(self):
            return 'Point: {0}'.format(str(self.point))

The ``__str__()`` method above returns a string consisting of a string
representing the point (``str(self.point)``) and a word saying that
it's a point. You may include any other helpful information you may
find relevant here. The only thing you have to keep in mind is that
the return value should be a string. Let's try printing a point object
now::

    >>> print(p1)
    Point: (1, 2, 3)

Much better isn't it? Now your program's user will have no problem in
understanding what ``p1`` is and also makes it easy for you to display
points in your program's output.

Definining custom operators
===========================

One of the basic things that you may want to do when you are working
with points in space is find what is usually known as the euclidean
distance. To refresh, for two points, p1 and p2 having co-ordinates
(x1,y1,z1) and (x2,y2,z2), the distance is calculated as follows (in
Python speak) math.sqrt((x1-x2)**2 + (y1-y2)**2 + (z1-z2)**2) (where
``math.sqrt`` is the square root function defined in the math
module). For our ``Point`` class, you could define a method to do this.
But, how about being able to do something like ``print(p1-p2)`` to
print the distance between the two? This also plays well with our
intuition of distance in 1 dimension (How far is 5 from 2? 5-2 =
3). Let's try doing that with our current code::

    >>> p1=Point((1,2,3))
    >>> p2=Point((1,2,3))
    >>> print(p1-p2)
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
      TypeError: unsupported operand type(s) for -: 'Point' and 'Point'

Of course, Python doesn't have any idea what you want it do when you
ask it to subtract p2 from p1. However, we can tell Python what to do
by adding a new method, ``__sub__()``. After adding this method, the
class looks like this::

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

The ``_sub__`` method basically calculates the euclidean distance and
returns it. The speciality of this method is that when you ask Python
to subtract something from an object of ``Point`` class, it calls this
method and the return value of this method is returned as the result
of the subtraction operation. If you are curious as to which is
``self`` and which is ``other`` in ``__sub__()`` when you ask Python
to evaluate: ``p1-p2``, ``self`` refers to ``p1`` and other refers to ``p2``.

Let's now try subtracting ``p2`` from ``p1`` again::

    >>> p1=Point((1,2,3))
    >>> p2=Point((1,2,3))
    >>> p1-p2
    0.0
    >>> p2=Point((1,2,4))
    >>> p1-p2
    1.0

So, you have basically defined the subtraction operator for objects of
your ``Point`` class. Can you define other mathematical operators in
such a fashion? Sure. Learn all about it `here
<http://docs.python.org/2/reference/datamodel.html#emulating-numeric-types>`__.

Here is the complete program (works with both Python 2 and 3):

.. literalinclude:: code/point.py

You may want to add the logic to your ``__sub__()`` method
so that it checks if the points are of the same dimension. If not,
then print a nice error message instead of printing a traceback.
That's it.
