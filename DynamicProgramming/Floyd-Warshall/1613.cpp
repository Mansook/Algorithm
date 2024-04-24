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

int N, M, K, S, adj[401][401], INF = 987654321;
int main() {
	FAST;
	cin >> N >> K;
	REP(i, N)REP(j, N) {
		adj[i][j] = INF;
		if (i == j)adj[i][j] = 0;
	}
	while (K--) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
	}
	REP(k, N) {
		REP(i, N) {
			REP(j, N) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
	cin >> S;
	while (S--) {
		int a, b;
		cin >> a >> b;
		if (adj[a][b] == INF && adj[b][a] == INF) {
			cout << 0 << "\n";
		}
		else if (adj[a][b] == INF && adj[b][a] < INF) {
			cout << 1 << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
}


