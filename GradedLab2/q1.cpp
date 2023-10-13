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
void sort_bucket(vector<string> &vs){
    int n = vs.size();
    int max_len = 0;
    for (int i = 0; i < n; i++)
        max_len = max(max_len, (int)vs[i].size());

    for(int i = 0; i < ) 
}

int main(){

    // inputs
    int n;
    cout << "Enter Number of Strings to sort : ";
    cin >> n;
    vector<string> vs(n, "");
    for (int i = 0; i < n; i++)
        cin >> vs[i];

    // segregate into buckets
    vector<vector<string>> bucket(26, vector<string>());
    for (int i = 0; i < n; i++)
        bucket[vs[i][0] - 'a'].push_back(vs[i]);

    // sorting each bucket
    for (int i = 0; i < 26; i++)
        sort_bucket(bucket[i]);

    // printing the sorted order of strings
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < bucket[i].size(); j++){
            cout << bucket[i][j] << endl;
        }
    }
}
