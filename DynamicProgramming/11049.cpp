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

int N, r, c, dp[501][501], s[501][2], INF = 987654321;
int main() {
	FAST;
	cin >> N;
	REP(i, N) {
		cin >> s[i][0] >> s[i][1];
	}
	REP(i, N)dp[i][i] = 0;
	for (int i = N - 1; i >= 1; i--) {
		for (int j = i + 1; j <= N; j++) {
			dp[i][j] = INF;
			for (int k = i; k <= j - 1; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[i][0] * s[j][1] * s[k][1]);
			}
		}
	}
	cout << dp[1][N];
}

