#ifndef PATHTRACER_RANDOM_H
#define PATHTRACER_RANDOM_H

#include <random>
namespace pathtracer
{

class Random
{
public:
    static Random& instance();

    template <class Distribution>
    auto next(Distribution& d) -> decltype(d())
    {
        return d(g);
    }

    template <class Distribution>
    auto operator()(Distribution& d) -> decltype(d())
    {
        return d(g);
    }

private:
    Random();
    Random(const Random&) = delete;
    void operator=(const Random&) = delete;

    std::mt19937 g;
};

}

#endif //PATHTRACER_RANDOM_H
