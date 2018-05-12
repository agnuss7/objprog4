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
    bool empty() const
    {
        if(sz==0)
        {
            return true;
        }
        else
            return false;
    }
    iterator begin() const
    {
        return &el[0];
    }
    iterator end() const
    {
        return &el[sz];
    }
    Vector(): cp(0),sz(0), el(new V[cp]) {};
    ~Vector()
    {
        delete[] el;
    }
    Vector(iterator f, iterator l):cp(std::distance(f,l)),sz(std::distance(f,l)),el(new V[cp])
    {
        for(std::size_t i=0; i<sz; i++)
        {
            el[i]=*f;
            f++;
        }
    };

    void erase (iterator f, iterator l)
    {
        V* A=new V[cp];
        std::copy(el,f,A);
        std::size_t temp=std::distance(el,f);
        std::copy(l,el+sz,A+temp);
        delete[] el;
        sz=sz-std::distance(f,l);
        el=A;
    };
    void clear()
    {
        sz=0;
        delete[] el;
        el=new V[cp];
    };
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
    };
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
    };
    void pop_back()
    {
        sz--;
    };
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
    };
    void print()
    {
        for(std::size_t i=0; i<sz; i++)
        {
            std::cout<<el[i]<<" ";
        }
    };
    std::size_t size() const
    {
        return sz;
    };
    std::size_t capacity() const
    {
        return cp;
    };
    V &front()
    {
        return el[0];
    };
    V &back()
    {
        return el[sz-1];
    };
    V &operator[](std::size_t b)
    {
        return el[b];
    }

};


