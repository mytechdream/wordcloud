#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char* argv[])
{
    string s;
    stack<char> s1;
    stack<char> s2;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)//´ÓÓÒµ½×óÉ¨Ãè
    {
    L1:
        if (s[i] >= '0' && s[i] <= '9')
        {
            s2.push(s[i]);
        }
        else
        {
            if (s[i] == ')' || s1.empty())
            {
                s1.push(s[i]);
            }
            else if (s[i] == '(')
            {
                while (s1.top() != ')')
                {
                    s2.push(s1.top());
                    s1.pop();
                    goto L1;
                }
                s1.pop();
            }

            else if (s1.top() == '*' && (s[i] == '-' || s[i] == '+'))
            {
                s2.push(s1.top());
                s1.pop();
                goto L1;
            }
            else if (s1.top() == '(' && (s[i] == '+' || s[i] == '-' || s[i] == '*'))
            {
                s2.push(s1.top());
                s1.pop();
                goto L1;
            }
            else
            {
                s1.push(s[i]);
            }
        }
    }
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    while (!s2.empty())
    {
        printf("%c", s2.top());
        s2.pop();
    }
    return 0;
}