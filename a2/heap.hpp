#ifndef HEAP_HPP
#define HEAP_HPP

#include "binary_tree.hpp"
#include <functional>

template <typename T>
class Heap : public Binary_tree<T>
	{
	public:
		Heap() {} // standart constructor

		void down_heap()
		{
			auto actual = this->get_root();
			if (!actual->is_leaf())
			{
				for(actual; actual!=nullptr; actual=std::greater<T>(actual->m_rhs->m_value,
					 actual->m_rhs->m_value))
				{

					if(actual->m_value > actual->m_parent->m_value)
					{
						std::swap(actual->m_value, actual->m_parent->m_value);
					}
					else
						{actual = nullptr;}

				}
			}
		}

		void up_heap()
		{
			auto actual = this->m_tree_elements.back();
			if (actual->is_leaf())
			{
				for(actual; actual!=nullptr; actual=actual->m_parent)
				{

					if(actual->m_value > actual->m_parent->m_value)
					{
						std::swap(actual->m_value, actual->m_parent->m_value);
					}
					else
						{actual = nullptr;}

				}
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

