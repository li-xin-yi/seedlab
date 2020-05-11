#!/usr/bin/python3
from sys import argv

_, first, second, third = argv
p1 = bytearray(first,encoding='utf-8')
c1 = bytearray.fromhex(second)
c2 = bytearray.fromhex(third)
p2 = bytearray(x ^ y ^ z for x, y, z in zip(p1, c1, c2))
print(p2.decode('utf-8'))
