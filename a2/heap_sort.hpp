#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP
#include <utility>
#include <functional>
#include "binary_tree.hpp"
#include <memory>

template <typename T>
void restore_heap(Binary_tree<T> &t)
{
	auto actual = t.get_root();
	if (!is_leaf(actual))
	{
		for(actual; actual!=nullptr; actual=std::greater<T>(actual->m_rhs->m_value,
			 actual->m_rhs->m_value))
		{

			if(actual->m_value > actual->m_father->m_value)
			{
				std::swap(actual->m_value, actual->m_father->m_value);
			}
			else
				{actual = nullptr;}

		}
	}
}

template <typename T, typename container>
Binary_tree<T> create_heap(container const& c)
{
	Binary_tree<T> heap{};

		auto root = std::make_shared<TreeNode<T>>();
		auto n = std::make_shared<TreeNode<T>>(c.front());
		for (auto i = c.begin()+1; i != c.end(); ++i)
		{
		n = std::make_shared<TreeNode<T>>(*i);

}

	return 0;
}


#endif // HEAP_SORT_HPP