#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    string s = "How are you?", name="Omuk";
    char sc[100] = "Kire ki koros?";
    s = "Hello "+name+", "+s;
    for(auto it = s.rbegin(); it!=s.rend(); it++)
        cout << *it << "\n";
    size_t spos;
    cout << s.substr(12, 3) << "\n";
    cout << (spos=s.find("Omuk")) << "\n";
    string ss  = "Hi "+s.substr(spos,6)+"Where are you?";
    cout << ss << "\n";
    swap(s,ss);
    cout <<s<<" -- " <<ss<<"\n";
    strcpy(sc,s.c_str());
    printf("s is %s\n",sc);

    cout <<"Size of S = " << s.size() << "\n";
    cout <<"It is said: " << ss << "\n";
    bool x;
    x = true;
    cout << "x = " << x << "\n";
    x = false;
    cout << "x = " << x << "\n";
    cout << sizeof(x) <<endl;
    return 0;
}
