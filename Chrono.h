#include <chrono>
class Timer
{
private:
    using hrClock = std::chrono::high_resolution_clock;
    using milli = std::chrono::duration<double, std::milli>;
    using micro = std::chrono::duration<double, std::micro>;
    std::chrono::time_point<hrClock> start;
public:
    Timer() : start{ hrClock::now() } {}
    void reset()
    {
        start = hrClock::now();
    }
    int elapsed(bool a) const
    {
        if(a==1)
        {
            return milli (hrClock::now() - start).count();
        }
        else
        {
            return micro (hrClock::now() - start).count();
        }
    }
};
