#include "huffman_tree.hpp"
#include <vector>
#include <string>
#include <memory>



int main(int argc, char const *argv[])
{
	std::vector<std::pair<std::string,int>> v;

	for (int i = 0; i < 10; ++i)
	{
		v.push_back({"c",i});
		
	}

	TreeNode<std::pair<std::string,int>> n{v.front()};
	auto p = std::make_shared<TreeNode<std::pair<std::string,int>>>(n);

	Huffman_tree t(p);
	Huffman_tree c{};

	for (auto i = v.begin()+1; i != v.end(); ++i)
	{
		TreeNode<std::pair<std::string,int>> n1{*i};
		t = {{},n1);
	}


	// for map
	// {
	// 	TreeNode<std::pair<std::string,int>> n = i;
		
	// }

	
	return 0;
}