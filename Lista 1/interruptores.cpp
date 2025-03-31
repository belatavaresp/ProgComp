#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <bitset>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int s,l;
    cin >> s >> l;
    bitset<1023> lights;
    int on;
    cin >> on;

    for(int i = 0; i < on; i++){
        int n;
        cin >> n;
        lights[n-1] = true;
    }

    vector<bitset<1023>> masks(s, bitset<1023>());
    for(int i = 0; i < s; i++){
        int amt;
        cin >> amt;
        for(int j = 0; j < amt; j++){
            int idx;
            cin >> idx;
            masks[i][idx-1] = true;
        }
    }

    int next = 0;
    bitset<1023> cur = lights;
    int it = 0;
    while(cur.any()){
        if(it >= s*s){
            cout << -1 << endl;
            exit(0);
        }
        cur ^= masks[next];
        next = (next + 1)%s;
        it++;
    }

    cout << it << endl;

	exit(0);
}