#include <stdio.h>


int primeOrComposite(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int firstDivisor(int n) {
    if (n <= 1) return n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) return i;
    }
    return n;
}

void goldbachDecomposition(int n) {
    for (int a = 2; a <= n/2; a++) {
        int b = n - a;
        if (primeOrComposite(a) == 1 && primeOrComposite(b) == 1) {
            printf("Гипотеза Гольдбаха: %d = %d + %d\n", n, a, b);
            return;
        }
    }
}


int main() {
    int id[12] = {17, 24, 91, 97, 100, 121, 13, 60, 77, 88, 101, 39};
    int primeCount = 0;
    printf("\nАнализ кандидатов в ID\n\n");

    for (int i = 0; i < 12; i++) {
        int candidate = id[i];
        printf("Кандидат %d: ", candidate);

        if (primeOrComposite(candidate) == 1) {
            printf("Простое\n");
            primeCount++;
        } else {
            int divisor = firstDivisor(candidate);
            printf("Составное, первый делитель: %d\n", divisor);
        }

        // по Гольдбаху
        if (candidate > 2 && candidate % 2 == 0) {
            goldbachDecomposition(candidate);
        }
    }

    printf("\nИтог\n");
    printf("Количество простых чисел среди кандидатов: %d\n", primeCount);

    return 0;
}

