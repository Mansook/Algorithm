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

vi a = { 1,2,3,5,7,8,9,11,14,15,16,20,24,33,35,44};
bool binarySearch(int target) {
	int le = 0, ri = a.size() - 1, mid;
	while (le <= ri) {
		mid = (le + ri) / 2;
		if (a[mid] == target)return true;
		a[mid] > target ? ri = mid - 1 : le = mid + 1;
	}
	return false;
}
int main() {
	FAST;
	int x;
	cin >> x;
	cout << binarySearch(x);
}
