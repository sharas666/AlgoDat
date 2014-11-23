#include "huffman_tree.hpp"
#include <iostream>

Huffman_tree::Huffman_tree(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& lhs,
							std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& rhs)
	: Binary_tree{}
	{

		m_root = std::make_shared<TreeNode<std::pair<std::string, int>>>(lhs,rhs);
		m_root->m_lhs = lhs;
		m_root->m_rhs = rhs;
		m_root->m_value = {"",m_root->m_lhs->m_value.second + m_root->m_rhs->m_value.second};

	}

void Huffman_tree::print()const{
	traverse_post_order([](std::pair<std::string, int> const& val){std::cout << val.first << " " << val.second << std::endl;});
}
