Data in C
---------

In C, the data you define will usually fall into one of the three
basic categories: ``int``, ``char`` and ``float``. Data in C has no
existence without an associated memory location, labeled by an
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

	printf("Address of a:: %p, Data in a:: %d\n", &a, a);

	return 0;
    }

When you compile and run the above program, you should see an output similar to the following::


Address of a:: 0x7fff0cadd1ac, Data at a:: 1


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
    
        printf("Address of a:: %p, Data in a:: %d\n", &a, a);

    	ptr = &a;
	*ptr = 2;

	printf("Address of a:: %p, Data in a:: %d\n", ptr, a);
    	
        return 0;
    }


When you compile and execute the above program,  you will see an
output similar to the following::

    Address of a:: 0x7fff85a7f134, Data in a:: 1
    Address of a:: 0x7fff85a7f134, Data in a:: 2

In the above program, we store the address of the variable ``a`` in
the variable ``ptr`` (declared as a integer pointer variable) in the
statement ``ptr=&``. Next, we use the dereferencing operator to change
the integer stored at memory location to ``2``. Now, when we retrieve
the data stored at ``a``, we get back the new integer.

Pointers are of course variables themselves and hence you could use the
``&`` and ``*`` operators on them as well. For the purpose of this
article however, we will just be needing pointers to non-pointer
variables.

Pointers are of course variables themselves, so, you could use the
``&`` and ``*`` operators on them as well. For the purpose of this
article however, we will just be needing `simple` pointers.

Assignment
==========

The declaration statement ``int a=1`` also includes an optional
`assignment` operation. It is not mandatory to assign a value while
declaring a variable. Thus, the above statement can be broken down to
two statements::

    int a;
    a=1;

The second statement is an assignment statement and the ``=`` is known
as the assignment operator. In C's terminology, the term on the left
hand side is called the `lvalue` and the term on the right hand-side
is called the `rvalue`. The `lvalue` must itself be a memory location
or an identifier identifying a valid memory location and must be
capable of storing new data. Thus, a variable initially declared
as a ``const`` cannot be used as a `lvalue`. The `rvalue` should
itself be data of the same type as the `lvalue` or an `expression` which
evaluates to it. (I hope to discuss `lvalue` and `rvalue` will be discussed in a later
article.)

The main point to note here is that assignment is simply the copying
of data on the right hand side into the memory location pointed to by
the left hand side (either using a variable name or using the direct
memory location). You can use the assignment operator on variables
which store numbers and single characters. For arrays, except during
declaration, you have to use specialized functions (in case of
strings) or assign each a value to each element individually.

The next code listing illustrates assignment operation and presents a
few other related ideas.

Listing: mut_data.c ::

/* Variables are by default mutable.

   Two variables occupy different locations in memory even if
   they may be storing the same data.

 */
# include <stdio.h>

int a = 1;

int main(int argc, char **argv)
{
  int b;

  /*Copy the value stored in a to b*/
  b = a;

  /* A no-op operation*/
  2;

  /* The & operator expects an 'lvalue' as an operand, and hence
     the following statement will result in a compilation error. 
   */
  /*printf("Address of 2 %p\n", &2);*/

  printf("Address of a: %p, Address of b: %p\n", &a, &b);
  printf("a = %d b = %d \n",a,b);

  /* Change value stored in the memory location identified as a.
   */
  a = 2;

  printf("Address of a: %p, Address of b: %p\n", &a, &b);
  printf("a = %d b = %d \n",a,b);

  return 0;
}
=======

Assignment statements are copy statements. They store the value of
the variable or the result of the expression on the right hand side 
in the memory location pointed to by the variable on the left hand 
side. 

Any changes to the "original" variable is not reflected in any
other copies of this variable.

This is a valid C expression, but there is no visible
effect of this operation. Unlike Python, data not stored in a
variable is not stored and hence isn't allocated any memory.



Listing: immut_data.c

# include <stdio.h>


int main(int argc, char **argv)
{
  int a = 1;
  const int b = a;

  /* Even though this is the same value as already stored in a,
     this is not known to the compiler at compile time. Hence, the
     following statement will result in a compile time error*/
  /*b = a;*/

  printf("Address of a: %p, Address of b: %p\n", &a, &b);
  printf("a = %d b = %d \n",a,b);

  return 0;
}

Function parameters
-------------------


*call by value* and *call by reference*

call an array by value

Conclusion
----------


