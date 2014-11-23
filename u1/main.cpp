#include "huffman_tree.hpp"
#include <vector>
#include <string>
#include <memory>



int main(int argc, char const *argv[])
{
	std::vector<std::pair<std::string,int>> v;

	for (int i = 0; i <= 10; ++i)
	{
		v.push_back({"c",i});
		
	}


auto t = generate_huffman(v);
// t->print();

	
	return 0;
}