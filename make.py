#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import random
try:
    f = open('a.in', 'w')
    n = 100
    q = 1000
    f.write(str(n)+" "+str(q)+"\n")
    a = []
    for i in range(0,n):
        tmp = random.randint(1,1000000)
        a.append(tmp)
        f.write(str(a[-1])+" ")
    f.write("\n")
    print(len(a))
    for i in range(0,q):
        f.write(str(a[random.randint(0,98)])+" "+str(a[random.randint(0,98)])+"\n")
finally:
    if f:
        f.close()