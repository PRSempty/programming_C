#include <stdio.h>

int main() {
        unsigned int a;
        int k;
        scanf("%d", &a);
        scanf("%d", &k);
        a = (a << k) | ((1 << k) - 1);
        printf("%d\n", a);

        return 0;
}

