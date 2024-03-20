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

int t, n;
vi pre, ino;
void DC(int pfrom, int pto, int ifrom, int ito) {
	if (pfrom == pto) {
		cout << pre[pfrom] << " ";
		return;
	}
	int M = pre[pfrom];
	int iidx;
	rep(i, n) {
		if (ino[i] == M) {
			iidx = i; break;
		}
	}
	int Ls = iidx - ifrom;
	int Rs = ito - iidx;
	if (pfrom + 1 <= pfrom + Ls) {
		DC(pfrom + 1, pfrom + Ls, ifrom, ifrom + Ls - 1);
	}
	if (iidx + 1 <= ito) {
		DC(pfrom + Ls + 1, pto, iidx + 1, ito);

	}
	cout << M << ' ';
}
int main() {
	FAST;
	cin >> t;
	while (t--) {
		pre.clear(), ino.clear();
		cin >> n;
		rep(i, n) {
			int x;
			cin >> x;
			pre.push_back(x);
		}
		rep(i, n) {
			int x;
			cin >> x;
			ino.push_back(x);
		}
		DC(0, n - 1, 0, n - 1);
		cout << "\n";
	}
}
