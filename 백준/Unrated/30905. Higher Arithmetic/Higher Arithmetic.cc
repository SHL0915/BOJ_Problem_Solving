#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];

void solve() {
    cin >> N;
    stack<string> one, two;
    priority_queue<pair<ll, string>> pq;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 1) one.push("1");
        else if (arr[i] == 2) two.push("2");
        else pq.push({-arr[i], to_string(arr[i])});
    }

    while (1) {
        while (two.size()) {
            if (one.size() == 0) break;
            string ot = one.top(), tt = two.top();
            one.pop(), two.pop();
            string ns = '(' + ot + '+' + tt + ')';
            pq.push({-3, ns});
        }

        if (one.size() >= 2) {
            two.push({"(1+1)"});
            one.pop();
            one.pop();
        } else break;
    }


    while (one.size()) {
        string t = one.top();
        one.pop();
        pq.push({-1, t});
    }


    while (two.size()) {
        string t = two.top();
        two.pop();
        pq.push({-2, t});
    }

    while (pq.size() > 1) {
        pair<ll, string> t = pq.top();
        if (t.first < -1) break;
        else {
            pq.pop();
            pair<ll, string> tt = pq.top();
            pq.pop();

            ll val = t.first + tt.first;
            string ns = '(' + t.second + '+' + tt.second + ')';
            pq.push({val, ns});
        }
    }

    string ans = "";
    while (pq.size()) {
        pair<ll, string> t = pq.top();
        pq.pop();
        if (ans.size() == 0) ans = t.second;
        else ans += '*', ans += t.second;
    }

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