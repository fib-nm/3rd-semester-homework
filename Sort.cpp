#define CATCH_CONFIG_MAIN
#include <iterator>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "catch.hpp"

template <class TRAI,
    class TCompare = std::less<
    typename std::iterator_traits<TRAI>::value_type
    >
>
void MergeSort(TRAI _begin, TRAI _end, TCompare cmp = {}) {
    auto real_end = _end - 1;
    size_t length = 1;
    auto i = _begin;
    while (i != real_end) {
        ++i;
        ++length;
    }
    if (length > 1) {

        auto middle = _begin;
        for (uint32_t j = 0; j < (length - 1) / 2; ++j) {
            ++middle;
        }

        auto old_begin = _begin;
        MergeSort(old_begin, middle + 1, cmp);
        auto new_begin = middle + 1;
        MergeSort(new_begin, _end, cmp);

        auto el_1 = *_begin;
        std::vector<decltype(el_1)> buffer;
        while (old_begin != (middle + 1) && new_begin != (real_end + 1)) {
            if (cmp(*old_begin, *new_begin)) {
                auto new_el = *old_begin;
                buffer.push_back(new_el);
                ++old_begin;
            }
            else {
                auto new_el = *new_begin;
                buffer.push_back(new_el);
                ++new_begin;
            }
        }
        while (old_begin != (middle + 1)) {
            auto new_el = *old_begin;
            buffer.push_back(new_el);
            ++old_begin;
        }
        while (new_begin != (real_end + 1)) {
            auto new_el = *new_begin;
            buffer.push_back(new_el);
            ++new_begin;
        }

        int32_t n = 0;
        auto b = _begin;
        while (b != (real_end + 1)) {
            auto iter = b;
            ++b;
            (*iter) = buffer[n];
            ++n;
        }
    }
}

template <class T>
void Print(const std::vector<T>& v) {
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

class Box {
public:
    float length, width, height;
    Box(float l, float w, float h) : length{ abs(l) }, width{ abs(w) }, height{ abs(h) } {}
};
std::ostream& operator<<(std::ostream& os, Box box) {
    os << "{ length = " << box.length << ", width = " << box.width << ", height = " << box.height << " }";
    return os;
}

TEST_CASE("ascending order") {
    std::cout << "1.enter vector's length\n";
    size_t n;
    std::cin >> n;
    std::cout << "enter vector of ints with " << n << " elements\n";
    std::vector<int32_t> v;
    for (int32_t i = 0; i < n; ++i) {
        int32_t e;
        std::cin >> e;
        v.push_back(e);
    }
    MergeSort(v.begin(), v.end());
    Print(v);
    std::cout << "\n";
    for (int32_t i = 0; i < n - 1; ++i) {
        REQUIRE(v[i] <= v[i + 1]);
    }
}

TEST_CASE("descending order") {
    std::cout << "2.enter vector's length\n";
    size_t n;
    std::cin >> n;
    std::cout << "enter vector of floats with " << n << " elements\n";
    std::vector<float> v;
    for (int32_t i = 0; i < n; ++i) {
        float e;
        std::cin >> e;
        v.push_back(e);
    }
    MergeSort(v.begin(), v.end(), [](float a, float b) { return a > b; });
    Print(v);
    for (int32_t i = 0; i < n - 1; ++i) {
        REQUIRE(v[i] >= v[i + 1]);
    }
}

TEST_CASE("comparing boxes") {
    std::cout << "3.enter number of boxes\n";
    size_t n;
    float l, w, h;
    std::vector<Box> v;
    std::cin >> n;
    for (int32_t i = 0; i < n; ++i) {
        std::cout << "enter length, width and height of box " << i + 1 << "\n";
        std::cin >> l >> w >> h;
        Box box{ l, w, h };
        v.push_back(box);
    }
    MergeSort(v.begin(), v.end(), [](Box a, Box b) { return a.length < b.length; });
    std::cout << "sorted by length:\n";
    Print(v);
    for (int32_t i = 0; i < n - 1; ++i) {
        REQUIRE((v[i]).length <= (v[i + 1]).length);
    }
    MergeSort(v.begin(), v.end(), [](Box a, Box b) { return a.width < b.width; });
    std::cout << "sorted by width:\n";
    Print(v);
    for (int32_t i = 0; i < n - 1; ++i) {
        REQUIRE((v[i]).width <= (v[i + 1]).width);
    }
    MergeSort(v.begin(), v.end(), [](Box a, Box b) { return a.height < b.height; });
    std::cout << "sorted by height:\n";
    Print(v);
    for (int32_t i = 0; i < n - 1; ++i) {
        REQUIRE((v[i]).height <= (v[i + 1]).height);
    }
}
