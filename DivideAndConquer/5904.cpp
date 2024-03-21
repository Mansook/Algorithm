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
ll s[31];
int main() {
	FAST;
	cin >> n;
	int k = 1;
	s[0] = 3;
	while (s[k-1]<n) {
		s[k++] = 2 * s[k - 1] + 3 + k;
	}
	int idx = k - 1;
	int mid = k + 2;
	while (1) {
		if (idx == 0)break;
		else if (n <= s[idx - 1]) {
			idx--;
			mid--;
		}
		else if (n - s[idx - 1] <= mid) {
			if (n - s[idx - 1] == 1) {
				cout << 'm';
				return 0;
			}
			cout << 'o';
			return 0;
		}
		else {
			n = n - s[idx - 1] - mid;
			idx--;
			mid--;
		}
	}
	n == 1 ? cout << 'm' : cout << 'o';
}
