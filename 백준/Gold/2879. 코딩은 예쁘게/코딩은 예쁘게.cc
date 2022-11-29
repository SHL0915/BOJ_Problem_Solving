#include <bits/stdc++.h>
using namespace std;

const int mxn = 100010;
int N, a[mxn], x;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)cin >> a[i];
    for (int i = 1; i <= N; i++)cin >> x, a[i] -= x;
    int res = 0;
    for (int i = 0; i <= N; i++)
        res += abs(a[i] - a[i + 1]);
    cout << res / 2;

    return 0;
}