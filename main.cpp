#include <iostream>
#include <string>
#include <vector>
#include "Vector.h"
#include "funkcijos.cpp"
#include "studentai.h"
#include "Chrono.h"
using std::cout;
using std::cin;
void CV2(std::string p, std::size_t N)
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
        a.back().mediana();
        a.back().vidurkis();
    }
    df.close();
    Vector<studentai>::iterator it=std::partition(a.begin(),a.end(),negavoSkolos);
    Vector<studentai> a2 (it,a.end());
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
    double u[]={1,2,3};
    Vector<int> h;
    h.push_back(8);
    h.push_back(8);
    h.insert(h.begin(),u,u+3);
    cout<<h[0]<<"\n";
    int s=10;
    int L;
    Timer T;
    do
    {
        cout<<"ivestkit operacija:\n1 - skaiciuti ivedimo trukme\n2 - skaiciuoti studentus (su 2 kont)\n3 - skaiciuoti studentus (su 3 kont)\n";
        cin>>s;


        if(s==1)
        {
            int k=0;
            cout<<"kiek elementu?\n";
            cin>>L;
            Vector<int> A2;
            T.reset();
            for(int i=0; i<L; i++)
            {
                A2.push_back(i);
                if(A2.capacity()==A2.size()){k++;}
            }
            cout<<"mano Vector push_back'inti "<<L<<" elementu uztruko "<<T.elapsed(0)<<" mikrosekundes\nperskirstymas ivyko "<<k<<" kartu.\n";
            std::vector<int> A1;
            k=0;
            T.reset();
            for(int i=0; i<L; i++)
            {
                A1.push_back(i);
                if(A1.capacity()==A1.size()){k++;}
            }
            cout<<"std::vector push_back'inti "<<L<<" elementu uztruko "<<T.elapsed(0)<<" mikrosekundes\nperskirstymas ivyko "<<k<<" kartu.\n";
        }
        else if(s==2)
        {
            do{cout<<"kiek studentu?\n";
            cin>>L;}while (L>100000);
            T.reset();
            CV2("5.txt",L);

            cout<<T.elapsed(1)<<" milisekundes \n";
        }
        else if(s==3)
        {
            do{cout<<"kiek studentu?\n";
            cin>>L;}while (L>100000);
            T.reset();
            CV3("5.txt",L);
            cout<<T.elapsed(1)<<" milisekundes \n";
        }

    }
    while(s!=0);



    return 0;
}
