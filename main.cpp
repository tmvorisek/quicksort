#include <algorithm>
#include <stdlib.h>
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

#include "quicksort.hpp"

using std::is_sorted;

TEST_CASE( "Test quicksort with various inputs", "[quicksort]" ) {

    SECTION("small vector ints")
    {
        vector<int> v_small_sorted = {0,1,2,3,4};
        quicksort(v_small_sorted, 0 ,v_small_sorted.size());
        REQUIRE(is_sorted(v_small_sorted.begin(), v_small_sorted.end()));

        vector<int> v_small_unsorted = {1,0,2,4,3};
        quicksort(v_small_unsorted, 0 ,v_small_unsorted.size());
        REQUIRE(is_sorted(v_small_unsorted.begin(), v_small_unsorted.end()));
    }

    SECTION("small vector floats")
    {
        vector<float> v_small_sorted = {0.1f,1.4f,2.0f,3.7f,4.8f};
        quicksort(v_small_sorted, 0 ,v_small_sorted.size());
        REQUIRE(is_sorted(v_small_sorted.begin(), v_small_sorted.end()));

        vector<float> v_small_unsorted = {1.4f,1.2f,1.5f,1.7f,1.0f};
        quicksort(v_small_unsorted, 0 ,v_small_unsorted.size());
        REQUIRE(is_sorted(v_small_unsorted.begin(), v_small_unsorted.end()));
    }

    SECTION("small vector chars")
    {
        vector<unsigned char> v_small_sorted = {(char)0, 'a', (char)127};
        quicksort(v_small_sorted, 0 ,v_small_sorted.size());
        REQUIRE(is_sorted(v_small_sorted.begin(), v_small_sorted.end()));

        vector<unsigned char> v_small_unsorted = {'e','d','c','b','a'};
        quicksort(v_small_unsorted, 0 ,v_small_unsorted.size());
        REQUIRE(is_sorted(v_small_unsorted.begin(), v_small_unsorted.end()));
    }

    std::srand(124838);
    #define LARGE_VEC_SIZE 256*256

    SECTION("Large vector ints")
    {
        vector<int> v_sorted, v_unsorted;
        for(int i = 0; i < LARGE_VEC_SIZE; ++i)
        {
            v_sorted.push_back(i);
            v_unsorted.push_back(rand());
        }
        quicksort(v_sorted, 0 ,v_sorted.size());
        quicksort(v_unsorted, 0 ,v_unsorted.size());
        REQUIRE(is_sorted(v_sorted.begin(), v_sorted.end()));
        REQUIRE(is_sorted(v_unsorted.begin(), v_unsorted.end()));
    }

    SECTION("Large vector double")
    {
        vector<double> v_sorted, v_unsorted;
        for(int i = 0; i < LARGE_VEC_SIZE; ++i)
        {
            v_sorted.push_back((double)i*3.14159);
            v_unsorted.push_back((double)rand()/3.14156);
        }
        quicksort(v_sorted, 0 ,v_sorted.size());
        quicksort(v_unsorted, 0 ,v_unsorted.size());
        REQUIRE(is_sorted(v_sorted.begin(), v_sorted.end()));
        REQUIRE(is_sorted(v_unsorted.begin(), v_unsorted.end()));
    }
    
    SECTION("Large vector indentical ints")
    {
        vector<int> v_indentical(LARGE_VEC_SIZE, 12);
        quicksort(v_indentical, 0 ,v_indentical.size());
        REQUIRE(is_sorted(v_indentical.begin(), v_indentical.end()));
    }
}
