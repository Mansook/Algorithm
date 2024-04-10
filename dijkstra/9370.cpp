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

int T, n, m, t, s, g, h, a, b, d, x;
int weight[2001][2001], W[2001], v[2001], visited[2001],INF = 987654321, target[2001];
vi adj[2001], before[2001];
void dij(int start) {
	W[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ W[start],start });
	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();
		if (v[cur])continue;
		v[cur] = 1;
		for (int next : adj[cur]) {
			if (W[next] > W[cur] + weight[cur][next]) {
				W[next] = W[cur] + weight[cur][next];
				before[next].clear();
				before[next].push_back(cur);
				pq.push({ W[next],next });
			}
			else if (W[next] == W[cur] + weight[cur][next]) {
				before[next].push_back(cur);
			}
		}
	}
}
void dfs(int x,int root) {
	visited[x] = 1;
	for (auto r : before[x]) {
		if ((x == g && r == h) || (x == h && r == g)) {
			target[root] = 1;
			return;
		}
		if (!visited[r])
			dfs(r,root);
	}
	return;
}
int main() {
	FAST;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t >> s >> g >> h;
		REP(i, n)REP(j, n)weight[i][j] = INF;
		REP(i, n) { W[i] = INF; adj[i].clear(); before[i].clear(); }
		mset(v);
		mset(target);
		mset(visited);
		while (m--) {
			cin >> a >> b >> d;
			weight[a][b] = d;
			weight[b][a] = d;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dij(s);

		while (t--) {
			cin >> x;
			mset(visited);
			dfs(x,x);
		}
		REP(i, n)if (target[i])cout << i << " ";
		cout << "\n";
	}
}

