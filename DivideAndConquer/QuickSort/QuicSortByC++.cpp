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

vi a = { 2, 3, 6, 5, 4, 8, 9, 1, 7 };

void quickSort(int le, int ri) {
	if (le == ri)return;
	int pivot = a[(le + ri) / 2];
	int l = le, r = ri;
	while (l < r) {
		while (a[l] < pivot)l++;
		while (a[r] > pivot)r--;

		int temp = a[l];
		a[l] = a[r];
		a[r] = temp;
	}
    if(le+1==ri)return;
	quickSort(le, l-1);
	quickSort(l, ri);
}
int main() {
	FAST;
	quickSort(0, a.size() - 1);
	for (auto r : a) {
		cout << r << " ";
	}
}
