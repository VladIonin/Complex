#include "../src/Complex.h"
#include <gtest/gtest.h>

// Test default constructor
TEST(ComplexTest, DefaultConstructor) {
    Complex<double> c;
    EXPECT_DOUBLE_EQ(0.0, c.getReal());
    EXPECT_DOUBLE_EQ(0.0, c.getImaginary());
}

// Test parameterized constructor
TEST(ComplexTest, ParameterizedConstructor) {
    Complex<double> c(3.0, 4.0);
    EXPECT_DOUBLE_EQ(3.0, c.getReal());
    EXPECT_DOUBLE_EQ(4.0, c.getImaginary());
}

// Test addition
TEST(ComplexTest, Addition) {
    Complex<double> c1(1.0, 2.0);
    Complex<double> c2(3.0, 4.0);
    Complex<double> result = c1 + c2;
    EXPECT_DOUBLE_EQ(4.0, result.getReal());
    EXPECT_DOUBLE_EQ(6.0, result.getImaginary());
}

// Test subtraction
TEST(ComplexTest, Subtraction) {
    Complex<double> c1(5.0, 6.0);
    Complex<double> c2(3.0, 2.0);
    Complex<double> result = c1 - c2;
    EXPECT_DOUBLE_EQ(2.0, result.getReal());
    EXPECT_DOUBLE_EQ(4.0, result.getImaginary());
}

// Test multiplication
TEST(ComplexTest, Multiplication) {
    Complex<double> c1(1.0, 2.0);
    Complex<double> c2(3.0, 4.0);
    Complex<double> result = c1 * c2;
    EXPECT_DOUBLE_EQ(-5.0, result.getReal());
    EXPECT_DOUBLE_EQ(10.0, result.getImaginary());
}

// Test division
TEST(ComplexTest, Division) {
    Complex<double> c1(3.0, 4.0);
    Complex<double> c2(1.0, 2.0);
    Complex<double> result = c1 / c2;
    EXPECT_DOUBLE_EQ(2.2, result.getReal());
    EXPECT_DOUBLE_EQ(-0.4, result.getImaginary());
}

// Test modulus
TEST(ComplexTest, Modulus) {
    Complex<double> c(3.0, 4.0);
    double modulus = c.modulus();
    EXPECT_DOUBLE_EQ(5.0, modulus);
}

// Test pow
TEST(ComplexTest, Pow) {
    Complex<double> c(1.0, 2.0);
    Complex<double> result = c.pow(3);
    EXPECT_DOUBLE_EQ(-11.0, result.getReal());
    EXPECT_DOUBLE_EQ(-2.0, result.getImaginary());
}

// Main function for the test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
