#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM * a)
{
	/* Use BN_bn2hex(a) for hex string
	* Use BN_bn2dec(a) for decimal string */
	char * number_str = BN_bn2hex(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}

int main ()
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *n = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *M = BN_new();
	BIGNUM *V = BN_new();
	BIGNUM *S = BN_new();

	// Initialize n, e, d and C
	BN_hex2bn(&n,"AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
	//BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F"); //modified S
	BN_hex2bn(&M, "4c61756e63682061206d697373696c652e"); //Launch a missile.
	
	/* Verify a digital signature using public-key (e, n)
		E(PU_a, S): E(PU_a, E(PR_a, H(M))) = S^e mod n
	   	Here, S = M^d mod n and V = S^e mod n, so V=M */
	BN_mod_exp(V, S, e, n, ctx);
	printBN("Original Message : ", M);
	printBN("Computed Message : ", V);
	
	if (BN_cmp(M, V)==0){
		printf("Signature verified!\n");
	}
	else {
		printf("Verification failed!\n");
	}
	
	return 0;
}
