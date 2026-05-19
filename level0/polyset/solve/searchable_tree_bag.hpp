# include "tree_bag.hpp"
# include "searchable_bag.hpp"

class searchable_tree_bag : public searchable_bag , public tree_bag
{
	bool isfound(tree_bag::node* node,int n) const;
	public: 
	searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag&other);
	~searchable_tree_bag();
	
	searchable_tree_bag& operator=( const searchable_tree_bag&);
	bool has(int) const;
};


