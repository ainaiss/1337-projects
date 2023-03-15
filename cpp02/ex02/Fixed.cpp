#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed() : _fixed_point(0)
{
	
}

Fixed::Fixed(const float point)
{
	this->_fixed_point = roundf(point * (1 << _bits));
}

Fixed::Fixed(const int point)
{
	this->_fixed_point = point * (1 << _bits);
}

Fixed::Fixed(Fixed const &obj)
{
	*this = obj;
}

Fixed::~Fixed()
{
	
}

int	Fixed::get_point() const
{
	return (this->_fixed_point);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point / (1 << this->_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed_point / (1 << this->_bits));
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._fixed_point < b._fixed_point)
		return b;
	else
		return a;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixed_point < b._fixed_point)
		return b;
	else
		return a;
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._fixed_point < b._fixed_point)
		return a;
	else
		return b;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixed_point < b._fixed_point)
		return a;
	else
		return b;
}

bool	Fixed::operator < (Fixed const &b)
{
	if (this->_fixed_point < b._fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator > (Fixed const &b)
{
	if (this->_fixed_point > b._fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator <= (Fixed const &b)
{
	if (this->_fixed_point <= b._fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator >= (Fixed const &b)
{
	if (this->_fixed_point >= b._fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator != (Fixed const &b)
{
	if (this->_fixed_point != b._fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator == (Fixed const &b)
{
	if (this->_fixed_point == b._fixed_point)
		return true;
	else
		return false;
}

Fixed	Fixed::operator + (Fixed const &b)
{
	Fixed	plus;
	plus = this->toFloat() + b.toFloat();
	return plus;
}

Fixed	Fixed::operator - (Fixed const &b)
{
	Fixed	sub;
	sub = this->toFloat() - b.toFloat();
	return sub;
}

Fixed	Fixed::operator * (Fixed const &b)
{
	Fixed	multiple;
	multiple = this->toFloat() * b.toFloat();
	return multiple;
}

Fixed	Fixed::operator / (Fixed const &b)
{
	Fixed	div;
	div = this->toFloat() / b.toFloat();
	return div;
}

Fixed	&Fixed::operator ++ (void)
{
	this->_fixed_point++;
	return *this;
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	temp = *this;
	this->_fixed_point++;
	// ++*this;
	return temp;
}

Fixed	&Fixed::operator -- (void)
{
	this->_fixed_point--;
	return *this;
}

Fixed	Fixed::operator -- (int)
{
	Fixed	temp = *this;
	this->_fixed_point--;
	return *this;
}

Fixed	& Fixed::operator = (const Fixed &b)
{
	this->_fixed_point = b._fixed_point;
	return *this;
}

std::ostream	&operator << (std::ostream &flux, Fixed	const &obj)
{
	flux << obj.toFloat();
	return flux;
}
