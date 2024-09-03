#include <bits/stdc++.h>
#include "gap.h"

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll ans[100005];

long long findGap(int T, int N) {
    if (T == 1) {
        ll l = 0, r = 2e18;
        int lidx = 0, ridx = N - 1;
        
        ll mn, mx;
        for (int i = 0; i < (N + 1) / 2; i++) {
            MinMax(l, r, &mn, &mx);
            ans[lidx++] = mn, ans[ridx--] = mx;
            l = mn + 1, r = mx - 1;
        }
        
        ll ret = 0;
        for (int i = 1; i < N; i++) ret = max(ret, ans[i] - ans[i - 1]);
        
        return ret;
    }
    
    if (T == 2) {
        ll l = 0, r = 1e18 + 500;
        
        ll mn, mx;
        MinMax(l, r, &mn, &mx);
        
        l = mn, r = mx;
        
        ll len = (r - 1) - (l + 1) + 1;
        
        if (N == 2) return r - l;
        
        ll b = len / N;
        if (len % N) b++;
        
        ll ret = 0;
        
        ll p = l;
        l++;
        
        while (l < r) {
            MinMax(l, l + b, &mn, &mx);
            
            l += b + 1;
            if (mn == -1 && mx == -1) continue;
            
            ret = max(ret, mn - p);
            ret = max(ret, mx - mn);
            p = mx;
        }
        
        return ret;
    }
}