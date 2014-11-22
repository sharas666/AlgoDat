#include "huffman_tree.hpp"

Huffman_tree::Huffman_tree(TreeNode<std::pair<std::string, int>> const& lhs,
							TreeNode<std::pair<std::string, int>> const& rhs)
	: Binary_tree{}
	{
		m_root->m_lhs = lhs.get_root();
		m_root->m_rhs = std::make_shared<TreeNode<std::pair<std::string, int>>>(rhs);
		m_root->m_value = {"",m_root->m_lhs->m_value.second + m_root->m_lhs->m_value.second};

	}