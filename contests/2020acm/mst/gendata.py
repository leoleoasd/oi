from random import randint
import sys
import os
import math

filename = sys.argv[1]

n = randint(10,500)
with open("./data/secret/"+filename+".in","w") as f:
    f.write("{}\n".format(n))
    data = [[0 for j in range(0,n)] for i in range(0,n)]
    for i in range(0,n):
        for j in range(0,i):
            data[i][j] = data[j][i] = randint(10,1000)
    for i in range(0,n):
        f.write(" ".join([str(i) for i in data[i]]))
        f.write("\n")

os.system("time ./a.out < ./data/secret/{}.in > ./data/secret/{}.ans".format(filename, filename))
