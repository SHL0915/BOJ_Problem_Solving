#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
ll ans = 0;

struct Trie {
    Trie *ch[2];
    int level;

    Trie(int lv) {
        level = lv;
        memset(ch, 0, sizeof(ch));
    }

    ~Trie() {
        delete ch[0];
        delete ch[1];
    }

    void insert(const char *s) {
        if (!*s) return;
        else {
            int now = *s - '0';
            if (!ch[now]) ch[now] = new Trie(level - 1);
            ch[now]->insert(s + 1);
        }
    }

    ll DNC(Trie *A, Trie *B) {
        ll ret = INF;
        if (!A->ch[0] && !A->ch[1] && !B->ch[0] && !B->ch[1]) return 0;
        if (A->ch[0] && B->ch[0]) ret = min(ret, DNC(A->ch[0], B->ch[0]));
        if (A->ch[1] && B->ch[1]) ret = min(ret, DNC(A->ch[1], B->ch[1]));
        if (ret != INF) return ret;
        if (A->ch[0] && B->ch[1]) ret = min(ret, (1LL << A->level) + DNC(A->ch[0], B->ch[1]));
        if (A->ch[1] && B->ch[0]) ret = min(ret, (1LL << A->level) + DNC(A->ch[1], B->ch[0]));
        return ret;
    }

    ll find_ans() {
        ll ret = 0;
        if (ch[0] && ch[1]) ret += (1LL << level) + DNC(ch[0], ch[1]);
        if (ch[0]) ret += ch[0]->find_ans();
        if (ch[1]) ret += ch[1]->find_ans();
        return ret;
    }

};

string convert(int a) {
    string ret = "";
    for (int i = 30; i >= 0; i--) {
        if (a & (1 << i)) ret += '1';
        else ret += '0';
    }
    return ret;
}

void solve() {
    cin >> N;
    Trie *root = new Trie(30);

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        string s = convert(a);
        root->insert(s.c_str());
    }

    ans = root->find_ans();

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