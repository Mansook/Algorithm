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

int n;
vi a[129];
int w, b;
int check(int x, int y, int s) {
	int t = 0;
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			t += (a[i][j]-'0');
		}
	}
	if (t == 0) { 
		return 2;
	}
	else if (t == s * s) {
		return 1;
	}
	return 0;
}
void dc(int x, int y, int s) {
	if (s == 1) {
		a[x][y]-'0' == 0 ? cout << 0 : cout << 1;
		return;
	}
	int r = check(x, y, s);
	if (r==0) {
		//divide
		cout << "(";
		dc(x, y, s / 2);
		dc(x, y + s / 2, s / 2);
		dc(x + s / 2, y, s / 2);
		dc(x + s / 2, y + s / 2, s / 2);
		cout << ")";
		return;
	}
	if (r == 1)cout << 1;
	else cout << 0;

}
int main() {
	FAST;
	cin >> n;
	rep(i, n) {
		rep(j, n) {
			char x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	dc(0, 0, n);

}
