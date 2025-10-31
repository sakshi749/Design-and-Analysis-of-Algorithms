// created by sakshi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to allocate memory for a matrix
int** allocate_matrix(int n) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to free the memory of a matrix
void free_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Standard 3-loop matrix multiplication
void matrix_mult_3loop(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix addition: C = A + B
void matrix_add(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix subtraction: C = A - B
void matrix_sub(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Divide and Conquer Matrix Multiplication (Recursive)
void divide_and_conquer(int n, int **A, int **B, int **C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int new_size = n / 2;

        // Allocate memory for submatrices
        int **A11 = allocate_matrix(new_size), **A12 = allocate_matrix(new_size);
        int **A21 = allocate_matrix(new_size), **A22 = allocate_matrix(new_size);
        int **B11 = allocate_matrix(new_size), **B12 = allocate_matrix(new_size);
        int **B21 = allocate_matrix(new_size), **B22 = allocate_matrix(new_size);
        int **C11 = allocate_matrix(new_size), **C12 = allocate_matrix(new_size);
        int **C21 = allocate_matrix(new_size), **C22 = allocate_matrix(new_size);

        // Split matrices A and B into 4 submatrices each
        for (int i = 0; i < new_size; i++) {
            for (int j = 0; j < new_size; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + new_size];
                A21[i][j] = A[i + new_size][j];
                A22[i][j] = A[i + new_size][j + new_size];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + new_size];
                B21[i][j] = B[i + new_size][j];
                B22[i][j] = B[i + new_size][j + new_size];
            }
        }

        // Recursively compute submatrices C = A * B
        divide_and_conquer(new_size, A11, B11, C11);
        divide_and_conquer(new_size, A12, B21, C12);
        matrix_add(new_size, C11, C12, C11);

        divide_and_conquer(new_size, A11, B12, C21);
        divide_and_conquer(new_size, A12, B22, C22);
        matrix_add(new_size, C21, C22, C21);

        // Combine the results into C
        for (int i = 0; i < new_size; i++) {
            for (int j = 0; j < new_size; j++) {
                C[i][j] = C11[i][j];
                C[i][j + new_size] = C12[i][j];
                C[i + new_size][j] = C21[i][j];
                C[i + new_size][j + new_size] = C22[i][j];
            }
        }

        // Free the allocated memory
        free_matrix(new_size, A11); free_matrix(new_size, A12);
        free_matrix(new_size, A21); free_matrix(new_size, A22);
        free_matrix(new_size, B11); free_matrix(new_size, B12);
        free_matrix(new_size, B21); free_matrix(new_size, B22);
        free_matrix(new_size, C11); free_matrix(new_size, C12);
        free_matrix(new_size, C21); free_matrix(new_size, C22);
    }
}

