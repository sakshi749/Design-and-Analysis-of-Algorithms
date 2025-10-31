//created by sakshi
#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 100

int matrixChainOrder(int p[], int n) {
    int m[MAX][MAX];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

double theoreticalTimeComplexity(int n) {
    return (double)(n * n * n);
}

int main() {
    int p10[] = {30, 35, 15, 5, 10, 20, 25, 30, 15, 10, 5};
    int p50[51];
    int p100[101];
    for (int i = 0; i < 51; i++) p50[i] = 5 + i % 20;
    for (int i = 0; i < 101; i++) p100[i] = 5 + i % 20;

    // Test cases for n = 10, 50, and 100
    int test_cases[3] = {10, 50, 100};
    int *p[] = {p10, p50, p100};

    for (int i = 0; i < 3; i++) {
        int n = test_cases[i];

        double theoreticalTime = theoreticalTimeComplexity(n);

        clock_t start = clock();
        int minMultiplications = matrixChainOrder(p[i], n + 1);
        clock_t end = clock();
        double practicalTime = (double)(end - start) / CLOCKS_PER_SEC;

        printf("For n = %d:\n", n);
        printf("Minimum number of multiplications: %d\n", minMultiplications);
        printf("Theoretical time complexity: %.2f\n", theoreticalTime);
        printf("Practical computation time: %.6f seconds\n\n", practicalTime);
    }

    return 0;
}