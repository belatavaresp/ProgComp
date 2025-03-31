#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dx[] = {-2,-2,2,2};
int dy[] = {-2,2,-2,2};

vector<vector<int>> t;
ll mcpt=0;
int n,m;

void capt(int a, int b, ll cpt){
    mcpt = max(mcpt, cpt);

    for(int i = 0; i < 4; i++){
        int x=a+dx[i], y=b+dy[i];
        int cx=a+dx[i]/2, cy=b+dy[i]/2;
        if(x>=0 && x<n && y>=0 && y<m && t[cx][cy] == 2 && t[x][y] == 0){
            t[cx][cy] = 0;
            t[a][b] = 0;
            t[x][y] = 1;
            capt(x,y,cpt+1);
            t[cx][cy] = 2;
            t[a][b] = 1;
            t[x][y] = 0;
        }
    }

}

int main() { _
    while(cin >> n >> m, n!=0 && m!=0){
        int cs = (n * m + 1) / 2;
        t.assign(n, vector<int>(m, -1));

        vector<int> s(cs);
        for (int &v : s) cin >> v;

        int idx=0;
        for(int i = 0; i < n; i++){
            for(int j = (i % 2 == 0 ? 0 : 1); j < m; j += 2){
                t[i][j] = s[idx++];
            }
        }

        mcpt=0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(t[i][j] == 1){
                    capt(i,j,0);
                }
            }
        }
        cout << mcpt << endl;
    }
	exit(0);
}