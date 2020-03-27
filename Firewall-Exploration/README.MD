---
title: Linux Firewall Exploration Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Firewall.pdf

Set up 2 VMs: 
- A: `10.0.2.15`
- B: `10.0.2.4`.

# Task 1

All commands run on the VM `10.0.2.15`, and modify Line 11 in its `/etc/default/ufw` with root privilege (e.g. `sudo vi`/`sudo gedit/sudo nano`+filename or whatever method you like) as:

```
DEFAULT_INPUT_POLICY="ACCEPT"
```

Or simly use the command:

```
sudo ufw default allow incoming
```

Ref to the [manual](http://manpages.ubuntu.com/manpages/xenial/man8/ufw.8.html) and [tutorial](https://help.ubuntu.com/community/UFW) of `ufw`

At first, enable it:

```
sudo ufw enable
```

After configuration, reset it to the installed status and remove added rules:

```
sudo ufw reset
```

## Prevent A from doing `telnet` to Machine B

```
sudo ufw deny out from 10.0.2.15 to 10.0.2.4 port 23
```

## Prevent B from doing `telnet` to Machine A

```
sudo ufw deny in from 10.0.2.4 to 10.0.2.15 port 23
```

## Prevent A from visiting an external web site

Use `ping` or `traceroute` to get one of the host IP address:

```
sudo ufw deny out from 10.0.2.15 to host_ip port 80
```

**Note**: As the [answer](https://askubuntu.com/a/270000) explains, It is impossible to stop the accessing to a domain.