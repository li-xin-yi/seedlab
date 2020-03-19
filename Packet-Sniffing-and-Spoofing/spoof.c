#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main()
{
    int sd;
    struct sockaddr_in sin;
    char buffer[1024]; // You can change the buffer size

    /* Create a raw socket with IP protocol. The IPPROTO_RAW parameter
    *tells the sytem that the IP header is already included;
    *this prevents the OS from adding another IP header.*/

    sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sd < 0)
    {
        perror("socket() error");
        exit(-1);
    }

    /* This data structure is needed when sending the packets
    * using sockets. Normally, we need to fill out several
    * fields, but for raw sockets, we only need to fill out
    * this one field */
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("10.0.2.4");
    sin.sin_port = htons(9090);

    // Here you can construct the IP packet using buffer[]
    // - construct the IP header ...
    // - construct the TCP/UDP/ICMP header ...
    // - fill in the data part if needed ...
    // Note: you should pay attention to the network/host byte order.
    /* Send out the IP packet.
* ip_len is the actual size of the packet. */
    if (sendto(sd, buffer, 100, 0, (struct sockaddr *)&sin,
               sizeof(sin)) < 0)
    {
        perror("sendto() error");
        exit(-1);
    }
    return 0;
}