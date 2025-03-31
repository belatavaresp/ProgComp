#include <iostream>
#include <string>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    double k;
    cin >> k;
    ll n = k*100;
    ll n_100=0,n_50=0,n_20=0,n_10=0,n_5=0,n_2=0;
    ll m_1=0,m_05=0,m_025=0,m_010=0,m_005=0,m_001=0;

    while(n != 0){
        if(n-10000 >= 0){
            n=n-10000;
            n_100++;
        }else if(n-5000 >=0){
            n=n-5000;
            n_50++;
        }else if(n-2000 >=0){
            n=n-2000;
            n_20++;
        }else if(n-1000 >=0){
            n=n-1000;
            n_10++;
        }else if(n-500 >=0){
            n=n-500;
            n_5++;
        }else if(n-200 >=0){
            n=n-200;
            n_2++;
        }else if(n-100 >= 0){
            n=n-100;
            m_1++;
        }else if(n-50 >=0){
            n=n-50;
            m_05++;
        }else if(n-25 >=0){
            n=n-25;
            m_025++;
        }else if(n-10 >=0){
            n=n-10;
            m_010++;
        }else if(n-5>=0){
            n=n-5;
            m_005++;
        }else if(n-1>=0){
            n=n-1;
            m_001++;
        }
    }

    cout << "NOTAS:" << endl;
    cout << n_100 << " nota(s) de R$ 100.00" << endl;
    cout << n_50 << " nota(s) de R$ 50.00" << endl;
    cout << n_20 << " nota(s) de R$ 20.00" << endl;
    cout << n_10 << " nota(s) de R$ 10.00" << endl;
    cout << n_5 << " nota(s) de R$ 5.00" << endl;
    cout << n_2 << " nota(s) de R$ 2.00" << endl;
    cout << "MOEDAS:" << endl;
    cout << m_1 << " moeda(s) de R$ 1.00" << endl;
    cout << m_05 << " moeda(s) de R$ 0.50" << endl;
    cout << m_025 << " moeda(s) de R$ 0.25" << endl;
    cout << m_010 << " moeda(s) de R$ 0.10" << endl;
    cout << m_005 << " moeda(s) de R$ 0.05" << endl;
    cout << m_001 << " moeda(s) de R$ 0.01" << endl;

	exit(0);
}