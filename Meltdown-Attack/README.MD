---
title: Meltdown Attack Lab
author: Xinyi Li
date: \today{}
---

# Task 1

To compile `CacheTime.c` successfully, you should add 2 lines first to resolve the type alias:

```c
#include <stdio.h>
#include <stdint.h>
```

Yes. Obviously, the accesses of `array[3*4096]` and `array[7*4096]` are extremely faster than that of the other elements, even though the access times of each element seems to be randomly various among 10 attempts.

# Task 2

Somehow it always finds the correct secret. So I modify the `CACHE_HIT_THRESHOLD` from 80 to 60, It begins to fail to find the secret with nothing output for a few times.

# Task 3

```txt
[  901.703115] secret data address:f881c000
```

# Task 4

No. I cannot access the kernel memory from user space. After executing the test program, the error message of *Segmentation fault* appears.

# Task 5

It handles the exception and prints

```txt
Memory access violation!
Program continues to execute.
```


# Task 6

Yes, I get the outputs

```txt
Memory access violation!
array[7*4096 + 1024] is in cache.
The Secret = 7.
```


# Task 7

## Taks 7.1

It shows

```
Memory access violation!
```

No useful information output.

## Task 7.2

Add the code in a place between `flushSideChannel()` and `sigsetjmp()`. Anyway, It doesn't work as well.

## Task 7.3

Somehow, it still fails to steal the actual secret value. Even though I tried many times and modified the loop number.

## Task 8

The attack fails.

I find that probably I cannot reproduce the attack according to the instruction. Because in the *lab environment* mentions:

> First, the Meltdown vulnerability is a flaw inside Intel CPUs, so if a student’s machine is an AMD machine, the attack will not work. Second, Intel is working on fixing this problem in its CPUs, so if a student’s computer uses new Intel CPUs, the attack may not work

The virtual machine still relies on the hardwares of my computer **physically**, which is equipped with [the last 10th intel CPU](https://ark.intel.com/content/www/us/en/ark/products/196597/intel-core-i7-1065g7-processor-8m-cache-up-to-3-90-ghz.html):

![Basic info about my computer](./cpu.png)

So I need to do the lab on another computer.



