---
title: Spectre Attack Lab
author: Xinyi Li
date: \today{}
---

*task 1 and 2 are exactly the same tasks as what in [Meltdown Attack lab](./Meltdown-Attack)*

# Task 3

```
array[97*4096 + 1024] is in cache.
The Secret = 97.
```

Because `97>size`, the statement of Line 2 should not be executed. But actually the program fetches the effects on CPU cache.

After commenting all `_mm_clflush(&size)`,it runs with nothing output. It shows that the program can read any extra information from cache now. The function [`_mm_clflush`](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_clflush&expand=678) flushs all content in caches that contains variable `size`, which ensure the cache is not influenced by `size` during each call of `victim`.


It also fails to give any output. Because when `i>size`, the statement will be not executed actually but still takes up the space of cache in the same way as `victim(97)` do. 
