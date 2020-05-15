# Find `snort` rules for XSS attack

## Pre-requirement

Install `snort` on Ubuntu 16.04 (VM provided by seed-project) as

```
sudo apt install snort
```

Edit `/etc/snort/snort.conf` using `sudo gedit /etc/snort/snort.conf`:

```conf
# ipvar HOME_NET any
ipvar HOME_NET 10.0.2.0/16
```

Compose all rules in file `/etc/snort/rules/local.rules`

```
sudo gedit /etc/snort/rules/local.rules
```

Then run it with

```
sudo snort -A console -q -c /etc/snort/snort.conf -i enp0s3.
```

