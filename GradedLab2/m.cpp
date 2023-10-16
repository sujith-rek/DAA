#include<bits/stdc++.h>

using namespace std;

struct Tuples{
    int index;
    char letter;
    string * word;
};

int main(){
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

    // form tuples
    

}