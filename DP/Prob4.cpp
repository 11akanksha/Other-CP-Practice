// A cleaner form of Prob3.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSum(int i, int sum, int *a, int n, vector<int> &sol)
{
    if (i == n)
    {
        sol.push_back(sum);
        return;
    }
    // pick
    findSum(i + 1, sum + a[i], a, n, sol);
    //not-pick
    findSum(i + 1, sum, a, n, sol);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> sol;
    findSum(0, 0, a, n, sol);
    sort(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); ++i)
    {
        cout << sol[i] << " ";
    }
    cout << endl;

    return 0;
}
