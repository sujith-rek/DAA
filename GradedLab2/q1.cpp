// Given n words w1, w2, … wn of lengths l1, l2, … ln respectively, arrange them in lexicographic order.
// Implement the algorithm where overall running time is O(n+|∑|), which includes the sum of sorting the
// pairs and the radix sort.
// Case 1:
// Input cave bat at
// Final Output a t
// b a t
// c a v e
// Note - The intermediate steps must also be shown: Forming pairs from the n words, Sorted order of pairs
// and display output after each round.

#include <bits/stdc++.h>

using namespace std;

// using radix sort
void sort_bucket(vector<string> &vs,int max_len)
{
    int n = vs.size();

    // from each index of string starting from 0 and going till max_len
    // for each index we compare the characters and sort the strings
    // according to the characters at that index with the help of inbuilt sort function
    // its an balanced sort
    for (int i = 0; i < max_len; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++){
                if (vs[j][i] > vs[k][i])
                    swap(vs[j], vs[k]);
                else if (vs[j][i] == vs[k][i])
                {
                    if (vs[j].size() > vs[k].size())
                        swap(vs[j], vs[k]);
                }
            }
        }
    }

    


}

int main()
{

    // inputs
    int n;
    cout << "Enter Number of Strings to sort : ";
    cin >> n;
    vector<string> vs(n, "");
    for (int i = 0; i < n; i++){
        cin >> vs[i];

        // converting to lowercase
        transform(vs[i].begin(), vs[i].end(), vs[i].begin(), ::tolower);
        cout << vs[i] << endl;
    }

    // segregate into buckets
    vector<vector<string>> bucket(26, vector<string>());
    vector<int> max_len(26, 0);
    for (int i = 0; i < n; i++){
        max_len[vs[i][0] - 'a'] = max(max_len[vs[i][0] - 'a'], (int)vs[i].size());
        bucket[vs[i][0] - 'a'].push_back(vs[i]);}

    // sorting each bucket
    for (int i = 0; i < 26; i++)
        if (bucket[i].size() > 0)
            sort_bucket(bucket[i], max_len[i]);

    // printing the sorted order of strings
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            cout << bucket[i][j] << endl;
        }
    }
}
