#include "Fixed.hpp"

const int Fixed::_bits= 8;

Fixed::Fixed() : _fixedPoint(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
    // returns the raw value of the fixed-point value
	return this->_fixedPoint;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
    // sets the raw value of the fixed-point number
	this->_fixedPoint = raw;	
}

//returnType operator symbol (arguments)
// copy assignment operator overload
Fixed & Fixed::operator = (Fixed const & fix) {
	std::cout << "Copy assignment operator" << std::endl;
		this->_fixedPoint = fix.getRawBits();
	return *this;
}