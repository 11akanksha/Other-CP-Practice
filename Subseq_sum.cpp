#include <iostream>
#include <vector>
using namespace std;

bool flag = false;
void subSeq_sum(int idx, vector<int> &v, int s, int sum, int *arr, int n)
{
    if (idx == n)
    {
        if (s == sum && flag == false)
        {
			flag = true;
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    v.push_back(arr[idx]);
    s += arr[idx];
    subSeq_sum(idx + 1, v, s, sum, arr, n);
    // Not pick:
    v.pop_back();
    s -= arr[idx];
    subSeq_sum(idx + 1, v, s, sum, arr, n);
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
    vector<int> v;
    subSeq_sum(0, v, 0, sum, a, n);
    return 0;
}

//i/p:
3
1 2 1
2
 
//O/p:
1 1
