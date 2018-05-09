#pragma once
template <class V>
class Vector {
private:
std::size_t sz;
std::size_t cp;
V *el;
public:
Vector(): sz(0), cp(0),el(new V[sz]){};
void reserve(std::size_t b);
void resize(std::size_t b);
void pop_back();
void push_back(V a);
void print();
std::size_t size() const;
std::size_t capacity() const;
double &operator[](std::size_t b){
return el[b];
}

};
