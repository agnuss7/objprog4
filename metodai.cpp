#include <iostream>
#include <algorithm>
#include "Vector.h"
template<class V>
void Vector<V>::push_back(V a)
{
    if(cp>sz)
    {
        el[sz]=a;
        sz++;
    }
    else{
        cp=sz*2;
        V* A=new V[cp];
        std::copy(el,el+sz,A);
        A[sz]=a;
        sz++;
        delete[] el;
        el=A;
    }
}
///del patogumo
template<class V>
void Vector<V>::print()
{
for(std::size_t i=0;i<sz;i++){
std::cout<<el[i]<<" ";}
}
template<class V>
std::size_t Vector<V>::size() const{
return sz;
}
template<class V>
std::size_t Vector<V>::capacity() const{
return cp;
}
template<class V>
void Vector<V>::pop_back()
{
sz--;
}
template<class V>
void Vector<V>::resize(std::size_t b)
{
    if(b<=cp)
    {
        sz=b;
    }
    else{
        cp=b*2;
        V* A=new V[cp];
        std::copy(el,el+b,A);
        sz=b;
        delete[] el;
        el=A;
    }
}
template<class V>
void Vector<V>::reserve(std::size_t b)
{
        cp=b;
        V* A=new V[cp];
        std::copy(el,el+sz,A);
        delete[] el;
        el=A;
}
