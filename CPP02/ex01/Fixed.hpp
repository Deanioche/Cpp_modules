#ifndef FIXED_01_HPP
# define FIXED_01_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed( void );
		Fixed( const Fixed &copy );
		Fixed( int const n );
		Fixed( float const f );
		
		// Destructor
		~Fixed( void );
		
		// Operator =
		Fixed & operator=( const Fixed &assign );
		
		// Getters / Setters
		int 	getRawBits( void ) const;
		void	setRawBits( int const rawBits );

		// Public Functions
		int		toInt( void ) const;
		float	toFloat( void ) const;
		
	private:
		int					_fixed_point;
		static const int 	_fractionalBits = 8;
		
};

// Operator <<
// orthdox 괜찮은가?
// stream << Fixed클래스 연산자 오버로딩                                
std::ostream & operator<<( std::ostream& o, const Fixed& f );

#endif
