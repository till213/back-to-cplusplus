#include <algorithm>
#include <vector>
#include <random>
#include <iostream>
#include <chrono>
#include <thread>
// Not yet available for clang++ (XCode) on macOS
// #include <execution>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

const size_t threshold = 10; // some value

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return;
    size_t dist = distance(first, last);
    auto pivot = *next(first, dist / 2);

    // parallel::execution_policy exec_pol = parallel::par;
    // if (distance < threshold)
    //     exec_pol = parallel_execution::seq;

    // ForwardIt middle1 = partition(exec_pol, first, last,
    //                               [pivot](const auto &em) { return em < pivot; });
    // ForwardIt middle2 = partition(exec_pol, middle1, last,
    //                               [pivot](const auto &em) { return !(pivot < em); });

    ForwardIt middle1 = partition(first, last,
                                  [pivot](const auto &em) { return em < pivot; });
    ForwardIt middle2 = partition(middle1, last,
                                  [pivot](const auto &em) { return !(pivot < em); });
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

int main()
{
    vector<int> numbers;
    generate_n(back_inserter(numbers), 500, randomNumberBetween(1, 100));

    cout << "Unsorted:" << endl;
    for (auto &n : numbers)
    {
        cout << n << ", ";
    }
    cout << endl;

    const auto startTime = high_resolution_clock::now();
    quicksort(numbers.begin(), numbers.end());
    const auto endTime = high_resolution_clock::now();

    cout << "Sorted:" << endl;
    for (auto &n : numbers)
    {
        cout << n << ", ";
    }
    cout << endl;
    cout << "Duration: " << duration_cast<duration<double, milli>>(endTime - startTime).count() << " milliseconds" << endl;
}