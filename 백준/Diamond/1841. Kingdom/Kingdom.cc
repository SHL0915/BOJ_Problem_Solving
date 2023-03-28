#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, G, E;
vector <pii> org[155];
vector <int> graph[155];
vector <pair<double, pair<pii, int>>> edge;
int cap[155][155], flow[155][155], parent[155];
int distA[155], distB[155];

void Dijkstra(int start, int type);
void add_Edge(int u, int v, int c);
int find_Max(int s, int e);
double cal(int a1, int a2, int b1, int b2, double l, double c);

void solve() {
    cin >> N >> G >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 95050) a = N;
        if (a == 104729) a = N + 1;
        if (b == 95050) b = N;
        if (b == 104729) b = N + 1;
        org[a].push_back({ b,c });
        org[b].push_back({ a,c });
        add_Edge(a, b, 1);
        add_Edge(b, a, 1);
        edge.push_back({ 0, {{a,b},c} });
    }

    memset(distA, INF, sizeof(distA));
    memset(distB, INF, sizeof(distB));

    Dijkstra(N, 0); Dijkstra(N + 1, 1);

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i].second.first.first, b = edge[i].second.first.second, c = edge[i].second.second;
        int a1 = distA[a], a2 = distB[a], b1 = distA[b], b2 = distB[b];

        double l = 0;
        double val = cal(a1, a2, b1, b2, l, c);

        l = c;
        val = min(val, cal(a1, a2, b1, b2, l, c));

        l = (double)(b2 + c - a1) / 2;
        if (l >= 0 && l <= c) val = min(val, cal(a1, a2, b1, b2, l, c));


        l = (double)(b1 + c - a2) / 2;
        if (l >= 0 && l <= c) val = min(val, cal(a1, a2, b1, b2, l, c));
        edge[i].first = val;
    }

    sort(edge.begin(), edge.end(), greater<>());

    if (find_Max(N, N + 1) > G) {
        cout << "Impossible";
        return;
    }

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i].second.first.first, b = edge[i].second.first.second;
        cap[a][b] = INF; cap[b][a] = INF;

        int min_cut = find_Max(N, N + 1);

        if (min_cut > G) {
            cout << edge[i].first;
            break;
        }
    }

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

void Dijkstra(int start, int type) {
    priority_queue <pii, vector<pii>, greater<>> pq;
    pq.push({ 0, start });
    if (type) distB[start] = 0;
    else distA[start] = 0;

    while (pq.size()) {
        pii t = pq.top(); pq.pop();
        int now = t.second, val = t.first;

        if (type && distB[now] < val) continue;
        if (type == 0 && distA[now] < val) continue;

        for (int i = 0; i < org[now].size(); i++) {
            int next = org[now][i].first;
            int next_val = val + org[now][i].second;
            if (type) {
                if (distB[next] > next_val) {
                    distB[next] = next_val;
                    pq.push({ next_val, next });
                }
            }
            else {
                if (distA[next] > next_val) {
                    distA[next] = next_val;
                    pq.push({ next_val, next });
                }
            }
        }
    }
    return;
}

void add_Edge(int u, int v, int c) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    cap[u][v] = c;
    return;
}

int find_Max(int s, int e) {
    int ret = 0;
    while (1) {
        memset(parent, -1, sizeof(parent));
        queue <int> q;
        q.push(s);
        while (q.size()) {
            int f = q.front(); q.pop();
            if (f == e) break;
            for (int i = 0; i < graph[f].size(); i++) {
                int now = graph[f][i];
                if (parent[now] == -1 && cap[f][now] - flow[f][now] > 0) {
                    parent[now] = f;
                    q.push(now);
                }
            }
        }
        if (parent[e] == -1) break;
        int val = 0x3f3f3f3f;
        for (int i = e; i != s; i = parent[i]) val = min(val, cap[parent[i]][i] - flow[parent[i]][i]);
        for (int i = e; i != s; i = parent[i]) {
            flow[parent[i]][i] += val;
            flow[i][parent[i]] -= val;
        }
        ret += val;
    }
    return ret;
}

double cal(int a1, int a2, int b1, int b2, double l, double c) {
    return max(min(a1 + l, b1 + c - l), min(a2 + l, b2 + c - l));
}