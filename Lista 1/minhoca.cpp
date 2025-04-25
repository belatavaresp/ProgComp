#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

vector<vector<pii>> g;
vector<int> vis, pai;
vector<ll> dist, acum;
vector<int> stk;
vector<pii> portas;

void dfs(int u, int m) {
    vis[u] = 1;
    stk.push_back(u);
    for (auto [v, w] : g[u]) {
        if (v == pai[u]) continue;
        if (!vis[v]) {
            pai[v] = u;
            acum[v] = acum[u] + w;
            dfs(v, m);
        } else if (vis[v] == 1) {
            ll sz = w;
            int i = stk.size() - 1;
            while (stk[i] != v) {
                sz += acum[stk[i]] - acum[pai[stk[i]]];
                i--;
            }
            if (sz >= m)
                portas.emplace_back(v, sz);
        }
    }
    vis[u] = 2;
    stk.pop_back();
}

ll solve(int x, int m, int s) {
    vis.assign(s + 1, 0);
    pai.assign(s + 1, -1);
    dist.assign(s + 1, INF);
    acum.assign(s + 1, 0);
    portas.clear();
    stk.clear();

    dfs(x, m);

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[x] = 0;
    pq.emplace(0, x);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    ll res = INF;
    for (auto [v, sz] : portas) {
        if (dist[v] < INF)
            res = min(res, 2 * dist[v] + sz);
    }

    return res == INF ? -1 : res;
}

int main() {
    int s, t;
    while(cin >> s >> t){
        g.assign(s + 1, vector<pii>());
        while (t--) {
            int a, b, c; cin >> a >> b >> c;
            g[a].emplace_back(b, c);
            g[b].emplace_back(a, c);
        }

        int q; cin >> q;
        while (q--) {
            int x, m; cin >> x >> m;
            cout << solve(x, m, s) << '\n';
        }
    }
}
