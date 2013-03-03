#!/usr/bin/env python

""" Passing mutable data objects
so that the changes are not propagated
"""

from __future__ import print_function
import copy

def func(alist):

    print('In func() before modification')
    print('{0} : {1}'.format(alist,id(alist)))
    print()

    astr = alist.append('new item')

    print('In func() after modification')
    print('{0} : {1}'.format(alist,id(alist)))
    print()

if __name__ == '__main__':
    l = [1,2,3]

    print('Before func()')

    print('{0} : {1}'.format(l,id(l)))
    print()

    # since l is a mutable object, any changes
    # are automatically propagated to all other bindings
    # hence, we create a *real* copy and send it
    func(copy.copy(l))

    print('After func()')

    print('{0} : {1}'.format(l,id(l)))
    print()
