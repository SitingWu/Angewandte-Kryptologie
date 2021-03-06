/** \file main.c */

/** 
 * \mainpage Programmieraufgabe
 * 
 * Die Aufgabe besteht aus vier Teilen:
 * -# Implementierung der Blockchiffre BKSQ (nur Verschlüsselung) des Blockmodus und des Counter-Modes.
 * -# Implementierung einer Hashfunktion als Davies-Meyer-Struktur mit \ref BKSQ und darauf aufbauend eines HMAC.
 * -# Implementierung einer Authenticated Encryption mit den ersten beiden Aufgaben.
 * -# Variation des Hashes und finden einer Kollision (optional).
 * 
 *
 * Die detaillierte Spezifikation findet sich in der Angabe. 
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h> // memset
#define PRINTSTRING(m) printf("%s",m) ///< String printing if normal PC is targeted
#define PRINTSTRINGINT(m,i) printf("%s%d",m,i) ///< String and int printing if normal PC is targeted
#define PRINTCHAR(c) printf("%c",c) ///< Char printing if normal PC is targeted

#define ERRMSG "\n~~~~~~~~~~~~~~~.++.~~~~~~~~~~~~~~~\nGroß ist seines Laufes Schnelle;\nAber ach, die Kammerschwelle\nIst ihm äußerst hinderlich.\nkurz gesagt: das stimmt noch nicht\n(frei nach Willhelm Busch)\n~~~~~~~~~~~~~~~.++.~~~~~~~~~~~~~~~\n" ///< A nice error message by Markus Wamser



#include "abgabe.c" ///< ja - das ist sehr haesslich, aber fuer moodle noetig!

/**
 *  The main function, demonstrating the calling of our functions
 */
// #define n 0x11B  //Koefizienten für Rijndael_Darstellung




