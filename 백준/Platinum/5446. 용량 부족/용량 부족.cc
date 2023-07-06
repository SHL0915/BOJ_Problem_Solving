#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Trie {
    map<char, Trie *> ch;
    int a, b, acnt, bcnt;

    Trie() {
        acnt = 0;
        bcnt = 0;
    }

    ~Trie() {
        for (auto i = ch.begin(); i != ch.end(); i++) delete (*i).second;
    }

    void insert(const char *s, int type) {
        if (!*s) {
            if (type == 0) acnt++;
            else bcnt++;
        } else {
            char next = *s;
            if (ch.count(next) == 0) ch[next] = new Trie;
            ch[next]->insert(s + 1, type);
        }
    }

    void psum() {
        a = acnt;
        b = bcnt;
        for (auto i = ch.begin(); i != ch.end(); i++) {
            (*i).second->psum();
            a += (*i).second->a;
            b += (*i).second->b;
        }
        return;
    }

    int query() {
        int ret = 0;
        if (a != 0 && b == 0) {
            a = 0;
            return 1;
        }

        a = acnt;
        for (auto i = ch.begin(); i != ch.end(); i++) {
            ret += (*i).second->query();
            a += (*i).second->a;
        }

        return ret;
    }
};

int A, B;

void solve() {
    cin >> A;

    Trie *root = new Trie;

    for (int i = 0; i < A; i++) {
        string s;
        cin >> s;
        root->insert(s.c_str(), 0);
    }

    cin >> B;

    for (int i = 0; i < B; i++) {
        string s;
        cin >> s;
        root->insert(s.c_str(), 1);
    }

    root->psum();

    int ans = root->query() + root->a;

    cout << ans << '\n';

    delete root;
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}