#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

void toLowerCase(char plain[], int ps)
{
	int i;
	for (i = 0; i < ps; i++) {
		if (plain[i] > 64 && plain[i] < 91)
			plain[i] += 32;
	}
}

int removeSpaces(char* plain, int ps)
{
	int i, count = 0;
	for (i = 0; i < ps; i++)
		if (plain[i] != ' ')
			plain[count++] = plain[i];
	plain[count] = '\0';
	return count;
}

void generateKeyTable(char key[], int ks, char keyT[5][5])
{
	int i, j, k, flag = 0, *dicty;
	dicty = (int*)calloc(26, sizeof(int));
	for (i = 0; i < ks; i++) {
		if (key[i] != 'j')
			dicty[key[i] - 97] = 2;
	}

	dicty['j' - 97] = 1;

	i = 0;
	j = 0;

	for (k = 0; k < ks; k++) {
		if (dicty[key[k] - 97] == 2) {
			dicty[key[k] - 97] -= 1;
			keyT[i][j] = key[k];
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}

	for (k = 0; k < 26; k++) {
		if (dicty[k] == 0) {
			keyT[i][j] = (char)(k + 97);
			j++;
			if (j == 5) {
				i++;
				j = 0;
			}
		}
	}
}

void search(char keyT[5][5], char a, char b, int arr[])
{
	int i, j;

	if (a == 'j')
		a = 'i';
	else if (b == 'j')
		b = 'i';

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {

			if (keyT[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keyT[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}

int mod5(int a)
{
	return (a % 5);
}

int prepare(char str[], int ptrs)
{
	if (ptrs % 2 != 0) {
		str[ptrs++] = 'z';
		str[ptrs] = '\0';
	}
	return ptrs;
}

void encrypt(char str[], char keyT[5][5], int ps)
{
	int i, a[4];

	for (i = 0; i < ps; i += 2) {

		search(keyT, str[i], str[i + 1], a);

		if (a[0] == a[2]) {
			str[i] = keyT[a[0]][mod5(a[1] + 1)];
			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
		}
		else if (a[1] == a[3]) {
			str[i] = keyT[mod5(a[0] + 1)][a[1]];
			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
		}
		else {
			str[i] = keyT[a[0]][a[3]];
			str[i + 1] = keyT[a[2]][a[1]];
		}
	}
}

void encryptByPlayfairCipher(char str[], char key[])
{
	char ps, ks, keyT[5][5];

	ks = strlen(key);
	ks = removeSpaces(key, ks);
	toLowerCase(key, ks);

	ps = strlen(str);
	toLowerCase(str, ps);
	ps = removeSpaces(str, ps);

	ps = prepare(str, ps);

	generateKeyTable(key, ks, keyT);

	encrypt(str, keyT, ps);
}

void intToBinary(int n)
{
    int binaryNum[32];
  
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    int k[i - 1];
    int f=0;
    for (int j = i - 1; j >= 0; j--){
        k[f]=binaryNum[j];
        f++;
    }
    
}

int main() {
    char key[SIZE];
    char plain_texts[5][SIZE] = {
        "DO",
        "NOT",
        "GIVE",
        "UP",
        "YET"
    };
    char concatenated_cipher_texts[5][SIZE];
    int binary_values[5];

    strcpy(key, "NOTTHEFLAG");
    //printf("Key text: %s\n", key);

    for (int i = 0; i < 5; i++) {
        char str[SIZE];
        strcpy(str, plain_texts[i]);
        //printf("Plain text %d: %s\n", i + 1, str);

        encryptByPlayfairCipher(str, key);

        char concatenated_ascii[SIZE];
        int ascii_sum = 0;
        for (int j = 0; str[j] != '\0'; j++) {
            ascii_sum += (int)str[j];
        }
        snprintf(concatenated_ascii, SIZE, "%d", ascii_sum);

        strcpy(concatenated_cipher_texts[i], concatenated_ascii);

        //printf("Concatenated ASCII value %d: %s\n", i + 1, concatenated_cipher_texts[i]);

        int binary_value = atoi(concatenated_ascii);
        binary_values[i] = binary_value;
        //printf("Binary representation %d: ", i + 1);
        //intToBinary(binary_value);
        //printf("\n");
    }

    int result = binary_values[0];
    for (int i = 1; i < 5; i++) {
        result ^= binary_values[i];
    }
    printf("XOR of all binary values: ");
    intToBinary(result);
    printf("\n");

    return 0;
}
