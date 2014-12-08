#ifndef HEAP_HPP
#define HEAP_HPP

#include "binary_tree.hpp"
#include <functional>
#include <memory>
#include <cmath>
#include <vector>



template <typename T>
class Heap : public Binary_tree<T>
	{
	public:
		Heap() {} // standart constructor

		// void down_heap()
		// {
		// 	auto current = this->get_root();
		// 	if (!current->is_leaf())
		// 	{
		// 		for(current; current!=nullptr; current=std::greater<std::shared_ptr<TreeNode<T>>>(current->m_lhs,
		// 			 current->m_rhs))
		// 		{

		// 			if(current->m_value > current->m_parent->m_value)
		// 			{
		// 				std::swap(current->m_value, current->m_parent->m_value);
		// 			}
		// 			else
		// 				{current = nullptr;}

		// 		}
		// 	}
		// }

		// void up_heap(int steps)
		// {
		// 	auto current = this->m_tree_elements.back();
		// 	for(current; current->m_parent!=nullptr; current=current->m_parent)
		// 	{
		// 		std::cout << "a" << std::endl;

		// 		if(current->m_value > current->m_parent->m_value)
		// 		{
		// 			std::swap(current->m_value, current->m_parent->m_value);
		// 		}
		// 		else
		// 			{break;}

		// 	}
		// }



		std::shared_ptr<TreeNode<T>> get_greater_child(std::shared_ptr<TreeNode<T>> const& current) const
		{
			std::shared_ptr<TreeNode<T>> greater_child;
			if (!current->is_complete())
			{
				greater_child = current->m_lhs;
			}
			else
			{
				greater_child = current->m_lhs->m_value > current->m_rhs->m_value ? current->m_lhs : current->m_rhs;
			}
			return greater_child;
		}

		void down_heap()
		{
			auto current = this->get_root();
			//std::cout << current->m_value << std::endl;
			std::shared_ptr<TreeNode<T>> next;
			if(!current->is_leaf())
			{
				// std::cout << end->m_value << std::endl;
				auto next = get_greater_child(current);
				//std::cout << current->m_value << " " << next->m_value << std::endl;
				while (current->m_value < next->m_value)
				{
					//std::cout << current->m_value << " " << next->m_value << std::endl;
					std::swap(current->m_value, next->m_value);
					current = next;
					next = get_greater_child(current);
					
					// if(next > end)
					// {
					// 	next = current->m_lhs;
					// }
					// std::cout << (*(end+1))->m_value << std::endl;

				}

			}
			// std::cout << this->get_root()->m_value << std::endl;
		}

		// void down_heap() // swaps an element down the heap checking every node
		// {
		// 	down_heap(this->m_tree_elements.end()-1);
		// }

		void up_heap()
		{
			auto current = this->m_tree_elements.back();
			while (current->m_parent != nullptr && current->m_value > current->m_parent->m_value)
			{
				std::swap(current->m_value, current->m_parent->m_value);
				current=current->m_parent;
			}
		}


		void insert_node(std::shared_ptr<TreeNode<T>> const& new_node) // adds a node on the correct position
		{
			if(this->empty()) // sets root if empty
			{
				new_node->m_depth=0;
				this->add(new_node);
			}
			else
            {
                this->add(new_node);
                new_node->m_parent = *(this->m_tree_elements.begin() + (this->size()-2)/2); // calculates position of parent node and sets pointer to it // size -2 because add() already pushed the node
                /*std::cout << new_node->m_parent->m_value << std::endl;
                std::cout << new_node->m_value << std::endl;*/
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
                new_node->m_depth=new_node->m_parent->m_depth+1;
                up_heap();
            }
		}

		void sort()
		{
			//int i = 1;
			auto last_unsorted = this->m_tree_elements.end()-1;
			while(*last_unsorted != this->get_root())
			{
					// std::cout << this->get_root()->m_value << std::endl;
				// std::cout << (*last_unsorted)->m_value << std::endl;
				// std::cout << this->get_root()->m_value << " " << ((*last_unsorted)->m_value) << std::endl;
				std::swap(this->get_root()->m_value, (*(last_unsorted))->m_value);
				if ((*last_unsorted)->m_parent->m_rhs != nullptr)
				{
					(*last_unsorted)->m_parent->m_rhs = nullptr;
				}
				else{
					(*last_unsorted)->m_parent->m_lhs = nullptr;
				}



				// std::cout << (*(last_unsorted))->m_value << std::endl;

				down_heap();

				
				--last_unsorted;
				// std::cout << (*last_unsorted)->m_value << std::endl;

    				// this->print();

				// std::cout << "i" << std::endl << std::endl; ++i;
			}
			// down_heap();
			// std::swap(this->get_root()->m_value, (*(last_unsorted))->m_value);
		}

		void print_vector() const
		{
			for (auto it = this->m_tree_elements.begin(); it != this->m_tree_elements.end(); ++it)
			{
				std::cout << (*it)->m_value << std::endl;
			}
		}

		template <typename container>
		void generate(container const& c) // generates a Heap from a container with iterator
		{
			std::shared_ptr<TreeNode<T>> to_add;
			for (auto i = c.begin(); i != c.end(); ++i)
			{
				to_add = std::make_shared<TreeNode<T>>(*i);
				insert_node(to_add);
			}
		}


	};

#endif // HEAP_HPP

