#include <iostream>
#include <algorithm>
#include <string>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

#define MAX 4000

int t, p;
int a[100], b[100];
int s[11][100];
int v[11];

int main() {
  while (cin >> t >> p, t || p) {
    for (int i = 0; i <= 10; i++){
        v[i] = 0;
    }
    for (int i = 0; i < t; i++) {
      a[i] = b[i] = 0;
      int solved = 0;
      for (int j = 0; j < p; j++) {
        int tent;
        string tmp;
        char barra;
        cin >> tent >> barra >> tmp;
        if (tmp == "-"){
            continue;
        }
        solved++;
        a[i] += tent - 1;
        b[i] += stoi(tmp);
      }
      s[solved][v[solved]++] = i;
    }

    int lo = 1, hi = MAX;
    bool fixo = false;

    for (int x = 0; x <= 10 && !fixo; x++) {
      if (v[x] == 0) continue;

      sort(s[x], s[x] + v[x], [](int i, int j) {
        return 20 * a[i] + b[i] < 20 * a[j] + b[j];
      });

      for (int k = 0; k + 1 < v[x]; k++) {
        int i = s[x][k];
        int j = s[x][k + 1];

        if (a[i] == a[j]) continue;

        int num = b[j] - b[i];
        int den = a[i] - a[j];

        int ep = num / den;

        if (ep > 20 || (ep == 20 && num % den != 0)) {
          if (num % den == 0){
            hi = min(hi, ep - 1);
          }else{
            hi = min(hi, ep);
          }
        } else if (ep < 20) {
          lo = max(lo, ep + 1);
        } else {
          lo = hi = 20;
          fixo = true;
          break;
        }
      }
    }

    cout << lo << " ";
    if (hi != MAX)
      cout << hi << "\n";
    else
      cout << "*\n";
  }
  exit(0);
}
