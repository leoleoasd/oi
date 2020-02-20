from random import randint
import random
import sys
import os
import cyaron

def maketree(l):
    if l == []:
        return None
    root = random.choice(l)
    l.remove(root)
    ls = random.randint(0, len(l))
    left = maketree(l[:ls])
    right = maketree(l[ls:])
    return {'data': root, 'left': left, 'right': right}


def front(node):
    if node is None:
        return []
    ret = [str(node['data'])]
    ret = ret + front(node['left'])
    ret = ret + front(node['right'])
    return ret

def mid(node):
    if node is None:
        return []
    ret = mid(node['left'])
    ret = ret + [str(node['data'])]
    ret = ret + mid(node['right'])
    return ret


filename = sys.argv[1]

t = randint(0, 100)

with open("./data/secret/" + filename + ".in", "w") as f:
    f.write("{}\n".format(t))
    for i in range(0, t):
        n = randint(1, 1000)
        f.write("{}\n".format(n))
        root = maketree(list(range(1, n + 1)))
        f.write(" ".join(front(root)))
        f.write("\n")
        f.write(" ".join(mid(root)))
        f.write("\n")

os.system("time ./a.out < ./data/secret/{}.in > ./data/secret/{}.ans".format(filename, filename))
