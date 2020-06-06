---
title: RSA Encryption and Signature Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Crypto_RSA.pdf

# Task 1

Compile [`Deriving-the-Private-Key.c`](./Deriving-the-Private-Key.c):

```
$ gcc -o Deriving-the-Private-Key Deriving-the-Private-Key.c -lcrypto
$ ./Deriving-the-Private-Key
```

**Note**: Link order matters. Place `-lcrypto` flag at last.

```
public key (0D88C3,E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1)
private key (3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB,E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1)
```
The value of `d` is:

```
3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB
```

# Task 2

First, convert the string to a hex string:

```
$ python -c 'print("A top secret!".encode("hex"))'
4120746f702073656372657421
```

Compile [`encrypt_m.c`](./encrypt_m.c) and run: 

```
$ gcc -o encrypt_m encrypt_m.c -lcrypto
$ ./encrypt_m
Encryption result: 6FB078DA550B2650832661E14F4F8D2CFAEF475A0DF3A75CACDC5DE5CFC5FADC
```

# Task 3

Compile [`decrypt_c.c`](./decrypt_c.c) and run:

```
$ gcc -o decrypt_c decrypt_c.c -lcrypto
$ ./decrypt_c
Decryption result: 50617373776F72642069732064656573
```

decode the hex string into a plain ASCII string:

```
$ python -c 'print("50617373776F72642069732064656573".decode("hex"))'
Password is dees
```

# Task 4

We utilize RSA encryption as signature:


First, get the hex strings of 2 strings:

```
$ python -c 'print("I owe you $2000".encode("hex"))'
49206f776520796f75202432303030
$ python -c 'print("I owe you $3000".encode("hex"))'
49206f776520796f75202433303030
```

Adapte some subtle modification based on [`encrypt_m.c`](./encrypt_m.c) and write [`encrypt_diff.c`](./encrypt_diff.c). Compile and then run:

```
$ gcc -o encrypt_diff encrypt_diff.c -lcrypto
$ ./encrypt_diff
Encryption M1: 16CDC2D574C9FDCF64A9E387F9EF69AB8BF9D6B839ABCDBF617EF41BA12BE37B
Encryption M2: 686126E57A64A817BF54D768ABD615B33ECE1C4D7C8160D3E6645250F3B1C98E
```

# Task 5

Get the hex string from `M`:

```
$ python -c 'print("Launch a missle.".encode("hex"))'
4c61756e63682061206d6973736c652e
```

Compile and run [`verify_sig.c`](./verify_sig.c):

```
$ gcc -o verify_sig verify_sig.c -lcrypto
$ ./verify_sig
Encryption result: 0408FCF5E626B154361F4785251F97C7E41527C95110162A0F906B2F54ACF6E1
Signature: 643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F
Verification fails! 
```

It's not Alice's message.

If a valid `S` happens to be corrupted, even just in one byte, our program will also reject the message.
