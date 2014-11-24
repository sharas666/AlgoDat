#include "huffman_tree.hpp"
#include <vector>
#include <string>
#include <memory>
#include <iostream>




int main(int argc, char const *argv[])
{
	std::vector<std::pair<std::string,int>> v;

/*	for (int i = 1; i <= 5; ++i)
	{
		v.push_back({"c"+std::to_string(i),i});
	}*/
		// std::cout << v.size() << std::endl;
		v.push_back({"a",1});
		v.push_back({"b",2});
		v.push_back({"c",3});
		v.push_back({"d",4});
		v.push_back({"e",5});




auto t = generate_huffman(v);
//t->print();
//t->generate_coding();
std::cout << t->generate_coding("c") << std::endl;


	return 0;
}
