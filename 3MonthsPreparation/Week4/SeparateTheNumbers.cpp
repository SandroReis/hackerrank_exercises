#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {

    long long start_number = 0;
    bool found = false;

    for (long long i = 1; i <= s.size() / 2; ++i) {


        start_number = std::stoll(s.substr(0, i));

        long long last = start_number;
        long long possible_next = start_number + 1;
        long long possible_previous = start_number - 1;


        long long pos = i;


        while (pos < s.size()) {
            if (stoll(s.substr(pos, to_string(possible_next).size())) == possible_next) {
                if (pos + to_string(possible_next).size() >= s.size()) {
                    // cout << i << ";" << stoll(s.substr(pos,to_string(possible_next).size()));
                    cout << "YES " << start_number << endl;
                    return;
                }
                pos += to_string(possible_next).size();
                last = possible_next;
                possible_previous = possible_next - 1;
                possible_next = possible_next + 1;

            }
            else if (stoll(s.substr(pos, to_string(possible_previous).size())) == possible_previous) {
                if (pos + to_string(possible_previous).size() >= s.size()) {
                    // cout << i << ";" << stoll(s.substr(pos,to_string(possible_previous).size()));


                    cout << "YES " << start_number << endl;
                    return;
                }
                pos += to_string(possible_previous).size();
                last = possible_previous;
                possible_next = possible_previous + 1;
                possible_previous = possible_previous - 1;
            }
            else {

                pos = s.size();
            }



        }

    }
    cout << "NO" << endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
