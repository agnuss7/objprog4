# objprog4

Laiko matavimas ir lyginimas su std::vector.

## Push_back'as _mikrosekundėm_ 

elementų skaičius|std::vector | mano Vector | perskirstimų skaičius
---|---|---|---
 10000 | 0 | 0|14
100000| 0 | 0|17
1000000| 26064.3 | 15190 |20
10000000| 189481.2 | 109276.5|24
100000000| 2338806.3 | 1083178.3|27

-o1 flag'as

elementų skaičius|std::vector | mano Vector
---|---|---
 10000 | 0 | 0
100000| 0 | 0
1000000| 26056.3 | 15351
10000000| 238305.25 | 119771.5
100000000| 2336196.25 | 1109301

-o2 flag'as

elementų skaičius|std::vector | mano Vector
---|---|---
 10000 | 0 | 0
100000| 0 | 0
1000000| 104179.7 | 41989.7
10000000| 246004.7 | 113086
100000000| 2337772.4 | 1091322.6

-o3 flag'as

elementų skaičius|std::vector | mano Vector
---|---|---
 10000 | 0 | 0
100000| 0 | 0
1000000| 2460 | 12750.5
10000000| 239622.3 | 112742.7
100000000| 2333588 | 1109573

mano Vector'ius greitesnis! 

## Studentų skirstymo lyginimas _milisekundėm_

# std::vector

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 7 | 7
|100 | 78| 79
|1000 | 765 | 732 
|10000 | 7066 | 6929 
|100000 | 54869 | 51717

# mano Vector

| Generuotų studentų skaičius faile |  2 konteineriai | 3 konteineriai
|------------ | -------------|--------
|10 | 15 | 6
|100 |68 | 52
|1000 | 695 | 539 
|10000 | 6564 | 5643
|100000 | 43851 | 79796

# coolish things

Šiek tiek labiau supratau iteratorius. Nustebau, kad lengva su template'ais inicializuoti bet kokio tipo konteinerius.

template<class InputIt>
    Vector(InputIt f, InputIt l):cp(std::distance(f,l)),sz(std::distance(f,l)),el(new V[cp])
    {
        for(std::size_t i=0; i<sz; i++)
        {
            el[i]=*f;
            f++;
        }
    }
                                   
# terrible things

Šie metodai kertasi, kai template<int>.

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
