---
title: RSA Encryption and Signature Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Crypto_RSA.pdf

# Task 1

Compile [`Deriving-the-Private-Key.c`](./Deriving-the-Private-Key.c):

```
gcc -o Deriving-the-Private-Key Deriving-the-Private-Key.c -lcrypto
```

**Note**: link order matters. Put `-lcrypto` at last.

```
public key (0D88C3,E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1)
private key (3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB,E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1)
```
The value of `d` is:

```
3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB
```