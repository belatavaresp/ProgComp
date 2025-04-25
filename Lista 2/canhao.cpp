#include <iostream>
#include <vector>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    cin >> n;

    while(n--){
        int cn;
        cin >> cn;
        vector<int> p(cn+1);
        vector<int> c(cn+1);
        for(int i = 1; i <= cn; i++){
            cin >> c[i] >> p[i];
        }
        int cap, cas;
        cin >> cap >> cas;
        vector<vector<int>> dp(cn+1, vector<int>(cap+1,0));

        for(int i = 1; i <= cn; i++){
            for(int j = 1; j <= cap; j++){
                if(p[i] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i]]+c[i]);
                }
            }
        }

        if(dp[cn][cap] < cas){
            cout << "Falha na missao" << endl;
        }else{
            cout << "Missao completada com sucesso" << endl;
        }
    }

	exit(0);
}