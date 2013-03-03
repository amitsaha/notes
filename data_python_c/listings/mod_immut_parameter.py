#!/usr/bin/env python

""" Passing immutable data objects
and returning a modified version.
"""

from __future__ import print_function


def func(astr):

    print('In func() before modification')
    print('{0} : {1}'.format(astr,id(astr)))
    print()

    astr = astr.replace('a','b')

    print('In func() after modification')
    print('{0} : {1}'.format(astr,id(astr)))
    print()

    # return the new string
    return astr

if __name__ == '__main__':
    s = str('a string')

    print('Before func()')

    print('{0} : {1}'.format(s,id(s)))
    print()

    # since s is an immutbale object, modifications 
    # are not possible without creating a new object
    # with the modified string
    # recieve the modified string back as the
    # return value
    s = func(s)

    print('After func()')

    print('{0} : {1}'.format(s,id(s)))
    print()
