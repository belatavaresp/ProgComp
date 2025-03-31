#include <iostream>
#include <vector>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

vector<int> fita, saida;

bool ver(int l) {
    int m = saida.size();
    int i;

    for (i = 0; i < m; i++) {
        if (fita[l + i] != saida[i]) break;
    }
    if (i == m) return true;
    for (i = 0; i < m; i++) {
        if (fita[l + i] != saida[m - i - 1]) break;
    }
    if (i == m) return true;
    return false;
}

bool poss(int l, int r) {
    int qtt = r - l + 1;
    if (qtt == saida.size()) {
        return ver(l);
    }
    if (qtt < saida.size()) return false;

    for (int i = 1; i <= qtt / 2; i++) {
        int k = 1;
        for (int j = l + i; j < l + 2 * i; j++) {
            fita[j] += fita[j - k];
            k += 2;
        }
        if (poss(l + i, r)) return true;
        k = 1;
        for (int j = l + i; j < l + 2 * i; j++) {
            fita[j] -= fita[j - k];
            k += 2;
        }
        k = 1;
        for (int j = r - i; j > r - 2 * i; j--) {
            fita[j] += fita[j + k];
            k += 2;
        }
        if (poss(l, r - i)) return true;
        k = 1;
        for (int j = r - i; j > r - 2 * i; j--) {
            fita[j] -= fita[j + k];
            k += 2;
        }
    }
    return false;
}

int main() { _
    int n, m;
    while (cin >> n) {
        fita.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> fita[i];
        }
        cin >> m;
        saida.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> saida[i];
        }
        if (poss(0, n - 1)) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}
