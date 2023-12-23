#include <stdio.h>
#include <string.h>
//#include <time.h>

typedef struct edge {
    long long u, v, cost;
} edge;

int V, E;
edge min_heap[100005];
int avail = 0, idx = 0;
edge ans[100005];
int par[10005];

int find(int a) {
    if (par[a] == a) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) par[a] = b;
    else par[b] = a;
    return;
}

void insert_heap(edge a) {
    int i = ++avail;
    while ((i > 1) && (min_heap[i / 2].cost > a.cost)) {
        min_heap[i] = min_heap[i / 2];
        i /= 2;
    }
    min_heap[i] = a;
    return;
}

edge pop_heap() {
    int par = 1, ch = 2;
    edge ret, temp;
    ret = min_heap[1];
    temp = min_heap[avail--];
    while (ch <= avail) {
        if ((ch < avail) && (min_heap[ch].cost > min_heap[ch + 1].cost)) ch++;
        if (temp.cost <= min_heap[ch].cost) break;
        min_heap[par] = min_heap[ch];
        par = ch;
        ch *= 2;
    }
    min_heap[par] = temp;
    return ret;
}

int main(void) {    
    //time_t s = time(NULL);
    
    scanf("%d", &V);
    scanf("%d", &E);

    for (int i = 0; i < V; i++) par[i] = i;
    for (int i = 0; i < E; i++) {
        long long u, v, c;
        scanf("%lld %lld %lld", &u, &v, &c);
        edge now;
        now.u = u;
        now.v = v;
        now.cost = c;
        insert_heap(now);
    }

    int cnt = 0;
    long long tot = 0;

    for (int i = 0; i < E; i++) {
        if (cnt == V - 1) break;
        edge now = pop_heap();
        long long u = now.u, v = now.v, c = now.cost;
        if (find(u) == find(v)) continue;
        else {
            merge(u, v);
            ans[idx++] = now;
            cnt++;
            tot += c;
        }
    }

    printf("%lld", tot);

    //time_t e = time(NULL);
    return 0;
}