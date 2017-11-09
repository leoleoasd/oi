#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import random
with open('china.in', 'w') as f:
    s=2000000000
    n=500000
    f.write(str(s)+" "+str(n)+"\n")
    now = 0
    for i in range(0,n):
        step = random.randint(0,100)
        pos = random.randint(1,5)

        f.write(str(now+pos)+" "+str(now+pos+step)+" "+str(random.randint(1,5))+"\n")
        now = now+pos+step
