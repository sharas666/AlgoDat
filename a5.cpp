#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cmath>
#include <limits>

double fRand()
{
    double f = (double)rand() / RAND_MAX;
    return f * 10;
}

struct point2d
{
    point2d() : mX{fRand()}, mY{fRand()}{}
    void print() const
    {
        std::cout << "x: " << mX << " y: " << mY << std::endl;
    }
    double get_distance(point2d const& rhs) const
    {
        return sqrt(pow(mX - rhs.mX, 2) + pow(mY - rhs.mY, 2));
    }

    double mX;
    double mY;
};

template <typename Iterator>
double shortest_distance(Iterator begin, Iterator end)
{
    double sdist = begin->get_distance(*(begin+1));
    double cdist;
    for(auto start = begin; start != end-1; ++start)
    {
        for (auto current = start+1; current != end; ++current)
        {
            cdist = start->get_distance(*current);
            if (cdist < sdist)
                sdist = cdist;
            // std::cout << cdist << std::endl;
        }
    }


    return sdist;
}

double divide(std::vector<point2d> const& v, int a, int b)
{
    double sdist = std::numeric_limits<double>::infinity();
    
    if( b - a > 3)
    {
       sdist = divide(v, a, a + ((b-a)/2));
       sdist = divide(v, a + ((b-a)/2)+1, b);
    }
    else
    {   
        // std::cout << shortest_distance(v.begin()+a, v.begin()+b) << std::endl;
        double cdist = shortest_distance(v.begin()+a, v.begin()+b);
        if (cdist < sdist)
            sdist = cdist;
    }
    return sdist;
}

int main(int argc, char const *argv[])
{
    
    std::vector<point2d> vx(100);
    std::vector<point2d> vy{vx};
    std::sort(vx.begin(), vx.end(), [](point2d const& a, point2d const& b)->bool{return a.mX < b.mX;});
    std::sort(vy.begin(), vy.end(), [](point2d const& a, point2d const& b)->bool{return a.mY < b.mY;});
    // std::cout << shortest_distance(vx.begin(), vx.end()) << std::endl;
    std::cout << divide(vx, 0, vx.size()-1) << std::endl;



	return 0;
}