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

class coder // functor to generate the coding for the entire tree
{
	public:
		coder(): m_code{""},m_full_coding{}{} // begins with empty string
		std::string operator()(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& actual_node)
		{
			if (actual_node->m_father != nullptr)
				{
					if (actual_node == actual_node->m_father->m_lhs) // adds 1 to "m_code" for taking the left edge
						{m_code+="1";}
					if (actual_node == actual_node->m_father->m_rhs) // adds 0 to "m_code" for taking the right edge
						{m_code+="0";}
				}
			if (is_leaf(actual_node))
			{
				//std::cout << m_code << std::endl;
				m_full_coding.insert(std::make_pair(actual_node->m_value.first,m_code)); // inserts leaf coding into a map
                    m_code.pop_back(); // deletes the last edge from "m_string"
			}
			return m_code;
		}
		std::map<std::string,std::string> get_coding()const
		{return m_full_coding;}
	private:
		std::string m_code;
		std::map<std::string,std::string>  m_full_coding;
};

class single_coder // functor to generate the coding for a single letter
{
	public:
		single_coder(std::string const& s): m_code{}, m_to_code{s}, m_searched_coding{} {} // begins with empty string, given a single letter to code
		std::string operator()(std::shared_ptr<TreeNode<std::pair<std::string, int>>> const& actual_node)
		{
			if (actual_node->m_father != nullptr)
				{
					if (actual_node == actual_node->m_father->m_lhs) // adds 1 to "m_code" for taking the left edge
						{m_code+="1";}
					if (actual_node == actual_node->m_father->m_rhs) // adds 0 to "m_code" for taking the right edge
						{m_code+="0";}
				}
			if (is_leaf(actual_node))
			{
				if(actual_node->m_value.first == m_to_code) //checks if "actual_node" equals the searched letter
                    {m_searched_coding = m_code;} // writes the coding for the letter into "m_searched_coding"

                    m_code.pop_back(); // deletes the last edge from "m_string"
			}
			return m_code;
		}
		std::string get_coding()const
		{return m_searched_coding;}
	private:
		std::string m_code;
		std::string m_to_code;
		std::string m_searched_coding;
};

// traverses the tree using the "single_coder" functor and returns the coding of the entire tree
std::string Huffman_tree::encode(std::string const& s)const
{
	single_coder code{s};
	traverse_pre_order(code);
	return code.get_coding();
}

// traverses the tree using the "coder" functor and returns the coding of the entire tree
std::map<std::string,std::string> Huffman_tree::encode()const
{
	coder code{};
	traverse_pre_order(code);
	return code.get_coding();
}
// decodes a single letter
std::string Huffman_tree::decode(std::string const& code)const
{
    std::shared_ptr<TreeNode<std::pair<std::string, int>>> actual_node = m_root; // starts at root
	if (!empty() && !is_leaf(actual_node)) // iterates through "code" only if the tree is not empty and the root node is not a leaf node
	{
		for (auto it = code.begin(); it < code.end(); it++) // iterates through "code" taking the left edge for 1 and the right edge for 0
        {
            if(is_leaf(actual_node))
            {
                return "entered code does not exist"; // on a leaf before "code" ended
            }
            else if (*it == '1') // goes left
            {
                actual_node = actual_node->m_lhs;
            }
            else if (*it == '0') // goes right
            {
                actual_node = actual_node->m_rhs;
            }
            else
            {
                return "wrong input"; // input not 1 or 0
            }
        }
	}
	if (is_leaf(actual_node))
        {return actual_node->m_value.first;}// returns the decoded letter
    else
        {return "entered code does not exist";} // if not on a leaf node
}
