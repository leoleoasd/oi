#! /usr/bin/env python3
# -*- coding:utf-8 -*-
def gcd(a,b):
    if a < b:
        c = b;
        b = a;
        a = c;
    if a % b == 0 :
        return b;
    return gcd(b,a%b);

n = int(input())
a = int(input())
b = int(input())
a = gcd(a,b);
for i in range(0,n-2):
    b =  int(input())
    a = gcd(a,b);

print(a);
