#include <iostream>
#include <vector>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n, k;
    while(cin >> n >> k, n&&k){
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<vector<ll>> dp(n, vector<ll>(k+1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][1] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 2; j <= k; j++){
                for(int m = 0; m < i; m++){
                    if(v[m]>=v[i]) continue;
                    dp[i][j] += dp[m][j-1];
                }
            }
        }
        ll sum=0;
        for(int i = 0; i < n; i++){
            sum+=dp[i][k];
        }
        cout << sum << endl;
    }
	exit(0);
}