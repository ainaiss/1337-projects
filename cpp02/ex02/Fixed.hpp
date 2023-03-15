#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixed_point;
		const static int	_bits;
	public:
		Fixed();
		Fixed(const float);
		Fixed(const int);
		Fixed(Fixed const &);
		~Fixed();
		int		get_point() const;
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator < (Fixed const &);
		bool	operator > (Fixed const &);
		bool	operator <= (Fixed const &);
		bool	operator >= (Fixed const &);
		bool	operator != (Fixed const &);
		bool	operator == (Fixed const &);
		Fixed	operator + (Fixed const &);
		Fixed	operator * (Fixed const &);
		Fixed	operator / (Fixed const &);
		Fixed	operator - (Fixed const &);
		Fixed	&operator = (const Fixed &);
		Fixed	&operator ++ ( void );
		Fixed	operator ++ ( int );
		Fixed	&operator -- ( void );
		Fixed	operator -- ( int );
		static 	Fixed	&min(Fixed &, Fixed &);
		static 	Fixed	const &min(const Fixed &, const Fixed &);
		static 	Fixed	&max(Fixed	&, Fixed	&);
		static 	Fixed	const &max(const Fixed &, const Fixed &);
};

std::ostream	&operator << (std::ostream &flux, Fixed const &obj);





#endif