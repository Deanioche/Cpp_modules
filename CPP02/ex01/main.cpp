#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f); // 42.4219 ?
    Fixed const d(b);

    a = Fixed(1234.4321f); // 1234.43 ?
    // 바로 위 Fixed(1234.4321f)의 _fixed_point 변수가 a로 삽입되고 클래스는 소멸되므로,
    // 소멸자가 호출된다.

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
