#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain(void);
	Brain(const Brain &b);
	~Brain(void);
	Brain &operator=(const Brain &b);

	std::string getIdea(int idx) const;
	void setIdea(int idx, std::string idea);
};

#endif