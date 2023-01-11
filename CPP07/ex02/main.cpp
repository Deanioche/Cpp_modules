#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << i << " : " << numbers[i] << std::endl;
    }
    //SCOPE
    {
        const Array<int> test(numbers);
        Array<int> tmp;
        tmp = test;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i] || numbers[i] != tmp[i] || numbers[i] != test[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                std::cerr << mirror[i] << " " << numbers[i] << " " << tmp[i] << " " << test[i]<< std::endl;
                std::cerr << &mirror[i] << " " << &numbers[i] << " " << &tmp[i] << " " << &test[i]<< std::endl;
                return 1;
            }
            if (&numbers[i] == &tmp[i] || &numbers[i] == &test[i] || &test[i] == &tmp[i])
            {
                std::cerr << "address duplicated!!" << std::endl;
                std::cerr << mirror[i] << " " << numbers[i] << " " << tmp[i] << " " << test[i]<< std::endl;
                std::cerr << &mirror[i] << " " << &numbers[i] << " " << &tmp[i] << " " << &test[i]<< std::endl;
                return 1;
            }
        }
    }
    std::cout << numbers;

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << numbers;
    delete [] mirror;

    return 0;
}