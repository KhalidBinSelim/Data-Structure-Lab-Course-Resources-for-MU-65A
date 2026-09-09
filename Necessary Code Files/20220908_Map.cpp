#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<string,int> population;

int main()
{
    FILE *file = fopen("20220908_worldpopulation.csv", "r+");
    char country[100];
    int pop_count;

    population["London2nd"] = 3567138;

    while(!feof(file))
    {
        fscanf(file,"%*d,%[^,],%d,%*s",country,&pop_count);
        population[country] = pop_count;
//        cout << country << " " << pop_count << endl;
    }

    for (auto x:population)
    {
        cout << x.first << ":" << x.second << "\n";
    }

    for(auto it = population.begin(); it!=population.end(); it++)
        cout << it->first << " = " << population[it->first] << "\n";

    int q;
    string qcountry;
    cin >> q;
    while(q--)
    {
        cin >> qcountry;
        cout << "Population of the country " << qcountry <<" is "
             << population[qcountry] << "\n";
    }


}
