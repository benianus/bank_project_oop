#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>

#include "cls_date.h"

const string client_file_name = "clients.txt";

class cls_utility
{

    short _key;
    string _text;
    string _phrase;
    char _letter;

public:
    cls_utility()
    {
    }
    cls_utility(short key, string text)
    {
        _key = key;
        _text = text;
    }
    cls_utility(string phrase)
    {
        _phrase = phrase;
    }
    cls_utility(char letter)
    {
        _letter = letter;
    }
    cls_utility(string phrase, char letter)
    {
        _phrase = phrase;
        _letter = letter;
    }

    void set_letter(char letter)
    {
        _letter = letter;
    }
    char get_letter()
    {
        return _letter;
    }
    //__declspec(property(get = get_letter, put = set_letter)) char letter;

    void set_phrase(string phrase)
    {
        _phrase = phrase;
    }
    string get_phrase()
    {
        return _phrase;
    }
    //__declspec(property(get = get_phrase, put = set_phrase)) string phrase;

    void set_key(short key)
    {
        _key = key;
    }
    short get_key()
    {
        return _key;
    }
    //__declspec(property(get = get_key, put = set_key)) short key;

    void set_text(string text)
    {
        _text = text;
    }
    string get_text()
    {
        return _text;
    }
    //__declspec(property(get = get_text, put = set_text)) string text;

    enum operationtypes
    {
        add = '+',
        subtract = '-',
        divide = '/',
        multiply = '*'
    };

    static float read_number(string message)
    {
        float number;
        cout << message << endl;
        cin >> number;

        return number;
    }
    static operationtypes read_operation(string message)
    {
        char operation;
        cout << message << endl;
        cin >> operation;

        return (operationtypes)operation;
    }
    static float calculate(float number1, float number2, operationtypes operation)
    {
        switch (operation)
        {
        case operationtypes::add:
            return number1 + number2;
            // break;
        case operationtypes::subtract:
            return number1 - number2;
            // break;
        case operationtypes::divide:
            return number1 / number2;
            // break;
        case operationtypes::multiply:
            return number1 * number2;
            // break;
        default:
            return number1 + number2;
            // break;
        }
    }

    static int sum_until()
    {
        int sum = 0;
        int counter = 1;
        int number = 0;

        do
        {
            number = read_number("Please enter the number " + to_string(counter));
            if (number == -99)
            {
                break;
            }
            sum += number;
            counter++;

        } while (number != -99);

        return sum;
    }

    enum number_type
    {
        prime,
        not_prime
    };

    static float read_positive_number(string message)
    {
        float number;
        do
        {
            cout << message << endl;
            cin >> number;
        } while (number <= 0);

        return number;
    }
    static number_type check_prime_notprime(int number)
    {
        int M = round(number / 2);
        for (int counter = 2; counter <= M; counter++)
        {
            if (number % counter == 0)
            {
                return number_type::not_prime;
            }
        }

        return number_type::prime;
    }
    static void print_prime_not_prime(int number)
    {
        switch (check_prime_notprime(number))
        {
        case number_type::prime:
            cout << "The number is not prime" << endl;
            break;
        case number_type::not_prime:
            cout << "The number is prime" << endl;
            break;
        default:
            break;
        }
    }

    static float calculateRemainder(float totalbill, float cashpaid)
    {
        return cashpaid - totalbill;
    }

    static float calculate_totalbill(float totalbill)
    {
        totalbill = totalbill * 1.1;
        totalbill = totalbill * 1.16;

        return totalbill;
    }

    static int read_number_hours(string message)
    {
        int number_of_hours;
        do
        {
            cout << message << endl;
            cin >> number_of_hours;

        } while (number_of_hours <= 0);

        return number_of_hours;
    }
    static float hours_to_days(float number_hours)
    {
        return (float)number_hours / 24;
    }
    static float hours_to_weeks(float number_hours)
    {
        return (float)number_hours / 24 / 7;
    }
    static float days_to_weeks(float number_days)
    {
        return (float)number_days / 7;
    }

