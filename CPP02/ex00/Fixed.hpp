#ifndef FIXED_00_HPP
# define FIXED_00_HPP

# include <iostream>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(Fixed const &copy);
		
		// Destructor
		~Fixed(void);
		
		// Operators
		Fixed & operator=(Fixed const &assign);
		
		// Getters / Setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
	private:
		int					_fixed_point;
		static const int 	_fractionalBits = 8;
};

#endif
