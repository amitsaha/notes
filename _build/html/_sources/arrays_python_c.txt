Passing around Arrays in Python (as compared to C)
--------------------------------------------------

For those of you with a C/C++ background (at some point of time, like
me), passing around Python’s arrays (or lists) to functions can lead
to a little bewilderment. For example, consider the following code
snippet ::

    from array import array

    def func(arr): 
        print('Object Identifier: {0:d}'.format(id(arr))) 
	for i in range(0,len(arr)): 
	    arr[i] = arr[i]**2
    
    if __name__=='__main__':

        arr=array('i',[1,2,3]) 
	print(arr) 
	print('Object Identifier: {0:d}'.format(id(arr))) 
	# results in passing a reference to the 
	# the original array 
	func(arr) 
	print(arr)

When you run the above snippet, it results in the following output ::

    array('i', [1, 2, 3]) 
    Object Identifier: 3075060736 
    Object Identifier: 3075060736 
    array('i', [1, 4, 9])

It is a little surprising here, since the array is invoked in a call
by value manner in C/C++. So why did the original array change? The
answer lies in Python’s mechanism of passing a reference to the
original object (the array object) itself, rather than a copy of it to
the called function. Since, an array is a mutable object, the changes
made to it is reflected in the original array sent. (You may think of
this as equivalent to passing a pointer to the function). This idea of
reference is better understood when you print the identifier of the
array object in the caller and the called functions. As you can see,
both of them are same. 

So, what do you do if you don’t want the changes made to an immutable
object to propagate to the original object? Use the copy module. For
example ::

    import copy 
    from array import array

    def func(arr): 
        print('Object Identifier: {0:d}'.format(id(arr))) 
	for i in range(0,len(arr)): 
	    arr[i] = arr[i]**2
    
    if __name__=='__main__':

        arr=array('i',[1,2,3]) 
	print(arr) 
	print('Object Identifier: {0:d}'.format(id(arr))) 
	# Pass the copy of the original array
        myarr = copy.copy(arr) 
	func(myarr)
	print(arr)

The above code results in the following output ::

    array('i', [1, 2, 3]) 
    Object Identifier: 3075063072 
    Object Identifier: 3075060736 
    array('i', [1, 2, 3])

As can be seen from the object identifiers, they are two separate
objects and hence changes made in the called function is not
propagated to the original object.

Code: https://gist.github.com/3487468

Note that I have used Python 3.3 for the examples.

Some related links:

    http://stackoverflow.com/questions/986006/python-how-do-i-pass-a-variable-by-reference
    http://effbot.org/zone/call-by-object.htm