    struct number_of_seconds
    {
        int numberofdays, numberofhours, numberofminutes, numberofseconds;
    };
    static number_of_seconds read_tota_seconds()
    {

        number_of_seconds number;

        number.numberofdays = read_positive_number("Please, enter the number of days");
        number.numberofhours = read_positive_number("Please, enter the number of hours");
        number.numberofminutes = read_positive_number("Please, enter the number of minutes");
        number.numberofseconds = read_positive_number("Please, enter the number of seconds");

        return number;
    }
    static float calculat_total_seconds(number_of_seconds number)
    {
        float total_seconds, number_of_days, number_of_hours, number_of_minutes, number_of_seconds;
        number_of_days = number.numberofdays * 24 * 60 * 60;
        number_of_hours = number.numberofhours * 60 * 60;
        number_of_minutes = number.numberofminutes * 60;
        number_of_seconds = number.numberofseconds;

        total_seconds = number_of_days + number_of_hours + number_of_minutes + number_of_seconds;

        return total_seconds;
    }
    static number_of_seconds calculate_seconds_to(int totalseconds)
    {
        number_of_seconds duration;

        const int seconds_per_day = 24 * 60 * 60;
        const int seconds_per_hour = 60 * 60;
        const int seconds_per_minute = 60;

        int remainder;

        duration.numberofdays = floor(totalseconds / seconds_per_day);
        remainder = totalseconds % seconds_per_day;
        duration.numberofhours = floor(remainder / seconds_per_hour);
        remainder = (int)remainder % seconds_per_hour;
        duration.numberofminutes = floor(remainder / seconds_per_minute);
        remainder = (int)remainder % seconds_per_minute;
        duration.numberofseconds = remainder;

        return duration;
    }

    static int read_positive_number_in_range(string message, int from, int to)
    {
        int number;
        do
        {
            cout << message << endl;
            cin >> number;

        } while (number < from || number > to);

        return number;
    }

