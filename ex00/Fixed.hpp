#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int	_value;
	static const int _fractionalBits = 8;

public:
	// default constructor
	Fixed();

	// copy constructor
	Fixed(const Fixed &other);

	// copy assignement operator overload
	Fixed &operator=(const Fixed &other);

	// destructor
	~Fixed();

	int	getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif