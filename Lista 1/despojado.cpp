#include <iostream>
#include <cmath>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dsp(ll n){
    int p = 1;
    if (n==1){
        return 0;
    }
    for(ll i = 2; i <= sqrt(n); i++){
        if(n%(i*i) == 0){
            return 0;
        }
        if(n%i ==0){
            p = 0;
        }
    }
    return !p;
}

int main() { _
    ll n;
    cin >> n;
    int c = 0;
    for(ll i = 1; i <= sqrt(n); i++){
        if(n%i==0){
            c+=dsp(i);
            if(i!=n/i){
                c+=dsp(n/i);
            }
        }
    }
    cout << c << endl;
	exit(0);
}