#include "huffman_tree.hpp"
#include <vector>
#include <string>
#include <memory>
#include <iostream>



int main(int argc, char const *argv[])
{
	std::vector<std::pair<std::string,int>> v;

	for (int i = 1; i <= 6; ++i)
	{
		v.push_back({"c",i});		
	}
		// std::cout << v.size() << std::endl;


auto t = generate_huffman(v);
// t->print();
t->generate_coding();

	
	return 0;
}