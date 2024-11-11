#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, D;
ll arr[35];
vector<ll> v1, v2, A, B;

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (i < N / 2) v1.push_back(arr[i]);
        else v2.push_back(arr[i]);
    }
    
    cin >> D;
    
    A.push_back(0), B.push_back(0);
    for (int i = 0; i < v1.size(); i++) {
        ll now = v1[i];
        vector<ll> merge;
        int a = 0, b = 0, c = 0;
        while (a < A.size() && b < A.size() && c < A.size()) {
            ll av = A[a] - now, bv = A[b], cv = A[c] + now;
            if (av <= bv && av <= cv) {
                merge.push_back(av);
                a++;
            } else if (bv <= av && bv <= cv) {
                merge.push_back(bv);
                b++;
            } else {
                merge.push_back(cv);
                c++;
            }
        }
        
        while (a < A.size() && b < A.size()) {
            ll av = A[a] - now, bv = A[b];
            if (av <= bv) {
                merge.push_back(av);
                a++;
            } else {
                merge.push_back(bv);
                b++;
            }
        }
        
        while (a < A.size() && c < A.size()) {
            ll av = A[a] - now, cv = A[c] + now;
            if (av <= cv) {
                merge.push_back(av);
                a++;
            } else {
                merge.push_back(cv);
                c++;
            }
        }
        
        while (b < A.size() && c < A.size()) {
            ll bv = A[b], cv = A[c] + now;
            if (bv <= cv) {
                merge.push_back(bv);
                b++;
            } else {
                merge.push_back(cv);
                c++;
            }
        }
        
        while (a < A.size()) merge.push_back(A[a++] - now);
        while (b < A.size()) merge.push_back(A[b++]);
        while (c < A.size()) merge.push_back(A[c++] + now);
        
        swap(A, merge);
    }
    
    for (int i = 0; i < v2.size(); i++) {
        ll now = v2[i];
        vector<ll> merge;
        int a = 0, b = 0, c = 0;
        while (a < B.size() && b < B.size() && c < B.size()) {
            ll av = B[a] - now, bv = B[b], cv = B[c] + now;
            if (av <= bv && av <= cv) {
                merge.push_back(av);
                a++;
            } else if (bv <= av && bv <= cv) {
                merge.push_back(bv);
                b++;
            } else {
                merge.push_back(cv);
                c++;
            }
        }
        
        while (a < B.size() && b < B.size()) {
            ll av = B[a] - now, bv = B[b];
            if (av <= bv) {
                merge.push_back(av);
                a++;
            } else {
                merge.push_back(bv);
                b++;
            }
        }
        
        while (a < B.size() && c < B.size()) {
            ll av = B[a] - now, cv = B[c] + now;
            if (av <= cv) {
                merge.push_back(av);
                a++;
            } else {
                merge.push_back(cv);
                c++;
            }
        }
        
        while (b < B.size() && c < B.size()) {
            ll bv = B[b], cv = B[c] + now;
            if (bv <= cv) {
                merge.push_back(bv);
                b++;
            } else {
                merge.push_back(cv);
                c++;
            }
        }
        
        while (a < B.size()) merge.push_back(B[a++] - now);
        while (b < B.size()) merge.push_back(B[b++]);
        while (c < B.size()) merge.push_back(B[c++] + now);
        
        swap(B, merge);
    }
    
    ll ans = 0;
    ll l = 0, r = 0;
    
    for (int i = 0; i < A.size(); i++) {
        while (l < B.size()) {
            if (B[l] < A[i] - D) l++;
            else break;
        }
        while (r < B.size()) {
            if (B[r] <= A[i] + D) r++;
            else break;
        }
        
        ans += (r - l);
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