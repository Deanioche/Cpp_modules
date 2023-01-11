#include "iter.hpp"
#include <iostream>

// int main()
// {

//     char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
//     std::cout << "===============type char===============" << std::endl;
//     iter(char_array, 5, &display);
//     std::cout << std::endl;

//     int int_array[5] = {1, 2, 3, 4, 5};
//     std::cout << "===============type int================" << std::endl;
//     iter(int_array, 5, &display);
//     std::cout << std::endl;

//     float float_array[5] = { 0.0f, 1.1f, 2.2f, 3.3f, 4.4f };
//     std::cout << "==============type float===============" << std::endl;
//     iter(float_array, 5, &display);
//     std::cout << std::endl;

//     double	double_array[5] = { 0.00, 1.11, 2.22, 3.33, 4.44 };
//     std::cout << "==============type double==============" << std::endl;
//     iter(double_array, 5, &display);
//     std::cout << std::endl;

//     std::string string_array[5] = { "CPP01", "CPP02", "CPP03", "CPP04", "CPP05" };
//     std::cout << "==============type string==============" << std::endl;
//     iter(string_array, 5, &display);
//     std::cout << std::endl;
// }

class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }

private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
    o << rhs.get();
    return o;
}

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
    return;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4}; // <---1 never understood why you can't write int[] tab. Wouldn't that make more sense?
    iter(tab, 5, print);
    Awesome tab2[5];
    iter(tab2, 5, print);
    return 0;
}