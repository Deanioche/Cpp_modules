#ifndef FIXED_02_HPP
# define FIXED_02_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(int const n);
		Fixed(float const f);
		
		// Destructor
		~Fixed(void);
		
		// Operators

		bool operator>(const Fixed &f) const;
		bool operator<(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;

		Fixed operator+(const Fixed &f) const;
		Fixed operator-(const Fixed &f) const;
		Fixed operator*(const Fixed &f) const;
		Fixed operator/(const Fixed &f) const;

		Fixed & operator++(void);
		Fixed 	operator++(int);
		Fixed & operator--(void);
		Fixed 	operator--(int);

		Fixed & operator=(const Fixed &assign);
		
		// Getters / Setters
		int 	getRawBits(void) const;
		void	setRawBits(int const rawBits);

		// Public Functions
		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
		
	private:
		int					_fixed_point;
		static const int 	_fractionalBits = 8;
		
};
                            
std::ostream & operator<<(std::ostream& o, const Fixed& f);

#endif
