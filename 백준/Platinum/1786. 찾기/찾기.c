#include <stdio.h>
#include <string.h>

char str[10000005];
char pattern[10000005];
int avail = 0;
int fail[10000005];
int ans[10000005];

void make_fail() {
    int m = strlen(pattern);
    fail[0] = -1;
    for (int i = 1; i < m; i++) {
        int pos = fail[i - 1];
        while ((pattern[i] != pattern[pos + 1]) && (pos >= 0)) pos = fail[pos];
        if (pattern[i] == pattern[pos + 1]) fail[i] = pos + 1;
        else fail[i] = -1;
    }
    return;
}

void kmp() {
    make_fail();
    int n = strlen(str), m = strlen(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (str[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                ans[avail++] = i - j;
                j = fail[j - 1] + 1;
            }
        } else if (j == 0) i++;
        else j = fail[j - 1] + 1;
    }
    return;
}

int main() {
    gets(str);
    gets(pattern);

    kmp();

    printf("%d\n", avail);
    for (int i = 0; i < avail; i++) printf("%d ", ans[i] + 1);

    return 0;
}