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

int N, s[301], a[301][2];

int main() {
	FAST;
	cin >> N;
	REP(i, N) {
		cin >> s[i];
	}
	a[1][0] = a[1][1] = s[1];
	a[2][0] = s[2];
	a[2][1] = s[1] + s[2];
	if (N <= 2) {
		cout << max(a[N][0], a[N][1]);
		return 0;
	}
	for (int i = 3; i <= N; i++) {
		a[i][0] = s[i] + max(a[i - 2][0], a[i - 2][1]);
		a[i][1] = s[i] + a[i - 1][0];
	}
	cout << max(a[N][0], a[N][1]);
}
