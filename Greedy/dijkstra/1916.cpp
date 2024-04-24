#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false),cin.tie(NULL);
#define mset(v) memset(v,0,sizeof(v));
#define rep(i,a) for(int i=0;i<a;++i)
#define REP(i,a) for(int i=1;i<=a;++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int>ti;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };


typedef pair<int, int>pi;
int N, M, v[1001], dist[1001];
vector<pi>adj[1001];
int dij(int from, int to) {
	memset(dist, 0x3f, sizeof(dist));
	dist[from] = 0;
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push({ 0,from });
	while(!pq.empty()) {
		auto [d, cur] = pq.top(); pq.pop();
		if (v[cur])continue;
		v[cur] = 1;
		for (auto [nxt, cost] : adj[cur]) {
			if (dist[nxt] > d + cost) {
				dist[nxt] = d + cost;
				pq.push({ dist[nxt],nxt });
			}
		}
	}
	return dist[to];
}
int main() {
	cin >> N >> M;
	int a, b, c;
	while (M--) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	int from, to;
	cin >> from >> to;
	cout << dij(from, to);
}