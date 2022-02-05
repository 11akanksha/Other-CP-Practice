#include <iostream>
#include <vector>
#define infinity 1e9
using namespace std;
 
int solve(vector<int> h, int n, int k)
{
    vector<int> dp(n + 1);
    dp[1] = 0;
    int steps = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = infinity;
        while (steps <= k)
        {
            int option = ((i - steps) < 1) ? infinity : (abs(h[i] - h[i - steps]) + dp[i - steps]);
            dp[i] = min(dp[i], option);
            steps++;
        }
        steps = 1;
    }
    return dp[n];
}
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> height(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
    }
 
    cout << solve(height, n, k) << endl;
    return 0;
}
