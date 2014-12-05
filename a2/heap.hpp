#ifndef HEAP_HPP
#define HEAP_HPP

#include "binary_tree.hpp"
#include <functional>
#include <memory>

template <typename T>
inline bool operator> (std::shared_ptr<TreeNode<T>> lhs, const std::shared_ptr<TreeNode<T>> rhs)
    { return (lhs->m_value > rhs->m_value); }

template <typename T>
class Heap : public Binary_tree<T>
	{
	public:
		Heap() {} // standart constructor

		void down_heap()
		{
			auto current = this->get_root();
			if (!current->is_leaf())
			{
				for(current; current!=nullptr; current=std::greater<std::shared_ptr<TreeNode<T>>(current->m_lhs,
					 current->m_rhs))
				{

					if(current->m_value > current->m_parent->m_value)
					{
						std::swap(current->m_value, current->m_parent->m_value);
					}
					else
						{current = nullptr;}

				}
			}
		}

		void up_heap()
		{
			auto current = this->m_tree_elements.back();
			for(current; current!=nullptr; current=current->m_parent)
			{

				if(current->m_value > current->m_parent->m_value)
				{
					std::swap(current->m_value, current->m_parent->m_value);
				}
				else
					{current = nullptr;}

			}
		}


		void add_node(std::shared_ptr<TreeNode<T>> const& new_node) // adds a node on the correct position
		{
			if(this->empty()) // sets root if empty
			{
				//new_node->m_depth=0;
				this->add(new_node);
			}
			else
            {
                this->add(new_node);
                new_node->m_parent = *(this->m_tree_elements.begin() + (this->m_tree_elements.size()-1)/2); // calculates position of parent node and sets pointer to it
                if (new_node->m_parent->m_lhs == nullptr)
                {
                    new_node->m_parent->m_lhs = new_node;	// sets parent nodes
                }
                else if (new_node->m_parent->m_rhs == nullptr)
                {
                    new_node->m_parent->m_rhs = new_node;
                }
                else
                {
                    std::cout << "structure error" << std::endl;
                }
                up_heap();
            }
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

