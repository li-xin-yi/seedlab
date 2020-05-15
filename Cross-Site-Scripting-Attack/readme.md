---
title: Cross-Site Scripting Attack Lab
author: Xinyi Li
date: \today{}
---

Instruction: https://seedsecuritylabs.org/Labs_16.04/PDF/Web_XSS_Elgg.pdf

# Set-up

2 VMs:

- attacker: `10.0.2.15`
- server: `10.0.2.4`

Edit the record in `etc/host` on the attacker:

```
10.0.2.4       www.xsslabelgg.com
```

Read the file `/etc/apache2/sites-available/000-default.conf`:

```conf
<VirtualHost *:80>
        ServerName http://www.xsslabelgg.com
        DocumentRoot /var/www/XSS/Elgg
</VirtualHost>
```

It shows that the sources of website `http://www.xsslabelgg.com` are hosted in `/var/www/XSS/Elgg`