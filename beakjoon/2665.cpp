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
int N, MAX = 987654321;
int a[51][51], v[51][51];

int main() {
	FAST;
	cin >> N;
	char x;
	REP(i, N) {
		REP(j, N) {
			cin >> x;
			a[i][j] = (x - '0');
			v[i][j] = MAX;
		}
	}
	queue<pi>q;
	q.push({ 1,1 });
	v[1][1] = 0;
	while (!q.empty()) {
		auto top = q.front();
		q.pop();
		int y = top.first;
		int x = top.second;
		rep(i, 4) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (a[ny][nx] == 1 && v[ny][nx]>v[y][x]) {
				v[ny][nx] = v[y][x];
				q.push({ ny,nx });
			}
			else if (a[ny][nx] == 0 && v[ny][nx] > v[y][x] + 1) {
				v[ny][nx] = v[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	cout << v[N][N];
}
