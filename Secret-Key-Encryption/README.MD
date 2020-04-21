---
title: Secret-Key Encryption Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Crypto_Encryption.pdf

# Task 1

- Step 1: Use the text of [the Gettysburg Address](https://en.wikipedia.org/wiki/Gettysburg_Address) as the original article file [`gettysburg.txt`](./gettysburg.txt). The usage of `tr` is available in [GNU documentations](https://www.gnu.org/software/coreutils/manual/html_node/tr-invocation.html#tr-invocation). `-d` means 'delete' and `-cd` means 'delete the complement of', so first we just keep the letters, spaces, and newlines as the plaintext.
  
```console
$tr [:upper:] [:lower:] < gettysburg.txt > lowercase.txt
$tr -cd '[a-z][\n][:space:]' < lowercase.txt > plaintext.txt
```

- Step 2: Use Python console to generate a permutation of `a-z`:

```python
>>> import random
>>> s = "abcdefghijklmnopqrstuvwxyz"
>>> ''.join(random.sample(s,len(s)))
'azfgmunhrqwetlxicdksjbpvyo'
```

- Step 3: encryption

```console
$tr "abcdefghijklmnopqrstuvwxyz" "azfgmunhrqwetlxicdksjbpvyo" < plaintext.txt > ciphertext.txt
```