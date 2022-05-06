#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

class Parser
{

    unordered_map<char, vector<string>> grammar;
    char startSymbol = '\0';
    int recur(char symbol, int index, string const &s, vector<string> &LeftMostDer)
    {
        if (index > s.size())
        {
            return -1;
        }

        if (grammar.find(symbol) == grammar.end())
        {
            return s[index] == symbol ? index + 1 : -1;
        }

        for (auto production : grammar.at(symbol))
        {
            int cursor = index;
            string left = "";
            left += symbol;
            LeftMostDer.push_back(left + " -> " + production);
            for (char c : production)
            {
                cursor = recur(c, cursor, s, LeftMostDer);
                if (cursor == -1)
                {
                    break;
                }
            }

            if (cursor == -1)
            {
                LeftMostDer.pop_back();
            }
            else
            {
                return cursor;
            }
        }

        return -1;
    }

public:
    void input()
    {
        int n;
        cin >> n;
        cin >> startSymbol;
        for (int i = 0; i < n; ++i)
        {
            char symbol;
            cin >> symbol;
            string production;
            getline(cin, production);
            grammar[symbol].push_back(ltrim(production));
        }
    }
    vector<string> parse(string s)
    {
        vector<string> LeftMostDer;
        int endIndex = recur(startSymbol, 0, s, LeftMostDer);
        if (s.size() != endIndex)
        {
            cerr << "Syntax Error";
            return vector<string>();
        }
        return LeftMostDer;
    }
};

int main(int argc, char const **argv)
{
    Parser parser;
    parser.input();

    if (argc > 1)
    {
        string path(argv[1]);
        ifstream inputFile(path);
        if (!inputFile.is_open())
        {
            cerr << "Error in opening the file '"
                 << path << "'" << endl;
            exit(EXIT_FAILURE);
        }

        string fileStr((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

        vector<string> LeftMostDer = parser.parse(fileStr);

        for (string s : LeftMostDer)
        {
            cout << s << endl;
        }
    }
    return 0;
}