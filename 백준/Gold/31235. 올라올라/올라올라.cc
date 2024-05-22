#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1000005];
int v[1000005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (st.size()) {
            if (arr[i] < arr[st.top()]) st.push(i);
            else {
                while (st.size()) {
                    int t = st.top();
                    if (arr[t] > arr[i]) break;
                    st.pop();
                    v[t] = (i - t);
                }
                st.push(i);
            }
        } else st.push(i);
    }
    
    while (st.size()) {
        int t = st.top();
        st.pop();
        v[t] = N - t;
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, v[i]);
    
    cout << ans;
    
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