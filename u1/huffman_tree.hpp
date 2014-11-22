#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include "binary_tree.hpp"
#include <string>

class Huffman_tree : public Binary_tree<std::pair<std::string, int>>
{
	public: 

		Huffman_tree(): Binary_tree<std::pair<std::string, int>>{} {}
		Huffman_tree(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& root):
			Binary_tree<std::pair<std::string, int>>{root} {}
		// Huffman_tree(TreeNode<std::pair<std::string, int>> const& root):
		// 	Binary_tree<std::pair<std::string, int>>(root) {}
		Huffman_tree(TreeNode<std::pair<std::string, int>> const& lhs, TreeNode<std::pair<std::string, int>> const& rhs);
		// Huffman_tree(Huffman_tree&& rhs):
		// 	Binary_tree<std::pair<std::string, int>>{rhs.m_root}
		// {
		// 	rhs.m_root = nullptr;
		// }


};

#endif