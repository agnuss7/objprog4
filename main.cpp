#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "Vector.h"
#include "funkcijos.cpp"
#include "studentai.h"
using std::cout;
using std::cin;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds TimeType;
void CV2(std::string p, std::size_t N)
{
    std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::vector<studentai> a;
    a.reserve(N);
    for(std::size_t i=0; i<N; i++)
    {
        a.resize(i+1);
        a[i].read(df);
        a.back().mediana();
        a.back().vidurkis();
    }
    df.close();
    std::vector<studentai>::iterator it=std::partition(a.begin(),a.end(),negavoSkolos);
    std::vector<studentai> a2 (it,a.end());
    a.erase(it,a.end());
    std::sort(a.begin(),a.end(),compare);
    std::sort(a2.begin(),a2.end(),compare);
    cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
    for(std::size_t i=0; i<a.size(); i++)
    {
        a[i].print(1);
    }
    cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
    for(std::size_t i=0; i<a2.size(); i++)
    {
        a2[i].print(0);
    }
}

void CV3 (std::string p, std::size_t N)
{
    std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    Vector<studentai> a;
    a.reserve(N);
    for(std::size_t i=0; i<N; i++)
    {
        a.resize(i+1);
        a[i].read(df);
        a[i].mediana();
        a[i].vidurkis();
    }
    df.close();

    Vector<studentai>::iterator it=std::partition(a.begin(),a.end(),negavoSkolos);
    Vector<studentai> a2 (it,a.end());
    Vector<studentai> a1 (a.begin(),it);
    std::sort(a1.begin(),a1.end(),compare);
    std::sort(a2.begin(),a2.end(),compare);
    cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
    for(std::size_t i=0; i<a1.size(); i++)
    {
        a1[i].print(1);
    }
    cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
    for(std::size_t i=0; i<a2.size(); i++)
    {
        a2[i].print(0);
    }
}
int main()
{
    int s=10;
    std::size_t L;
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    do
    {
        cout<<"ivestkit operacija:\n1 - skaiciuti ivedimo trukme\n2 - skaiciuoti studentus (su 2 kont)\n3 - skaiciuoti studentus (su 3 kont)\n";
        cin>>s;



        if(s==1)
        {
            cout<<"kiek elementu?\n";
            cin>>L;

            Vector<double> A2;
            t1=Clock::now();
            for(double i=0.1; i<L; i++)
            {
                A2.push_back(i);
            }
            t2=Clock::now();
            cout<<"mano Vector'ius uztruko "<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
            std::vector<double> A1;
            t1=Clock::now();
            for(double i=0.1; i<L; i++)
            {
                A1.push_back(i);
            }
            t2=Clock::now();
            cout<<"std::vector uztruko "<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n\n";

        }
        if(s==2)
        {
            cout<<"kiek studentu?\n";
            cin>>L;
            t1=Clock::now();
            CV2("5.txt",L);
            t2=Clock::now();
            cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
        }
        if(s==3)
        {
            cout<<"kiek studentu?\n";
            cin>>L;
            t1=Clock::now();
            CV3("5.txt",L);
            t2=Clock::now();
            cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
        }
    }
    while(s!=0);



    return 0;
}
