#include <stdio.h>

void pup(int n) {
    printf("%*s", n, "");
}

int main() {
    char z = '*';
    int h;
    printf("Введите высоту: ");
    if (scanf("%d", &h) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }

for (int k = 0; k < 2; k++) {
    for (int i = 1; i <= h; i++) {
        pup(h - i);

        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%c", z);
        }

        printf("\n");
    }
}
    return 0;
}

