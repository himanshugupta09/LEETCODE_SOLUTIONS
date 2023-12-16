#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */
vector<int>parent;
vector<int>s;

int find_set(int a)
{
    if(a == parent[a])
    {
        return a;
    }
    return parent[a] = find_set(parent[a]);
}


void unionfind(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    
    if(a != b)
    {
        if(s[a] < s[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        s[a] += s[b];
        
    }
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    
    int n = gb.size();
    parent.resize(2*n,0);
    s.resize(2*n,1);
    
    for(int i=0;i<2*n;i++)
    {
        parent[i] = i;
    }
    
    for(int i=0;i<n;i++)
    {
        int a = gb[i][0]-1;
        int b = gb[i][1]-1;
        unionfind(a,b);
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    for(int i=0;i<2*n;i++)
    {
        int ok  =  s[find_set(i)];
        if(ok == 1)
        {
            continue;
        }
        maxi = max(maxi,ok);
        mini = min(mini,ok);
    }
    return {mini,maxi};

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
