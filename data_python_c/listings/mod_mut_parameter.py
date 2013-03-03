#!/usr/bin/env python

""" Passing mutable data objects
and returning a modified version.
"""

from __future__ import print_function

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
    func(l)

    print('After func()')

    print('{0} : {1}'.format(l,id(l)))
    print()
