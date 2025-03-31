#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
typedef pair<double, int> di;

int main() { _
    int n;
    cin >> n;
    for (int t = 0; t < n; t++){
        int pac;
        cin >> pac;

        vector<int> peso(pac);
        vector<int> brinq(pac);
        vector<int> pacs;

        for(int i = 0; i < pac; i++){
            int q,p;
            cin >> q >> p;
            peso[i] = p;
            brinq[i] = q;
        }

        vector<vector<int>> dp(51, vector<int>(pac+1,0));

        for (int j = 1; j <= pac; j++) {
            for (int i = 0; i <= 50; i++) {
                dp[i][j] = dp[i][j - 1];
                if (peso[j - 1] <= i) {
                    dp[i][j] = max(dp[i][j], dp[i - peso[j - 1]][j - 1] + brinq[j - 1]);
                }
            }
        }

        int i = 50, j = pac;
        while (j > 0 && i > 0) {
            if (dp[i][j] != dp[i][j - 1]) {
                pacs.push_back(j);
                i -= peso[j - 1];
            }
            j--;
        }

        int w = 0;
        for(int i = 0; i < pacs.size(); i++){
            w+=peso[pacs[i]-1];
        }

        cout << dp[50][pac] << " brinquedos" << endl << "Peso: " << w << " kg" << endl << "sobra(m) " << pac - pacs.size() << " pacote(s)" << endl;
        if (t < n - 1) cout << endl;
    }
	exit(0);
}