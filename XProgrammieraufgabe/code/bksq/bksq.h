/* 
 * File:   bksq.h
 */
#ifndef ROUNDS
#define ROUNDS 10
#endif

#ifndef BKSQ_H 
#define	BKSQ_H




#include <stdint.h>
   



typedef union {
	uint8_t u8[12];
	uint32_t u32[3];
	} normalkey_t;
	
	
typedef struct{
	normalkey_t k[ROUNDS+1];
	} roundkey_t;

void lineartransformation(uint8_t * plain);
void linearbacktransformation(uint8_t * cyphertext);
void Permutation(uint8_t *plain);
void nonlinearTransformation(uint8_t *text);
void nonlinearbackTransforamtion(uint8_t *text);
void createRoundkeys(uint8_t const *key, roundkey_t *roundkey) ;
void roundkeyaddition(uint8_t *text, roundkey_t *roundkey, uint8_t round);

#endif