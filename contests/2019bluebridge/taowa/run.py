import os
import sys
filename = sys.argv[1]


os.system("time ./a.out < ./data/secret/{}.in > ./data/secret/{}.ans".format(filename, filename))