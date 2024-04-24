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

int N, M, w[201][201],v[201],dist[201][201], INF = 987654321;
vi adj[201];
int find(int from, int to) {
	while (w[from][to] != from) {
		to = w[from][to];
	}
	return to;
}
int main() {
	FAST;
	cin >> N >> M;
	REP(i, N) {
		fill(dist[i], dist[i] + N + 1, 0x3f3f3f3f);
		dist[i][i] = 0;
	}
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	REP(i, N)REP(j, N)w[i][j] = i;
	REP(k, N) {
		REP(i, N) {
			REP(j, N) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					w[i][j] = k;
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	REP(i, N) {
		REP(j, N) {
			if (i == j)
				cout << "- ";
			else
				cout << find(i, j) << " ";
		}
		cout << "\n";
	}
}


