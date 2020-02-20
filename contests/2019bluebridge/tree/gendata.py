from random import randint
import random
import sys
import os
filename = sys.argv[1]

with open("./data/secret/" + filename + ".in", "w") as f:
    n = random.randint(0, 1000)
    f.write("{}\n".format(n))
    for i in range(0,n):
        f.write("{} ".format(random.randint()))

os.system("time ./a.out < ./data/secret/{}.in > ./data/secret/{}.ans".format(filename, filename))