    static float Area(float a, float b)
    {
        float area = a * sqrt(pow(b, 2) - pow(a, 2));
        return area;
    }
    static float Rectengal_Area(float A, float Hight)
    {
        float area = (A * Hight) / 2;
        return area;
    }
    static float CircleArea(float r)
    {
        const float pi = 3.14;
        float area = pi * pow(r, 2);

        return area;
    }
    static float Circle_area_diameter(float D)
    {
        const float pi = 3.141592653589793238462643383279502884197;
        float area = (pi * pow(D, 2)) / 4;

        return area;
    }
    static float Circle_area_squar(float squar)
    {
        const float pi = 3.141592653589793238462643383279502884197;
        float area = (pi * pow(squar, 2)) / 4;

        return area;
    }
    static float Circle_area_circumfrences(float L)
    {
        const float pi = 3.14;
        float area = pow(L, 2) / (4 * pi);

        return area;
    }
    static float Circle_area_ins(float a, float b)
    {
        const float pi = 3.14;
        float area = pi * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));

        return area;
    }
    static float Circle_area_des(float A, float B, float C)
    {
        const float pi = 3.14;
        float p = (A + B + C) / 2;
        float T = (A * B * C) / (4 * sqrt(p * (p - A) * (p - B) * (p - C)));
        float area = pi * pow(T, 2);
        return area;
    }

    static void reversed_order(int number)
    {
        int remainder = 0;
        while (number > 0)
        {
            remainder = number % 10;
            number = number / 10;
            cout << remainder << endl;
        }
    }
    static int print_sumofdigits(int number)
    {
        int remainder = 0;
        int sum = 0;
        while (number > 0)
        {
            remainder = number % 10;
            number = number / 10;
            sum += remainder;
        }

        return sum;
    }
    static int number_frequency(int number, short number2)
    {
        int remainder = 0;
        int frequency = 0;
        while (number > 0)
        {
            remainder = number % 10;
            number = number / 10;
            if (remainder == number2)
            {
                frequency++;
            }
        }

        return frequency;
    }
    static int frequency_digits(int number, short number2)
    {
        int frequency = 0;
        int remainder = 0;
        while (number > 0)
        {
            remainder = number % 10;
            number = number / 10;
            if (remainder == number2)
            {
                frequency++;
            }
        }
        return frequency;
    }
    static void reverse_sumofdigits(int number)
    {
        int remainder = 0;
        while (number > 0)
        {
            remainder = number % 10;
            number = number / 10;
            cout << remainder << endl;
        }
    }
    static int check_palindrom_number(int number)
    {
        return number == print_sumofdigits(number);
    }
    static void inverted_pattern_number(int number)
    {
        for (int i = number; i >= 1; i--)
        {

            for (int b = 1; b <= number; b++)
            {
                cout << number;
            }
            number--;
            cout << endl;
        }
    }
    static void inverted_pattern_letter(int number)
    {

        for (int i = 65 + number - 1; i >= 65; i--)
        {
            // cout << char(i) << endl;
            for (int b = 1; b <= number - (65 + number - 1 - i); b++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }
    static void letter_pattern(int number)
    {
        for (int i = 65; i <= 65 + number - 1; i++)
        {
            for (int a = 1; a <= i - 65 + 1; a++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    void all_words()
    {
        string word = "";
        for (int i = 65; i <= 90; i++)
        {
            for (int a = 65; a <= 90; a++)
            {
                for (int b = 65; b <= 90; b++)
                {
                    word = word + char(i);
                    word = word + char(a);
                    word = word + char(b);

                    cout << word << endl;

                    word = "";
                }
            }
            cout << endl;
        }
    }
    bool all_words(string password)
    {
        int trial = 0;
        string word = "";
        for (int i = 65; i <= 90; i++)
        {
            for (int a = 65; a <= 90; a++)
            {
                for (int b = 65; b <= 90; b++)
                {
                    trial++;

                    word = word + char(i);
                    word = word + char(a);
                    word = word + char(b);

                    cout << "Trial [" << trial << "] " << word << endl;

                    if (word == password)
                    {
                        cout << "The password is: " << word << endl;
                        cout << "Founded after: [" << trial << "] Trial " << endl;
                        return true;
                    }

                    word = "";
                }
            }
        }
        return false;
    }

    static string encryption(string text, short key = 2)
    {
        for (int i = 0; i <= text.length(); i++)
        {
            text[i] = char((int)text[i] + key);
        }

        return text;
    }
    string encryption()
    {
        return encryption(_text, _key);
    }

    static string decryption(string text, short key = 2)
    {
        for (int i = 0; i <= text.length(); i++)
        {
            text[i] = char((int)text[i] - key);
        }

        return text;
    }
    string decryption()
    {
        return decryption(_text, _key);
    }

    static void s_rand()
    {
        srand((unsigned)time(NULL));
    }

    static int random_number(int from, int to)
    {
        int rand_num = rand() % (to - from + 1) + from;

        return rand_num;
    }

    enum random_digits
    {
        small_letter,
        capital_letter,
        special_character,
        digit_order,
        mix
    };
    static char get_random_char(random_digits random)
    {
        switch (random)
        {
        case random_digits::small_letter:
            return char(random_number(97, 122));
            break;
        case random_digits::capital_letter:
            return char(random_number(65, 90));
            break;
        case random_digits::special_character:
            return char(random_number(33, 47));
            break;
        case random_digits::digit_order:
            return char(random_number(48, 57));
            break;
        default:
            return char(random_number(33, 122));
            break;
        }
    }
    static string generate_word(random_digits chartype, short length)
    {
        string word;
        for (int i = 1; i <= length; i++)
        {
            word = word + get_random_char(chartype);
        }

        return word;
    }
    static string generate_key()
    {
        string key = "";

        key = generate_word(random_digits::capital_letter, 4) + "-";
        key = key + generate_word(random_digits::capital_letter, 4) + "-";
        key = key + generate_word(random_digits::capital_letter, 4) + "-";
        key = key + generate_word(random_digits::capital_letter, 4);

        return key;
    }
    static void generate_keys(short number_of_keys)
    {
        for (int i = 1; i <= number_of_keys; i++)
        {
            cout << "Key [" << i << "] : " << generate_key() << endl;
        }
    }

    static int max_array_number(int array[100], int array_length)
    {
        int max = array[0];
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }
        return max;
    }
    static int min_array_number(int array[100], int array_length)
    {
        int min = array[0];
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }
    static void fill_array(int array[100], int &array_length)
    {
        cout << "Please, etner the length of the arry" << endl;
        cin >> array_length;

        for (int i = 0; i < array_length; i++)
        {
            array[i] = random_number(1, 100);
        }
    }
    static int sum_array_number(int array[100], int array_length)
    {
        int sum = 0;
        for (int i = 0; i < array_length; i++)
        {
            sum += array[i];
        }
        return sum;
    }
    static float average_array_number(int array[100], int array_length)
    {
        return (float)sum_array_number(array, array_length) / array_length;
    }
    static void copy_array(int array[100], int array2[100], int array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            array2[i] = array[i];
        }
    }
    static void copy_prime_array(int array[100], int array2[100], int array_length, int &array2_length)
    {
        int counter = 0;
        for (int i = 0; i < array_length; i++)
        {

            if (check_prime_notprime(array[i]) == number_type::prime)
            {
                array2[counter] = array[i];
                counter++;
            }
        }

        array2_length = --counter;
    }
    static void sum_arrays(int array[100], int array2[100], int array3[100], int array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            array3[i] = array[i] + array2[i];
        }
    }
    static void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    static void fill_unshuffle(int array[100], int &array_length)
    {

        for (int i = 0; i < array_length; i++)
        {
            array[i] = i + 1;
        }
    }
    static void array_shuffle(int array[100], int array_length)
    {

        for (int i = 1; i < array_length; i++)
        {
            swap(array[random_number(1, array_length) - 1], array[random_number(1, array_length) - 1]);
        }
    }
    static void array_elements(int array[100], int &array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            array[i] = random_number(1, 100);
        }
    }
    static void array_reverse(int array[100], int array_2[100], int array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            array_2[i] = array[array_length - i - 1];
        }
    }
    static void array_fill_with_keys(string array[100], int &array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            array[i] = generate_key();
        }
    }
    static void print_string_array(string array[100], int array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            cout << "Array [" << i << "]: " << array[i] << endl;
        }
    }
    static short search_number_postion(int array[100], int array_length, int number_searched)
    {
        for (int i = 0; i < array_length; i++)
        {
            if (array[i] == number_searched)
            {
                return i;
            }
        }
        return -1;
    }
    static bool check_number_is_found(int array[100], int array_length, short number_searched)
    {

        return search_number_postion(array, array_length, number_searched) != -1;
    }
    static void fill_array(int array[100], int &array_length, int number)
    {
        array_length++;
        array[array_length - 1] = number;
    }
    static void input_user_number(int array[100], int &array_length)
    {
        bool add_more = 0;
        do
        {
            fill_array(array, array_length, read_positive_number("Please, enter a number"));
            cout << "Do you want more numbers [0]No, [1]Yes" << endl;
            cin >> add_more;

        } while (add_more);
    }
    static void copy_array_using_add_elements(int array[100], int array_2[100], int array_length, int &array_length_2)
    {
        for (int i = 0; i < array_length; i++)
        {
            fill_array(array_2, array_length_2, array[i]);
        }
    }
    static void copy_array_elements(int array[100], int array_2[100], int array_length, int &array_length_2)
    {

        for (int i = 0; i < array_length; i++)
        {
            if (array[i] % 2 != 0)
            {
                fill_array(array_2, array_length_2, array[i]);
            }
        }
    }
    static void copy_array_prime_elements(int array[100], int array_2[100], int array_length, int &array_length_2)
    {
        for (int i = 0; i < array_length; i++)
        {
            if (check_prime_notprime(array[i]) == number_type::prime)
            {
                fill_array(array_2, array_length_2, array[i]);
            }
        }
    }
    static bool check_palindrom_array(int arraySource[100], int array_length)
    {
        for (int i = 0; i < array_length; i++)
        {
            if (arraySource[i] != arraySource[array_length - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    static int check_odd_number_in_array(int ArraySource[100], int ArrayLength)
    {
        int OddNumberCount = 0;
        for (int i = 0; i < ArrayLength; i++)
        {
            if (ArraySource[i] % 2 != 0)
            {
                OddNumberCount++;
            }
        }

        return OddNumberCount;
    }
    static int check_even_num_in_array(int ArraySource[100], int ArrayLength)
    {
        int EvenNumberCount = 0;
        for (int i = 0; i < ArrayLength; i++)
        {
            if (ArraySource[i] % 2 == 0)
            {
                EvenNumberCount++;
            }
        }

        return EvenNumberCount;
    }
    static int check_positive_number_in_arrary(int ArraySource[100], int ArrayLength)
    {
        int counter = 0;
        for (int i = 0; i < ArrayLength; i++)
        {
            if (ArraySource[i] > 0)
            {
                counter++;
            }
        }

        return counter;
    }
    static int check_negative_numbers_in_array(int ArraySource[100], int ArrayLength)
    {
        int counter = 0;
        for (int i = 0; i < ArrayLength; i++)
        {
            if (ArraySource[i] < 0)
            {
                counter++;
            }
        }

        return counter;
    }
    static void Print_Array_Random_Number(int Random_Array[3][3], short Rows, short Columns)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Columns; j++)
            {
                cout << setw(3) << Random_Array[i][j] << " ";
            }
            cout << endl;
        }
    }
    static void Fill_Matrix_Random_Number(int array[3][3], short Rows, short Colums)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Colums; j++)
            {
                array[i][j] = random_number(1, 100);
            }
        }
    }
    static void Print_Matrix(int array[3][3], short Rows, short Colums)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Colums; j++)
            {
                cout << setw(3) << array[i][j] << "   ";
            }
            cout << endl;
        }
    }
    static int matrix_Row_Sum(int array[3][3], short Row_Number, short Colums)
    {
        int Sum = 0;
        for (int i = 0; i < Colums; i++)
        {
            Sum += array[Row_Number][i];
        }

        return Sum;
    }
    static void Print_Matrix_Row_Sum(int array[3][3], short Rows, short Colums)
    {
        for (short i = 0; i < Rows; i++)
        {
            cout << "Row " << i << " Sum = " << matrix_Row_Sum(array, i, Colums) << endl;
        }
    }
    static void Row_Sum_in_New_Array(int New_array[3], int array[3][3], short Rows, short Colums)
    {
        for (int i = 0; i < Rows; i++)
        {
            New_array[i] = matrix_Row_Sum(array, i, Colums);
        }
    }
    static int Matrix_Colums_Sum(int array[3][3], short Rows, short Colum_Number)
    {
        int Sum = 0;
        for (short i = 0; i < Rows; i++)
        {
            Sum += array[i][Colum_Number];
        }
        return Sum;
    }
    static void Print_Matrix_Colums_Sum(int array[3][3], short Rows, short Colums)
    {
        for (short Colum_Number = 0; Colum_Number < Colums; Colum_Number++)
        {
            cout << "Col " << Colum_Number + 1 << " Sum: " << Matrix_Colums_Sum(array, Rows, Colum_Number) << endl;
        }
    }
    static void Fill_single_arr_with_Colu_Sum(int two_Di_arr[3][3], int Single_arr[3], short Rows, short Colums)
    {
        for (short i = 0; i < Rows; i++)
        {
            Single_arr[i] = Matrix_Colums_Sum(two_Di_arr, Rows, i);
        }
    }
    static void Print_Single_Matrix(int array[3], short Rows)
    {
        for (short i = 0; i < Rows; i++)
        {
            cout << "Col " << i + 1 << " Sum: " << array[i] << endl;
        }
    }
    static void Fill_Matrix_with_Ordered_Number(int array[3][3], short Rows, short Colums)
    {
        short counter = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Colums; j++)
            {
                counter++;
                array[i][j] = counter;
            }
        }
    }
    static void Transpose_Matrix(int array[3][3], int arr[3][3], short Rows, short Colums)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Colums; j++)
            {
                arr[i][j] = array[j][i];
            }
        }
    }
    static void matrix_multiplication(int matrix_03[3][3], int matrix_01[3][3], int matrix_02[3][3], short rows, short colums)
    {

        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                matrix_03[i][j] = matrix_01[i][j] * matrix_02[i][j];
            }
        }
    }
    static void print_middle_rows(int matrix[3][3], short rows, short colums)
    {
        short middle_rows = round(rows / 2);
        for (short i = 0; i < colums; i++)
        {
            printf("%0*d   ", 2, matrix[middle_rows][i]);
        }
    }
    static void print_middle_colums(int matrix[3][3], short rows, short colums)
    {
        short middle_colums = round(colums / 2);
        for (short i = 0; i < rows; i++)
        {
            printf("%0*d   ", 2, matrix[i][middle_colums]);
        }
    }
    static int print_sum_of_matrix(int matrix[3][3], short rows, short colums)
    {
        int sum = 0;
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                sum += matrix[i][j];
            }
        }

        return sum;
    }
    static int sum_of_matrix(int matrix[3][3], short rows, short colums)
    {
        int sum = 0;
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                sum += matrix[i][j];
            }
        }

        return sum;
    }
    static bool is_matrices_equal(int matrix_01[3][3], int matrix_02[3][3], short rows, short colums)
    {
        return (sum_of_matrix(matrix_01, rows, colums) == sum_of_matrix(matrix_02, rows, colums));
    }
    static bool is_matices_typical(int matrix_01[3][3], int matrix_02[3][3], short rows, short colums)
    {
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                if (matrix_01[i][j] != matrix_02[i][j])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    static bool is_matrix_identity(int matrix[3][3], short rows, short colums)
    {
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                if (i == j && matrix[i][j] != 1)
                {
                    return false;
                }
                else if (i != j && matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    static bool is_matrix_scalar(int matrix[3][3], short rows, short colums)
    {
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                if (i == j && matrix[i][j] != matrix[0][0])
                {
                    return false;
                }

                else if (i != j && matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    static short count_number_in_matrix(int matrix[3][3], int number, short rows, short colums)
    {

        short counter = 0;
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                if (number == matrix[i][j])
                {
                    counter++;
                }
            }
        }
        return counter;
    }
    static bool is_matrix_sparce(int matrix[3][3], short rows, short colums)
    {
        short matrix_size = rows * colums;
        return count_number_in_matrix(matrix, 0, 3, 3) >= (matrix_size / 2);
    }
    static bool is_number_in_matrix(int matrix[3][3], int number, short rows, short colums)
    {
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                if (number == matrix[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
    static void print_intersected_numbers_in_matrices(int matrix_01[3][3], int matrix_02[3][3], short rows, short colums)
    {
        int number = 0;
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                int number = matrix_01[i][j];
                if (is_number_in_matrix(matrix_02, number, 3, 3))
                {
                    cout << setw(2) << matrix_01[i][j] << "   ";
                }
            }
        }
    }
    static int matrix_max(int matrix[3][3], short rows, short colums)
    {
        int max = matrix[0][0];
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                if (max < matrix[i][j])
                {
                    max = matrix[i][j];
                }
            }
        }
        return max;
    }
    static int matrix_min(int matrix[3][3], short rows, short colums)
    {
        int min = matrix[0][0];
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums; j++)
            {
                if (min > matrix[i][j])
                {
                    min = matrix[i][j];
                }
            }
        }
        return min;
    }
    static bool is_palindrom_matrix(int matrix_01[3][3], short rows, short colums)
    {
        for (short i = 0; i < rows; i++)
        {
            for (short j = 0; j < colums / 2; j++)
            {
                // compare last number in matrix with the first number in each row
                // to the half colum
                if (matrix_01[i][j] != matrix_01[i][colums - j - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }

    static void fibonacci_series(short number)
    {
        int prev_01 = 0;
        int prev_02 = 1;
        int finbonacci_number = 0;
        cout << "1 ";
        for (short i = 2; i <= number; i++)
        {
            finbonacci_number = prev_01 + prev_02;
            cout << finbonacci_number << " ";

            prev_01 = prev_02;
            prev_02 = finbonacci_number;
        }
    }
    static void fibonacci_sries_recursion(short number, int prev_01, int prev_02)
    {

        int finbonacci_number = 0;

        if (number > 0)
        {
            finbonacci_number = prev_01 + prev_02;
            prev_02 = prev_01; // shift numbers
            prev_01 = finbonacci_number;

            cout << finbonacci_number << " "; // print

            fibonacci_sries_recursion(number - 1, prev_01, prev_02);
        }
    }
    static void print_string_first_letter(string phrase)
    {
        bool is_first_letter = true;
        for (short i = 0; i < phrase.length(); i++)
        {

            if (phrase[i] != ' ' && is_first_letter)
            {
                cout << phrase[i] << endl;
            }
            is_first_letter = (phrase[i] == ' ' ? true : false);
        }
    }
    void print_string_first_letter()
    {
        print_string_first_letter(_phrase);
    }
    static string lowercase_first_letter(string phrase)
    {
        bool is_first_letter = true;
        for (short i = 0; i < phrase.length(); i++)
        {
            if (phrase[i] != ' ' && is_first_letter)
            {
                phrase[i] = towupper(phrase[i]);
            }
            is_first_letter = (phrase[i] == ' ' ? true : false);
        }
        return phrase;
    }
    string lowercase_first_letter()
    {
        return lowercase_first_letter(_phrase);
    }
    static string all_capital_letters(string phrase)
    {
        for (short i = 0; i < phrase.length(); i++)
        {
            phrase[i] = toupper(phrase[i]);
        }
        return phrase;
    }
    string all_capital_letters()
    {
        return all_capital_letters(_phrase);
    }
    static string all_small_letters(string phrase)
    {
        for (short i = 0; i < phrase.length(); i++)
        {
            phrase[i] = tolower(phrase[i]);
        }
        return phrase;
    }
    string all_small_letters()
    {
        return all_small_letters(_phrase);
    }
    static char invert_charachter_case(char letter)
    {
        return (isupper(letter)) ? tolower(letter) : toupper(letter);
    }
    char invert_charachter_case()
    {
        return invert_charachter_case(_letter);
    }
    static string invert_all_character_case(string phrase)
    {
        string sentence = " ";
        for (short i = 0; i < phrase.length(); i++)
        {
            phrase[i] = invert_charachter_case(phrase[i]);
        }
        return phrase;
    }
    string invert_all_character_case()
    {
        return invert_all_character_case(_phrase);
    }
    enum en_what_to_count
    {
        small_letters = 0,
        capital_letters = 1,
        digits = 2,
        blanc = 3,
        all = 4
    };
    static short count_letter_and_digits(string phrase, en_what_to_count what_to_count = en_what_to_count::all)
    {
        if (what_to_count == en_what_to_count::all)
        {
            return phrase.length();
        }
        char blanc = ' ';
        short counter = 0;
        for (short i = 0; i < phrase.length(); i++)
        {
            if (what_to_count == en_what_to_count::small_letters && islower(phrase[i]))
            {
                counter++;
            }
            if (what_to_count == en_what_to_count::capital_letters && isupper(phrase[i]))
            {
                counter++;
            }
            if (what_to_count == en_what_to_count::digits && isdigit(phrase[i]))
            {
                counter++;
            }
            if (what_to_count == en_what_to_count::blanc && phrase[i] == blanc)
            {
                counter++;
            }
        }
        return counter;
    }
    static short count_small_letters(string phrase)
    {
        short counter = 0;
        for (short i = 0; i < phrase.length(); i++)
        {
            if (islower(phrase[i]))
            {
                counter++;
            }
        }
        return counter;
    }
    short count_small_letters()
    {
        return count_small_letters(_phrase);
    }
    static short count_capital_letters(string phrase)
    {
        short counter = 0;
        for (short i = 0; i < phrase.length(); i++)
        {
            if (isupper(phrase[i]))
            {
                counter++;
            }
        }
        return counter;
    }
    short count_capital_letters()
    {
        return count_capital_letters(_phrase);
    }
    static short count_digits(string phrase)
    {
        short counter = 0;
        for (short i = 0; i < phrase.length(); i++)
        {
            if (isdigit(phrase[i]))
            {
                counter++;
            }
        }
        return counter;
    }
    short count_digits()
    {
        return count_digits(_phrase);
    }
    static short count_blanc_space(string phrase)
    {
        short counter = 0;
        char blanc = ' ';
        for (short i = 0; i < phrase.length(); i++)
        {
            if (phrase[i] == blanc)
            {
                counter++;
            }
        }
        return counter;
    }
    short count_blanc_space()
    {
        return count_blanc_space(_phrase);
    }
    static short count_letter_in_string(string phrase, char letter)
    {
        short counter = 0;

        for (short i = 0; i < phrase.length(); i++)
        {
            if (phrase[i] == letter)
            {
                counter++;
            }
        }
        return counter;
    }
    short count_letter_in_string()
    {
        return count_letter_in_string(_phrase, _letter);
    }
    static short count_letter_in_string_case_sensetive(string phrase, char letter, bool match_case = true)
    {
        short counter = 0;
        for (short i = 0; i < phrase.length(); i++)
        {
            if (match_case)
            {
                if (phrase[i] == letter)
                {
                    counter++;
                }
            }

            else
            {
                if (tolower(phrase[i]) == tolower(letter))
                {
                    counter++;
                }
            }
        }
        return counter;
    }
    short count_letter_in_string_case_sensetive()
    {
        return count_letter_in_string_case_sensetive(_phrase, _letter);
    }
    static bool is_vowel(char letter)
    {
        letter = tolower(letter);
        return ((letter == 'a') || (letter == 'e') || (letter == 'o') || (letter == 'u') || (letter == 'i'));
    }
    bool is_vowel()
    {
        return is_vowel(_letter);
    }
    static int count_vowels_in_string(string phrase)
    {
        short counter = 0;
        for (short i = 0; i < phrase.length(); i++)
        {

            if (is_vowel(phrase[i]))
            {
                counter++;
            }
        }
        return counter;
    }
    int count_vowels_in_string()
    {
        return count_vowels_in_string(_phrase);
    }
    static void print_all_vowels_in_string(string phrase)
    {

        for (short i = 0; i < phrase.length(); i++)
        {
            if (is_vowel(phrase[i]))
            {
                cout << phrase[i] << " ";
            }
        }
    }
    void print_all_vowels_in_string()
    {
        print_all_vowels_in_string(_phrase);
    }
    static void print_each_word_in_string(string sentence)
    {
        string delimiter = " ";       // blanc space that we're search for
        short delimiter_position = 0; // intialize positon
        string word;                  // string variable that we'll store the word on
        while ((delimiter_position = sentence.find(delimiter)) != string::npos)
        {
            word = sentence.substr(0, delimiter_position); // store the word from 0 to blanc space position
            if (word != "")
            {
                cout << word << endl;
            }
            sentence.erase(0, delimiter_position + delimiter.length()); // erase the after print
        }
        if (sentence != "") // print the last word, because they are not a blanc space after it
        {
            cout << sentence << endl;
        }
    }
    void print_each_word_in_string()
    {
        print_each_word_in_string(_phrase);
    }
    static short count_words_in_string(string sentence)
    {
        string blanc_space = " "; // delimiter
        short position = 0;
        string word;
        short counter = 0;

        while ((position = sentence.find(blanc_space)) != string::npos)
        {
            word = sentence.substr(0, position);
            if (word != "")
            {
                counter++;
            }
            sentence.erase(0, position + blanc_space.length());
        }
        if (sentence != "")
        {
            counter++;
        }

        return counter;
    }
    short count_words_in_string()
    {
        return count_words_in_string(_phrase);
    }
    static vector<string> split_word_in_vector(string sentence, string blanc_space = " ")
    {
        vector<string> v_string;
        short position = 0;
        string word;

        while ((position = sentence.find(blanc_space)) != string::npos)
        {
            word = sentence.substr(0, position);
            if (word != "")
            {
                v_string.push_back(word);
            }
            sentence.erase(0, position + blanc_space.length());
        }
        if (sentence != "")
        {
            v_string.push_back(sentence);
        }

        return v_string;
    }
    vector<string> split_word_in_vector()
    {
        return split_word_in_vector(_phrase);
    }
    static string trim_string_left(string sentence)
    {
        for (short i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] != ' ')
            {
                return sentence.substr(i, sentence.length() - i);
            }
        }
        return "";
    }
    string trim_string_left()
    {
        return trim_string_left(_phrase);
    }
    static string trim_string_right(string sentence)
    {
        for (short i = sentence.length() - 1; i >= 0; i--)
        {
            if (sentence[i] != ' ')
            {
                return sentence.substr(0, i + 1);
            }
        }
        return "";
    }
    string trim_string_right()
    {
        return trim_string_right(_phrase);
    }
    static string trim_string_left_right(string sentence)
    {
        return trim_string_left(trim_string_right(sentence));
    }
    string trim_string_left_right()
    {
        return trim_string_left_right(_phrase);
    }
    static string join_word_in_vector(vector<string> &sentence, string delimiter)
    {
        string word = "";

        for (string &words : sentence)
        {
            word = word + words + delimiter;
        }

        return word.substr(0, word.length() - delimiter.length());
    }
    static string join_word_in_vector(string array[], string delimiter, short length)
    {
        string word = "";

        for (short i = 0; i < length; i++)
        {
            word = word + array[i] + delimiter;
        }

        return word.substr(0, word.length() - delimiter.length());
    }
    static string reverve_string(string sentence)
    {
        vector<string> v_sentence = split_word_in_vector(sentence, " ");
        string new_string = "";

        vector<string>::iterator iter = v_sentence.end();
        while (iter != v_sentence.begin())
        {
            --iter;
            new_string += *iter + " ";
        }

        new_string = new_string.substr(0, new_string.length() - 1);

        return new_string;
    }
    string reverve_string()
    {
        return reverve_string(_phrase);
    }
    static string replace_word_in_string(string sentence, string word_to_replace, string replace_word)
    {
        short position = sentence.find(word_to_replace); // find word
        while (position != string::npos)
        {
            sentence = sentence.replace(position, word_to_replace.length(), replace_word);
            position = sentence.find(word_to_replace); // find word again
        }

        return sentence;
    }
    static string replace_word_in_string(string sentence, string word_to_replace, string replace_word, bool match_case = true)
    {
        vector<string> v_sentence = split_word_in_vector(sentence, " ");

        for (string &v_string : v_sentence)
        {
            if (match_case)
            {
                if (v_string == word_to_replace)
                {
                    v_string = replace_word;
                }
            }
            else
            {
                if (all_small_letters(v_string) == all_small_letters(word_to_replace))
                {
                    v_string = replace_word;
                }
            }
        }
        return join_word_in_vector(v_sentence, " ");
    }
    static string remove_punct_from_string(string sentence)
    {
        string string_02 = "";
        for (short i = 0; i < sentence.length(); i++)
        {
            if (!ispunct(sentence[i]))
            {
                string_02 += sentence[i];
            }
        }
        return string_02;
    }
    string remove_punct_from_string()
    {
        return remove_punct_from_string(_phrase);
    }

    static string converting_number_to_letter(int number)
    {
        if (number == 0)
        {
            return "";
        }
        if (number >= 1 && number <= 19)
        {
            string array[] = {
                "",
                "one",
                "two",
                "three",
                "four",
                "five",
                "six",
                "seven",
                "eight",
                "nine",
                "ten",
                "eleven",
                "tweleve",
                "thirteen",
                "fourteen",
                "fifteen",
                "sixteen",
                "seventeen",
                "eighteen",
                "nineteen",
            };
            return array[number] + " ";
        }
        if (number >= 20 && number <= 99)
        {
            string array[] = {"",
                              "",
                              "twenty",
                              "thirry",
                              "fourty",
                              "fifty",
                              "sixty",
                              "seventy",
                              "eight",
                              "ninety"};
            return array[number / 10] + " " + converting_number_to_letter(number % 10);
        }
        if (number >= 100 && number <= 199)
        {
            return "One hundred " + converting_number_to_letter(number % 100);
        }
        if (number >= 200 && number <= 999)
        {
            return converting_number_to_letter(number / 100) + "Hundred " + converting_number_to_letter(number % 100);
        }
        if (number >= 1000 && number <= 1999)
        {
            return "One thousand " + converting_number_to_letter(number % 1000);
        }
        if (number >= 2000 && number <= 999999)
        {
            return converting_number_to_letter(number / 1000) + "Thousand " + converting_number_to_letter(number % 1000);
        }
        if (number >= 1000000 && number <= 1999999)
        {
            return "One million " + converting_number_to_letter(number % 1000000);
        }
        if (number >= 2000000 && number <= 999999999)
        {
            return converting_number_to_letter(number / 1000000) + "Million " + converting_number_to_letter(number % 1000000);
        }
        if (number >= 1000000000 && number <= 1999999999)
        {
            return "One billion" + converting_number_to_letter(number % 1000000000);
        }
        else
        {
            return converting_number_to_letter(number / 1000000000) + "Billions " + converting_number_to_letter(number % 1000000000);
        }
    }
};