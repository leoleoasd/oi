#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import sys
from os import system
from os import chroot
import time
byxx = "  "
def main():
    t = sys.argv[1]
    print("judging question "+t)
    print("using filename "+t+'.cpp')
    system("g++ -g  -o "+t+" "+t+".cpp"+byxx)
    print("Compile Endded")
    print("------------------------------------------------------------------------")
    #before = time.time()
    system(" ./"+t + " 2>&1")
    #after = time.time()
    print("")
    print("------------------------------------------------------------------------")
    #print("Time: {}".format(after-before))
    #print("git committing")
    #system("git add -A")
    #system("git commit -a -m \"judged question"+t+"\" 1>/dev/null 2>&1")
    #system("git push  1>/dev/null 2>&1")
if(__name__ == "__main__"):
    main()
