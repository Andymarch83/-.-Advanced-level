#include <stdio.h>
#include <stdlib.h>

double cnk3(int n, int k)
{
    const int maxn = n;
    double** C = (double**)malloc((maxn + 1) * sizeof(double*));
    for (int i = 0; i <= maxn; ++i)
    {
        C[i] = (double*)malloc((maxn + 1) * sizeof(double));
        C[i][0] = C[i][i] = 1.0;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    double result = C[n][k];
    for (int i = 0; i <= maxn; ++i)
        free(C[i]);
    free(C);
    return result;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%f ", cnk3(n, k));
    return 0;
}
