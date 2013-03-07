Data in C
---------

In C, the data you define will usually fall into one of the three
basic categories: ``int``, ``char`` and ``float``. Data in C has no
existence without an associated memory location, labelled by an
``identifier``, usually referred to as a `variable` (the term variable
is a bit misleading, since it essentially means that it must always
vary, but you can have `constant variables` - i.e. variables whose
values do not vary). Considering this and C's requirement for static
typing, a `variable declaration` statement is required before data can
be stored in a variable. This declaration statement usually takes the
form of ``data-type var-name [= value]``, where the `=value` part may
or may not be present. For example, the statement ``int a=1;``
declares a variable ``a`` which will store integer data and stores
``1`` in it. What this statment basically tells the C compiler is
that it should allocate a block of memory large enough to store an
integer and it will referred to as ``a``. It is possible to obtain the
address of this memory location using the ``&`` operator.


Listing: address.c ::

    #include <stdio.h>
    int main(int argc, char **argv)
    {
        int a=1;

	printf("Address of a:: %p, Value of a:: %d\n", &a, a);
	return 0;
    }

When you compile and run the above program, you should see an output similar to the following::

Address of a:: 0x7fff0cadd1ac, Value of a:: 1

You should note that, the exact value of this address is immaterial
for us and it will definitely be different for you. Once you have this
address, it is possibly to refer to this memory location without using
the variable, `a`, by making use of the `dereferencing` operator,
``*``.

Listing dereferencing.c ::

    #include <stdio.h>

    int main(int argc, char **argv)
    {
        int a=1;
    	int *ptr;
    
        printf("Address of a:: %p, Value of a:: %d\n", &a, a);

    	ptr = &a;
	*ptr = 2;

	printf("Address of a:: %p, Value of a:: %d\n", ptr, a);
    	
        return 0;
    }


When you compile and execute the above program,  you will see an
output similar to the following::

    Address of a:: 0x7fff85a7f134, Value of a:: 1
    Address of a:: 0x7fff85a7f134, Value of a:: 2

In the above program, we store the address of the variable ``a`` in
the variable ``ptr`` (declared as a integer pointer variable) in the
statement ``ptr=&``. Next, we use the dereferencing operator to change
the value stored at memory location to ``2``. Now, when we retrieve
the value of ``a``, we get back the new value.

Pointers are of course variables themselves, so, you could use the
``&`` and ``*`` operators on them as well. For the purpose of this
article however, we will just be needing `simple` pointers.

Assignment
==========


Assignment statements are copy statements. They store the value of
the variable or the result of the expression on the right hand side 
in the memory location pointed to by the variable on the left hand 
side. 

Any changes to the "original" variable is not reflected in any
other copies of this variable.

this is a no-op statement.
     This is a valid C expression, but there is no visible
     effect of this operation. Unlike Python, data not stored in a
     variable is not stored and hence isn't allocated any memory.

