#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
int main() {
	srand(time(NULL));
	short iq[2*N];
	for (int i = 0; i < N; i++) {
		iq[2*i] = (rand() % 65536) - 32768;
		iq[2*i+1] = (rand() % 65536) - 32768;
	}
	for (int i = 0; i < N; i++) {
		printf("s[%d] = %.1f + j*(%.1f)\n", i, (float)iq[2*i], (float)iq[2*i+1]);
	}
	long long E = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		long long re = iq[2*i];
        	long long im = iq[2*i+1];
        	E += (re * re) + (im * im);
	}
	printf("Энергия сигнала: E = %.1f\n", (float)E);

	short max_re = iq[0];
    	int max_index = 0;
    	for (int i = 1; i < N; i++) {
        	if (iq[2*i] > max_re) {
            		max_re = iq[2*i];
            		max_index = i;
        	}
	}
    	printf("Максимальный элемент среди реальной части: s[%d] = %.1f\n", max_index, (float)max_re);

	return 0;
}

