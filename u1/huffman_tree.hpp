#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include "binary_tree.hpp"
#include <string>
#include <iostream>


class Huffman_tree : public Binary_tree<std::pair<std::string, int>>
{
	public: 

		Huffman_tree(): Binary_tree<std::pair<std::string, int>>{} {}
		Huffman_tree(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& root):
			Binary_tree<std::pair<std::string, int>>{root} {}
		// Huffman_tree(TreeNode<std::pair<std::string, int>> const& root):
		// 	Binary_tree<std::pair<std::string, int>>(root) {}
		Huffman_tree(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& lhs, std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& rhs);
		Huffman_tree(Huffman_tree&& rhs):
			Binary_tree<std::pair<std::string, int>>{rhs.m_root}
		{
			rhs.m_root = nullptr;
		}
		void print() const;
};

template <typename T>
std::shared_ptr<Huffman_tree> generate_huffman(T const& container){

	auto n = std::make_shared<TreeNode<std::pair<std::string,int>>>(container.front());
	auto t = std::make_shared<Huffman_tree>(n);

	for (auto i = container.begin()+1; i != container.end()-1; ++i)
	{
		n = std::make_shared<TreeNode<std::pair<std::string,int>>>(*i);
		t = std::make_shared<Huffman_tree>(t->get_root(),n);
		std::cout << t->get_root()->m_value.second << std::endl;

	}
	return t;
}

#endif