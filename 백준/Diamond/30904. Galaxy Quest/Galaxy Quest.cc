#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()
const ll V = 100005;
const double ere = 1e-9;
ll N, M, Q;
vector<ll> G[V];
double dis[V];

struct Planet{ll x, y, z;} arr[V];

struct Node {
	double d; ll n;
	bool operator>(const Node &rhs) const {
		return d > rhs.d;
	}
};

double dist(int a, int b) {
	double ret = 0;
	ret += (arr[a].x-arr[b].x)*(arr[a].x-arr[b].x);
	ret += (arr[a].y-arr[b].y)*(arr[a].y-arr[b].y);
	ret += (arr[a].z-arr[b].z)*(arr[a].z-arr[b].z);
	return sqrt(ret);
}

bool ok(double k, double ot, double limit) {
	double bt = (ot-k)/2;
	double L = (ot*ot)/4 - (bt*bt);
	double overtime = L/bt;
	if (ot-k+overtime > limit) return 0;
	else return 1;
}

void solve() {

	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) {
		ll x, y, z; cin >> x >> y >> z;
		arr[i] = {x, y, z};
	}

	while (M--) {
		ll a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 2; i <= N; i++) dis[i] = 1e18;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({0, 1});
	while (pq.size()) {
		double cd = pq.top().d;
		ll cn = pq.top().n; pq.pop();
		if (dis[cn] < cd) continue;
		for (ll nn: G[cn]) {
			double cost = cd + 2*sqrt(dist(cn, nn));
			if (cost < dis[nn]) {
				dis[nn] = cost;
				pq.push({cost, nn});
			}
		}
	}

	cout << fixed << setprecision(10);
	while (Q--) {
		ll c, t; cin >> c >> t;
		if (dis[c] > t) cout << "impossible" << '\n';
		else {
			double lo = 0, hi = dis[c];
			while (lo + ere < hi) {
				double mid = (lo+hi)/2;
				if (ok(mid, dis[c], t)) lo = mid;
				else hi = mid;
			}
			cout << dis[c] - lo << '\n';
		}
	}
	
}

int main(void) {
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}