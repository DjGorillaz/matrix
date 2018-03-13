#include <iostream>
#include <cassert>

#include "matrix.h"



int main()
{
    try
    {
        Matrix<int, 0> matrix;
        for(int i=0; i<10; ++i)
        {
            matrix[i][i] = i;
            matrix[9-i][i]=i;
        }

        for(int i=1; i<=8; ++i)
        {
            for(int j=1; j<=8; ++j)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }

        std::cout << "\nNumber of occupied cells: " << matrix.size() << std::endl << std::endl;

        for(auto c: matrix)
        {
            std::pair<std::size_t, std::size_t> k;
            int v;
            std::tie(k, v) = c;
            std::cout << k.first << k.second << v << std::endl;
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what();
    }
}
