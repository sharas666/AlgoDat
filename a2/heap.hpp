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
		// standart constructor
		Heap() {}

		// returns the greater child of a tree node
		std::shared_ptr<TreeNode<T>> get_greater_child(std::shared_ptr<TreeNode<T>> const& current) const
		{
			std::shared_ptr<TreeNode<T>> greater_child;
			if (!current->is_complete())
			{
				greater_child = current->m_lhs; // if the node has only one child it's always the left child
			}
			else
			{
				// compares both childs
				greater_child = current->m_lhs->m_value > 
								current->m_rhs->m_value ? current->m_lhs : current->m_rhs;
			}
			return greater_child;
		}

		// swaps the root node down the tree until heap condition is restored
		void down_heap()
		{
			auto current = this->get_root();
			std::shared_ptr<TreeNode<T>> next;
			if(!current->is_leaf())
			{
				auto next = get_greater_child(current);
				/* swaps the parent node with the greater child as long as a 
				child exists and the parent note is smaller then the greater child */
				while (next != nullptr && current->m_value < next->m_value)
				{
					std::swap(current->m_value, next->m_value);
					current = next;
					next = get_greater_child(current);
				}
			}
		}

		// swaps the last node of the tree up the heap until heap condition is restored
		void up_heap()
		{
			auto current = this->m_tree_elements.back();
			// runs while parent exists and is greater then its parent  
			while (current->m_parent != nullptr && current->m_value > current->m_parent->m_value)
			{
				std::swap(current->m_value, current->m_parent->m_value);
				current=current->m_parent;
			}
		}

		// adds a node to the tree and moves it to the correct position
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
                // calculates position of parent node and sets pointer to it // size -2 because add() already pushed the node
                new_node->m_parent = *(this->m_tree_elements.begin() + (this->size()-2)/2); 

                if (new_node->m_parent->m_lhs == nullptr) // puts new node as parents lhs if lhs didn't exist before
                {
                    new_node->m_parent->m_lhs = new_node;
                }
                else if (new_node->m_parent->m_rhs == nullptr) // puts new node as parents rhs if lhs existed and rhs didn't exist before
                {
                    new_node->m_parent->m_rhs = new_node;
                }
                else // parent node is already complete
                {
                    std::cout << "structure error" << std::endl;
                }
                new_node->m_depth=new_node->m_parent->m_depth+1; // depth = parents depth +1
                up_heap();
            }
		}

		// sorts the heap in place
		void sort()
		{

			auto last_unsorted = this->m_tree_elements.end()-1;
			while(*last_unsorted != this->get_root()) // while unsorted elements exist
			{
				std::swap(this->get_root()->m_value, (*(last_unsorted))->m_value); // swap root with last unsorted
				// remove parents pointer to the node
				if ((*last_unsorted)->m_parent->m_rhs != nullptr)
				{
					(*last_unsorted)->m_parent->m_rhs = nullptr;
				}
				else{
					(*last_unsorted)->m_parent->m_lhs = nullptr;
				}
				down_heap(); // restore heap condition
				--last_unsorted; // new last unsorted
			}
		}

		// prints the value of the tree nodes in the order of the vector they are stored in
		void print_vector() const
		{
			for (auto it = this->m_tree_elements.begin(); it != this->m_tree_elements.end(); ++it)
			{
				std::cout << (*it)->m_value << std::endl;
			}
		}

		// generates a Heap from a container with iterator
		template <typename container>
		void generate(container const& c)
		{
			std::shared_ptr<TreeNode<T>> to_add;
			for (auto i = c.begin(); i != c.end(); ++i)
			{
				to_add = std::make_shared<TreeNode<T>>(*i); // create new tree node from container element
				insert_node(to_add);
			}
		}
	};

#endif // HEAP_HPP

