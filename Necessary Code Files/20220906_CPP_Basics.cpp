#include<iostream>
#include <vector>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<"x = "<<x<<", y = "<<y<<"\n";

    vector<int> v;
    v.push_back(15);
    v.push_back(35);
    v.push_back(6);
    v.push_back(-96);
    v.push_back(15);
    cout << "Size of the vector = " << v.size() << "\n";
    for (int i = 0; i<v.size(); i++)
        cout << v[i] << ",\n"[i==v.size()-1];

    for (vector<int>::iterator it = v.begin(); it!=v.end(); it++)
        cout << *it << ",\n"[it+1==v.end()];
    cout << &v[0] << endl;

    for(auto &x:v)
        cout << x << ",";
    cout << "\n";

    return 0;
}
