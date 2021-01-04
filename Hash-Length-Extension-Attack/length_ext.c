#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <openssl/sha.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int i;
    unsigned char buffer[SHA256_DIGEST_LENGTH];
    SHA256_CTX c;
    char hex[] = "3a286321c4cb101ce172c1377a75a4ccf46ad9ff4fc8680ec582fa1d004da2e2";
    char subbuffer[9];
    SHA256_Init(&c);
    for (i = 0; i < 64; i++)
        SHA256_Update(&c, "*", 1);
    // MAC of the original message M (padded)
    for (i = 0; i < 8; i++)
    {
        strncpy(subbuffer, hex + i * 8, 8);
        subbuffer[8] = '\0';
        c.h[i] = htole32(strtol(subbuffer, NULL, 16));
    }

    // Append additional message
    SHA256_Update(&c, "&download=secret.txt", 20);
    SHA256_Final(buffer, &c);
    for (i = 0; i < 32; i++)
    {
        printf("%02x", buffer[i]);
    }
    printf("\n");
    return 0;
}