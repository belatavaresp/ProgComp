#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int N, M, K;
    double P;

    while (cin >> N >> M >> K >> P) {
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }

        int A;
        cin >> A;
        vector<int> sni(N, 0);
        for (int i = 0; i < A; ++i) {
            int pos;
            cin >> pos;
            sni[pos - 1]++;
        }

        int start, end;
        cin >> start >> end;
        start--; end--;

        vector<int> dist(N, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[start] = sni[start];
        pq.emplace(dist[start], start);

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (int v : adj[u]) {
                int new_cost = cost + sni[v];
                if (new_cost < dist[v]) {
                    dist[v] = new_cost;
                    pq.emplace(new_cost, v);
                }
            }
        }

        if (dist[end] > K) {
            cout << fixed << setprecision(3) << 0.000 << '\n';
        } else {
            double prob = pow(P, dist[end]);
            cout << fixed << setprecision(3) << prob << '\n';
        }
    }

	exit(0);
}