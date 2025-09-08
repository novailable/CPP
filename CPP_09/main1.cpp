// #include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

long long compare_n = 0;

struct CountCompare {
    bool operator()(const int &a, const int &b) const {
        compare_n++;
        return a < b;
    }
};

void binary_insert(std::vector<int> &sorted, int value)
{
    // std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value, CountCompare());
    // sorted.insert(it, value);

    int left = 0, right = sorted.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        compare_n++;
        if (value < sorted[mid])
            right = mid;
        else
            left = mid + 1;
    }
    sorted.insert(sorted.begin() + left, value);
}

// Ford-Johnson Merge-Insertion Sort
std::vector<int> ford_johnson_sort(const std::vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1) return arr;

    std::vector<int> small, large;

    // Step 1: Pair elements
    for (int i = 0; i + 1 < n; i += 2) {
        compare_n++;
        if (arr[i] < arr[i + 1]) {
            small.push_back(arr[i]);
            large.push_back(arr[i + 1]);
        } else {
            small.push_back(arr[i + 1]);
            large.push_back(arr[i]);
        }
    }
    if (n % 2 != 0) small.push_back(arr[n-1]); // Handle odd element

    // Step 2: Recursively sort the large elements
    std::vector<int> sorted_large = ford_johnson_sort(large);

    // Step 3: Insert small elements using binary insertion
    for (int val : small) {
        binary_insert(sorted_large, val);
    }

    return sorted_large;
}

bool    checker(std::vector<int> arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i - 1] > arr[i])
            return (false);
    }
    return (true);
}

int main(int argc, char **argv) {

    double duration;
    for (int j = 0; j < 100; ++j)
    {
  
        int n = std::atoi(argv[1]);
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = n - i;
        
        std::clock_t	start = std::clock();
        std::vector<int> sorted = ford_johnson_sort(arr);

        std::clock_t	end = std::clock();
        duration += double(end - start) * 1000000.0 / CLOCKS_PER_SEC;
        // std::cout << "Time: " << duration << " us. compare: " << compare_count << "\n";
        if (!checker(sorted))
            std::cout << "failed on: " << n << std::endl;
    }
    std::cout << "avg time : " << duration / 100 << " avg compare: " << compare_n / 100 << "\n";
}
