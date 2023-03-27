#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

class dsu{
    public:
    vector<int> p;
    vector<int> s;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
    }
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        s[p2] += s[p1];
        return true;
    }
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
};

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    dsu d(n);
    for(int i = 0 ; i < astronaut.size() ; i++){
        d.unite(astronaut[i][0],astronaut[i][1]);
    }
    long long ans = 1;
    for(int i = 0 ; i < n ; i++){
        if(d.p[i] == i){
            ans += (d.s[i]*(n-d.s[i]));
        }
    }
    return ans/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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

/**OR
 * 
 * size of components
 * a b c d e f
 * 
 * ans = a*(b+c+d+e+f)+b*(c+d+e+f)+c*(d+e+f)+d*(e+f)+e*f+f*(0)
 * 
 * 
 * */