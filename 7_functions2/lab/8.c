#include <stdio.h>
#include <string.h>

int main() {
	char log[] = "error: disk error, then error again";
	char word[] = "error";
	char *res = strstr(log, word);
	int count = 0;
	while (res != NULL) {
		count += 1;
		printf("Позиция: [%d]\n", (int)(res-log));
		res += strlen(word);
		res = strstr(res, word);

	}
	printf("Количество вхождений: %d\n", count);
return 0;
}
