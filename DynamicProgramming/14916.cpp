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

	int n, a[100001][2];
	int main() {
		FAST;
		cin >> n;
		a[1][0] = a[1][1] = a[3][0] = a[3][1] = -1;
		a[2][0] = 1;
		a[4][0] = 2;
		a[5][1] = 1;
		if (n == 1 || n == 3) { cout << -1; return 0; }
		if (n <= 5) { cout << a[n][0] + a[n][1]; return 0; }
		for (int i = 6; i <= n; i++) {
			if (i - 5 != 1 && i - 5 != 3) {
				a[i][0] = a[i - 5][0];
				a[i][1] = a[i - 5][1] + 1;
			}
			else {
				a[i][0] = a[i - 2][0] + 1;
				a[i][1] = a[i - 2][1];
			}
		}
		cout << a[n][0] + a[n][1];
	}
