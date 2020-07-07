// Parallel execution STL not yet available for e.g.
// clang++ (XCode) on macOS
// #define PARALLEL

#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
#include <chrono>
#include <sstream>
#ifdef PARALLEL
#include <execution>
#endif

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

static size_t threshold;

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return;
    size_t dist = distance(first, last);
    auto pivot = *next(first, dist / 2);

    ForwardIt middle1;
    ForwardIt middle2;

#ifdef PARALLEL
    if (dist < threshold)
    {
        middle1 = partition(std::execution::seq, first, last,
                            [pivot](const auto &em) { return em < pivot; });
        middle2 = partition(std::execution::seq, middle1, last,
                            [pivot](const auto &em) { return !(pivot < em); });
    }
    else
    {
        middle1 = partition(std::execution::par, first, last,
                            [pivot](const auto &em) { return em < pivot; });
        middle2 = partition(std::execution::par, middle1, last,
                            [pivot](const auto &em) { return !(pivot < em); });
    }
#else
    middle1 = partition(first, last,
                        [pivot](const auto &em) { return em < pivot; });
    middle2 = partition(middle1, last,
                        [pivot](const auto &em) { return !(pivot < em); });
#endif
    quicksort(first, middle1);
    quicksort(middle2, last);
}

auto randomNumberBetween = [](int low, int high) {
    auto randomFunc = [distribution = std::uniform_int_distribution<int>(low, high),
                       random_engine = std::mt19937{std::random_device{}()}]() mutable {
        return distribution(random_engine);
    };
    return randomFunc;
};

int main(int argc, char *argv[])
{
    size_t size;
    if (argc > 1)
    {
        stringstream s(argv[1]);
        s >> size;
        if (argc > 2)
        {
            s = stringstream(argv[2]);
            s >> threshold;
        }
        else
        {
            threshold = size;
        }
    }
    else
    {
        size = 10000;
        threshold = size;
    }
    vector<int> numbers;
    generate_n(back_inserter(numbers), size, randomNumberBetween(1, size));

    cout << "Vector size:" << size << " sorting with parallel threshold: " << threshold << endl;
    const auto startTime = high_resolution_clock::now();
    quicksort(numbers.begin(), numbers.end());
    const auto endTime = high_resolution_clock::now();

    cout << "Duration: " << duration_cast<duration<double, milli>>(endTime - startTime).count() << " milliseconds" << endl;
}