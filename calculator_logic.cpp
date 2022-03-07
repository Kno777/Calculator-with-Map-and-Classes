#include <iostream>
#include <exception>
#include "calculator.hpp"

using namespace call;

template <typename T>
class Calculator
{
public:
    Calculator();
    Calculator(char, T, T);
    ~Calculator();
private:
    using fptr = T(*)(T a,T b);
    std::map<char, fptr> mp;
public:
    void set_operation(char op);
    void set_number_one(T num);
    void set_number_two(T num);
public:
    char get_operation() const;
    T get_number_one() const;
    T get_number_two() const;
public:
    void calc_start();
public:
    Calculator(const Calculator &) = delete;
    Calculator& operator=(const Calculator &) = delete;
    Calculator& operator=(Calculator&&) = delete;
    Calculator(Calculator &&) = delete;
private:
    T m_one{};
    T m_two{};
    char m_op;
};

template <typename T>
Calculator<T>::Calculator()
{
    mp['+'] = sum;
    mp['-'] = sub;
    mp['*'] = mul;
    mp['/'] = dive;
}


template <typename T>
Calculator<T>::~Calculator()
{

}

template <typename T>
void Calculator<T>::set_operation(char op)
{
    m_op = op;
}

template <typename T>
void Calculator<T>::set_number_one(T num)
{
    m_one = num;
}

template <typename T>
void Calculator<T>::set_number_two(T num)
{
    m_two = num;
}

template <typename T>
char Calculator<T>::get_operation() const
{
    return m_op;
}

template <typename T>
T Calculator<T>::get_number_one() const
{
    return m_one;
}

template <typename T>
T Calculator<T>::get_number_two() const
{
    return m_two;
}

template <typename T>
void Calculator<T>::calc_start()
{
    char op;
    T num1;
    T num2;
    std::cout << "Please input first number!" << std::endl;
    std::cin >> num1;
    set_number_one(num1);

    std::cout << "Please input seconde number!" << std::endl;
    std::cin >> num2;
    set_number_two(num2);
    
start:
    std::cout << "Please input this is operation(+,-,*,/)!" << std::endl;
    std::cin >> op;
    set_operation(op);

    m_one = num1;
    m_two = num2;
    m_op = op;

    if(op == '+' || op == '-' || op == '*' || op == '/')
    {
        std::cout << get_number_one() << " " << get_operation() << " " << get_number_two()
                << " = " << mp[m_op](m_one, m_two);
    }
    else
    {
        goto start;
    }
}

template <typename T>
Calculator<T>::Calculator(char op, T a, T b)
{
    m_one = a;
    m_two = b;
    m_op = op;

    mp['+'] = sum;
    mp['-'] = sub;
    mp['*'] = mul;
    mp['/'] = dive;

    try
    {
        if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            std::cout << get_number_one() << " " << get_operation() << " " << get_number_two()
                      << " = " << mp[m_op](m_one, m_two);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    //Calculator<int> myCalc('*',23,45); // perfect
    Calculator<int> myCalculator;
    myCalculator.calc_start();
}
