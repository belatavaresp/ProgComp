#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main() { _
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(11, false));
        dp[0][5] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                if (dp[i][j]) {
                    int diff = j - 5;
                    int a = diff + p[i+1];
                    int b = diff - p[i+1];

                    if (abs(a) <= 5) dp[i+1][a + 5] = true;
                    if (abs(b) <= 5) dp[i+1][b + 5] = true;
                }
            }
        }

        bool ok = false;
        for (int j = 0; j <= 10; j++) {
            if (dp[n][j]) {
                ok = true;
                break;
            }
        }

        if(ok){
            cout << "Feliz Natal!" << endl;
        }else{
            cout << "Ho Ho Ho!" << endl;
        }
    }
    return 0;
}
