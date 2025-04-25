#include <iostream>
#include <vector>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n, p;
    while(cin >> n >> p){
        vector<int> dano(n+1);
        vector<int> mana(n+1);

        for(int i = 1; i <= n; i++){
            cin >> dano[i] >> mana[i];
        }

        vector<vector<int>> dp (n+1, vector<int>(3001,INF));

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        dp[0][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= p; j++){
                dp[i][j] = dp[i-1][j];
                dp[i][j] = min(dp[i][j], dp[i-1][max(0, j - dano[i])] + mana[i]);
            }
        }

        int ans = INF;
        ans = min(ans, dp[n][p]);

        cout << (ans == INF ? -1 : ans) << endl;
    }
	exit(0);
}