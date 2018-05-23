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
    ///constructor, initializing with a specified value
    Vector(std::size_t n, V t):cp(n),sz(n),el(new V[cp])
    {
        for(std::size_t i=0; i<sz; i++)
        {
            el[i]=t;
        }
    }
    ///constructor, initializing with an initializer list
    Vector (std::initializer_list<V> A):cp(static_cast<std::size_t>(A.size())),sz(static_cast<std::size_t>(A.size())),el(new V[cp])
    {
        std::copy(A.begin(),A.end(),el);
    }
    ///copy constructor
    Vector (const Vector& v):cp(v.cp),sz(v.sz),el(new V[cp])
    {
            delete[] el;
            V* A=new V[v.cp];
            std::copy(v.el,v.el+v.sz,A);
            el=A;

    }
    ///move constructor
    Vector (Vector&& v):cp(v.cp),sz(v.sz),el(v.el)
    {
            v.el=nullptr;
            v.sz=0;
            v.cp=0;
    }
    ///returns how many elements can be added
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
    ///shrinks the capacity to be equal to size
    void shrink_to_fit ()
    {
        iterator A=new V[sz];
        std::copy(el,el+sz,A);
        delete[] el;
        cp=sz;
        el=A;
    }
    ///inserts a value in a specified position
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
    //nezinau ka daryt, kad nesimaisytu su kitu insert'u, kai V - int.
   /* void insert(iterator p, const std::size_t c, const V& a)
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
    }*/
    ///inserts a specified range
    template<class InputIt>
    void insert(iterator p, InputIt f, InputIt l)
    {
        std::size_t c=std::distance(f,l);
        while(sz+c>=cp){cp*=2;}
        iterator A=new V[cp];
        std::copy(el,p,A);
        std::size_t temp=std::distance(el,p);
        for(std::size_t  i=0;i<c;i++)
        {
           *(A+temp+i)=*f;
           f++;
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
    ///access element with bounds checking
    V &at(std::size_t b)
    {
        if(b<sz){
        return el[b];
        }
        else {throw std::out_of_range("");}
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
///copy = operator
    Vector &operator=(const Vector& v)
    {
        if(&v==this) {return *this;}
        else{
            delete[] el;
            V* A=new V[v.cp];
            std::copy(v.el,v.el+v.sz,A);
            el=A;
            sz=v.sz;
            cp=v.cp;
            return *this;
        }
    }
    ///move = operator
    Vector &operator=(Vector&& v)
    {
        if(&v==this) {return *this;}
        else{
            delete[] el;
            el=v.el;
            sz=v.sz;
            cp=v.cp;
            v.el=nullptr;
            v.sz=0;
            v.cp=0;
            return *this;
        }
    }


/*
    void print()
    {
        for(int i=0;i<sz;i++){
        std::cout<<el[i]<<" ";
        }
        std::cout<<std::endl;
    }*/
};


