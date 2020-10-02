#include "C:\Users\nimak\cpp_libraries\test_runner.h"
#include "C:\Users\nimak\cpp_libraries\profile.h"
#define DEBUG(x) std::cout << #x << " = " << x << "\n"
#include <future>
#include <algorithm>
#include <numeric>

const size_t NUMBER_OF_THREADS = 8;


/*
 *
 * Solution by Coursera.
 * Two additional classes: IteratorRange and Paginator(make set of pages(certain size) of any container
 *
 */
template <typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end)
            : first(begin)
            , last(end)
            , size_(distance(first, last))
    {
    }

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }

    size_t size() const {
        return size_;
    }

private:
    Iterator first, last;
    size_t size_;
};

template <typename Iterator>
class Paginator {
private:
    vector<IteratorRange<Iterator>> pages;
public:
    Paginator(Iterator begin, Iterator end, size_t page_size) {
        for (size_t left = distance(begin, end); left > 0; ) {
            size_t current_page_size = min(page_size, left);
            Iterator current_page_end = next(begin, current_page_size);
            pages.push_back({begin, current_page_end});

            left -= current_page_size;
            begin = current_page_end;
        }
    }

    auto begin() const {
        return pages.begin();
    }

    auto end() const {
        return pages.end();
    }

    size_t size() const {
        return pages.size();
    }
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(begin(c), end(c), page_size);
}

template <typename ContainerOfVectors>
int64_t SumSingleThread(const ContainerOfVectors& matrix) {
    int64_t sum = 0;
    for (const auto& row : matrix) {
        for (auto item : row) {
            sum += item;
        }
    }
    return sum;
}

int64_t CalculateMatrixSum(const vector<vector<int>>& matrix) {
    vector<future<int64_t>> futures;
    for (auto page : Paginate(matrix, 2000)) {
        DEBUG(page.size());
        futures.push_back(async([=] { return SumSingleThread(page); }));
    }
    int64_t result = 0;
    for (auto& f : futures) {
        result += f.get();
    }
    return result;
}


template <typename Iterator>
int64_t SumSingleThread(Iterator begin,
                                   Iterator end) {
    int64_t ans = 0;
    for(auto row = begin; row != end; row++){
        for(auto col = row->begin(); col != row->end(); col++){
            ans += *col;
        }
    }
    return ans;
}


int64_t CalculateMatrixSumMulti(const vector<std::vector<int>>& matrix) {
    size_t size_part = (matrix.size() < NUMBER_OF_THREADS) ? 1: matrix.size() / NUMBER_OF_THREADS;
    size_t num_thr = (matrix.size() < NUMBER_OF_THREADS) ? matrix.size() : NUMBER_OF_THREADS;

    DEBUG(size_part);
    DEBUG(num_thr);

    std::vector<std::future<int64_t>> futures;
    for (size_t it = 0; it < num_thr; it++){

        futures.push_back(async([matrix, it, size_part] { return SumSingleThread(matrix.begin() + it * size_part,
                                                             matrix.begin() + (it+1) * size_part);}));
    }
    int64_t result = 0;
    for (auto& f: futures){
        result += f.get();
    }
    return result;
}


//Test matrix
const std::vector<std::vector<int>> matrix(16000, {1,2,-1,1,2,-22,4,5,56,1,2,2,2,2});



void TestMyCalculateMatrixSumMulti() {
    ASSERT_EQUAL(CalculateMatrixSumMulti(matrix),
                    matrix.size() * std::accumulate(matrix[0].begin(), matrix[0].end(), 0));


}

void TestCalculateMatrixSumSingle() {
    ASSERT_EQUAL(SumSingleThread(matrix),
                 matrix.size() * std::accumulate(matrix[0].begin(), matrix[0].end(), 0));
}

void TestCalculateMatrixSumCoursera() {
    ASSERT_EQUAL(CalculateMatrixSum(matrix),
                 matrix.size() * std::accumulate(matrix[0].begin(), matrix[0].end(), 0));
}



int main() {
    {
        LOG_DURATION("My matrix sum multi thr");
        RUN_TEST(TestRunner(), TestMyCalculateMatrixSumMulti);
    }

    {
        LOG_DURATION("Matrix Sum single mode");
        RUN_TEST(TestRunner(), TestCalculateMatrixSumSingle);
    }

    {
        LOG_DURATION("Coursera sol.");
        RUN_TEST(TestRunner(), TestCalculateMatrixSumCoursera);
    }

}
