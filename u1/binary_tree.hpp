#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>

// Tree . hpp


template <typename T>
class Binary_tree;


template <typename T>
struct TreeNode
{
	TreeNode() : m_value(), m_lhs(), m_rhs(){}
	TreeNode(T const& v, std::shared_ptr<TreeNode<T>> lhs, std::shared_ptr<TreeNode<T>> rhs)
		:m_value(v), m_lhs(lhs), m_rhs(rhs) {}
	TreeNode(T const& v)
	:m_value(v), m_lhs(nullptr), m_rhs(nullptr) {}
	T m_value;
	std::shared_ptr<TreeNode<T>> m_lhs; 
	std::shared_ptr<TreeNode<T>> m_rhs;
};




template <typename T>
class Binary_tree
{
	public:
		Binary_tree():
			m_root{nullptr}
		{}

		// Binary_tree(TreeNode<T> const& root): m_root{std::make_shared<T>(root)} {}

		Binary_tree(std::shared_ptr<TreeNode<T>> const& root): m_root{root} {}

		Binary_tree(Binary_tree&& rhs):
			m_root{rhs.m_root}
		{
			rhs.m_root = nullptr;
		}

		template <class Function>
		void pre_order(std::shared_ptr<TreeNode<T>> const& n, Function& f)const
		{
			f(n->m_value);

			if (n.m_lhs)
			{
				pre_order(n.m_lhs, f);
			}
			if (m_root.m_rhs)
			{
				pre_order(n.rhs, f);
			}
		}

		template <class Function>
		void traverse_pre_order(Function& f)const
		{
			pre_order(m_root, f);
		}

		template <class Function>
		void post_order(std::shared_ptr<TreeNode<T>> const& n, Function& f)const
		{
			if (n.m_lhs)
			{
				post_order(n.m_lhs, f);
			}
			if (m_root.m_rhs)
			{
				post_order(n.rhs, f);
			}
			f(n->m_value);
		}

		template <class Function>
		void traverse_post_order(Function& f)const
		{
			post_order(m_root, f);
		}

		template <class Function>
		void in_order(std::shared_ptr<TreeNode<T>> const& n, Function& f)const
		{
			if (n.m_lhs)
			{
				in_order(n.m_lhs, f);
			}

			f(n->m_value);

			if (m_root.m_rhs)
			{
				in_order(n.rhs, f);
			}
		}

		template <class Function>
		void traverse_in_order(Function& f)const
		{
			in_order(m_root, f);
		}

		std::shared_ptr<TreeNode<T>> get_root()const
		{
			return m_root;
		}

		bool empty() const
		{
			return !m_root;
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



