#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    vector<pair<int, pii>> q;

    int l = 2100, r = 2399;

    int cnt = 0, ccnt = 0, flag = 0;
    while (ccnt < 15) {
        int mid = (l + r + 1) / 2;
        cout << "? " << mid << endl;
        ccnt++;
        int a;
        cin >> a;
        if (a == 0) {
            cnt++;
            q.push_back({0, {l, r}});
            if (cnt >= 3 && !flag) {
                int last = -1;
                for (int i = 0; i < q.size(); i++) if (q[i].first == 1) last = i;
                if (last != -1 && ccnt < 15) {
                    int ll = q[last].second.first, rr = q[last].second.second;
                    int mmid = (ll + rr + 1) / 2;
                    cout << "? " << mmid << endl;
                    ccnt++;
                    cin >> a;
                    if (a == 1) r = mid - 1;
                    else {
                        flag = 1;
                        l = ll, r = rr;
                        r = mmid - 1;
                        q.push_back({0, {l, r}});
                    }
                    cnt = -100;
                }
                else r = mid - 1;
            } else r = mid - 1;
        } else {
            cnt = 0;
            q.push_back({1, {l, r}});
            l = mid;
        }
    }

    cout << "! " << l << endl;


    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}