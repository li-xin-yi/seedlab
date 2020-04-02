---
title: Heartbleed Attack Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Heartbleed.pdf

Set up 2 VMs:

- Attacker: `10.0.2.6`
- Victim/Server: `10.0.2.7`

On the attacker edit one DNS rule:

```
sudo gedit /etc/hosts
```

Replace the line

```
127.0.0.1 www.heartbleedlabelgg.com
```

With

```
10.0.2.7 www.heartbleedlabelgg.com
```


# Task 1

Send a bunch of private messages to Boby.

Then run [attack.py](./attack.py)

```
sudo chmod u+x attack.py
./attack.py www.heartbleedlabelgg.com
```

It might not reveal any secret message in one single run. To get useful data, the program should be executed several times.

![](./hello.png)

![](./test.png)

![](./message_body.png)

