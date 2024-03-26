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

	int n, a[5001], s[5001];
	int main() {
		FAST;
		char c;
		int num = 0;
		bool z = 0;
		while (cin >> c) {
			s[++num] = c - '0';
		}
		a[0] = 1;
		a[1]= 1;
		if (s[1] == 0) {
			cout << 0;
			return 0;
		}
		for (int i = 2; i <= num; i++) {
			if (s[i] != 0) {
				z = 0;
				a[i] += a[i - 1];
				a[i] %= 1000000;
				if (s[i-1]!=0 && (s[i - 1] * 10 + s[i]) <= 26) {
					a[i] += a[i - 2];
				}
			}
			else {
				if (z || s[i - 1] > 2) {
					cout << 0;
					return 0;
				}
				z = 1;
				a[i] += a[i - 2];
			}
			a[i] %= 1000000;
		}
		cout << a[num] % 1000000;
	}
