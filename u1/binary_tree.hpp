#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>

// Tree . hpp


template <typename T>
class Binary_tree;


template <typename T>
struct TreeNode
{
	TreeNode() : m_value{}, m_lhs{nullptr}, m_rhs{nullptr}{} // standart constructor
	TreeNode(T const& v, std::shared_ptr<TreeNode<T>> const& lhs, std::shared_ptr<TreeNode<T>> const& rhs)
		:m_value{v}, m_lhs{lhs}, m_rhs{rhs}, m_father{} {} // constructor taking value and child pointers
	TreeNode(T const& v, std::shared_ptr<TreeNode<T>> const& lhs, std::shared_ptr<TreeNode<T>> const& rhs, std::shared_ptr<TreeNode<T>> const& father)
		:m_value{v}, m_lhs{lhs}, m_rhs{rhs}, m_father{father} {} // constructor taking value, child and father pointers
	TreeNode(std::shared_ptr<TreeNode<T>> const& lhs, std::shared_ptr<TreeNode<T>> const& rhs)
		:m_value{}, m_lhs{lhs}, m_rhs{rhs}, m_father{} {} // constructor taking child pointers
	TreeNode(T const& v) // constructor taking value
		:m_value{v}, m_lhs{nullptr}, m_rhs{nullptr},m_father{} {}
	TreeNode(T const& v, std::shared_ptr<TreeNode<T>> const& father) // constructor taking value and father
		:m_value{v}, m_lhs{nullptr}, m_rhs{nullptr},m_father{father} {}

	T m_value;
	std::shared_ptr<TreeNode<T>> m_lhs;
	std::shared_ptr<TreeNode<T>> m_rhs;
	std::shared_ptr<TreeNode<T>> m_father;
};




template <typename T>
class Binary_tree
{
	public:
		Binary_tree():
			m_root{}
		{}

		// Binary_tree(TreeNode<T> const& root): m_root{std::make_shared<T>(root)} {}

		Binary_tree(std::shared_ptr<TreeNode<T>> root): m_root{root} {}

		Binary_tree(Binary_tree&& rhs):
			m_root{rhs.m_root}
		{
			rhs.m_root = nullptr;
		}

		template <class Function>
		void pre_order(std::shared_ptr<TreeNode<T>> const& n, Function f)const
		{
			f(n);

			if (n->m_lhs != nullptr)
			{
				pre_order(n->m_lhs, f);
			}
			if (n->m_rhs != nullptr)
			{
				pre_order(n->m_rhs, f);
			}
		}

		template <class Function>
		void traverse_pre_order(Function f)const
		{
			if (m_root != nullptr)
			{
				pre_order(m_root, f);
			}
		}

		template <class Function>
		void post_order(std::shared_ptr<TreeNode<T>> const& n, Function f)const
		{
			if (n->m_lhs != nullptr)
			{
				post_order(n->m_lhs, f);
			}
			if (n->m_rhs != nullptr)
			{
				post_order(n->m_rhs, f);
			}
			f(n);
		}

		template <class Function>
		void traverse_post_order(Function f)const
		{
			if (m_root != nullptr)
			{
				post_order(m_root, f);
			}
		}

		template <class Function>
		void in_order(std::shared_ptr<TreeNode<T>> const& n, Function f)const
		{
			if (n->m_lhs != nullptr)
			{
				in_order(n->m_lhs, f);
			}

			f(n);

			if (n->m_rhs != nullptr)
			{
				in_order(n->m_rhs, f);
			}
		}

		template <class Function>
		void traverse_in_order(Function f)const
		{
			if (m_root != nullptr)
			{
				in_order(m_root, f);
			}
		}

		std::shared_ptr<TreeNode<T>> get_root()const
		{
			return m_root;
		}

		bool isleaf(std::shared_ptr<TreeNode<T>> const& n)
		{
			if (n->m_lhs == nullptr && n->m_lhs == nullptr)
				{return true;}
			else
				{return false;}
		}


		bool empty() const
		{
			if (m_root == nullptr)
				{return false;}
			else
				{return true;}
		}

		Binary_tree& operator= (Binary_tree rhs)
		{
			swap(rhs);
			return *this;
		}

		void swap(Binary_tree& rhs)
		{
			std::swap(m_root, rhs.m_root);
		}

		friend void swap(Binary_tree& a, Binary_tree& b)
		{
			a.swap(b);
		}

	protected:
		std::shared_ptr<TreeNode<T>> m_root;
};



#endif // # define BINARY_TREE_HPP

template <typename T>
bool isleaf(std::shared_ptr<TreeNode<T>> const& n)
{
	if (n->m_lhs == nullptr && n->m_lhs == nullptr)
		{return true;}
	else
		{return false;}
}
