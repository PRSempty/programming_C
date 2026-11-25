#include <stdio.h>

int main() {
	int n = 2;
	int b;
	scanf("%d", &b);
	int flag = 0;
	if (b == 1) {
        	printf("0\n");
        	return 0;
    	}
	while (b % n != 0) {
		n++;
		if (n == b) {
			flag = 1;
			break;
		}
	}
	if (b == 2) {
        	printf("1\n");
        	return 0;
	}
	if (flag == 1) {
		printf("1\n");

	} else {
		printf("0\n");
	}
	return 0;
}
