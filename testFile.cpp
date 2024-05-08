#include <fmt/core.h>
#include <fmt/ranges.h>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> ints = {1, 2, 3, 4, 6, 8};
    std::ranges::sort(ints, std::ranges::greater());

    fmt::println("{}", ints);
}