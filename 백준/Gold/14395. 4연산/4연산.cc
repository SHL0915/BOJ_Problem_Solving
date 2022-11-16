#include <iostream>
#include <queue>
#include <set>
using namespace std;

long long s, t, flag;
set<long long> mark;
queue <pair<long long, string>> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}	
	q.push({ s,"" });
	while (q.size()) BFS();
	cout << -1;
	return 0;
}

void BFS() {
	pair<long long, string> f = q.front();
	string oper = f.second;
	long long now = f.first;
	q.pop();
	if (now > 1000000000LL) return;
	if (mark.count(now) != 0) return;
	mark.insert(now);
	if (now == t) {
		cout << oper;
		exit(0);
	}
	q.push({ now * now, oper + '*' });
	q.push({ now + now, oper + '+' });
	q.push({ now - now, oper + '-' });
	if (now != 0) q.push({ 1, oper + '/' });
}