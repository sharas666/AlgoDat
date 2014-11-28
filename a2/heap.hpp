#ifndef HEAP_HPP
#define HEAP_HPP

#include "binary_tree.hpp"

template <typename T>
class Heap : public Binary_tree<T>
	{
	public:
		Heap() {} // standart constructor

		void add_node(std::shared_ptr<TreeNode<T>> const& new_node) // adds a node on the correct position
		{
			if(this->m_tree_elements.empty()) // sets root if empty
			{
				new_node->m_depth=0;
				add(new_node);
			}
			add(new_node);
			new_node->m_parent = *(this->m_tree_elements.begin() + (this->m_tree_elements.size()-1)/2); // calculates position of parent node and sets pointer to it
			if (new_node->m_parent->m_lhs == nullptr)  
			{
				new_node->m_parent->m_lhs = new_node;
			}
			else
			{
				new_node->m_parent->m_rhs = new_node;
			}
			auto k = this->m_tree_elements;
		}

		template <typename container>
		void generate(container const& c) // generates a Heap from a container with iterator
		{
			std::shared_ptr<TreeNode<T>> to_add;
			for (auto i = c.begin(); i != c.end(); ++i)
			{
				to_add = std::make_shared<TreeNode<T>>(*i);
				add_node(to_add);
			}
		}


	};
#endif // HEAP_HPP