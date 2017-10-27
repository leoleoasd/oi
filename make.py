#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import random
try:
    f = open('a.in', 'w')
    n = 100
    q = 1000
    for(i in range(1,n)):
        f.write(random.randint(1,1000000)+" ")
    f.write("\n")
    for(i in range(1,q)):
        f.write(random.randint(1,1000000)+" "+random.randint(1,1000000)+"\n")
finally:
    if f:
        f.close()