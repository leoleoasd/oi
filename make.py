#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import random
with open('brazil.in', 'w') as f:
    n=300
    m=100
    f.write("0 0 "+str(n)+" "+str(m)+"\n")
    for i in range(0,n+m):
        f.write(str(random.randint(1,100))+" "+str(random.randint(1,100))+"\n")
