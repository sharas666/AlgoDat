#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "binary_tree.hpp"
#include "heap.hpp"




int main(int argc, char const *argv[])
{


    std::vector<int> v;
    for (int i = 10; i > 0; i++)
    {
    	v.push_back(i);
    }
    Heap<int> h{};
    h.generate(v);


	return 0;
}
