#include "studentai.h"
#include <fstream>
#include <iostream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iomanip>
using std::cout;

studentai::studentai (std::istream &in)
{
    read(in);
}
///taip mes ivesim visus reikalingus parametrus i klases objekta
void studentai::add (std::string & name, std::string & sname, std::size_t & e, std::vector<std::size_t> & p)
{
    var=name;
    pav=sname;
    egz=e;
    paz=p;
}
///iraso varda, pavarde, pazymius ir egzamina i objekta is failo
std::istream& studentai::read (std::istream& in)
{
    char s;
    float q;
    in.get(s);
    while(s!='\t')
    {
        var.push_back(s);
        in.get(s);
    }
    in.get(s);
while(s=='\t')
{
in.get(s);
}
    while(s!='\t')
    {
        pav.push_back(s);
        in.get(s);
    }
    while (s!='\n')
    {
        in>>q;
        paz.push_back(q);
        in.get(s);
    }
    egz=paz.back();
    paz.pop_back();
	return in;
}

///apskaiciuoja nd mediana ir galutini bala
void studentai::mediana()
{
if(paz.size()==0){mednd=0;}
else{
    std::sort(paz.begin(),paz.end());
    if(paz.size()%2==0)
{
mednd=(paz[paz.size()/2]+paz[paz.size()/2-1])/2;
}
else
{
mednd=paz[paz.size()/2];
}}
medtotal=mednd*0.4+egz*0.6;
}
///apskaiciuoja nd vidurki ir galutini bala
void studentai::vidurkis()
{
    vidnd=0;
if(paz.size()==0){vidnd=0;}
  else{  for(std::size_t i:paz)
{
    vidnd+=i;
}
vidnd=vidnd/paz.size();}
vidtotal=vidnd*0.4+egz*0.6;
}
///nd vidurkio getter'is
float studentai::getVid() const
{return vidnd;}
///nd medianos getter'is
float studentai::getMed() const
{return mednd;}
/**skausdina varda, pavarde
*ir, priklausant nuo bool a busenos,
*arba galutinius balus (geri studentai)
arba nd vidurki ir mediana (blogi studentai)*/
void studentai::print(bool a)
{
if(a==1)
{
cout<<var<<"\t";
if(var.length()<8){cout<<"\t";}
cout<<pav<<"\t";
if(pav.length()<8){cout<<"\t";}
cout<<std::setprecision(3)<<vidtotal<<"\t\t"<<medtotal<<"\n";
}
if(a==0)
{
cout<<var<<"\t";
if(var.length()<8){cout<<"\t";}
cout<<pav<<"\t";
if(pav.length()<8){cout<<"\t";}
cout<<std::setprecision(3)<<vidnd<<"\t\t"<<mednd<<"\n";
}
}
///pavardes getter'is
inline std::string studentai::getPav () const
{
return pav;
}
///naudojamas rikiuojant pagal pavardes
bool compare  (const studentai & e, const  studentai & b)
{
if (e.getPav()<b.getPav())
{return true;}
else return false;
}
///naudojamas rikiuojant gerus/blogus
bool negavoSkolos(const studentai & e)
{
if(e.getVid()<6 || e.getMed()<6)
{return false;}
else return true;
}

void cont2v (std::string p, const std::size_t N)
{
    std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::vector<studentai> a;
    a.reserve(N);
for(std::size_t i=0;i<N;i++){
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
for(std::size_t i=0;i<a.size();i++)
{
    a[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}
void cont3v(std::string p, const std::size_t N)
{
std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::vector<studentai> a;
    a.reserve(N);
for(std::size_t i=0;i<N;i++){
a.resize(i+1);
a[i].read(df);
a[i].mediana();
a[i].vidurkis();
}
df.close();




std::vector<studentai>::iterator it=std::partition(a.begin(),a.end(),negavoSkolos);
std::vector<studentai> a2 (it,a.end());
std::vector<studentai> a1 (a.begin(),it);










std::sort(a1.begin(),a1.end(),compare);
std::sort(a2.begin(),a2.end(),compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<a1.size();i++)
{
    a1[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}

void cont2d(std::string p, const std::size_t N)
{
    std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::deque<studentai> a;
for(std::size_t i=0;i<N;i++){
a.resize(i+1);
a[i].read(df);
a[i].vidurkis();
a[i].mediana();
}
df.close();
std::deque<studentai>::iterator it=std::partition(a.begin(),a.end(),negavoSkolos);
std::deque<studentai> a2 (it,a.end());
a.erase(it,a.end());
std::sort(a.begin(),a.end(),compare);
std::sort(a2.begin(),a2.end(),compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<a.size();i++)
{
    a[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}
void cont3d(std::string p, const std::size_t N)
{
std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::deque<studentai> a;
for(std::size_t i=0;i<N;i++){
a.resize(i+1);
a[i].read(df);
a[i].vidurkis();
a[i].mediana();
}
df.close();

std::deque<studentai>::iterator it=std::partition(a.begin(),a.end(),negavoSkolos);
std::deque<studentai> a2 (it,a.end());
std::deque<studentai> a1 (a.begin(),it);


std::sort(a1.begin(),a1.end(),compare);
std::sort(a2.begin(),a2.end(),compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<a1.size();i++)
{
    a1[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}
void cont2l(std::string p, const std::size_t N)
{
    std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::list<studentai> a;
    for(std::size_t i=1;i<=N;i++)
{
a.resize(i);
(a.back()).read(df);
(a.back()).mediana();
(a.back()).vidurkis();
}
df.close();
std::list<studentai>::iterator it=partition(a.begin(),a.end(),negavoSkolos);
std::list<studentai> a2(it,a.end());
a.erase(it,a.end());
a.sort(compare);
a2.sort(compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
while(!a.empty())
{
    a.front().print(1);
    a.pop_front();
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
while(!a2.empty())
{
    a2.front().print(0);
    a2.pop_front();
}

}
void cont3l(std::string p, const std::size_t N)
{
std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::list<studentai> a;
    for(std::size_t i=1;i<=N;i++)
{
a.resize(i);
(a.back()).read(df);
(a.back()).mediana();
(a.back()).vidurkis();
}
df.close();
std::list<studentai>::iterator it=partition(a.begin(),a.end(),negavoSkolos);
std::list<studentai> a1(a.begin(),it);
std::list<studentai> a2(it,a.end());
a1.sort(compare);
a2.sort(compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
while(!a1.empty())
{
    a1.front().print(1);
    a1.pop_front();
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
while(!a2.empty())
{
    a2.front().print(0);
    a2.pop_front();
}
}
///spausdina varda, pavarde, pazymius ir egzamina
std::ostream& operator<<(std::ostream& out, const studentai& f)
{
    out << f.var << "\t";
if(f.var.length()<8){out<<"\t";}
out << f.pav<<"\t" ;
if(f.pav.length()<8){out<<"\t";}
    for(std::size_t i :f.paz)
{
out<<i<<"\t";
}
out<<f.egz<<"\n";
   return out ;
}
