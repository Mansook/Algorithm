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
int N, w[1001][1001];

struct Edge {
	int a;
	int b;
	int w;
	bool operator<(const Edge& d) {
		return w > d.w;
	}
};
struct comp {
	bool operator()(Edge& f, Edge& d) {
		return f.w > d.w;
	}
};

int inY[1001]; //it shows if a specific vertex is in Y
ll sum = 0;
int main() {
	FAST;
	//let's use Prim's algorithm
	priority_queue<Edge, vector<Edge>,comp>Q;
	cin >> N;
	REP(i, N)REP(j, N) {
		cin >> w[i][j];
	}
	int cur = 1; //let's start with 1
	inY[cur] = 1;
	vector<int>Y; //create an empty set
	Y.push_back(cur);
	while(Y.size()!=N) {  //V-1 times

		REP(i, N) {//EXTRACT_MIN : find nearest vertex from Y in V-Y
			if (inY[i])continue; //if i is in Y continue;
			Q.push({ cur,i,w[cur][i] });
		}
		while (inY[Q.top().a] && inY[Q.top().b]) {
			Q.pop();
		}
		auto e = Q.top();
		Q.pop();

		inY[e.a] ? cur = e.b : cur = e.a;
		
		Y.push_back(cur);
		inY[cur] = 1;
		sum += e.w;

	}
	cout << sum;
}
