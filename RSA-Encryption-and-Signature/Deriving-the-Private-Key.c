#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 128

void printBN(char *msg, BIGNUM *a, BIGNUM *b)
{
    char *number_str_a = BN_bn2hex(a);
    char *number_str_b = BN_bn2hex(b);
    printf("%s (%s,%s)\n", msg, number_str_a, number_str_b);
    OPENSSL_free(number_str_a);
    OPENSSL_free(number_str_b);
}

int main()
{
    // init
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *phi = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *res = BN_new();
    BIGNUM *p_minus_1 = BN_new();
    BIGNUM *q_minus_1 = BN_new();

    // assign value
    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");

    // n = pq
    BN_mul(n, p, q, ctx);
    printBN("public key", e, n);

    // phi(n) = (p-1)*(q-1)
    BN_sub(p_minus_1, p, BN_value_one());
    BN_sub(q_minus_1, q, BN_value_one());
    BN_mul(phi, p_minus_1, q_minus_1, ctx);

    // check if e and phi(n) is relatively prime
    BN_gcd(res, phi, e, ctx);
    if (!BN_is_one(res))
    {
        printf("Error: e and phi(n) is not relatively prime \n ");
        exit(0);
    }

    BN_mod_inverse(d, e, phi, ctx);
    printBN("private key", d, n);

    BN_clear_free(p);
    BN_clear_free(q);
    BN_clear_free(n);
    BN_clear_free(res);
    BN_clear_free(phi);
    BN_clear_free(e);
    BN_clear_free(d);
    BN_clear_free(p_minus_1);
    BN_clear_free(q_minus_1);

    return 0;
}
