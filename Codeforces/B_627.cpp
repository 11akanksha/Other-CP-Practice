#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        map<int, vector<int>> m;
        for (int i = 0; i < n; ++i)
            m[a[i]].push_back(i);
        string ans = "NO\n";
        
        for (int i = 0; i < n; ++i)
        {
            if (m[a[i]].size() >= 3)
            {
                ans = "YES\n";
                break;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (m[a[i]].size() == 2 and m[a[i]][0] != m[a[i]][1] - 1)
            {
                ans = "YES\n";
                break;
            }
        }
        cout << ans;
    }
    return 0;
}
