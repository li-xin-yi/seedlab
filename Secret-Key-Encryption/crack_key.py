#!/usr/bin/python3
from sys import argv
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

_, first, second, third = argv

assert len(first) == 21
data = bytearray(first, encoding='utf-8')
ciphertext = bytearray.fromhex(second)
iv = bytearray.fromhex(third)

with open('./words.txt') as f:
    keys = f.readlines()

for k in keys:
    k = k.rstrip('\n')
    if len(k) <= 16:
        key = k + '#'*(16-len(k))
        cipher = AES.new(key=bytearray(key,encoding='utf-8'), mode=AES.MODE_CBC, iv=iv)
        guess = cipher.encrypt(pad(data, 16))
        if guess == ciphertext:
            print("find the key:",key)
            exit(0)

print("cannot find the key!")
