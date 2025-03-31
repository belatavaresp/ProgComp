#include <iostream>
#include <string>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    string cif, crib;
    cin >> cif >> crib;
    int c = 0;
    for(int i = 0; i <= cif.size() - crib.size(); i++){
        bool ans = true;
        for(int j = 0; j < crib.size(); j++){
            if(crib[j] == cif[i+j]){
                ans = false;
                break;
            }
        }
        if(ans) c++;
    }

    cout << c << endl;
	exit(0);
}