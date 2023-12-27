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
    for (int i = 0; i < N - 1; i++) {
        int now = order.back();
        for (int j = N - 1; j > 0; j--) order[j] = order[j - 1];
        order[0] = now;
        b = publish(order);
        int pos = (N + (b - a)) / 2;
        ans[pos] = now;
        a = b;
    }

    set<int> s;
    for (int i = 1; i <= N; i++) s.insert(i);
    for (int i = 0; i < N; i++) s.erase(ans[i]);
    for (int i = 0; i < N; i++) if (ans[i] == 0) ans[i] = *s.begin();

    answer(ans);

    return;
}