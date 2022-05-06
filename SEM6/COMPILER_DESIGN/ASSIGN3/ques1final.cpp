#include <bits/stdc++.h>
using namespace std;
// This creates a map of all the brackets with the position where it is appearing
// in the file
struct element
{
    int row, col;
    char bracket;
};
map<pair<int, int>, char> mp;
stack<element> st;
void process_line(string tp, int curr_row)
{
    int curr_col = 0;
    for (int i = 0; i < tp.size(); i++)
    {
        // read the string as well as the row number and the col number in a map having integer
        // and the bracket that is found there .
        curr_col++;
        if (tp[i] == '(' || tp[i] == ')' || tp[i] == '}' || tp[i] == '{' || tp[i] == '[' || tp[i] == ']')
        {
            mp[{curr_row, curr_col}] = tp[i];
        }
    }
    curr_col = 0;
}

void input(string filename)
{
    fstream newfile;
    newfile.open(filename, ios::in);
    int current_row = 0;
    if (newfile.is_open())
    {
        string tp;
        while (getline(newfile, tp))
        {
            current_row++;
            process_line(tp, current_row);
        }
        newfile.close();
    }
}
// we need to solve using stack now
void solve(vector<element> &expression)
{
    stack<element> st1;
    int n = expression.size();
    for (int i = 0; i < n; i++)
    {
        int row = expression[i].row;
        int col = expression[i].col;
        char bracket = expression[i].bracket;
        if (bracket == '(' || bracket == '[' || bracket == '{')
        {
            st1.push(expression[i]);
            continue;
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}')
        {
            if (bracket == ')')
            {
                if (st1.top().bracket == '(')
                    st1.pop();
                else
                {
                    cout << "Expected '(' corresponding to ')' in row number " << row << "and col number" << col << "\n";
                    st1.pop();
                    continue;
                }
            }
            if (bracket == ']')
            {
                if (st1.top().bracket == '[')
                    st1.pop();
                else
                {
                    cout << "Expected '[' corresponding to ']' in row number " << row << "and col number" << col << "\n";
                    st1.pop();
                    continue;
                }
            }
            if (bracket == '}')
            {
                if (st1.top().bracket == '{')
                    st1.pop();
                else
                {
                    cout << "Expected '{' corresponding to '}' in row number " << row << "and col number" << col << "\n";
                    st1.pop();
                    continue;
                }
            }
        }
    }
    while (!st1.empty())
    {
        int row = st1.top().row;
        int col = st1.top().col;
        char bracket = st1.top().bracket;
        if (bracket == ')')
        {
            cout << "Expected '(' corresponding to ')' in row number " << row << "and col number" << col << "\n";
            st1.pop();
            continue;
        }
        if (bracket == ']')
        {
            cout << "Expected '[' corresponding to ']' in row number " << row << "and col number" << col << "\n";
            st1.pop();
            continue;
        }
        if (bracket == '}')
        {
            cout << "Expected '{' corresponding to '}' in row number " << row << "and col number" << col << "\n";
            st1.pop();
            continue;
        }
        if (bracket == '(')
        {
            cout << "Expected ')' corresponding to '(' in row number " << row << "and col number" << col << "\n";
            st1.pop();
            continue;
        }
        if (bracket == '[')
        {
            cout << "Expected ']' corresponding to '[' in row number " << row << "and col number" << col << "\n";
            st1.pop();
            continue;
        }
        if (bracket == '{')
        {
            cout << "Expected '}' corresponding to '{' in row number " << row << "and col number" << col << "\n";
            st1.pop();
            continue;
        }
    }
}

int main()
{
    string filename = "test.txt";
    input(filename); // take the file input in the program and then display the error
    vector<element> expression;
    element e;
    for (auto itr : mp)
    {
        e.row = itr.first.first;
        e.col = itr.first.second;
        e.bracket = itr.second;
        expression.push_back(e);
    }
    solve(expression);

    return 0;
}
