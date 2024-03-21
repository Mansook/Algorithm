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


int N, M, v[101], r[101][101];
vi a[101], b[101];

void dfs1(int k,int root) {
	if (v[k]) {
		return;
	}
	v[k] = 1;
	for (auto x : a[k]) {
		if (!v[x]) {
			r[root][x] = 1;
			r[x][root] = 1;
			dfs1(x,root);
		}
	}
}
void dfs2(int k, int root) {
	if (v[k]) {
		return;
	}
	v[k] = 1;
	for (auto x : b[k]) {
		if (!v[x]) {
			r[root][x] = 1;
			r[x][root] = 1;
			dfs2(x, root);
		}
	}
}
int main() {
	FAST;
	cin >> N >> M;
	rep(i, M) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		b[y].push_back(x);
	}
	REP(i, N) {
		r[i][i] = 1;
		mset(v);
		dfs1(i,i);
		mset(v);
		dfs2(i, i);
	}
	REP(i, N) {
		int n = 0;
		REP(j, N) {
			if (!r[i][j])n++;
		}
		cout << n << "\n";
	}
}
