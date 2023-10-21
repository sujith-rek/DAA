#include <bits/stdc++.h>

using namespace std;

typedef struct tuples
{
    int index;
    int word;
    char letter;
} tuples;


void sort_by_char(vector<vector<tuples>> &v, int len)
{
    // radix sort
    vector<vector<tuples>> temp(26);
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            temp[v[i][j].letter - 'a'].push_back(v[i][j]);
        }
    }

}

int main()
{

    int n, len = 0;
    cout << "Enter the number of words: ";
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
        if (len < s.length())
        {
            len = s.length();
        }

    }

    vector<vector<tuples>> v(len);
    // make tuples and store them 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            tuples t;
            t.index = i;
            t.word = j;
            t.letter = words[i][j];
            v[j].push_back(t);
        }
    }

    // sort by char


}
