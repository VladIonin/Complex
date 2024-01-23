#include "gtest/gtest.h"
#include "Complex.h"

TEST(ComplexTest, Addition) {
    Complex<int> a(1, 2);
    Complex<int> b(3, 4);
    Complex<int> result = a + b;

    EXPECT_EQ(result.getReal(), 4);
    EXPECT_EQ(result.getImaginary(), 6);
}

TEST(ComplexTest, Subtraction) {
    Complex<float> a(2.5, 3.5);
    Complex<float> b(1.5, 2.5);
    Complex<float> result = a - b;

    EXPECT_NEAR(result.getReal(), 1.0, 1e-5);
    EXPECT_NEAR(result.getImaginary(), 1.0, 1e-5);
}

TEST(ComplexTest, Multiplication) {
    Complex<double> a(2.0, 3.0);
    Complex<double> b(4.0, 5.0);
    Complex<double> result = a * b;

    EXPECT_DOUBLE_EQ(result.getReal(), -7.0);
    EXPECT_DOUBLE_EQ(result.getImaginary(), 22.0);
}

TEST(ComplexTest, Division) {
    Complex<double> a(6.0, 8.0);
    Complex<double> b(2.0, 2.0);
    Complex<double> result = a / b;

    EXPECT_EQ(result.getReal(), 3.5);
    EXPECT_EQ(result.getImaginary(), 0.5);
}

TEST(ComplexTest, Power) {
    Complex<int> base(2, 1);
    Complex<int> result = base.pow(3);

    EXPECT_EQ(result.getReal(), 2);
    EXPECT_EQ(result.getImaginary(), 11);
}

TEST(ComplexTest, Modulus) {
    Complex<float> c(3.0, 4.0);
    float result = c.modulus();

    EXPECT_FLOAT_EQ(result, 5.0);
}

TEST(ComplexTest, Comparison) {
    Complex<float> a(2.0, 3.0);
    Complex<float> b(2.0, 3.0);
    Complex<float> c(3.0, 4.0);

    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(ComplexTest, IntComparison) {
    Complex<int> a(2, 3);
    Complex<int> b(2, 3);
    Complex<int> c(3, 4);
    Complex<int> d(3, 0);

    EXPECT_EQ(a, b);
    EXPECT_EQ(d, 3);
    EXPECT_NE(a, c);
}

TEST(ComplexTest, FloatComparison) {
    Complex<float> a(2.0, 3.0);
    Complex<float> b(2.0, 3.0);
    Complex<float> c(3.0, 4.0);
    Complex<float> d(3.0, 0.0);

    EXPECT_EQ(a, b);
    EXPECT_EQ(d, 3);
    EXPECT_NE(a, c);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}