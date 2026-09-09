#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

int opPre(string x)
{
    if(x=="+"||x=="-") return 1;
    if(x=="*"||x=="/") return 2;
    if(x=="^") return 3;
    return 0;
}

vector<string> infixToPostfix(vector<string> q)
{
    vector<string> p;
    stack<string> st;
    st.push("(");
    q.push_back(")");
    int ind = 0;
    while(!st.empty())
    {
        if(ind >= q.size())
        {
            cout <<"Error in the equation!\n";
            break;
        }
        string &x = q[ind++];
        if(opPre(x))
        {
            while( opPre(x) <= opPre(st.top()) )
            {
                p.push_back(st.top());
                st.pop();
            }
            st.push(x);
        }
        else if(x=="(") st.push(x);
        else if(x==")")
        {
            while(st.top()!="(")
            {
                p.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else p.push_back(x);
    }
    return p;
}

int strToInt(string x)
{
    for (char &y:x)
        if(!isdigit(y))
        {
            cout << "Non-numeric Operand!\n";
            return -1;
        }
    int ret;
    sscanf(x.c_str(), "%d", &ret);
    return ret;
}

int doOp(int a, int b, string op)
{
    if(op=="-") return b-a;
    if(op=="+") return b+a;
    if(op=="*") return b*a;
    if(op=="/") return b/a;
    if(op!="^")
    {
        cout << "Unkown Operator!\n";
        return -1;
    }
    int ret = 1;
    for (int i =0; i<a; i++)
        ret *= b;
    return ret;
}

int evalPostfix(vector<string> p)
{
    p.push_back("$");
    stack<int>st;

    for (string &x: p)
    {
        if(x=="$")
        {
            if(st.size()==1) return st.top();
            cout << "Error in postfix expression!\n";
            return -1;
        }
        else if(opPre(x))
        {
            int a, b;
            a = st.top(); st.pop();
            b = st.top(); st.pop();
            st.push(doOp(a,b,x));
        }
        else st.push(strToInt(x));

    }
    return st.top();
}

int main()
{
    int n;
    cin >> n;
    vector<string>v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<string> postfix = infixToPostfix(v);

//    for (string &x: postfix)
//        cout << x << " ";
//    cout << "\n";

    int res = evalPostfix(postfix);

    cout << "Result of the equation = " << res << "\n";

    return 0;
}
/**
21
654 + ( 78 * 5 - ( 32 / 2 ^ 3 ) * 25 ) * 99 + 1
19
A + ( B * C - ( D / E ^ F ) * G ) * H
*/
