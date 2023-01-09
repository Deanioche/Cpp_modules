#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int value = rand() % 3;
	if (value == 0)
	{
		std::cout << "A created." << std::endl;
		return new A;
	}
	else if (value == 1)
	{
		std::cout << "B created." << std::endl;
		return new B;
	}
	else if (value == 2)
	{
		std::cout << "C created." << std::endl;
		return new C;
	}
	
	return 0;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "ptr: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "ptr: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "ptr: C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "ref: A" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "ref: B" << std::endl;
		return ;
	}
	catch (...) {}

	try
	{
		static_cast<void>(dynamic_cast<C &>(p));
		std::cout << "ref: C" << std::endl;
		return ;
	}
	catch (...)	{}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << "===============test" << i + 1 << "===============" << std::endl;
		Base *p = generate();
		identify(p);
		identify(*p);

		delete p;
	}
	return 0;
}