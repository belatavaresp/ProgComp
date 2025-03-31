#include <string>
#include <bitset>
#include <cstdint>
#include <iostream>
  
using namespace std;
int main()
{
    string s = "baballoo";
    s.erase(s.end()-1);
    cout << s << endl;
}