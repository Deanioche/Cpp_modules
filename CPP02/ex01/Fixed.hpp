#ifndef FIXED_01_HPP
# define FIXED_01_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed(int const n);
		Fixed(float const f);
		
		// Destructor
		~Fixed(void);
		
		// Operator =
		Fixed & operator=(Fixed const &assign);
		
		// Getters / Setters
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);

		// Public Functions
		int		toInt(void) const;
		float	toFloat(void) const;
		
	private:
		int					_fixed_point;
		static const int 	_fractionalBits = 8;
		
};

std::ostream & operator<<(std::ostream& o, Fixed const& f);

#endif
