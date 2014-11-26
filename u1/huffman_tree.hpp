#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include "binary_tree.hpp"
#include <string>
#include <map>


class Huffman_tree : public Binary_tree<std::pair<std::string, int>>
{
	public:

		Huffman_tree(): Binary_tree<std::pair<std::string, int>>{} {} // standart constructor
		Huffman_tree(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& root): // constructor setting root
			Binary_tree<std::pair<std::string, int>>{root} {}

		// constructor taking two child notes and automatically setting the root node
		Huffman_tree(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& lhs,
						 std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& rhs);
		void print() const; // prints the tree
		std::map<std::string,std::string> encode()const; // generates the coding for the entire tree
		std::string encode(std::string const& s)const; // generates the coding for a single letter
		std::string decode(std::string const& code)const; // decodes a single letter

};



template <typename T> // generates a Huffman_tree from a container with iterator
std::shared_ptr<Huffman_tree> generate_huffman(T const& container){

	auto n = std::make_shared<TreeNode<std::pair<std::string,int>>>(container.front());
	auto t = std::make_shared<Huffman_tree>(n);

	for (auto i = container.begin()+1; i != container.end(); ++i)
	{
		n = std::make_shared<TreeNode<std::pair<std::string,int>>>(*i);
		t = std::make_shared<Huffman_tree>(n,t->get_root());

	}
	return t;
}

#endif
