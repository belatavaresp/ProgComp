#include <iostream>
#include <cmath>
#include <vector>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

int main() {
    int n, c, t;
    int z, u = 0;
    int d, j = 1;
    int r;
    bool ok = false;

    cin >> n >> c >> t;
    vector<int> q(n);

    for (int i = 0; i < n; i++) {
        cin >> q[i];
        u = max(u, q[i]);
    }

    z = pow(2, (int)ceil(log2(u / t)));
    d = z / 2;

    while (j != 0) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ceil(q[i] * 1.0 / t) > z || cnt == c) {
                cnt = c + 1;
                break;
            }
            if (ceil((double)(sum + q[i]) / (t * 1.0)) <= z) {
                sum += q[i];
            } else {
                cnt++;
                sum = q[i];
            }
        }
        cnt++;
        j = (z - d) / 2;

        if (cnt <= c) {
            r = z;
            ok = true;
            z -= j;
        } else if (ok) {
            d = z;
            z += j;
        } else {
            j = 1;
            d = z;
            z = z * 2;
        }
    }

    cout << r << endl;
    exit(0);
}
