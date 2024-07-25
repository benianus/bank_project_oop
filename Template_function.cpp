#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#include "cls_utility.h"
#include "cls_input_validation.h"

template <typename t>

t my_name(t first_name, t last_name)
{
    return (first_name + last_name);
}

template <typename t>
t my_number(t number1, t number2)
{
    return number1 + number2;
}
int main()
{
    cout << my_name<string>("Mohamed ", "BENIANE") << endl;

    cout << my_name<int>(5, 3) << endl;

    cout << my_name<float>(10.56, 112.233) << endl;

    cout << my_name<double>(10.22355, 123.26547) << endl;

    cout << my_name<short>(1, 5) << endl;

    cout << my_name<char>('M', 'B') << endl;

    cout << my_name<bool>(1, 1) << endl;

    cout << my_number<int>(1,2) << endl;

    return 0;
}
