# include "array_bag.hpp"
# include "searchable_bag.hpp"

class searchable_array_bag : public searchable_bag , array_bag
{
	public:
	array_bag array;
	searchable_array_bag();
	searchable_array_bag(const searchable_array_bag&other);
	~searchable_array_bag();

	using array_bag::print;
	searchable_array_bag& operator=(const searchable_array_bag&);
	bool has(int) const;
};


