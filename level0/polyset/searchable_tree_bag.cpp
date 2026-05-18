# include "searchable_bag.hpp"
# include "searchable_tree_bag.hpp"
# include "bag.hpp"

searchable_tree_bag::searchable_tree_bag() : searchable_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag&other) : searchable_bag(other)
{
}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag&other)
{
	if(this == &other)
		return *this;
	bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{

}
bool searchable_tree_bag::isfound(tree_bag::node* node,int n) const
{
	if(node == nullptr)
		return false;
	if(node->value == n)
		return true;
	return isfound(node->r,n) && isfound(node->l,n);
}
bool searchable_tree_bag::has(int n) const
{
	return isfound(tree,n);
}
