#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "qh_vector.h"

using namespace std;
using namespace qh;

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好

    qh::vector<int> num_vect;
    num_vect.push_back(1);
    std::cout<<num_vect.size()<<std::endl;
    qh::vector<int> v1(8, 2);
    std::cout<<v1.size()<<std::endl;
    std::cout<<v1.begin()<<v1.end()<<" ";
    v1.push_back(2);
    std::cout<<v1.size()<<std::endl;
    std::cout<<v1.begin()<<v1.end()<<" ";
    std::cout<<v1[8];

    v1.pop_back();
    std::cout<<v1.size()<<std::endl;
    std::cout<<v1[8];

    v1.clear();
    std::cout<<v1.empty()<<std::endl;

    qh::vector<std::string> s1;
    /*for(int i = 1; i <= 3; ++i)
    {
        string str(i, '0');
        s1.push_back(str);
    }*/
    s1.push_back("123");
    s1.push_back("abc");

    std::cout<<s1.size()<<" "<<s1.end()<<std::endl;

#ifdef WIN32
    system("pause");
#endif

	return 0;
}
