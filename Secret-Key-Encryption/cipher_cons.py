#!/usr/bin/python3
from sys import argv

_, first, second, third = argv
p1 = bytearray(first, encoding='utf-8')
padding = 16 - len(p1) % 16  # padding to match the block size as 128 bit
p1.extend([padding]*padding)
IV = bytearray.fromhex(second)
IV_NEXT = bytearray.fromhex(third)
p2 = bytearray(x ^ y ^ z for x, y, z in zip(p1, IV, IV_NEXT))
print(p2.decode('utf-8'), end='')
