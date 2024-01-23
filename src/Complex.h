#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

template<typename T>
class Complex {
    static_assert(std::is_arithmetic<T>::value, "Template type T must be a numeric type");
private:
    T real;
    T imaginary;
public:
    Complex() : real(T()), imaginary(T()) {}
    Complex(T re, T im) : real(re), imaginary(im) {}

    void setReal(const T &re) { real = re; }
    void setImaginary(const T &im) { imaginary = im; }

    T getReal() const { return real; }
    T getImaginary() const { return imaginary; }

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex &other) const {
        return Complex(
                real * other.real - imaginary * other.imaginary,
                real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex &other) const {
        T denominator = other.real * other.real + other.imaginary * other.imaginary;
        if (denominator == T()) {
            throw std::runtime_error("Complex division by zero");
        }
        return Complex(
                (real * other.real + imaginary * other.imaginary) / denominator,
                (imaginary * other.real - real * other.imaginary) / denominator);
    }

    // Сравнение
    bool operator==(const Complex &other) const {
        const double epsilon = 1e-8;
        return std::abs(real - other.real) < epsilon && std::abs(imaginary - other.imaginary) < epsilon;
    }
    bool operator!=(const Complex &other) const {
        return !(*this == other);
    }

    // Степень и модуль
    Complex pow(int exponent) const {
        Complex result(1, 0); // Start with 1 + 0i
        Complex base = *this;
        while (exponent != 0) {
            if (exponent % 2) {
                result = result * base;
            }
            exponent /= 2;
            if (exponent) base = base * base;
        }
        return result;
    }

    T modulus() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
        os << c.real;
        if (c.imaginary >= 0) os << '+';
        os << c.imaginary << 'i';
        return os;
    }
};

#endif // COMPLEX_H
