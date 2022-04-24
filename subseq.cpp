#include <iostream>
#include <vector>
using namespace std;

int subSeq_sum(int idx, int s, int sum, int *arr, int n)
{
    if (s > sum)
        return 0;
    if (idx == n)
    {
        if (s == sum)
        {
            return 1;
        }
        return 0;
    }
    // pick:
    s += arr[idx];
    int l = subSeq_sum(idx + 1, s, sum, arr, n);

    // Not pick:
    s -= arr[idx];
    int r = subSeq_sum(idx + 1, s, sum, arr, n);
    return l + r;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int sum;
    cin >> sum;
    cout << subSeq_sum(0, 0, sum, a, n);
    return 0;
}
