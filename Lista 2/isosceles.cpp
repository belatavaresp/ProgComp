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
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> d(n, 1);
    for(int i = 1; i < n; i++){
        if(v[i] >= d[i-1] + 1){
            d[i] = d[i-1] + 1;
        }else{
            d[i] = v[i];
        }
    }
    vector<int> e(n, 1);

    for(int i = n-2; i >= 0; i--){
        if(v[i] >= e[i+1] + 1){
            e[i] = e[i+1] + 1;
        }else{
            e[i] = v[i];
        }
    }

    int mx = 1;
    for(int i = 0; i < n; i++){
        int m = min(d[i],e[i]);

        if(m > mx) mx = m;
    }

    cout << mx << endl;

	exit(0);
}