#include <iostream>
#include <vector>
#include <chrono>
#include "Vector.h"
#include "metodai.cpp"
using std::cout;
const std::size_t N=100000;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds TimeType;
int main()
{
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    Vector<double> A2;
    t1=Clock::now();
    A2.reserve(N);
    for(double i=0.1;i<N;i++)
    {
        A2.push_back(i);
    }
    t2=Clock::now();
    cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
    std::vector<double> A1;
    t1=Clock::now();
    for(double i=0.1;i<N;i++)
    {
        A1.push_back(i);
    }
    t2=Clock::now();
    cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n\n";

    return 0;
}
