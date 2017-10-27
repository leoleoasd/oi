#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import random
try:
    f = open('a.in', 'w')
    n = 100
    q = 1000
    f.write(str(n)+" "+str(q)+"\n")
    for i in range(1,n):
        f.write(str(random.randint(1,1000000))+" ")
    f.write("\n")
    for i in range(1,q):
        f.write(str(random.randint(1,1000000))+" "+str(random.randint(1,1000000))+"\n")
finally:
    if f:
        f.close()