#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

template <class type>
unsigned int partition(vector<type> & v, int lo, int hi)
{
    type pivot = v[hi];
    int i = lo;
    for (int j = lo; j < hi; j++)
    {
        if(v[j] < pivot)
        {
            std::swap(v[i], v[j]);
            ++i;
        }
    }
    swap(v[i], v[hi]);
    return i;
}

template <class type>
void quicksort(vector<type> & v, int lo, int hi)
{
    if(lo < hi)
    {
        int part = partition(v, lo, hi);
        quicksort(v, lo, part - 1);
        quicksort(v, part + 1, hi);
    }
}

