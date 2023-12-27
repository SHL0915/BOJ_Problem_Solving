#include <bits/stdc++.h>
#include "art.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve(int N) {
    vector<int> order(N);
    vector<int> ans(N);

    for (int i = 0; i < N; i++) order[i] = i + 1;
    int a = publish(order), b;
    for (int i = 0; i < N; i++) {
        int now = order.back();
        for (int j = N - 1; j > 0; j--) order[j] = order[j - 1];
        order[0] = now;
        b = publish(order);
        int pos = (N + (b - a)) / 2;
        ans[pos] = now;
        a = b;
    }

    answer(ans);

    return;
}
