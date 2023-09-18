#include <bits/stdc++.h>

using namespace std;

int kth(vector<int> &a, int k) {
    int n = a.size() / 5;

    for (int i = 0; i < 5; i++) {
        if (i % 2) continue;
        shuffle(a.begin() + i * n, min(a.begin() + (i + 1) * n, a.end()), default_random_engine());
    }

    nth_element(a.begin(), a.begin() + k - 1, a.end());
    return a[k - 1];
}