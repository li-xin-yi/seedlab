/* Allocate memory for the response, size is 1 byte
* message type, plus 2 bytes payload length, plus
* payload, plus padding
*/

unsigned int payload;
unsigned int padding = 16; /* Use minimum padding */
// Read from type field first
hbtype = *p++;
 /* After this instruction, the pointer
 p will point to the payload_length field */

// Read from the payload_length field
// from the request packet

n2s(p, payload); 

/* Function n2s(p, payload) reads 16 bits
* from pointer p and store the value
* in the INT variable "payload". */
pl = p;        // pl points to the beginning of the payload content
if (hbtype == TLS1_HB_REQUEST)
{
    unsigned char *buffer, *bp;
    int r;
    /* Allocate memory for the response, size is 1 byte
    * message type, plus 2 bytes payload length, plus
    * payload, plus padding
    */
    buffer = OPENSSL_malloc(1 + 2 + payload + padding);
    bp = buffer;
    // Enter response type, length and copy payload
    *bp++ = TLS1_HB_RESPONSE;
    s2n(payload, bp);
    // copy payload
    memcpy(bp, pl, payload); 
    /* pl is the pointer which
    * points to the beginning
    * of the payload content */
    bp += payload;
    // Random padding
    RAND_pseudo_bytes(bp, padding);
    // this function will copy the 3+payload+padding bytes
    // from the buffer and put them into the heartbeat response
    // packet to send back to the request client side.
    OPENSSL_free(buffer);
    r = ssl3_write_bytes(s, TLS1_RT_HEARTBEAT, buffer,
                         3 + payload + padding);
}
