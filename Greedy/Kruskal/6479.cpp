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
int N, M;

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
int r[200001];
int findParent(int a) {
	while (a != r[a]) {
		a = r[a];
	}
	return r[a];
}
void uni(int target,int root) {
	while (target != r[target]) {
		target = r[target];
	}
	r[target] = root;
}
bool checkCycle(Edge& e) {
	int fa = findParent(e.a);
	int fb = findParent(e.b);
	if (fa == fb)return false; //Same root means they are in a same subtree of V

	fa < fb ? uni(e.b,fa) : uni(e.a,fb);
	return true;
}

int main() {
	FAST;
	//kruskal 이 더 편할거같다. 왜냐하면 가중치가 싼 엣지들로 MST를 구성할거라서
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		priority_queue<Edge, vector<Edge>, comp>Q;
		int sum = 0;
		while (M--) {
			int a, b, c;
			cin >> a >> b >> c;
			sum += c; //모든 도로의 가로등 유지비용을 더함
			Q.push({ a,b,c });
		}
		rep(i, N) r[i] = i; // STEP 0. Create disjoint set of each vertex. 
		vector<Edge>E; //STEP 0. make empty set
		//STEP 1. Sort is implemented by Priority Queue !
		while (!Q.empty()) {//while not solved yet
			auto top = Q.top();
			Q.pop();
			if (checkCycle(top)) {//STEP2. feasibility : check if there is Cycle
				E.push_back(top);
			}
		}
		int mst = 0;
		for (auto r : E) {
			mst += r.w;
		}
		cout << sum - mst << "\n";
	}
}
