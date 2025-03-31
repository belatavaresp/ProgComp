#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    string t;

    while(cin >> n && (n!=0)){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, t);

        unordered_map<char,int>f;
        int l = 0, len = 0, d = 0;
        for(int r = 0; r < t.size(); r++){
            if(f[t[r]] == 0){
                d++;
            }
            f[t[r]]++;
            while(d > n){
                f[t[l]]--;
                if(f[t[l]] == 0){
                    d--;
                }
                l++;
            }
            len = max(len, r-l+1);
        }
        cout << len << endl;
    }
	exit(0);
}