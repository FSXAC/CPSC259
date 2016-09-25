/* This is to test string pointer function that counts length
 */

int main(void) {
	char str1[]  = "StringNumberOne";
	printf("===%d\n", lengthOfString(str1));


	return 1;
}

int lengthOfString(char * string) {
	int length = 0;
	while((*(string+length)!='\0')) {
		length++;
	}

	return length;
}
