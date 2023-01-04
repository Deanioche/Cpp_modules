#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain(void);
	Brain(const Brain &origin);
	~Brain(void);
	Brain &operator=(const Brain &origin);
	
	std::string getIdea(int idx) const;
	void setIdea(int idx, std::string idea);
};

#endif