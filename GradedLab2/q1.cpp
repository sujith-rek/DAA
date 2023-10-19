#include <bits/stdc++.h>

using namespace std;

// using radix sort
void sort_bucket(vector<string> &vs, int max_len)
{
    int n = vs.size();
    vector<string> output(n);

    // Sort by each character from right to left
    for (int i = max_len - 1; i >= 0; i--)
    {
        // Count the frequency of each character
        vector<int> count(27, 0);
        for (int j = 0; j < n; j++)
        {
            if (i >= vs[j].size())
            {
                count[0]++;
            }
            else
            {
                count[vs[j][i] - 'a' + 1]++;
            }
        }

        // Compute the prefix sum of the counts
        for (int j = 1; j < 27; j++)
        {
            count[j] += count[j - 1];
        }

        // Place the strings in the output array
        for (int j = n - 1; j >= 0; j--)
        {
            int index;
            if (i >= vs[j].size())
            {
                index = count[0] - 1;
            }
            else
            {
                index = count[vs[j][i] - 'a' + 1] - 1;
            }
            output[index] = vs[j];
            if (i >= vs[j].size())
            {
                count[0]--;
            }
            else
            {
                count[vs[j][i] - 'a' + 1]--;
            }
        }

        // Copy the output array to the input array
        for (int j = 0; j < n; j++)
        {
            vs[j] = output[j];
        }
    }
}

void print_bucket(vector<string> &vs)
{
    for (int i = 0; i < vs.size(); i++)
        cout << vs[i] << endl;
}

int main()
{
    // inputs
    int n;
    cout << "Enter Number of Strings to sort : ";
    cin >> n;
    vector<string> vs(n, "");
    for (int i = 0; i < n; i++)
    {
        cin >> vs[i];

        // converting to lowercase
        transform(vs[i].begin(), vs[i].end(), vs[i].begin(), ::tolower);
    }

    // segregate into buckets
    vector<vector<string>> bucket(26, vector<string>());
    vector<int> max_len(26, 0);
    for (int i = 0; i < n; i++)
    {
        max_len[vs[i][0] - 'a'] = max(max_len[vs[i][0] - 'a'], (int)vs[i].size());
        bucket[vs[i][0] - 'a'].push_back(vs[i]);
    }

    // sorting each bucket
    for (int i = 0; i < 26; i++)
        if (bucket[i].size() > 0)
        {
            cout << "Bucket " << char(i + 'a') << " before sorting : "
                 << endl,
                print_bucket(bucket[i]), cout << endl;
            sort_bucket(bucket[i], max_len[i]);
            cout << "Bucket " << char(i + 'a') << " after sorting : "
                 << endl,
                print_bucket(bucket[i]), cout << endl;
        }

    // printing the sorted order of strings
    cout << endl
         << "Sorted Order : " << endl;
    for (int i = 0; i < 26; i++)
        if (bucket[i].size() > 0)
            print_bucket(bucket[i]);
}
