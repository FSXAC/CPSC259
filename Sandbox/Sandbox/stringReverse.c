#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str1[] = "Canada";
	int length = reverseString(str1);
	printf("length: %d\t", length);

	int i = 0;
	for (; i < length; i++) {
		printf("%c", str1[i]);
//		printf("%c", *(str1 + i));
	}
	printf("\n");
	return 1;
}

int reverseString( char * string ) {
	int length = 0;
	int i = 0;
	char temp;
	while ((*(string + length) != '\0')) {
		length++;
	}

	for (; i < length / 2; i++) {
		temp = *(string + i);
		*(string + i) = *(string + (length - i - 1));
		*(string + (length - i - 1)) = temp;
	}

	return length;
}

int reverse(char string[]) {
	int length = 0;
	int i = 0;
	char temp;

	while(string[length] != '\0') {
		length++;
	}

	for (; i < length / 2; i++) {
		temp = string[i];
		string[i] = string[length - i];
		string[length - i] = temp;
	}

	return length;
}
