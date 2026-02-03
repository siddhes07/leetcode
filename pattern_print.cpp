#include <stdio.h>

int main() {
    int i, j, n = 5;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == 0 || j == n - 1 || 
                (i == j && i <= n / 2) || 
                (i + j == n - 1 && i <= n / 2))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
