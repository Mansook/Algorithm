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
int N, ar[1200][1200];
void div(int k) {
	
	rep(i, k / 2) {
		rep(j, k / 2) {
			vi temp;
			temp.push_back(ar[i * 2][j * 2]);
			temp.push_back(ar[i * 2][j * 2 + 1]);
			temp.push_back(ar[i * 2 + 1][j * 2]);
			temp.push_back(ar[i * 2 + 1][j * 2 + 1]);
			sort(temp.begin(), temp.end());
			ar[i][j] = temp[2];
		}
	}
	if (k == 2) {
		cout << ar[0][0];
		return;
	}
	div(k / 2);
}
int main() {
	FAST;
	cin >> N;
	rep(i, N) 
		rep(j, N) 
			cin >> ar[i][j];
	div(N);
}
