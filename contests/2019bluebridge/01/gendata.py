from random import randint
import sys
import os
import math

filename = sys.argv[1]

t = randint(1,100)
base = math.sqrt(1e8 / t)
print(base)
base = int(base)
sum = 0
with open("./data/secret/"+filename+".in","w") as f:
    f.write("{}\n".format(t))
    for i in range(0,t):
        n = randint(int((base/2)*0.8),int((base/2)*1.2))
        m = randint(int((base*2)*0.8),int((base*2)*0.8))
        sum = sum + n*m
        w = randint(1,10000000)
        f.write("{} {} {}\n".format(n,m,w))
        tt = m//n
        for j in range(0,n):
            f.write("{} {}\n".format(randint(tt+1, 2*tt), randint(0, 100)))
print(sum)
print(math.log10(sum))
os.system("time ./a.out < ./data/secret/{}.in > ./data/secret/{}.ans".format(filename, filename))