#include <bits/stdc++.h>
using namespace std;
constexpr int SZ = 1 << 21;

int T[SZ<<1], L[SZ<<1];

// 실험, 출처 https://justicehui.github.io/ps/2023/02/03/BOJ2601/#

void Push(int node, int s, int e){
    T[node] += L[node];
    if(s != e) L[node<<1] += L[node], L[node<<1|1] += L[node];
    L[node] = 0;
}

void Update(int l, int r, int v, int node=1, int s=0, int e=SZ-1){
    Push(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){ L[node] += v; Push(node, s, e); return; }
    int m = (s + e) / 2;
    Update(l, r, v, node<<1, s, m);
    Update(l, r, v, node<<1|1, m+1, e);
    T[node] = max(T[node<<1], T[node<<1|1]);
}

int Query(int l, int r, int node=1, int s=0, int e=SZ-1){
    Push(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return T[node];
    int m = (s + e) / 2;
    return max(Query(l, r, node<<1, s, m), Query(l, r, node<<1|1, m+1, e));
}

struct Event{
    int t, l, r, v;
    Event() = default;
    Event(int t, int l, int r, int v) : t(t), l(l), r(r), v(v) {}
    bool operator < (const Event &e) const { return t < e.t; }
};

int K, N, R, X1, Y1, X2, Y2;
vector<Event> E;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> X1 >> Y2 >> X2 >> Y1 >> K >> N; X1 += K; Y1 += K; E.reserve(N+N);
    for(int i=0; i<N; i++){
        int r2, c2, r1, c1; cin >> r2 >> c1 >> r1 >> c2;
        r2 += K; c2 += K;
        if(r1 <= r2 && c1 <= c2) E.emplace_back(r1, c1, c2, +1), E.emplace_back(r2+1, c1, c2, -1);
    }
    sort(E.begin(), E.end());
    for(int i=0, j=0; i<E.size(); i=j){
        while(j < E.size() && E[i].t == E[j].t) Update(E[j].l, E[j].r, E[j].v), j++;
        // if(X1 <= E[i].t && E[i].t <= X2) R = max(R, Query(Y1, Y2));
        Push(1, 0, SZ-1); R = max(R, T[1]);
    }
    cout << R;
}