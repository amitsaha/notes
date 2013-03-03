#!/usr/bin/env python
from __future__ import print_function

#immutable data types

int(1)
print('1: {0}'.format(id(1)))

str('string')
print('string: {0}'.format(id('string')))

tuple()
print('tuple: {0}'.format(id(tuple())))

def func():
    a = int(1)
    s = str('string')
    t = tuple()
    print('1: {0}'.format(id(a)))
    print('string: {0}'.format(id(s)))
    print('tuple: {0}'.format(id(t)))

class A:

    def __init__(self):
        self.a = int(1)
        self.s = str('string')
        self.t = tuple()

        print('1: {0}'.format(id(self.a)))
        print('string: {0}'.format(id(self.s)))
        print('tuple: {0}'.format(id(self.t)))

if __name__=='__main__':
    func()
    a = A()
    b = A()
