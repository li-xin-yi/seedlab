#!/usr/bin/python3
with open('big_file.txt', 'rb') as f:
    f1 = f.read()
with open('decrypted.txt', 'rb') as f:
    f2 = f.read()
res = 0
for i in range(min(len(f1), len(f2))):
    if f1[i] != f2[i]:
        res += 1
print("diff bytes: "+str(res+abs(len(f1)-len(f2))))
