#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    map<char, int> ch_count;
    bool flag = false;

    for (char ch : s)
    {   
        if (ch_count.find(ch) != ch_count.end())
            ch_count[ch] += 1;
        else
            ch_count[ch] = 1;
    }

    for (auto a = ch_count.begin(), b = ++ch_count.begin(); b != ch_count.end(); ++b)
    {
        
        if (a->second == b->second)
            continue;
        else if ((b->second == 1 || abs(a->second - b->second) == 1) && flag == false)
            flag = true;
        else
            return "NO";
    }

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

