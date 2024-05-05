#include <iostream>
#include <queue>

using namespace std;

void solve() {
    queue<int> q;
    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        if (s[0] == 'p' && s[1] == 'u') {
            int x;
            cin >> x;
            q.push(x);
        } else if (s[0] == 'p') {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (s[0] == 's') {
            cout << q.size() << '\n';
        } else if (s[0] == 'e') {
            cout << q.empty() << '\n';
        } else if (s[0] == 'f') {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else if (s[0] == 'b') {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;

    while (t--)
        solve();

    return 0;
}