#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    
    // copy 생성자 통해서 복사 
    // ( 생성자 안에서 '=' 연산자 사용하므로 아래 c=b와 같은 동작 )
    Fixed b(a);
    Fixed c;

    // '=' 연산자 통해서 복사
    // c와 b가 다르면 getRawBits() 함수를 통해서 _fixed_point 값을 삽입.
    // Fixed라는 클래스 자체가 바뀌는게 아님. _fixed_point 변수에 값만 들어가는 것.
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return (0);
}
