#include <iostream>
// fstream은 ifstream, ofstream을 둘다 포함한다.
#include <fstream>
#include <string>

void str_repl(std::string &line, std::string before, std::string after)
{
    std::size_t pos = 0;
    // find 함수가 아무것도 못찾았을 때 npos 반환
    // npos(no-postion)는 size_t가 가질 수 있는 가장 큰 값.
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

    // 파일 열기
    // std::ios::in 은 디폴트값이므로 없어도 됨.
    std::ifstream fin(filename, std::ios::in);

    // 스트림이 파일을 가졌는지 체크
    // 가졌으면 true 반환
    if (!fin.good() || !fin.is_open())
    {
        std::cout << "error : failed to open " << filename << std::endl;
        return (1);
    }

    filename.append(".replace");

    // fout은 파일 읽기에 실패했을때 failbit or badfit가 1이 되고, false를 반환한다.
    // fout.is_open()은 스트림이 성공적으로 파일을 획득했으면 1 반환.
    // std::ios::trunc | std::ios::app 등 동시에 있을 수 없는 옵션이 오면 에러.
    // out과 trunc는 ofstream의 default이다.
    std::ofstream fout(filename, std::ios::out | std::ios::trunc);
    if (!fout.good() || !fout.is_open())
    {
        std::cout << "error : failed to open or create the file" << std::endl;
        return (1);
    }

    std::string line;
    /**
     * getline이 실패하는 경우
     * - eofbit : 작업 중 문자들의 끝에 도달하였을 때
     * - failbit : 끝에 바로 도달한 경우
     * - errbit : 그 외 오류
     */
    if (!std::getline(fin, line))
    {
        std::cout << "error : failed to read data" << std::endl;
        return (1);
    }
    do
    {
        str_repl(line, s1, s2);
        fout << line;

        // getline은 개행문자를 받지 않으므로
        // 파일에 읽을게 더 있다면 수동으로 개행을 넣어 다음줄에 쓰게 한다.
        if (!fin.eof())
            fout << std::endl;
    }
    while (std::getline(fin, line));

    fin.close();
    fout.close();
    return (0);
}
