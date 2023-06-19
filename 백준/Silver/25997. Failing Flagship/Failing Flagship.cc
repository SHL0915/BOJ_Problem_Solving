#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string X, Y;

double cal(string s);

void solve() {
    cin >> X >> Y;
    double a = cal(X);
    double b = cal(Y);
    
    double cw = a - b;
    double ccw = b - a;
    
    while (cw < 0) cw += 360;
    while (cw >= 360) cw -= 360;
    
    while (ccw < 0) ccw += 360;
    while (ccw >= 360) ccw -= 360;
    
    cout << min(cw, ccw);
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

double cal(string s) {
    double now = 90, ret = 0;
    switch (s.back()) {
        case 'N' :
            ret = 0;
            break;
        case 'E' :
            ret = 90;
            break;
        case 'S' :
            ret = 180;
            break;
        case 'W' :
            ret = 270;
            break;
    }
    
    for (int i = s.length() - 2; i >= 0; i--) {
        char cur = s[i];
        now /= 2;
        
        if (cur == 'N') {
            if (ret <= 180) ret -= now;
            else ret += now;
        } else if (cur == 'E') {
            if (ret <= 90) ret += now;
            else ret -= now;
        } else if (cur == 'S') {
            if (ret <= 180) ret += now;
            else ret -= now;
        } else {
            if (ret <= 270) ret += now;
            else ret -= now;
        }
    }
    
    return ret;
}