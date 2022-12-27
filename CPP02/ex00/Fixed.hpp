#ifndef FIXED_00_HPP
# define FIXED_00_HPP

# include <iostream>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(const Fixed &copy);
		
		// Destructorß
		~Fixed(void);
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		
		// Getters / Setters
		int getRawBits(void) const;
		
	private:
		int					_fixed_point;
		static const int 	_fractionalBits = 8;
		
};

#endif
