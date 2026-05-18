# include "set.hpp"
# include "searchable_bag.hpp"


set::set(const set& set) : a(set.a)
{

}

set::set(searchable_bag & other) : a(other)
{

}

set& set::operator=(const set& set)
{
    if(this == &set)
        return *this;
    a = set.a;
    return *this;
}

    void set::print() const{ a.print();}
    void set::insert(int n) {a.insert(n);}
    void set::insert(int * arr, int s){ a.insert(arr,s);}
    void set::clear() {
        a.clear();
    }
    bool set::has(int n)const  {return a.has(n);}

    bag& set::get_bag() {return a;}


set:: ~set()
{

}