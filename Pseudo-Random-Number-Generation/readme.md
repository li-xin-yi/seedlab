---
title: Pseudo Random Number Generation Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Crypto_Random_Number.pdf

# Task 1

compile [`time_random.c`](./time_random.c) and run:

```
gcc time_random.c -o time_random
./time_random
```

Executing `./time_random` several times, it always gives different results:

![](./diff_time_seed.png)

Because it uses the current time as a random seed to generate random numbers, which guarantee the seed is always different in each run.

Comment out the line [`srand(time(NULL));`](./time_random.c#L11), recompile it and run, the numbers generated are the same now:

![](./same_seed.png)