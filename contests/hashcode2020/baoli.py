import threading
import random
import os
import time

def run():
    while True:
        seed = random.random()
        s = os.popen("./a.out {} < d_tough_choices.txt ".format(seed))
        point = int(s.readline())
        if point > 5031325:
            print(point,seed)

for i in range(0,48):
    t = threading.Thread(target=run, name='LoopThread')
    t.start()

t.join()

# 476353268