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
vi in, pre, post;
void recur(int infrom,int into,int postfrom,int postto) {
	int M = post[postto];
	cout << M << " ";
	if (infrom==into)return;

	int inmid = 0;
	for (int i = infrom; i <= into; i++) {
		if (in[i] == M) {
			inmid = i;
			break;
		}
	}
	int len = inmid - infrom;
	if(infrom<=inmid-1)
		recur(infrom,inmid-1,postfrom,postfrom+len-1);
	if(inmid+1<=into)
		recur(inmid+1,into,postfrom+len,postto-1);
}
int main() {
	FAST;
	cin >> n;
	int x;
	rep(i, n) {  //in
		cin >> x;
		in.push_back(x);
	}
	rep(i, n) { //post
		cin >> x;
		post.push_back(x);
	}
	recur(0,n-1,0,n-1);
}
