self in Python 
---------------

``self`` is a reference to the invoking class instance. Consider
the following code ::

    class Point:
    
        def __init__(self): 
	    print 'Self identifier:: ',id(self)
    

   if __name__ == '__main__': 
        # create an instance of the class 
        p = Point()
        print 'Point object identifier', id(p)

        # create an instance of the class p = Point()
        print 'Point object identifier', id(p)

As you can see, a class (that does nothing) called ``Point`` is defined
and then two objects/instances are created. To verify that
``self`` is really a reference to the invoking object, we print
the identifier for the calling object and ``self``. Unsurprisingly, both are the same.

It is to be noted that it is just a convention to use ``self`` as a
reference to the invoking object. You can use anything else, for
example, ``this`` ::

    class Point:
  
        def __init__(this): 
	    print 'This identifier:: ',id(this)

    if __name__ == '__main__': 
        #create an instance of the class p =
        Point()

        print 'Point object identifier', id(p)
    
        # create an instance of the class p = Point()
	print 'Point object identifier', id(p)
