#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
import sys
from os import system
from os import chroot
byxx = "  "
def main():
    t = sys.argv[1]
    print("judging question "+t)
    print("using filename "+t+'.cpp')
    system("g++ -g -o "+t+" "+t+".cpp"+byxx)
    print("Compile Endded")
    print("------------------------------------------------------------------------")
    system("./"+t)
    print("")
    print("------------------------------------------------------------------------")
    print("git committing")
    system("git add -A")
    system("git commit -a -m \"judged question"+t+"\" 1>/dev/null 2>&1")
    system("git push  1>/dev/null 2>&1")
if(__name__ == "__main__"):
    main()