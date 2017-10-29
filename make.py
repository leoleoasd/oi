#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import random
try:
    f = open('mai.in', 'w')
    w=5000
    n=5000
    d=5000
    f.write(str(w)+" "+str(n)+" "+str(d)+" ")
    for i in range(0,d):
        tmp = random.randint(1,5000)
        f.write(str(tmp)+" ")
    f.write("\n")
    for i in range(0,n):
        f.write(str(random.randint(0,5000))+" "+str(random.randint(0,5000))+" "+str(random.randint(0,5000))+" "+"\n")
finally:
    if f:
        f.close()
