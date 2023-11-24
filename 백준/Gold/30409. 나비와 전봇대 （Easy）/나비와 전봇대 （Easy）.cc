#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, Q;
ll arr[100005];
ll A[100005], B[100005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    stack<pii> st;
    for (int i = 1; i <= N; i++) {
        if (st.size() == 0) st.push({arr[i], i});
        else {
            while (st.size()) {
                pii t = st.top();
                if (arr[i] > t.first) st.pop();
                else {
                    A[i] += A[t.second] + (arr[i] - t.first) * (arr[i] - t.first) + (i - t.second) * (i - t.second);
                    break;
                }
            }
        }
        st.push({arr[i], i});
    }
    while (st.size()) st.pop();
    
    for (int i = N; i >= 1; i--) {
        if (st.size() == 0) st.push({arr[i], i});
        else {
            while (st.size()) {
                pii t = st.top();
                if (arr[i] > t.first) st.pop();
                else {
                    B[i] += B[t.second] + (arr[i] - t.first) * (arr[i] - t.first) + (i - t.second) * (i - t.second);
                    break;
                }
            }
        }
        st.push({arr[i], i});
    }
    
    cin >> Q;
    while (Q--) {
        int a;
        cin >> a;
        cout << A[a] + B[a] << '\n';
    }
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}