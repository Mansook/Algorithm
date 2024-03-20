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
void ctor(int n,int f) {
	if (!f) {
		rep(i, pow(3, n))cout << ' ';
		return;
	}
	if (n == 0) {
		cout << '-';
		return;
	}
	ctor(n - 1,1);
	ctor(n - 1,0);
	ctor(n - 1,1);
}
int main() {
	FAST;
	while (cin >> n) {
		ctor(n,1);
		cout << "\n";
	}
}
