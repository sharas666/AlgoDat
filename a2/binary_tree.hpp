#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include <vector>

// Tree . hpp


template <typename T>
class Binary_tree;


template <typename T>
struct TreeNode // Tree Node containing pointers too two child nodes and one parent node and a template value
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
class Binary_tree // template binary tree
{
	public:
		Binary_tree(){}  // standard constructor

		// Binary_tree(TreeNode<T> const& root): m_tree_elements{} {m_tree_elements.}
		// Binary_tree(std::shared_ptr<TreeNode<T>> root, std::shared_ptr<TreeNode<T>> lhs,
		//  				std::shared_ptr<TreeNode<T>> rhs): m_tree_elements.front(){root} {
		// 	m_tree_elements.front().m_lhs = lhs;
		// 	m_tree_elements.front().m_rhs = rhs;
		// 	m_tree_elements.front().m_lhs.m_father = m_tree_elements.front();
		// 	m_tree_elements.front().m_rhs.m_father = m_tree_elements.front();
		// }

		void generate()
		{

		}

		void insert_node(TreeNode<T> const& new_node)
		{
			
			m_tree_elements.push_back(new_node);
		}


		template <class Function>
		void pre_order(std::shared_ptr<TreeNode<T>> const& n, Function &f)const // traverses through the binary tree in preorder
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
		void traverse_pre_order(Function &f)const // traverses through the binary tree in preorder beginning at root
		{
			if (!empty())
			{
				pre_order(std::make_shared<TreeNode<T>>(m_tree_elements.front()), f);
			}
		}

		template <class Function>
		void post_order(std::shared_ptr<TreeNode<T>> const& n, Function &f)const // traverses through the binary tree in postorder
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
		void traverse_post_order(Function &f)const // traverses through the binary tree in postorder beginning at root
		{
			if (!empty())
			{
				post_order(std::make_shared<TreeNode<T>>(m_tree_elements.front()), f);
			}
		}

		template <class Function>
		void in_order(std::shared_ptr<TreeNode<T>> const& n, Function &f)const // traverses through the binary tree inorder
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
		void traverse_in_order(Function f)const // traverses through the binary tree inorder beginning at root
		{
			if (!empty())
			{
				in_order(std::make_shared<TreeNode<T>>(m_tree_elements.front()), f);
			}
		}

		TreeNode<T> get_root()const
		{
			return m_tree_elements.front();
		}

		bool is_leaf(std::shared_ptr<TreeNode<T>> const& n)const // checks if a node is a leaf node
		{
			if (n->m_lhs == nullptr && n->m_lhs == nullptr)
				{return true;}
			else
				{return false;}
		}


		bool empty() const // checks if the tree has no nodes
		{
			return m_tree_elements.empty();
		}

		Binary_tree& operator= (Binary_tree rhs)
		{
			swap(rhs);
			return *this;
		}

		void swap(Binary_tree& rhs)
		{
			std::swap(m_tree_elements, rhs.m_tree_elements);
		}

		friend void swap(Binary_tree& a, Binary_tree& b)
		{
			a.swap(b);
		}

	protected:
		std::vector<TreeNode<T>> m_tree_elements;
};



#endif // # define BINARY_TREE_HPP

template <typename T>
bool is_leaf(std::shared_ptr<TreeNode<T>> const& n) // free function to check if a node is a leaf node
{
	if (n->m_lhs == nullptr && n->m_lhs == nullptr)
		{return true;}
	else
		{return false;}
}
