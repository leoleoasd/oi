from random import randint
import sys
import os
import math

filename = sys.argv[1]

n = randint(1,6)
dims = [randint(1, 6) for _ in range(0,n)]
p = [randint(1, i) for i in dims]
m = [randint(1, i) for i in dims]
while p == m:
    m = [randint(1, i) for i in dims]

print(dims, p, m)


def write(f, dims, p, m):
    if len(dims) == 1:
        for i in range(1, dims[-1]+1):
            if p is not None and i == p[-1]:
                c = "P"
            elif m is not None and i == m[-1]:
                c = "M"
            else:
                c = "."
            f.write(c)
        f.write("\n")
    else:
        for i in range(1, dims[-1]+1):
            if p is not None and i == p[-1]:
                pp = p[:-1]
            else:
                pp = None
            if m is not None and  i == m[-1]:
                mm  = m[:-1]
            else:
                mm = None
            write(f, dims[:-1], pp, mm)


with open("./data/secret/"+filename+".in", "w") as f:
    f.write("{}\n".format(n))
    for i in dims:
        f.write("{} ".format(i))
    f.write("\n")
    write(f, dims, p, m)

os.system("time ./a.out < ./data/secret/{}.in > ./data/secret/{}.ans".format(i, i))
