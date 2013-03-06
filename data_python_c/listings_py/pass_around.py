#!/usr/bin/env python

""" Passing around mutable and immutable data objects
"""

from __future__ import print_function

def func(alist, astr, adict):

    print('In func() before modification')

    print('{0} : {1}'.format(astr,id(astr)))
    print('{0} : {1}'.format(alist,id(alist)))
    print('{0} : {1}'.format(adict,id(adict)))
    print()

    alist.append('func')
    astr = 'b string'
    adict = dict([('python','guido')])

    print('In func() after modification')

    print('{0} : {1}'.format(astr,id(astr)))
    print('{0} : {1}'.format(alist,id(alist)))
    print('{0} : {1}'.format(adict,id(adict)))
    print()


if __name__ == '__main__':
    l = [1,3,4]
    d = {}
    s = 'a string'

    print('Before func()')

    print('{0} : {1}'.format(s,id(s)))
    print('{0} : {1}'.format(l,id(l)))
    print('{0} : {1}'.format(d,id(d)))

    print()

    func(l,s,d)

    print('After func()')

    print('{0} : {1}'.format(s,id(l)))
    print('{0} : {1}'.format(l,id(l)))
    print('{0} : {1}'.format(d,id(d)))
    print()
