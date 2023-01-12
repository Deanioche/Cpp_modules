#include "MutantStack.hpp"

int basic_test(void)
{	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << "------basic iterator stack-------" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int reverse_test(void)
{	
	MutantStack<std::string> mstack;
	mstack.push("I want to go home.");
	mstack.push("Now I'm tired.");
	mstack.push("Then I just finished a subject.");
	mstack.push("I studied so hard.");
	mstack.push("From the beginning of the day.");
	std::cout << "------reverse iterator stack-------" << std::endl;

	MutantStack<std::string>::reverse_iterator it = mstack.rbegin();
	MutantStack<std::string>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}

int const_test(void)
{	
	MutantStack<char> mstack;
	mstack.push('a');
	mstack.push('b');
	mstack.push('c');
	mstack.push('d');
	mstack.push('e');
	std::cout << "------const iterator stack-------" << std::endl;

	MutantStack<char>::const_iterator it = mstack.cbegin();
	MutantStack<char>::const_iterator ite = mstack.cend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}

int const_reverse_test(void)
{	
	MutantStack<double> mstack;
	mstack.push(1.0);
	mstack.push(2.0);
	mstack.push(3.0);
	mstack.push(5.0);
	mstack.push(10.0);
	std::cout << "------const reverse iterator stack-------" << std::endl;

	MutantStack<double>::const_reverse_iterator it = mstack.crbegin();
	MutantStack<double>::const_reverse_iterator ite = mstack.crend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}

int main(void)
{
	basic_test();
	std::cout << std::endl;
	reverse_test();
	std::cout << std::endl;
	const_test();
	std::cout << std::endl;
	const_reverse_test();
	return 0;
}