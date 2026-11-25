#include <stdio.h>

#define N_max 3
float a[N_max][N_max];
float b[N_max];

float opred(float a[N_max][N_max], int n) {
    if (n == 2) {
        float det = a[0][0]*a[1][1] -  a[0][1]*a[1][0];
        return det;
    } else if (n ==3) {
        float glav = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[1][0]*a[2][1]*a[0][2];
        float poboch = a[0][2]*a[1][1]*a[2][0] + a[0][1]*a[1][0]*a[2][2] + a[1][2]*a[2][1]*a[0][0];
        float det = glav - poboch;
        return det;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("b[%d] = ", i);
        scanf("%f", &b[i]);
    }
    
    printf("\nРасширенная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f  ", a[i][j]);
        }
        printf("|  %.0f\n", b[i]); 
    }
    
    float det = opred(a, n);

    if (det == 0) {
        printf("Нет единственного решения\n");
        return 0;
    }

    if (n == 2) {
        float det_x = b[0]*a[1][1] - b[1]*a[0][1];
        float det_y = a[0][0]*b[1] - a[1][0]*b[0];
        float x = det_x / det;
        float y = det_y / det;
        printf("\nОтвет: ");
        printf("x = %.2f ", x);
        printf("y = %.2f\n", y);
    }
    if (n == 3) {
        float answer[N_max];
        for (int k = 0; k < n; k++) {
            float copy[N_max][N_max];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    copy[i][j] = a[i][j];
                }
            }
            for (int i = 0; i < n; i++) {
                copy[i][k] = b[i];
            }
            float det_k = opred(copy, n);
            answer[k] = det_k/det;
        }
        
        printf("\nОтвет: ");
        printf("x = %.2f, ", answer[0]);
        printf("y = %.2f, ", answer[1]);
        printf("z = %.2f\n", answer[2]);

    }

    return 0;
}