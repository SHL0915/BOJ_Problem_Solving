#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pll = pair<ll, ll>;
 
#define all(v) (v).begin(), (v).end()
#define X first
#define Y second
 
 
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
 
// end of def
 
 
ll ccw(pll a, pll b, pll c){
    return a.X * b.Y + b.X * c.Y + c.X * a.Y - a.Y * b.X - b.Y * c.X - c.Y * a.X;
}
 
void CH(vector<pll> &v){
    vector<pll> up, dw;
    sort(all(v));
    for (pll p: v){
        while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p) <= 0) up.pop_back();
        while (dw.size() >= 2 && ccw(dw[dw.size() - 2], dw[dw.size() - 1], p) >= 0) dw.pop_back();
        up.emplace_back(p);
        dw.emplace_back(p);
    }
    v.clear();
    for (pll p: up){
        v.emplace_back(p);
    }
    for (int i=dw.size() - 2;i >= 1; i--){
        v.emplace_back(dw[i]);
    }
}
 
bool pt_in_ch(vector<pll> &p, pll q){
    int n = p.size();
    if (ccw(p[0], p[n - 1], q) > 0) return false;
    if (ccw(p[0], p[1], q) < 0) return false;
    int s = 1, e = n - 1;
    while (s < e){
        int m = (s + e) >> 1;
        if (ccw(p[0], p[m], q) >= 0) s = m + 1;
        else e = m;
    }
    return ccw(p[s - 1], p[s], q) >= 0;
}
 
int main() {
    fastio;
    int n; cin >> n;
    vector<pll> v;
    for (int i=1;i<=n;i++){
        ll x, y; cin >> x >> y;
        v.emplace_back(x, y);
    }
    CH(v);
    int m; cin >> m;
    int ans = 0;
    for (int i=0;i<m;i++){
        ll x, y; cin >> x >> y;
        if (pt_in_ch(v, {x, y})) ans++;
    }
    cout << ans << endl;
    return 0;
}