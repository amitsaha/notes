#!/usr/bin/env python

# mutable data types: dictionary, list.

from __future__ import print_function

dict()
print('dict: {0}'.format(id(dict())))

list()
print('list: {0}'.format(id(list())))

def func():
    d = dict()
    print('dict: {0}'.format(id(d)))
    
    l = list()
    print('list: {0}'.format(id(l)))


class A:

    def __init__(self):
        self.d = dict()
        self.l = list()
        print('dict: {0}'.format(id(self.d)))
        print('list: {0}'.format(id(self.l)))

if __name__=='__main__':
    func()
    a = A()
    b = A()
