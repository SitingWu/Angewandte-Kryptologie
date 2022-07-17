#include <stdint.h>
#include <stdio.h>

#define ROTL8(x,shift) ((uint8_t) ((x) << (shift)) | ((x) >> (8 - (shift))))

void initialize_aes_sbox(uint8_t sbox[256]) { 
	uint8_t p = 1, q = 1;
	
	/* loop invariant: p * q == 1 in the Galois field */
	do {
		/* multiply p by 3 */
		p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);

		/* divide q by 3 (equals multiplication by 0xf6) */
		q ^= q << 1;
		q ^= q << 2;
		q ^= q << 4;
		q ^= q & 0x80 ? 0x09 : 0;

		/* compute the affine transformation */
		uint8_t xformed = q ^ ROTL8(q, 1) ^ ROTL8(q, 2) ^ ROTL8(q, 3) ^ ROTL8(q, 4);

		sbox[p] = xformed ^ 0x63;
	} while (p != 1);

	/* 0 is a special case since it has no inverse */
	sbox[0] = 0x63;
}

// //ace_sbox_generator
// int main()
// {
//     uint8_t sbox[256];
//     initialize_aes_sbox(sbox);
//     for (int i=0;i<256;i++)
//     {
// 		if(i%4==0&&i!=0)
// 		printf(", ");	
// 		if(i%16==0 && i!=0)
// 		printf("\n");
// 		if(i%4==0)
// 		printf("0x");
// 	 	printf("%02x",sbox[i]);
		
//    // printf("0x%02x, ",sbox[i-1]);

//     }
//     return 0;
// }

int main()
{
	uint32_t tmp[3]={
		0x637c777b, 0xf26b6fc5, 0x3001672b
	};
	uint8_t *sub;
		sub =tmp;
    
	uint32_t *two;
		two=sub;
		
    for (int i=0;i<8;i++)
    {
	 	printf("%02x ",sub[i]);
		
   // printf("0x%02x, ",sbox[i-1]);

    }	printf(" \n ");
	for(int j=3 ;j>0 ;j--)
	{
		printf("0x%02x ",two[3-j] );
	}

	
    return 0;
}