// Strassen's matrix multiplication
void strassen(int n, int **A, int **B, int **C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int new_size = n / 2;

        // Allocate memory for submatrices
        int **A11 = allocate_matrix(new_size), **A12 = allocate_matrix(new_size);
        int **A21 = allocate_matrix(new_size), **A22 = allocate_matrix(new_size);
        int **B11 = allocate_matrix(new_size), **B12 = allocate_matrix(new_size);
        int **B21 = allocate_matrix(new_size), **B22 = allocate_matrix(new_size);
        int **C11 = allocate_matrix(new_size), **C12 = allocate_matrix(new_size);
        int **C21 = allocate_matrix(new_size), **C22 = allocate_matrix(new_size);
        int **M1 = allocate_matrix(new_size), **M2 = allocate_matrix(new_size);
        int **M3 = allocate_matrix(new_size), **M4 = allocate_matrix(new_size);
        int **M5 = allocate_matrix(new_size), **M6 = allocate_matrix(new_size);
        int **M7 = allocate_matrix(new_size);
        int **temp1 = allocate_matrix(new_size), **temp2 = allocate_matrix(new_size);

        // Split matrices A and B into 4 submatrices each
        for (int i = 0; i < new_size; i++) {
            for (int j = 0; j < new_size; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + new_size];
                A21[i][j] = A[i + new_size][j];
                A22[i][j] = A[i + new_size][j + new_size];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + new_size];
                B21[i][j] = B[i + new_size][j];
                B22[i][j] = B[i + new_size][j + new_size];
            }
        }

        // Strassen's 7 steps
        // M1 = (A11 + A22) * (B11 + B22)
        matrix_add(new_size, A11, A22, temp1);
        matrix_add(new_size, B11, B22, temp2);
        strassen(new_size, temp1, temp2, M1);

        // M2 = (A21 + A22) * B11
        matrix_add(new_size, A21, A22, temp1);
        strassen(new_size, temp1, B11, M2);

        // M3 = A11 * (B12 - B22)
        matrix_sub(new_size, B12, B22, temp1);
        strassen(new_size, A11, temp1, M3);

        // M4 = A22 * (B21 - B11)
        matrix_sub(new_size, B21, B11, temp1);
        strassen(new_size, A22, temp1, M4);

        // M5 = (A11 + A12) * B22
        matrix_add(new_size, A11, A12, temp1);
        strassen(new_size, temp1, B22, M5);

        // M6 = (A21 - A11) * (B11 + B12)
        matrix_sub(new_size, A21, A11, temp1);
        matrix_add(new_size, B11, B12, temp2);
        strassen(new_size, temp1, temp2, M6);

        // M7 = (A12 - A22) * (B21 + B22)
        matrix_sub(new_size, A12, A22, temp1);
        matrix_add(new_size, B21, B22, temp2);
        strassen(new_size, temp1, temp2, M7);

        // C11 = M1 + M4 - M5 + M7
        matrix_add(new_size, M1, M4, temp1);
        matrix_sub(new_size, temp1, M5, temp2);
        matrix_add(new_size, temp2, M7, C11);

        // C12 = M3 + M5
        matrix_add(new_size, M3, M5, C12);

        // C21 = M2 + M4
        matrix_add(new_size, M2, M4, C21);

        // C22 = M1 - M2 + M3 + M6
        matrix_sub(new_size, M1, M2, temp1);
        matrix_add(new_size, temp1, M3, temp2);
        matrix_add(new_size, temp2, M6, C22);

        // Combine submatrices into result matrix C
        for (int i = 0; i < new_size; i++) {
            for (int j = 0; j < new_size; j++) {
                C[i][j] = C11[i][j];
                C[i][j + new_size] = C12[i][j];
                C[i + new_size][j] = C21[i][j];
                C[i + new_size][j + new_size] = C22[i][j];
            }
        }

        // Free allocated memory
        free_matrix(new_size, A11); free_matrix(new_size, A12);
        free_matrix(new_size, A21); free_matrix(new_size, A22);
        free_matrix(new_size, B11); free_matrix(new_size, B12);
        free_matrix(new_size, B21); free_matrix(new_size, B22);
        free_matrix(new_size, C11); free_matrix(new_size, C12);
        free_matrix(new_size, C21); free_matrix(new_size, C22);
        free_matrix(new_size, M1); free_matrix(new_size, M2);
        free_matrix(new_size, M3); free_matrix(new_size, M4);
        free_matrix(new_size, M5); free_matrix(new_size, M6);
        free_matrix(new_size, M7); free_matrix(new_size, temp1);
        free_matrix(new_size, temp2);
    }
}

// Function to measure time taken
double get_time_in_seconds(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int n = 2; // 2x2 matrix size

    // Allocate memory for matrices A, B, and C
    int **A = allocate_matrix(n);
    int **B = allocate_matrix(n);
    int **C = allocate_matrix(n);

    // Initialize matrices A and B with random values
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Measure time for 3-loop method
    clock_t start = clock();
    int **C3loop = allocate_matrix(n);
    matrix_mult_3loop(n, A, B, C3loop);
    clock_t end = clock();
    double time_3loop = get_time_in_seconds(start, end);
    printf("3-Loop method time: %.12f seconds\n", time_3loop);

    // Measure time for Divide and Conquer method
    start = clock();
    int **C_dc = allocate_matrix(n);
    divide_and_conquer(n, A, B, C_dc);
    end = clock();
    double time_dc = get_time_in_seconds(start, end);
    printf("Divide and Conquer method time: %.12f seconds\n", time_dc);

    // Measure time for Strassen's method
    start = clock();
    int **C_strassen = allocate_matrix(n);
    strassen(n, A, B, C_strassen);
    end = clock();
    double time_strassen = get_time_in_seconds(start, end);
    printf("Strassen's method time: %.12f seconds\n", time_strassen);

    // Free the allocated memory
    free_matrix(n, A);
    free_matrix(n, B);
    free_matrix(n, C3loop);
    free_matrix(n, C_dc);
    free_matrix(n, C_strassen);

    return 0;
}
