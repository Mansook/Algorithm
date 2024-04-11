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

int N, M, d1[4001], v1[4001], v2[4001][2];
double d2[4001][2];
vector<pi> adj[4001];
void dij1(int s) {
	fill(d1, d1 + N + 1, 0x3f3f3f3f);
	d1[s] = 0;
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	pq.push({ d1[s],s });
	while (!pq.empty()) {
		auto [dist, cur] = pq.top();
		pq.pop();
		if (v1[cur])continue;
		v1[cur] = 1;
		for (auto [next, cost] : adj[cur]) {
			if (d1[next] > d1[cur] + cost) {
				d1[next] = d1[cur] + cost;
				pq.push({ d1[next],next });
			}
		}
	}
}
struct node {
	double dist;
	int cur;
	bool s;
	
	bool operator<(const node& d) const {
		return dist > d.dist;
	}
};
void dij2(int s) {
	REP(i, N) {
		rep(j, 2)d2[i][j] = 987654321;
	}
	d2[s][0] = 0;
	//d2[s][1] = 987654321;
	priority_queue<node>pq;
	pq.push({ d2[s][0], s, 0}); //0 : 2배로 나가야함 , 1: 1/2배로 나가야함
	while (!pq.empty()) {
		auto [dist, cur, s] = pq.top();
		pq.pop();
		if (v2[cur][s])continue;
		v2[cur][s] = 1;
		for (auto [next, cost] : adj[cur]) {
			if (s == 0) {
				if (d2[next][1] > d2[cur][0] + (double)cost / 2) {
					d2[next][1] = d2[cur][0] + (double)cost / 2;
					pq.push({d2[next][1], next, 1});
				}
			}
			else {
				if (d2[next][0] > d2[cur][1] + cost * 2) {
					d2[next][0] = d2[cur][1] + cost * 2;
					pq.push({ d2[next][0], next, 0 });
				}
			}
		}
	}
}
int main() {
	FAST;
	cin >> N >> M;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dij1(1);
	dij2(1);
	int t = 0;
	for (int i = 2; i <= N; i++) {
		if (d1[i] < d2[i][0] && d1[i] < d2[i][1]) {
			t++;
		}
	}
	cout << t;
}

