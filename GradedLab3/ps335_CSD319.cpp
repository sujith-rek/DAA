#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;       // size of array
    int ans = 0; // length of longest increasing subsequence

    cin >> n; // input size of array

    if (n < 0)
    {
        cout << "Invalid Input\n";
        return 0;
    }
    else if (n == 0)
    { // if size of array is 0
        cout << "Length of the longest increasing subsequence is 0\n";
        return 0;
    }
    else if (n == 1)
    {
        cout << "Length of the longest increasing subsequence is 1\n";
        return 0;
    }

    vector<int> arr(n);   // array of size n
    vector<int> dp(n, 1); // dp array of size n

    for (int i = 0; i < n; i++)
    { // input array
        cin >> arr[i];
    }

    // dp[i] = length of longest increasing subsequence ending at index i
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << "Length of the longest increasing subsequence is " << ans << "\n";
}
