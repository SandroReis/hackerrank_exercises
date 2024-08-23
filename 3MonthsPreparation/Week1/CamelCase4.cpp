#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cstdio>
using namespace std;

std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        tokens.push_back(item);
        // std::cout << item << std::endl;
    }

    return tokens;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string line;
    char delimiter = ';';
    while (std::getline(std::cin, line)) {

        std::vector<std::string> tokens = splitString(line, delimiter);

        if (!tokens.empty()) {
            if (tokens[0] == "S") {
                // split operation
                std::string result = "";
                for (int i = 0; i < tokens[2].length(); i++)
                {
                    if (std::isupper(tokens[2][i]) && i != 0)
                    {
                        result += ' ';
                    }
                    // if (!std::isspace(tokens[2][i]))
                    // {}
                    result += std::tolower(tokens[2][i]);
                }

                std::cout << result << endl;
                result = "";
            }
            else
            {
                // Combine operation
                std::string result = "";
                for (int i = 0; i < tokens[2].length(); i++)
                {
                    if (i == 0 && tokens[1] == "C")
                    {
                        result += std::toupper(tokens[2][i]);
                    }
                    else if (std::isspace(tokens[2][i]) && i + 1 < tokens[2].length() && !std::isspace(tokens[2][i + 1]))
                    {
                        i++;
                        result += std::toupper(tokens[2][i]);
                    }
                    else
                    {
                        result += tokens[2][i];
                    }
                }
                if (tokens[1] == "M")
                {
                    result += "()";
                }
                std::cout << result << endl;
                result = "";

            }
        }
    }
    return 0;
}
