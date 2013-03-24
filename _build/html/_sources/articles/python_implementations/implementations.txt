Python Implementations
----------------------
 
In common parlance, Python is used to refer to Python - the
programming language *and* Python - the compiler freely available from
the official `project website`_. These are obviously two different
things. 

CPython
=======

Python, the *programming language* is exactly what it says - a
programming language, noting more. It has a `grammar specification`_, a `data
model`, an `execution model`, etc_. It is a blueprint for the
language. However, Python being a high level language requires a
translator to take care of transforming the program in high level
language to form executable by the underlying computer system. Thus,
nothing stops anyone with the necessary knowledge and armed
with the right tools to write his or her own program which will
recognize a program written in Python, process it and carry out the
instructions laid out in the program. This program
would be called an *implementation* of the Python language. This is
exactly what Python - the compiler available from the project website
is. This implementation is the default (reference) implementation of the Python
programming language and is written in C. Hence, it is also referred
to as `CPython`. With other production quality Python
implementation existing, it is a good idea to make it a habit to refer
to it as `CPython`, rather than Python to distinguish it from Python,
the programming language.

CPython currently supports both Python 2 and Python 3 language
specifications and is available for Mac OS/X, Linux, Windows and other
Unix-es.
 
Now that we know what CPython is, let's look at the other production
quality Python implementations.

Jython
======

`Jython`_ is a Python implementation written in Java. The CPython
implementation's compiler compiles a Python program into bytecodes
executable by the CPython virtual machine. `Jython` on the other hand
generates bytecodes for the Java virtual machine from the Python
language program (just as a Java program when compiled is translated
into bytecodes for the JVM). 

An interesting aspect of Jython is tha you can use Java's standard
libraries in your Python programs. For example, you could use Java Swing
to write a GUI application in Jython.

Jython currently implements the Python 2 language specification with
the latest release (as of 04-March, 2013) being Jython 2.7 beta 1(to match with Python 2.7). Since
it is written in Java, it is available on all platforms capable of
running Java and needs the Java run-time to be available for its functioning.


IronPython
==========

`IronPython`_ is an implementation of Python which runs on the `.NET`_
framework. Specifically, IronPython is built on top of the DLR
(`Dynamic Language Runtime`_), which is again built upon the CLR
(`Common language Runtime`_`). What all this effectively means is that
Python code when built upon IronPython have access to the .NET
libraries in addition to its own features and libraries.

As of 04-March-2013, the last release of IronPython was
2.7.3. IronPython is available for Windows and on Linux (via
`Mono`_).

PyPy
====

`PyPy`_ is an implementation of Python, written in a restricted proper
subject of Python, `RPython`. I will not go into any further details
about the implementation here, since that is out of scope for this
article.

As of this writing PyPy is compatible with Python 2.7.2 and supports
most of the standard library modules. PyPy is available for Linux, Mac
OS/X and Windows.

Others
======

In this article, we have learnt about the major Python
implementations. There are many more at varying stages of
development listed on the Python wiki page_.


.. _`project website`: http://www.python.org
.. _`grammar specification`: http://docs.python.org/3/reference/grammar.html
.. _etc: http://docs.python.org/3/reference/index.html
.. _`PyPy`: http://pypy.org/
.. _`Jython`: http://jython.org/
.. _`IronPython`: http://ironpython.net/
.. _`NET`: http://en.wikipedia.org/wiki/.NET_Framework
.. _`Dynamic Language Runtime`: http://en.wikipedia.org/wiki/Dynamic_Language_Runtime
.. _`Common Language Runtime`: http://en.wikipedia.org/wiki/Common_Language_Runtime
.. _`Mono`: http://www.mono-project.com/Python
.. _page: http://wiki.python.org/moin/PythonImplementations
