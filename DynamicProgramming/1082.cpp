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
int N, M, p[11];
struct n {
	int num[11] = { 0 };
	
	int ret() {
		int r = 0;
		REP(i, N) {
			r += num[i];
		}
		return r;
	}
};
n dp[51][10];
int main() {
	FAST;
	cin >> N;
	REP(i, N)cin >> p[i];
	cin >> M;
	for (int i = 2; i <= N; i++) {
		for (int cost = 1; cost <= M; cost++) {
			auto a = dp[cost][i - 1];
			if (cost - p[i] < 0) {
				dp[cost][i] = a;
				continue;
			}
			auto b = dp[cost - p[i]][i];
			b.num[i]++;

			n c;
			c.num[i]++;
			c.num[1] += (int)(cost - p[i]) / p[1];

			int al = a.ret();
			int bl = b.ret();
			int cl = c.ret();

			if (al > bl && al > cl) {
				dp[cost][i] = a;
			}
			else if (bl >= cl) {
				dp[cost][i] = b;
			}
			else
				dp[cost][i] = c;
		}
	}
	vi vt;
	for (int i = 1; i <= 10; i++) {
		rep(j, dp[M][N].num[i])
			vt.push_back(i - 1);
	}
	if (!vt.size()) {
		cout << 0;
	}
	else {
		sort(vt.begin(), vt.end(), greater<int>());
		rep(i, vt.size())cout << vt[i];
	}
}
