#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sys
from os import system
byxx = "  "
def main():
    t = sys.argv[1]
    print("judging question "+t)
    print("using filename "+t+'.cpp')
    system("g++ -g -o "+t+" "+t+".cpp"+byxx)
    print("Compile Endded")
    print("------------------------------------------------------------------------")
    system("./"+t)
    print("git committing")
    system("git commit -a -m \"judged question"+t+"\"")
    system("git push")

if(__name__ == "__main__"):
    main()