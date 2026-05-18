# include "searchable_bag.hpp"

class set : searchable_bag
{
    public :
        searchable_bag& a;
    set(const set& set);
    set(searchable_bag & other);
    set& operator=(const set& set);

    void print() const;
    void insert(int );
    void insert(int * , int);
    void clear();
    bool has(int a)const;
    bag& get_bag();
    ~set();

};