# RSA Public-key Encryption 

This project focuses on implementing the RSA algorithm to generate private/public keys and perform encryption/decryption and 
signature generation/verification using the C programming language.

`Project Report` - PDF file containing observations and steps to reimplement this project.

`Crypto_RSA` - Setup and Instructions for each task.

Task files - `task1.c`, `task2.c`, `task3.c`, `task4.c`, `task5.c`.

## Task 1: Calculate private-key d

Run `task1.c` using the following commands:
	
	Compile	: gcc -o task1.out task1.c -lcrypto
	run	: ./task1.out
	
You should get the output as `d = 3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB`

## Task 2: Encrypt message M by computing C

Use the following command in a terminal to get the Hexadecimal value of a string.
	
	python3 -c 'print("A top secret!".encode("utf-8").hex())'
You should get the output as `4120746f702073656372657421`
	
We can then use this Hexadecimal string in encryption by converting it into BIGNUM with `BN_hex2bn()` function.
Initialize all required variables in `task2.c` and run the program using following commands:
	
	compile	: gcc -o task2.out task2.c -lcrypto
	run	: ./task2.out
	
You should get the output as `C = 6FB078DA550B2650832661E14F4F8D2CFAEF475A0DF3A75CACDC5DE5CFC5FADC`

## Task 3: Decrypt message M

Run `task3.c` using the following commands:
	
	Compile	: gcc -o task3.out task3.c -lcrypto
	run	: ./task3.out
	
You should get the output as `Decrypted message = 50617373776F72642069732064656573`
	
Use the following command in a terminal to convert a Hexadecimal string to plain text.
	
	python3 -c 'print(bytes.fromhex("50617373776F72642069732064656573").decode("utf-8"))'

You should get the output as `Password is dees`
	
## Task 4: Generate a Signature S

Use the following command in a terminal to get the Hexadecimal value of a string.
	
	python3 -c 'print("I owe you $2000.".encode("utf-8").hex())'

The output must be `49206f776520796f752024323030302e`

Run `task4.c` using the following commands:
	
	compile	: gcc -o task4.out task4.c -lcrypto
	run	: ./task4.out
	
The output must be `S = 55A4E7F17F04CCFE2766E1EB32ADDBA890BBE92A6FBE2D785ED6E73CCB35E4CB`
	
Next, get the hex value of `"I owe you $3000."`
	
	command: python3 -c 'print("I owe you $3000.".encode("utf-8").hex())'

The output must be `49206f776520796f752024333030302e`
	
Run `task4.c` again and observe a totally different signature.
	
The output must be `S = BCC20FB7568E5D48E434C387C06A6025E90D29D848AF9C3EBAC0135D99305822`
	
## Task 5: Verify a Signature S

Get Hex value of M = `"Launch a missile."`
	
	python3 -c 'print("Launch a missile.".encode("utf-8").hex())'

The output must be `4c61756e63682061206d697373696c652e`
	
Run `task5.c` using the following commands:
	
	compile	: gcc -o task5.out task5.c -lcrypto
	run	: ./task5.out

The output will be: 
	
 	Original Message :  4C61756E63682061206D697373696C652E
	Computed Message :  4C61756E63682061206D697373696C652E
	Signature verified!
	
Now, modify a single bit in Signature s by using `643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F`
	
Running `task5.c` again gives us the output as,

	Original Message :  4C61756E63682061206D697373696C652E
	Computed Message :  91471927C80DF1E42C154FB4638CE8BC726D3D66C83A4EB6B7BE0203B41AC294
	Verification failed!
	
