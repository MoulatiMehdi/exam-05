# include "vect2.hpp"

vect2::vect2() : x(0),y(0)
{

}

vect2::vect2(int x,int y) : x(x),y(y)
{



}

vect2::vect2(const vect2& o) : x(o.x),y(o.y)
{

}

vect2::~vect2()
{

}


vect2& vect2::operator-=(const vect2& vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}
vect2& vect2::operator+=(const vect2& vec)
{
   x += vec.x;
   y += vec.y;
   return *this;
}

vect2& vect2::operator*=(int n)
{
    x *= n;
    y *= n;
    return *this;
}

vect2 vect2::operator*(int n) const
{
    vect2 tmp(*this);
    return tmp *=n;
}


vect2 vect2::operator-(const vect2& vec) const
{
    vect2 tmp(*this);
    return  tmp -= vec;
}

vect2 vect2::operator+(const vect2& vec) const
{
    vect2 tmp(*this);
    return  tmp += vec;
}



bool vect2::operator==(const vect2& vec) const
{
    return vec.x == x && vec.y == y;    
}

bool vect2::operator!=(const vect2& vec) const
{
    return !(*this == vec);    
}

vect2& vect2::operator=(const vect2& vec)
{
    x = vec.x;
    y = vec.y;
    return *this;
}


int vect2::operator[](int n) const
{
    if(n == 0)
        return x;
    return y;
}

int& vect2::operator[](int n)
{
    if(n == 0)
        return x = n;
    return y = n;
}

vect2 operator*(int n,const vect2& vec)
{
    return vec * n;
}

vect2& vect2::operator++() 
{
    *this += vect2(1,1);
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 tmp(*this);
    ++*this;
    return tmp; 
}
vect2& vect2::operator--() 
{
    *this += vect2(-1,-1);
    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 tmp(*this);
    --*this;
    return tmp; 
}

vect2 vect2::operator-() const
{
    return vect2(*this)*= -1; 
}