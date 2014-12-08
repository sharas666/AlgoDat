#include <vector>
#include <iostream>
#include "heap.hpp"
#include <cctype>
#include <algorithm>
#include <string>

// checks if all chars of a string are numbers
bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

int main(int argc, char const *argv[])
{
    std::string test_string;
    int to_push;
    std::vector<int> v;

    for (int i = 1; i <= argc-1; ++i)
    {
        test_string = argv[i];
        // break if input is not a number
        if (!is_digits(test_string))
        {
            std::cout <<"input is not a number" << std::endl;
            return 0;
        }
        // add input to the vector
        else
        {
            to_push = stoi(test_string);
            v.push_back(to_push);
        }
    }

    Heap<int> h{};
    h.generate(v); // insert elements of v into heap
    h.sort(); // sort heap
  	h.print_vector(); // print sorted vector

	return 0;
}
