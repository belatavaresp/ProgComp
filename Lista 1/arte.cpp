#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k;

struct circle {
    int x, y, r, idx = -1;
};

double dist(circle &a, circle &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool inter(circle &a, circle &b) {
    return dist(a, b) <= a.r + b.r;
}

int main() {
    cin >> n >> m >> k;
    vector<circle> c(k);
    vector<vector<int>> comps;

    for (int i = 0; i < k; i++)
        cin >> c[i].x >> c[i].y >> c[i].r;

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (!inter(c[i], c[j])) continue;
            int a = c[i].idx, b = c[j].idx;
            if (a == -1 && b == -1) {
                c[i].idx = c[j].idx = comps.size();
                comps.pb({i, j});
            } else if (a != -1 && b == -1) {
                c[j].idx = a;
                comps[a].pb(j);
            } else if (a == -1 && b != -1) {
                c[i].idx = b;
                comps[b].pb(i);
            } else if (a != b) {
                for (int id : comps[b]) {
                    c[id].idx = a;
                    comps[a].pb(id);
                }
                comps[b].clear();
            }
        }
        if (c[i].idx == -1) {
            c[i].idx = comps.size();
            comps.pb({i});
        }
    }

    for (auto &gr : comps) {
        int minX = n + 1, maxX = 0, minY = m + 1, maxY = 0;
        for (int i : gr) {
            auto &[x, y, r, __] = c[i];
            minX = min(minX, x - r);
            maxX = max(maxX, x + r);
            minY = min(minY, y - r);
            maxY = max(maxY, y + r);
        }
        if ((minX <= 0 && (maxX >= n || minY <= 0)) ||
            (maxY >= m && (minY <= 0 || maxX >= n))) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
    return 0;
}
