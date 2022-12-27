#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(Fixed &copy);
		
		// Destructorß
		~Fixed(void);
		
		// Operators
		Fixed & operator=(Fixed &assign);
		
		// Getters / Setters
		int getRawBits(void) const;
		
	private:
		int					_fixed_point;
		static const int 	_fractionalBits = 8;
		
};

#endif
