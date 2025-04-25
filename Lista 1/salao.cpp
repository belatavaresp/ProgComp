#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

int l;
vector<int> v;
unordered_map<int, int> s;

int check(int a, int b) {
    if (a % l != 0) return -1;
    int cnt = a / l;
    
    if (s.count(b) && s[b] >= cnt) {
        return cnt;
    }

    int res = s.count(b) ? s[b] : 0;
    int need = cnt - res;
    int count = 0;
    bool got = false;

    unordered_map<int, int> freq = s;
    freq[b] = 0;

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < v.size(); i++) {
        int x = v[i];
        if (x >= b || freq[x] == 0) continue;

        int y = b - x;
        if (x == y) {
            if (freq[x] >= 2) {
                count++;
                freq[x] -= 2;
            }
        } else if (freq.count(y) && freq[y] > 0) {
            count++;
            freq[x]--;
            freq[y]--;
        }

        if (count == need) {
            got = true;
            break;
        }
    }

    return got ? res + 2 * need : -1;
}

int main() {
    int m, n, k;
    while (cin >> m >> n, m && n) {
        m *= 100;
        n *= 100;
        cin >> l >> k;
        v.resize(k);
        s.clear();

        for (int i = 0; i < k; ++i) {
            cin >> v[i];
            v[i] *= 100;
            s[v[i]]++;
        }

        int ans = -1;
        int res_m = check(m, n);
        if (res_m != -1) ans = res_m;

        int res_n = check(n, m);
        if (res_n != -1) {
            if (ans == -1 || res_n < ans) ans = res_n;
        }

        if (ans == -1) {
            cout << "impossivel" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
