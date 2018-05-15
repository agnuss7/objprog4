#include <iterator>
#include <algorithm>

template <class V>

class Vector
{
private:
    std::size_t cp;
    std::size_t sz;
    V *el;

public:
using iterator = V*;
std::size_t max_size() const
{
    std::allocator<V> a;
    return a.max_size();;
}
///checks if the vector is empty
    bool empty() const
    {
        if(sz==0)
        {
            return true;
        }
        else
            return false;
    }
///returns a reference to the start of the vector
    iterator begin() const
    {
        return &el[0];
    }
///returns a reference to the end of the vector
    iterator end() const
    {
        return &el[sz];
    }
///default constructor
    Vector(): cp(0),sz(0), el(new V[cp]) {};
///destructor
    ~Vector()
    {
        delete[] el;
    }
///constructor, initializing with a specified range
template<class InputIt>
    Vector(InputIt f, InputIt l):cp(std::distance(f,l)),sz(std::distance(f,l)),el(new V[cp])
    {
        for(std::size_t i=0; i<sz; i++)
        {
            el[i]=*f;
            f++;
        }
    }
        Vector(std::size_t n, V t):cp(n),sz(n),el(new V[cp])
    {
        for(std::size_t i=0; i<sz; i++)
        {
            el[i]=t;
        }
    }
    void shrink_to_fit ()
    {
        iterator A=new V[sz];
        std::copy(el,el+sz,A);
        delete[] el;
        cp=sz;
        el=A;
    }
    void insert(iterator p, const V& a)
    {
        if(sz>=cp){cp*=2;}
        iterator A=new V[cp];
        std::copy(el,p,A);
        std::size_t temp=std::distance(el,p);
        *(A+temp)=a;
        std::copy(el+temp,el+sz,A+temp+1);
        delete [] el;
        el=A;
        sz++;
    }
    void insert(iterator p, const std::size_t c, const V& a)
    {
        if(sz+c>=cp){cp+=c;cp*=2;}
        iterator A=new V[cp];
        std::copy(el,p,A);
        std::size_t temp=std::distance(el,p);
        for(std::size_t  i=0;i<c;i++)
        {
           *(A+temp+i)=a;
        }
        std::copy(el+temp,el+sz,A+temp+c);
        delete [] el;
        el=A;
        sz+=c;
    }
    template<class InputIt>
    void insert(iterator p, InputIt f, InputIt l)
    {
        if(sz+std::distance(f,l)>=cp){cp+=std::distance(f,l);cp*=2;}
        iterator A=new V[cp];
        std::copy(el,p,A);
        std::size_t temp=std::distance(el,p);
        for(std::size_t  i=0;i<c;i++)
        {
           *(A+temp+i)=a;
        }
        std::copy(el+temp,el+sz,A+temp+c);
        delete [] el;
        el=A;
        sz+=c;
    }
///removes specified range [f,l) from vector
    void erase (iterator f, iterator l)
    {
        iterator A=new V[cp];
        std::copy(el,f,A);
        std::size_t temp=std::distance(el,f);
        std::copy(l,el+sz,A+temp);
        delete[] el;
        sz=sz-std::distance(f,l);
        el=A;
    }
///clears the vector
    void clear()
    {
        sz=0;
        delete[] el;
        el=new V[cp];
    }
///reserves space for upcoming elements
    void reserve(std::size_t b)
    {
        if(b>sz)
        {
            cp=b;
            V* A=new V[cp];
            std::copy(el,el+sz,A);
            delete[] el;
            el=A;
        }
    }
///sets the specified size
    void resize(std::size_t b)
    {
        if(b<=cp)
        {
            sz=b;
        }
        else
        {
            cp=b*2;
            V* A=new V[cp];
            std::copy(el,el+b,A);
            sz=b;
            delete[] el;
            el=A;
        }
    }
///removes the last element from the vector
    void pop_back()
    {
        sz--;
    }
///attaches the indicated value to the tail of the vector
    void push_back(const V &a)
    {
        if(cp>sz)
        {
            el[sz]=a;
            sz++;
        }
        else
        {
            if(cp>0)
            {
                cp=sz*2;
            }
            else
                cp=1;
            V* A=new V[cp];
            std::copy(el,el+sz,A);
            A[sz]=a;
            sz++;
            delete[] el;
            el=A;
        }
    }
///returns the size of the vector
    std::size_t size() const
    {
        return sz;
    }
///returns the capacity of the vector
    std::size_t capacity() const
    {
        return cp;
    }
///accesses the first element
    V &front()
    {
        return el[0];
    }
///accesses the last element
    V &back()
    {
        return el[sz-1];
    }
///allows for random access
    V &operator[](std::size_t b)
    {
        return el[b];
    }
};


