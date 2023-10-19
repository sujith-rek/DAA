#include <bits/stdc++.h>

using namespace std;

typedef struct tuples
{
    int index;
    int word;
    char letter;
} tuples;

void sort_by_letter(vector<tuples> &v)
{
    vector<vector<tuples>> m(26);
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i].letter - 'a'].push_back(v[i]);
    }
    v.clear();
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            v.push_back(m[i][j]);
        }
    }
}

void sort_by_index(vector<tuples> &v, int len)
{
    vector<vector<tuples>> m(len);
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i].index].push_back(v[i]);
    }
    v.clear();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            v.push_back(m[i][j]);
        }
    }
}

void arrange_words_by_length(int max_len, vector<string> &words)
{
    vector<vector<string>> m(max_len);
    for (int i = 0; i < words.size(); i++)
    {
        m[words[i].length() - 1].push_back(words[i]);
    }
    words.clear();
    for (int i = 0; i < max_len; i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            words.push_back(m[i][j]);
        }
    }
}

int main()
{

    int n, len = 0;
    cout << "Enter the number of words: ";
    cin >> n;

    vector<tuples> v;
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

    // sort the vector of tuples by length
    arrange_words_by_length(len, words);

    // create a vector of tuples
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            tuples t;
            t.index = j;
            t.word = i;
            t.letter = words[i][j];
            v.push_back(t);
        }
    }

    cout << "Tuples before any sorting: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].index << " " << v[i].letter << " " << words[v[i].word] << endl;
    }

    // sort the vector of tuples by letter
    sort_by_letter(v);
    cout << "Tuples after sorting the characters: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].index << " " << v[i].letter << " " << words[v[i].word] << endl;
    }

    // sort the vector of tuples by index
    sort_by_index(v, len);
    cout << "Tuples after sorting the indexes: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].index << " " << v[i].letter << " " << words[v[i].word] << endl;
    }

    cout << "The sorted order is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << words[v[i].word] << "\n";
    }
}
