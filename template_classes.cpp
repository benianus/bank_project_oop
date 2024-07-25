#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

template <class t>

class calculator
{
private:
    t _number1, _number2;

public:
    calculator(t number1, t number2)
    {
        _number1 = number1;
        _number2 = number2;
    }

    t add()
    {
        return _number1 + _number2;
    }
    t multiply()
    {
        return _number1 * _number2;
    }
    t subtraction()
    {
        return _number1 - _number2;
    }
    t divide()
    {
        return _number1 / _number2;
    }
    t concatonatNumbers()
    {
        return _number1 + ' ' + _number2;
    }

    void print_results()
    {
        cout << "\nAdd: " << _number1 << " + " << _number2 << " : " << add();
        cout << "\nSubtraction: " << _number1 << " - " << _number2 << " : " << subtraction();
        cout << "\nMultiply: " << _number1 << " * " << _number2 << " : " << multiply();
        cout << "\nDivide: " << _number1 << " / " << _number2 << " : " << divide();
    }
};

int main()
{
    
    calculator<int> int_calculator(10, 2);
    cout << "\nInterger results: ";
    int_calculator.print_results();

    cout << endl;

    calculator<float> float_calculator(20.55, 2.22);
    cout << "\nFloat results: ";
    float_calculator.print_results();

    cout << endl;

    calculator<double> double_calculator(10.222, 11.2233);
    cout << "\nDouble results: ";
    double_calculator.print_results();

    cout << endl;

    calculator<short> short_calculator(1, 5);
    cout << "\nShort results: ";
    short_calculator.print_results();
    
    calculator<string> stringCalculator("15", "16");
    cout << "\nString results: ";
    cout << stringCalculator.concatonatNumbers() << endl;

    return 0;
}
