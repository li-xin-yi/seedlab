#!/usr/bin/python3
from sys import argv

_, first, second = argv

with open(first, 'rb') as f:
    f1 = f.read()
with open(second, 'rb') as f:
    f2 = f.read()

for i in range(min(len(f1), len(f2))):
    if f1[i] != f2[i]:
        print("different bytes in", hex(i), ": " ,hex(f1[i]) + ' vs ' + hex(f2[i]))