#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
      int             _point;
        static const int _bits;
    public:
        Fixed();
        Fixed(const Fixed &src);
        Fixed(const int);
        Fixed(const float);
        ~Fixed();
        Fixed & operator=(const Fixed &obj);
        float toFloat( void ) const;
        int toInt( void ) const;
};
    std::ostream & operator << (std::ostream &o, Fixed const &obj);
#endif