#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int             _fixedPoint;
        static const int _bits;
    public:
        Fixed();
        Fixed(const Fixed &src);
        ~Fixed();
         Fixed & operator=(const Fixed &rhs);
        int     getRawBits(void) const ;
        void    setRawBits(int const raw); 

};

#endif