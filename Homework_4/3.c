#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int zFunction(char* suffix, char* prefix) {
    char* s = (char*)malloc(strlen(prefix) + strlen(suffix) + 2);
    strcpy(s, prefix);
    strcat(s, "#");
    strcat(s, suffix);
    int n = strlen(s);
    int* z = (int*)malloc(n * sizeof(int));
    memset(z, 0, n * sizeof(int));
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = (r - i + 1 < z[i - l]) ? r - i + 1 : z[i - l];
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    int max_z = 0;
    for (int i = 0; i < n; i++) {
        if (z[i] > max_z) {
            max_z = z[i];
        }
    }
    free(s);
    free(z);
    return max_z;
}

int main() {
    char prefix[100], suffix[100];
    scanf("%s", suffix);
    scanf("%s", prefix);
    int result = zFunction(suffix, prefix);
    printf("%d\n", result);
    return 0;
}
