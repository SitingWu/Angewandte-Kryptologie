#include "bksq.h"
#include <stddef.h>
#include <stdio.h>

void printbase16(uint8_t const * data, size_t const len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}


int main(void){
	
	
uint8_t plain[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
uint8_t theta[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
uint8_t theta_invers[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
uint8_t pi[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
uint8_t gamma[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
uint8_t key[12] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x10, 0x20, 0x30, 0x40};
int i = 0;   
roundkey_t roundkey;



/******************** Round function ************************/  



printf("Testing individual round functions ....\n\n");

printf("Testing Theta with:    ");
printbase16(theta, 12*sizeof(uint8_t));
lineartransformation(theta); // theta
printf("Result after Theta:    ");
printbase16(theta, 12*sizeof(uint8_t));
printf("\n");

printf("Testing Theta^-1 with: ");
printbase16(theta_invers, 12*sizeof(uint8_t));
linearbacktransformation(theta_invers); // theta^-1
printf("Result after Theta^-1: ");
printbase16(theta_invers, 12*sizeof(uint8_t));
printf("\n");

printf("Testing Pi with:       ");
printbase16(pi, 12*sizeof(uint8_t));
Permutation(pi); // pi
printf("Result after Pi:       ");
printbase16(pi, 12*sizeof(uint8_t));
printf("\n");

printf("Testing Gamma with:    ");
printbase16(gamma, 12*sizeof(uint8_t));
nonlinearTransformation(gamma); // gamma
printf("Result after Gamma:    ");
printbase16(gamma, 12*sizeof(uint8_t));
printf("\n\n");

/******************** Key Scheduling ************************/

printf("Testing round keys ....\n\n");
printf("Testing for key:          ");
printbase16(key, 12*sizeof(uint8_t));
createRoundkeys(key, &roundkey);

for (i = 1; i < ROUNDS+1; i++){
	printf("Roundkey for round %2i is: ", i);
	printbase16(roundkey.k[i].u8, 12*sizeof(uint8_t)); 
}
printf("\n\n");
	
	
/******************** One Round ************************/

printf("Testing one complete round ....\n\n");


printf("Round key 1:           ");
printbase16(key, 12*sizeof(uint8_t));
printf("Plaintext:             ");
printbase16(plain, 12*sizeof(uint8_t));
printf("\n");


lineartransformation(plain); // theta
printf("Result after Theta:    ");
printbase16(plain, 12*sizeof(uint8_t));
nonlinearTransformation(plain); // gamma
printf("Result after Gamma:    ");
printbase16(plain, 12*sizeof(uint8_t));
Permutation(plain); // pi
printf("Result after Pi:       ");
printbase16(plain, 12*sizeof(uint8_t));
roundkeyaddition(plain,&roundkey,1); // sigma[k^t]
printf("Result after add key:  ");
printbase16(plain, 12*sizeof(uint8_t));	
	
return 0;
}
