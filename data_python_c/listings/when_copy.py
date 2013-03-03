#!/usr/bin/env python

from __future__ import print_function
import copy

# Immutable object
a = 1
b = a

# At this stage, a and b both are bound to 1.
# This changes in the next step, since I am now changing the 
# value of b and int is immutable.
b = b**2+5

print(a,b)
print()

# Mutable object
alist = [1,2,3]
blist = alist

# At this stage, alist and blist both are bound to [1,2,3]
# Since a list is mutable, and hence any change to blist is 
# also reflected back in alist

blist.append(4)

print(alist,blist)

# We need to rebind alist, since it has been modified 
# in the append operation above
alist = [1,2,3]

# create a real copy
blist = copy.copy(alist)

# only blist is modified.
blist.append(4)

print(alist,blist)

