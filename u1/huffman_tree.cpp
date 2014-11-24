#include "huffman_tree.hpp"
#include <iostream>

// constructor taking two child notes and automatically setting the root node
Huffman_tree::Huffman_tree(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& lhs,
							std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& rhs)
	: Binary_tree{}
	{

		m_root = std::make_shared<TreeNode<std::pair<std::string, int>>>(lhs,rhs); // create new root

		m_root->m_lhs->m_father = m_root; // sets father to root
		m_root->m_rhs->m_father = m_root; // sets father to root
		m_root->m_value = {"",m_root->m_lhs->m_value.second + m_root->m_rhs->m_value.second}; // sets root value to "" and the sum of both child notes int values
	}

void Huffman_tree::print()const{ // prints the tree using the binary trees post post order traversing and a lambda
	auto f = [](std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& n){std::cout << n->m_value.first << " " << n->m_value.second << std::endl;};
	traverse_post_order(f);
}

class coder
{
	public:
		coder(): m_code{""},m_full_coding{}{}
		std::string operator()(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& actual_node)
		{
			if (actual_node->m_father != nullptr)
				{
					if (actual_node == actual_node->m_father->m_lhs)
						{m_code+="1";}
					if (actual_node == actual_node->m_father->m_rhs)
						{m_code+="0";}
				}
			if (isleaf(actual_node))
			{
				//std::cout << m_code << std::endl;
				m_full_coding.insert(std::make_pair(actual_node->m_value.first,m_code));
                    m_code.pop_back();
			}
			return m_code;
		}
		std::map<std::string,std::string> get_coding()const
		{return m_full_coding;}
	private:
		std::string m_code;
		std::map<std::string,std::string>  m_full_coding;
};

std::map<std::string,std::string> Huffman_tree::generate_coding()const
{
	coder code{};
	traverse_pre_order(code);
	return code.get_coding();
}
