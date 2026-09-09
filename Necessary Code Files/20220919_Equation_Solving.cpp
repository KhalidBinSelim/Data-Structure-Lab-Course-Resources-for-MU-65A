#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    string val;
    node *prev;
    node(string x, node *p){
        val = x;
        prev = p;
    }
};

struct Stack{
    node *top;
    Stack(){
        top = NULL;
    }
    void push(string x)
    {
        node *cur = new node(x,top);
        top = cur;
    }
    string pop()
    {
        node *temp = top;
        if(temp==NULL){
            cout << "Stack is empty!\n";
            return "";
        }
        string s = temp->val;
        top = top->prev;
        delete temp;
        return s;
    }
};

string eval(string op, string a, string b)
{
    string ret;int x, y;
    char temp[100];
    sscanf(a.c_str(),"%d",&x);
    sscanf(b.c_str(),"%d",&y);
    if(op == "+") {
        sprintf(temp,"%d",x+y);
        ret = temp;
    }
    else if(op == "-") {
        sprintf(temp,"%d",x-y);
        ret = temp;
    }
    else if(op == "*") {
        sprintf(temp,"%d",x*y);
        ret = temp;
    }
    else if(op == "/") {
        sprintf(temp,"%d",x/y);
        ret = temp;
    }
    else if(op == "^") {
        int res = 1;
        for (int i = 0; i<y; i++)
            res*=x;
        sprintf(temp,"%d",res);
        ret = temp;
    }
    return ret;
}

int main()
{
    string s;
    Stack st;

    while(cin >> s)
    {
        if(s=="+" || s=="-" || s=="*" || s == "/" || s=="^")
        {
            string a = st.pop();
            string b = st.pop();
            st.push(eval(s,b,a));
        }
        else st.push(s);
    }
    if(st.top!=NULL) cout <<"Result = " << st.pop() <<"\n";
    else cout << "There are some problems in the equation!\n";
    if(st.top!=NULL)
        cout << "There are some problems in the equation!\n";

    return 0;
}
/**
-60 + ( 3 * 8 - ( 16 / 2 ^ 3 ) * 6 ) * 5
5 6 2 + * 12 4 / -
*/
