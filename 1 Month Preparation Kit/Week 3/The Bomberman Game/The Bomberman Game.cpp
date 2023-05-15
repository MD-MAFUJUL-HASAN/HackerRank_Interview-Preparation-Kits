#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
 
vector<string> explode(const vector<string>& grid){
    int r = grid.size();
    int c = grid[0].size();
    vector<string> B (r, string(c, 'O'));
    for (int x = 0; x < r; ++x){
        for (int y = 0; y < c; ++y){
            if (grid[x][y] == 'O'){
                B[x][y] = '.';
                if (x-1>=0)
                    B[x-1][y] = '.';
                if (x+1 <= r-1)
                    B[x+1][y] = '.';
                if (y+1 <= c-1)
                    B[x][y+1] = '.';
                if (y-1 >= 0)
                    B[x][y-1] = '.';
            }
        }
    }
    return B;
}

vector<string> bomberMan(int n, vector<string> grid) {
    int r = grid.size();
    int c = grid[0].size();
    
    vector<string> O (r, string(c, 'O'));
    vector<string> S1 = explode(grid);
    vector<string> S2 = explode(S1);
    vector<string> S3 = explode(S2);
    
    if (n == 1)
        return grid;
    if (n == 3)
        return S1;
    if (n % 4 == 1)
        return S2;
    if (n % 4 == 3)
        return S3;
    return O;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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

