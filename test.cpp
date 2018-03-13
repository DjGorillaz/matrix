#include "matrix.h"
#define BOOST_TEST_MODULE test_matrix

#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(add_values)
{
    Matrix<int, -1> matrix;
    BOOST_REQUIRE(matrix.size() == 0);

    matrix[100,100] = 100;
    BOOST_REQUIRE(matrix.size() == 1);

    matrix[0,0] = 100;
    BOOST_REQUIRE(matrix.size() == 2);
}

BOOST_AUTO_TEST_CASE(access_values)
{
    Matrix<int, -1> matrix;
    matrix[100,100] = 100;
    matrix[200,200] = matrix[100][100]*2;

    auto a = matrix[200,200];
    BOOST_REQUIRE(a == 200);
}

BOOST_AUTO_TEST_CASE(delete_values)
{
    Matrix<int, -1> matrix;

    matrix[100,100] = 100;
    BOOST_REQUIRE(matrix.size() == 1);

    matrix[100,100] = -1;
    BOOST_REQUIRE(matrix.size() == 0);
}
