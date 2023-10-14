#include <bits/stdc++.h>

using namespace std;

// using radix sort
void sort_bucket(vector<string> &vs, int max_len)
{
    int n = vs.size();

    // from each index of string starting from 0 and going till max_len
    // for each index we compare the characters and sort the strings
    // according to the characters at that index with the help of inbuilt sort function
    // its an balanced sort

    vector<int> count(27, 0);
    for (int i = 1; i < max_len; i++)
    {
        for (int j = 0; j < n; j++)
            if (vs[j][i] == ' ')
                count[0]++;
            else
                count[vs[j][i] - 'a' + 1]++;

        int index = 0;
        for (int j = 0; j < 27; j++)
            if (count[j] > 0)
                while (count[j] > 0)
                {
                    if (j == 0)
                        vs[index][i] = ' ';
                    else
                        vs[index][i] = char(j + 'a' - 1);
                    count[j]--;
                    index++;
                }
    }
}

void print_bucket(vector<string> &vs)
{
    for (int i = 0; i < vs.size(); i++)
        cout << vs[i] << endl;
}

void even_the_strings_out(vector<string> &vs, int max_len)
{
    for (int i = 0; i < vs.size(); i++)
        while (vs[i].size() < max_len)
            vs[i] += ' ';
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
            even_the_strings_out(bucket[i], max_len[i]);
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