int main(int argc, char** argv) {

    
    /* single test for the blockcipher
     */
    PRINTSTRING("Teste BKSQ...  ");

    uint8_t data[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    uint8_t key[12] = {0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4};
    uint8_t check[12] = {0x89, 0xf3, 0x73, 0x81, 0x95, 0x6f, 0xc5, 0xb5, 0xa7, 0xed, 0x1f, 0xa7};
    uint8_t result[12];

    bksq_encrypt(data, result, key);

    char * msg = "OK!";

    int i;

    for (i = 0; i < 12; i++) {

        if (result[i] != check[i]) {
            msg = ERRMSG;
            break;
		}
    }

    PRINTSTRING(msg);
    PRINTSTRING("\n");

  

    /* test for counter mode
     */
    PRINTSTRING("Teste CTR-Mode... ");

    uint8_t test[144] = {0x48, 0x65, 0x72, 0x7a, 0x6c, 0x69, 0x63, 0x68, 0x65, 0x6e, 0x20, 0x47, 0x6c, 0x75, 0x65, 0x63, 0x6b, 0x77, 0x75, 0x6e, 0x73, 0x63, 0x68, 0x2c, 0x20, 0x69, 0x68, 0x72, 0x20, 0x43, 0x54, 0x52, 0x2d, 0x4d, 0x6f, 0x64, 0x65, 0x20, 0x73, 0x63, 0x68, 0x65, 0x69, 0x6e, 0x74, 0x20, 0x7a, 0x75, 0x20, 0x66, 0x75, 0x6e, 0x6b, 0x74, 0x69, 0x6f, 0x6e, 0x69, 0x65, 0x72, 0x65, 0x6e, 0x21, 0x20, 0x53, 0x69, 0x65, 0x20, 0x6b, 0x6f, 0x65, 0x6e, 0x6e, 0x65, 0x6e, 0x20, 0x49, 0x68, 0x72, 0x65, 0x6e, 0x20, 0x43, 0x6f, 0x64, 0x65, 0x20, 0x6a, 0x65, 0x74, 0x7a, 0x74, 0x20, 0x65, 0x69, 0x6e, 0x72, 0x65, 0x69, 0x63, 0x68, 0x65, 0x6e, 0x2e, 0x20, 0x55, 0x6e, 0x64, 0x20, 0x64, 0x61, 0x6e, 0x61, 0x63, 0x68, 0x3a, 0x20, 0x41, 0x75, 0x66, 0x20, 0x7a, 0x75, 0x72, 0x20, 0x6e, 0x61, 0x65, 0x63, 0x68, 0x73, 0x74, 0x65, 0x6e, 0x20, 0x41, 0x75, 0x66, 0x67, 0x61, 0x62, 0x65, 0x21, 0x00};
    uint8_t input[144] = {0x56, 0x2b, 0x8b, 0x39, 0x18, 0xd0, 0x49, 0x03, 0xc5, 0x01, 0x76, 0x16, 0xe8, 0xd8, 0xa9, 0x96, 0x46, 0xa8, 0xeb, 0x4b, 0x38, 0x47, 0x5f, 0xda, 0x18, 0xaa, 0xc7, 0x82, 0x9c, 0x0a, 0x3f, 0xba, 0x53, 0x71, 0xe3, 0x33, 0x09, 0x8e, 0x6b, 0x3f, 0x6d, 0xe3, 0xa7, 0x06, 0xca, 0xa1, 0xd1, 0xf4, 0xdc, 0xe0, 0xbc, 0xe8, 0x8a, 0x83, 0x2f, 0x54, 0xe5, 0x3b, 0xce, 0x2c, 0x0a, 0x51, 0x39, 0xfb, 0x9e, 0x27, 0x4e, 0xdd, 0x3a, 0x23, 0xe6, 0x40, 0xc4, 0x1c, 0x2c, 0x49, 0x90, 0xdb, 0x86, 0x6b, 0xf5, 0x26, 0x52, 0xe9, 0x84, 0x35, 0xdb, 0x75, 0xb8, 0x02, 0x09, 0x5c, 0x30, 0x6b, 0xa8, 0xb9, 0x65, 0xde, 0xde, 0x9e, 0x06, 0x50, 0x2b, 0x95, 0xab, 0xb0, 0xfc, 0xbc, 0xf7, 0x32, 0x66, 0xdf, 0xf4, 0xd5, 0x8b, 0xe0, 0xfc, 0x5a, 0xd0, 0x2f, 0x0d, 0xda, 0x6e, 0xe5, 0x31, 0xaa, 0x34, 0xf3, 0x46, 0x99, 0x2d, 0xb4, 0x2a, 0x0b, 0x4e, 0x9c, 0xce, 0x5c, 0x37, 0x35, 0x52, 0x66, 0x8c, 0x39};
    uint8_t ctrkey[12] = {0x6f, 0x68, 0x20, 0x73, 0x6f, 0x20, 0x73, 0x65, 0x63, 0x72, 0x65, 0x74};
    uint8_t nonce[6] = {0x75, 0x6e, 0x69, 0x71, 0x75, 0x65};

    CONTEXT ctx = {.data = input, .data_length = 144 * 8, .key = ctrkey, .nonce = nonce, .nonce_length = 6 * 8};
    int ret = ctr(ctx);
    if (ret != 0) PRINTSTRINGINT("Error: ", ret);

    msg = "OK!";
    for (i = 0; i < 144; i++) {
        //PRINTCHAR(ctx.data[i]);
        //printf("0x%02x, ", ctx.data[i]);
        if (ctx.data[i] != test[i]) {
            msg = ERRMSG;
            break;
        }
    }
    PRINTSTRING(msg);

    /* Testing the Davies-Meyer construction
     */
    PRINTSTRING("\n");
    PRINTSTRING("Teste Davies-Meyer...  ");
    msg = "OK!";
    uint8_t testdm[144] = {0x56, 0x2b, 0x8b, 0x39, 0x18, 0xd0, 0x49, 0x03, 0xc5, 0x01, 0x76, 0x16, 0xe8, 0xd8, 0xa9, 0x96, 0x46, 0xa8, 0xeb, 0x4b, 0x38, 0x47, 0x5f, 0xda, 0x18, 0xaa, 0xc7, 0x82, 0x9c, 0x0a, 0x3f, 0xba, 0x53, 0x71, 0xe3, 0x33, 0x09, 0x8e, 0x6b, 0x3f, 0x6d, 0xe3, 0xa7, 0x06, 0xca, 0xa1, 0xd1, 0xf4, 0xdc, 0xe0, 0xbc, 0xe8, 0x8a, 0x83, 0x2f, 0x54, 0xe5, 0x3b, 0xce, 0x2c, 0x0a, 0x51, 0x39, 0xfb, 0x9e, 0x27, 0x4e, 0xdd, 0x3a, 0x23, 0xe6, 0x40, 0xc4, 0x1c, 0x2c, 0x49, 0x90, 0xdb, 0x86, 0x6b, 0xf5, 0x26, 0x52, 0xe9, 0x84, 0x35, 0xdb, 0x75, 0xb8, 0x02, 0x09, 0x5c, 0x30, 0x6b, 0xa8, 0xb9, 0x65, 0xde, 0xde, 0x9e, 0x06, 0x50, 0x2b, 0x95, 0xab, 0xb0, 0xfc, 0xbc, 0xf7, 0x32, 0x66, 0xdf, 0xf4, 0xd5, 0x8b, 0xe0, 0xfc, 0x5a, 0xd0, 0x2f, 0x0d, 0xda, 0x6e, 0xe5, 0x31, 0xaa, 0x34, 0xf3, 0x46, 0x99, 0x2d, 0xb4, 0x2a, 0x0b, 0x4e, 0x9c, 0xce, 0x5c, 0x37, 0x35, 0x52, 0x66, 0x8c, 0x39};
    uint8_t hash[12];
    uint8_t checkdm[12] = {0xb7, 0x41, 0x17, 0xd9, 0x98, 0xf8, 0xc7, 0xb9, 0xa9, 0xc5, 0x7c, 0x47};
    dmhash(testdm, 144 * 8, hash);
    for (i = 0; i < 12; i++) {
        if (hash[i] != checkdm[i]) {
            msg = ERRMSG;
            break;
        }
    }

    PRINTSTRING(msg);

	/* Testing the HMAC
     */
    PRINTSTRING("\n");
    PRINTSTRING("Teste HMAC...  ");
    msg = "OK!";
    uint8_t testhmac[144] = {0x56, 0x2b, 0x8b, 0x39, 0x18, 0xd0, 0x49, 0x03, 0xc5, 0x01, 0x76, 0x16, 0xe8, 0xd8, 0xa9, 0x96, 0x46, 0xa8, 0xeb, 0x4b, 0x38, 0x47, 0x5f, 0xda, 0x18, 0xaa, 0xc7, 0x82, 0x9c, 0x0a, 0x3f, 0xba, 0x53, 0x71, 0xe3, 0x33, 0x09, 0x8e, 0x6b, 0x3f, 0x6d, 0xe3, 0xa7, 0x06, 0xca, 0xa1, 0xd1, 0xf4, 0xdc, 0xe0, 0xbc, 0xe8, 0x8a, 0x83, 0x2f, 0x54, 0xe5, 0x3b, 0xce, 0x2c, 0x0a, 0x51, 0x39, 0xfb, 0x9e, 0x27, 0x4e, 0xdd, 0x3a, 0x23, 0xe6, 0x40, 0xc4, 0x1c, 0x2c, 0x49, 0x90, 0xdb, 0x86, 0x6b, 0xf5, 0x26, 0x52, 0xe9, 0x84, 0x35, 0xdb, 0x75, 0xb8, 0x02, 0x09, 0x5c, 0x30, 0x6b, 0xa8, 0xb9, 0x65, 0xde, 0xde, 0x9e, 0x06, 0x50, 0x2b, 0x95, 0xab, 0xb0, 0xfc, 0xbc, 0xf7, 0x32, 0x66, 0xdf, 0xf4, 0xd5, 0x8b, 0xe0, 0xfc, 0x5a, 0xd0, 0x2f, 0x0d, 0xda, 0x6e, 0xe5, 0x31, 0xaa, 0x34, 0xf3, 0x46, 0x99, 0x2d, 0xb4, 0x2a, 0x0b, 0x4e, 0x9c, 0xce, 0x5c, 0x37, 0x35, 0x52, 0x66, 0x8c, 0x39};
    uint8_t hmackey[12] = {0x6f, 0x68, 0x20, 0x73, 0x6f, 0x20, 0x73, 0x65, 0x63, 0x72, 0x65, 0x74};
	uint8_t tag[12];
	uint8_t checkMAC[12] = {0x6f,0x93,0x2a,0x40,0xba,0xdd,0x79,0xca,0xf4,0x1d,0xb0,0xb1};

	hmac(testhmac, 144 * 8, hmackey, tag, NULL);
    for (i = 0; i < 12; i++) {
        if (tag[i] != checkMAC[i]) {
            msg = ERRMSG; 
        break;}
    }
    PRINTSTRING(msg);

	memset(tag,0,12);
    PRINTSTRING("\n");
    PRINTSTRING("Teste mit Prefix...  ");

	msg = "OK!";
		
	hmac(testhmac+12, 132 * 8, hmackey, tag, testhmac);
    for (i = 0; i < 12; i++) {
        if (tag[i] != checkMAC[i]) {
            msg = ERRMSG; 
        break;}
    }
    PRINTSTRING(msg);

	/* Testing Authenticated Encryption
     */
    PRINTSTRING("\n");
    PRINTSTRING("Teste Authenticated Encryption...  ");
    msg = "OK!";
    uint8_t aetest[144] = {0x56, 0x2b, 0x8b, 0x39, 0x18, 0xd0, 0x49, 0x03, 0xc5, 0x01, 0x76, 0x16, 0xe8, 0xd8, 0xa9, 0x96, 0x46, 0xa8, 0xeb, 0x4b, 0x38, 0x47, 0x5f, 0xda, 0x18, 0xaa, 0xc7, 0x82, 0x9c, 0x0c, 0x1f, 0xa5, 0x53, 0x71, 0xe3, 0x33, 0x09, 0x8e, 0x6b, 0x3f, 0x6d, 0xe3, 0xa7, 0x06, 0xca, 0xa1, 0xd1, 0xf4, 0xdc, 0xe0, 0xbc, 0xe8, 0x8a, 0x83, 0x2f, 0x54, 0xe5, 0x3b, 0xce, 0x2c, 0x0a, 0x51, 0x39, 0xfb, 0x9e, 0x27, 0x4e, 0xdd, 0x3a, 0x23, 0xe6, 0x40, 0xc4, 0x1c, 0x2c, 0x49, 0x90, 0xdb, 0x86, 0x6b, 0xf5, 0x26, 0x52, 0xe9, 0x84, 0x35, 0xdb, 0x75, 0xb8, 0x02, 0x09, 0x5c, 0x30, 0x6b, 0xa8, 0xb9, 0x65, 0xde, 0xde, 0x9e, 0x06, 0x50, 0x2b, 0x95, 0xab, 0xb0, 0xfc, 0xbc, 0xf7, 0x32, 0x66, 0xdf, 0xf4, 0xd5, 0x8b, 0xe0, 0xfc, 0x5a, 0xd0, 0x2f, 0x0d, 0xda, 0x6e, 0xe5, 0x31, 0xaa, 0x34, 0xf3, 0x46, 0x99, 0x2d, 0xb4, 0x2a, 0x0b, 0x4e, 0x9c, 0xce, 0x5c, 0x37, 0x35, 0x52, 0x66, 0x8c, 0x39};
    uint8_t aekey[12] = {0x6f, 0x68, 0x20, 0x73, 0x6f, 0x20, 0x73, 0x65, 0x63, 0x72, 0x65, 0x74};
    uint8_t aenonce[6] = {0x75, 0x6e, 0x69, 0x71, 0x75, 0x65};
    uint8_t aetag[12];
    uint8_t aecheckMAC[12] = {0x65,0xd1,0x4a,0xa0,0xbd,0x6f,0x8d,0xd4,0xaa,0x33,0x41,0x1c};

    CONTEXT aectx = {.data = aetest, .data_length = 144 * 8, .key = aekey, .nonce = aenonce, .nonce_length = 6 * 8};
    ret = ae_enc(aectx,aetag);
    if (ret != 0){
        PRINTSTRINGINT("Error: ", ret);
    }
    
    int isok = 1;
    for (i = 0; i < 12; i++) {
        if (aetag[i] != aecheckMAC[i]) {
            msg = ERRMSG;
	    isok = 0;          			
            break;
	}
    }
		
    if (isok != 0) {
        msg = "OK!";
      //for (i = 0; i < 144; i++) {
      //    PRINTCHAR(aectx.data[i]);
      //    printf("%02x ", aectx.data[i]);
      //}
    }

    PRINTSTRING(msg);

    PRINTSTRING("\n");
    PRINTSTRING("Fertig!");
    PRINTSTRING("\n\n");

    return (EXIT_SUCCESS);
}

