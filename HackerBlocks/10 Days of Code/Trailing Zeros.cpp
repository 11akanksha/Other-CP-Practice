#include <iostream>
using namespace std;

int findingZeros(int n)
{
    int ans = 0;
    int p = 5;
    while ((n / p) > 0)
    {
        ans += (n / p);
        p *= 5;
    }
    return ans;
}

int main()
{
    long long int n;
    cin >> n;
    cout << findingZeros(n) << endl;
    return 0;
}

//O/p:
10
2
  
900
224
  
1000
249
