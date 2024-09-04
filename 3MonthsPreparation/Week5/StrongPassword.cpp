#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

bool f_in(string& pass, string& c)
{
    bool found = false;
    for (auto n : c)
    {
        auto s = pass.find(n);
        if (s != string::npos)
        {
            found = true;
            break;
        }
    }

    return found;
}

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    if (n <= 2) {
        return 6 - n;
    }

    int result = 0;

    if (!f_in(password, numbers))
    {
        result++;
    }
    if (!f_in(password, lower_case))
    {
        result++;
    }
    if (!f_in(password, upper_case))
    {
        result++;
    }
    if (!f_in(password, special_characters))
    {
        result++;
    }
    if (n < 6) {
        result = result > 6 - n ? result : 6 - n;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
