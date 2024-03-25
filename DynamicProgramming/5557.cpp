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

	ll s[21][101], N, a[101];
	ll ans;
	int main() {
		FAST;
		cin >> N;
		REP(i, N)cin >> a[i];
		s[a[1]][1] = 1;
		for (int idx = 2; idx < N; idx++) {
			for (int i = 0; i <= 20; i++) {
				if (s[i][idx - 1] > 0) {
					if (i - a[idx] >= 0) {
						s[i - a[idx]][idx] += s[i][idx - 1];
					}
					if (i + a[idx] <= 20) {
						s[i + a[idx]][idx] += s[i][idx - 1];
					}
				}
			}
		}
		cout << s[a[N]][N - 1];
	}
