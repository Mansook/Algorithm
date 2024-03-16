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

vi a = { 1,2,3};

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
	if (le + 1 == ri)return;
	quickSort(le, l - 1);
	quickSort(l, ri);
}

void mergeSort(int le, int ri) {
	if (le+1 == ri)return;
	int mid = (le + ri) / 2;
	mergeSort(le, mid);
	mergeSort(mid, ri);
	vi temp;
	int l = le, r = mid;
	while (1) {
		if (l == mid && r == ri)break;
		if (l == mid)
			temp.push_back(a[r++]);
		else if (r == ri)
			temp.push_back(a[l++]);
		else
			a[l] < a[r] ? temp.push_back(a[l++]) : temp.push_back(a[r++]);
	}
	for (auto r : temp) {
		a[le++] = r;
	}
}
int main() {
	FAST;
	mergeSort(0, a.size());
	for (auto r : a)cout << r << " ";
}
