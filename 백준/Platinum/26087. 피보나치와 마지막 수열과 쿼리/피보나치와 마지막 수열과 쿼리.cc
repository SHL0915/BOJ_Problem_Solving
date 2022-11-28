#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;
const int mod = 1000000007;

struct arrcmp {
    bool operator() (piii A, piii B) {
        return A.first.first > B.first.first;
    }
};

struct pqcmp {
    bool operator() (piii A, piii B) {
        return A.second < B.second;
    }
};

int N, Q;
int fib[1000005];
priority_queue <piii, vector<piii>, arrcmp> arr;
priority_queue <piii, vector<piii>, pqcmp> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 1000005; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        arr.push({ {L, R} ,i });
    }
    for (int i = 1; i <= N; i++) {
        while (pq.size()) {
            if (pq.top().first.second < i) pq.pop();
            else break;
        }
        while (arr.size()) {
            if (arr.top().first.first <= i) {
                pq.push({ { arr.top().first.first, arr.top().first.second } , arr.top().second });
                arr.pop();
            }
            else break;
        }
        if (pq.size() == 0) cout << 0 << " ";
        else cout << fib[i - pq.top().first.first + 1] << " ";
    }
    return 0;
}