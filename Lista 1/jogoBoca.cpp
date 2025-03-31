#include <iostream>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    char c;
    int ans = 0;
    while(cin >> c){
        ans += int(c);
    }
    cout << ans % 3 << endl;
	exit(0);
}