#include <iostream>
#include <fstream>
#include <string>

void str_repl(std::string &line, std::string before, std::string after)
{
    std::size_t pos = 0;
    while ((pos = line.find(before, pos)) != std::string::npos)
    {
        line.erase(pos, before.length());
        line.insert(pos, after);
        pos += after.length();
    }
}

int main(int ac, char **av)
{

    if (ac != 4)
    {
        std::cout << "error : check arguments [ ./sed filename s1 s2 ]" << std::endl;
        return (1);
    }

    std::string s1(av[2]);
    std::string s2(av[3]);
    std::string filename(av[1]);
    if (s1.empty() || s2.empty() || !s1.compare(s2))
    {
        std::cout << "error : argument s1, s2 cannot be same or empty. [ ./sed filename s1 s2 ]" << std::endl;
        return (1);
    }

    std::ifstream fin(filename, std::ios::in);

    if (!fin.good() || !fin.is_open())
    {
        std::cout << "error : failed to open " << filename << std::endl;
        return (1);
    }

    filename.append(".replace");

    std::ofstream fout(filename, std::ios::out | std::ios::trunc);
    if (!fout.good() || !fout.is_open())
    {
        std::cout << "error : failed to open or create the file" << std::endl;
        return (1);
    }

    std::string line;
    if (!std::getline(fin, line))
    {
        std::cout << "error : failed to read data" << std::endl;
        return (1);
    }
    do
    {
        str_repl(line, s1, s2);
        fout << line;

        if (!fin.eof())
            fout << std::endl;
    }
    while (std::getline(fin, line));

    fin.close();
    fout.close();
    return (0);
}
