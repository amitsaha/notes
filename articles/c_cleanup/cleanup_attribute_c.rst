Using the __cleanup__ variable attribute in GCC
-----------------------------------------------

GCC's C compiler allows you to define various `variable attributes
<http://gcc.gnu.org/onlinedocs/gcc/Variable-Attributes.html>`__. One
of them is the ``cleanup`` attribute (which you can also write as
``__cleanup__``) which allows you to define a function to be called when
the variable goes out of scope (for example, before returning from a
function). This is useful, for example to never forget to close a file
or freeing the memory you may have allocated. Next up is a demo
example defining this attribute on an integer variable (which
obviously has no practical value). I am using `gcc (GCC) 4.7.2
20121109` on Fedora 18.

Demo
====

The next code listing declares an integer variable, ``avar`` with the
``cleanup`` attribute set such that the function ``clean_up`` is
called before ``main()`` returns (Line no. 27). 

.. literalinclude:: cleanup_attribute_demo.c
   :language: c
   :emphasize-lines: 12,27
   :linenos:

The ``clean_up`` function above accepts an argument which is an
integer pointer. This is a pointer to the integer variable ``avar``
for which this function is called due to the ``__cleanup__`` attribute
being set. When you compile and execute the program, you should see
the following output::

    $ gcc -Wall cleanup_attribute_demo.c 
    $ ./a.out 
    Cleaning up
    Final value: 5

Download :download:`cleanup_attribute_demo.c`. Next, I will present a hopefull more useful example. 

Cleaning up temporary files
===========================

In your programs, you may need to create one or more temporary files
for some reason. Most likely, you would want to remove them after your
program exits. Defining a ``__cleanup__`` attribute on the ``FILE *`` variable
(assuming stream I/O) and setting it to an appopriate cleanup function
sounds like something which could be put to good use. We don't have to
manually call the cleanup function.

Here is the program:

.. literalinclude:: cleanup_tempfile.c
   :language: c
   :emphasize-lines: 14, 20, 31, 32
   :linenos:

The above program creates a temporary file in the location specified
by ``TMP_FILE``, writes a line of text with no spaces, resets the file
pointer to the beginning and reads it back. In line no.32, I declare a
variable ``fp`` of type ``FILE*`` and define the ``__cleanup__``
attribute such that the function ``cleanup__file`` will be called upon
the return of the ``main()`` function. This function closes the file
and also deletes it from the file system. When you run your program,
you should see the following output::

    Alinewithnospaces
    Closing file
    Deleting the file
    Freeing buffer

If you check the existence of the file specified by ``TMP_FILE``, you
will see that it doesn't exist. Note how I also use define the
``__cleanup__`` attribute on the variable, ``buffer`` to automatically
free memory as well.

Download :download:`cleanup_tempfile.c`.

Resources
=========

I first came across this attribute while reading *Understanding and
Using C Pointers* (`Link to my review
<http://echorand.me/2013/05/14/book-review-understanding-and-using-c-pointers/>`__) where the author discusses `RAII
<http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization#GCC_extensions_for_C>`__. Take
a look at how the ``RAII_VARIABLE`` macro is defined using the
``__cleanup__`` attribute (In case you didn't know, ``##`` is
concatenation in C macros).
