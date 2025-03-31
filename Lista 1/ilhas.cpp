#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<vector<ii>> g;
vector<int> w, vis;
int gr = -INF;
int sm = INF;

void djikstra(int s){
	priority_queue<ii> pq;
	w[s] = 0;
	pq.push(make_pair(0, s));

	while(!pq.empty()){
		ii cur = pq.top();
		pq.pop();

		if(!vis[cur.second]){
			vis[cur.second] = 1;

			for(auto it : g[cur.second]){
				if (w[it.second] > w[cur.second] + it.first){
					w[it.second] = w[cur.second] + it.first;

					pq.push(make_pair(-w[it.second], it.second));
				}
			}
		}
	}
}

int main() { _
    int n, m;
	cin >> n >> m;
	g.resize(n);
	w.resize(n, INF);
	vis.resize(n, 0);

	for(int i = 0; i < m; i++){
		int u, v, p;
		cin >> u >> v >> p;
		u--; v--;

		g[u].push_back(make_pair(p,v));
		g[v].push_back(make_pair(p,u));
	}
	int s;
	cin >> s;
	s--;
	djikstra(s);

	for (int i = 0; i < n; i++) {
        if (i == s) continue;

        gr = max(gr, w[i]);
        sm = min(sm, w[i]);
    }

	cout << gr-sm << endl;

	exit(0);
}