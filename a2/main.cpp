#include <vector>
#include <iostream>
#include "heap.hpp"
#include <cstdlib>




int main(int argc, char const *argv[])
{


    std::vector<int> v;
    for (int i = 30; i > 0; --i)
    {
    	v.push_back(rand()%100);
    }
    // v.push_back(8);
    // v.push_back(3);
    // v.push_back(7);
    // v.push_back(5);


    Heap<int> h{};
    h.generate(v);
    h.sort();
  	h.print_vector();
  	//h.print();
  	//std::cout << h.get_root()->m_value << std::endl;


	return 0;
}
