/** \file abgabe.c */


// Status Codes

#define BKSQ_ENCRYPT_OK 0 ///< Return value: BKSQ Encryption OK!
#define CTR_OK 0 ///< Return value: Counter Mode OK!

#define INVALID_DATA_LENGTH 1 ///< Error/Return value: data length no good, maybe missing padding
#define INVALID_NONCE_LENGTH 2 ///< Error/Return value: nonce length no good, maybe missing padding 

#define DM_OK 0 ///< Return value: Davies-Meyer-Hash OK!
#define HMAC_OK 0 ///< Return value: HMAC OK!

#define AE_ENC_OK 0 ///< Return value: Authenticated Encryption OK!

// Macros and Constants


#define BLOCKSIZE 96 ///< fix the BLOCKSIZE to 96 bits
#define BLOCKSIZE_BYTE (BLOCKSIZE+7)/8 ///< the BLOCKSIZE in bytes, for convenience only  
#define BLOCKCYPHER_ENCRYPT(in, key, out) bksq_encrypt(in, out, key) ///< dependeny injection, defining the block cypher used



/**
 * A data structure holding all information relevant for en/decryption
 */
typedef struct {
    uint8_t *data; ///< a pointer to the input data
    uint32_t data_length; ///< length of the input data in bits; must be a multiple of the blocklength
    uint8_t const *key; ///< a pointer to the key
    uint8_t const *nonce; ///< a pointer to the nonce to be used for encryption/decryption
    uint8_t nonce_length; ///< the length of the none in bits
} CONTEXT;
    

    


/** The |bksq_encrypt| ist the main method to encrypt a single block of data with the BKSQ algorithm. 
 * Note that we only support 96 bit (12 byte) keys.
 * 
 * @param plain points to a 96 bit (12 byte) input-to-be-encrypted
 * @param cyphertext points to a 96 bit (12 byte) array to receive the output
 * @param key provides the 96 bit (12 byte) key for encryption
 * @returns whether operation was successful
 */
uint8_t bksq_encrypt(uint8_t const * plain, uint8_t * cyphertext, uint8_t const * key) {

    // TODO: put your code for BKSQ-Encryption here.

    return BKSQ_ENCRYPT_OK;
}


   



/**
 * Encrypts/Decrypts data in counter mode. The structure |ctx| holds the relevant data.
 * Note that operation happens \e in place, so input data is overwritten by output!
 * @param ctx The encryption/decryption context.
 * @return Returns 0, if encryption/decryption was successful
 */
uint8_t ctr(CONTEXT const ctx) {
    // sanity checks
    if ((ctx.data_length % BLOCKSIZE) != 0) return INVALID_DATA_LENGTH;
    if (ctx.nonce_length != (BLOCKSIZE / 2)) return INVALID_NONCE_LENGTH;

    // TODO: put your code for Counter-Mode here
	
    return CTR_OK;
}


/**
 * Encrypts data in an authenticated envryption mode, namely Encrypt-then-MAC (EtM)
 * with Counter-Mode Encryption and HMAC
 * The structure |ctx| holds the relevant data.
 * Note that operation happens *in place*, so input data is overwritten by output!
 * @param ctx The encryption context as with ctr()
 * @param tag a buffer to receive the authentication tag
 * @return Returns 0, if encryption/decryption was successful
 */
uint8_t ae_enc(CONTEXT const ctx, uint8_t *tag) {

    // TODO: put your code for EtM here
	
    return CTR_OK | HMAC_OK; 
}


/**
 * hashes given data using the Davies-Meyer-construction
 * @param data a pointer to the data to be hashed
 * @param data_length The length of the data in bits
 * @param hash a pointer to an array for receiving the hash, must be of size |BLOCKSIZE_BYTE| bytes
 * @return Returns 0, if hashing successful
 */
uint8_t dmhash(uint8_t const *data, uint32_t const data_length, uint8_t * hash) {
    // sanity checks
    if ((data_length % BLOCKSIZE) != 0) return INVALID_DATA_LENGTH;
    
	// TODO: put your code for hashing here

    return DM_OK;
}

/**
 * computes a HMAC as in RFC 2104 using the dmhash function
 * @param data a pointer to the data to be hashed
 * @param data_length the length of the data in bits
 * @param key the key to be used for computing HMAC
 * @param tag a pointer to an array for receiving the MAC, must be of size |BLOCKSIZE_BYTE| bytes
 * @param data_prefix either NULL or a pointer to a single block which is prepended to data
 * @return Returns 0, if MACing successful
 */
uint8_t hmac(uint8_t const *data, uint32_t const data_length, uint8_t const *key, uint8_t * tag, uint8_t * data_prefix) {
    
	// TODO: put your code for MACing here

    return HMAC_OK;
}
