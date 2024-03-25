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

	int N, M, a[2001][2001];
	int main() {
		FAST;
		cin >> N;
		REP(i, N) {
			cin >> a[0][i];
			a[1][i] = 1;
		}
		for (int level = 2; level <= N;level++) {
			for(int i=1;i<=N-level+1;i++) {
				if (level == 2) {
					if (a[0][i] == a[0][i + 1])
						a[level][i] = 1;
				}
				else {
					if (a[0][i] == a[0][i + level - 1] && a[level - 2][i + 1]) {
						a[level][i] = 1;
					}
				}
			}
		}
		cin >> M;
		rep(i, M) {
			int x,y;
			cin >> x >> y;
			cout << a[y - x + 1][x] << "\n";
		}
	}
