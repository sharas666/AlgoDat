#include "huffman_tree.hpp"
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <cctype>
#include <algorithm>




int main(int argc, char const *argv[])
{


    std::vector<std::pair<std::string,int>> v;

    v.push_back({"E",29});
    v.push_back({"O",15});
    v.push_back({"M",10});
    v.push_back({"N",8});
    v.push_back({"S",4});

    auto t = generate_huffman(v);

    if (argc == 2)
    {
        std::string input = argv[1];

        if (std::all_of( input.begin(), input.end(), ::isdigit ))
        {
            std::cout << t->decode(input) << std::endl;

        }
        else
        {
            std::cout << t->encode(input) << std::endl;
        }


    }
	return 0;
}
