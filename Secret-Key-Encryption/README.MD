---
title: Secret-Key Encryption Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Crypto_Encryption.pdf

# Task 1

- Step 1: Use the text of [the Gettysburg Address](https://en.wikipedia.org/wiki/Gettysburg_Address) as the original article file [`gettysburg.txt`](./gettysburg.txt). The usage of `tr` is available in [GNU documentations](https://www.gnu.org/software/coreutils/manual/html_node/tr-invocation.html#tr-invocation). `-d` means 'delete' and `-cd` means 'delete the complement of', so first we just keep the letters, spaces, and newlines as the plaintext.
  
```
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

- Step 3: Encryption

```
$tr "abcdefghijklmnopqrstuvwxyz" "azfgmunhrqwetlxicdksjbpvyo" < plaintext.txt > ciphertext.txt
```

## Break 

Use http://www.richkni.co.uk/php/crypta/freq.php to analyze the frequency of `ciphertext.txt`, its full report shows as [`analysis.md`](./analysis.md).

By [single letter frequcey](./analysis.md#Letter-frequencies),the letters in ciphertext sorted by frequency are:

```
msaxhdlrgkefpnubjiztywcqvo 
```

Compared with letter frequency rank as  `eothasinrdluymwfgcbpkvjqxz` in modern English (see [Wikipedia](https://en.wikipedia.org/wiki/Letter_frequency))

```
$ tr 'msaxhdlrgkefpnubjiztywcqvo' 'eothasinrdluymwfgcbpkvjqxz' < in.txt > out.txt
```