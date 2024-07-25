#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cls_string
{
private:
    string _value;

public:
    // constructors
    cls_string()
    {
        _value = "";
    }
    cls_string(string value)
    {
        _value = value;
    }

    // set and get properties
    void set_value(string value)
    {
        _value = value;
    }
    string get_value()
    {
        return _value;
    }

    // __declspec(property(get = get_value, put = set_value)) string value;

    // methods
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
        print_string_first_letter(_value);
    }

    static string uppercase_first_letter(string phrase)
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
    void uppercase_first_letter()
    {
        _value = uppercase_first_letter(_value);
    }

    static string lowercase_first_letter(string phrase)
    {
        bool is_first_letter = true;

        for (short i = 0; i < phrase.length(); i++)
        {
            if (phrase[i] != ' ' && is_first_letter)
            {
                phrase[i] = tolower(phrase[i]);
            }
            is_first_letter = (phrase[i] == ' ' ? true : false);
        }
        return phrase;
    }
    void lowercase_first_letter()
    {
        _value = lowercase_first_letter(_value);
    }

    static string all_capital_letters(string phrase)
    {
        for (short i = 0; i < phrase.length(); i++)
        {
            phrase[i] = toupper(phrase[i]);
        }
        return phrase;
    }
    void all_capital_letters()
    {
        _value = all_capital_letters(_value);
    }

    static string all_small_letters(string phrase)
    {
        for (short i = 0; i < phrase.length(); i++)
        {
            phrase[i] = tolower(phrase[i]);
        }
        return phrase;
    }
    void all_small_letters()
    {
        _value = all_small_letters(_value);
    }

    static char invert_charachter_case(char letter)
    {
        return (isupper(letter)) ? tolower(letter) : toupper(letter);
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
    void invert_all_character_case()
    {
        _value = invert_all_character_case(_value);
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
        return count_small_letters(_value);
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
        return count_capital_letters(_value);
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
        return count_digits(_value);
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
        return count_blanc_space(_value);
    }

    static short count_letter_case_sensetive(string phrase, char letter, bool match_case = true)
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

    static bool is_vowel(char letter)
    {
        letter = tolower(letter);
        return ((letter == 'a') || (letter == 'e') || (letter == 'o') || (letter == 'u') || (letter == 'i'));
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
        return count_vowels_in_string(_value);
    }

    static void print_all_vowels_in_string(string word)
    {

        for (short i = 0; i < word.length(); i++)
        {
            if (is_vowel(word[i]))
            {
                cout << word[i] << " ";
            }
        }
    }
    void print_all_vowels_in_string()
    {
        print_all_vowels_in_string(_value);
    }

    static void print_each_word_in_string(string sentence)
    {
        string blanc_space = " "; // blanc space that we're search for
        short position = 0;       // intialize positon
        string word;              // string variable that we'll store the word on
        while ((position = sentence.find(blanc_space)) != string::npos)
        {
            word = sentence.substr(0, position); // store the word from 0 to blanc space position
            if (word != "")
            {
                cout << word << endl;
            }
            sentence.erase(0, position + blanc_space.length()); // erase the after print
        }
        if (sentence != "") // print the last word, because they are not a blanc space after it
        {
            cout << sentence << endl;
        }
    }
    void print_each_word_in_string()
    {
        print_each_word_in_string(_value);
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
        return count_words_in_string(_value);
    }

    static vector<string> split(string sentence, string blanc_space = " ")
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
        return split(_value, _value);
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
    void trim_string_left()
    {
        _value = trim_string_left(_value);
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
    void trim_string_right()
    {
        _value = trim_string_right(_value);
    }

    static string trim_string_left_right(string sentence)
    {
        return trim_string_left(trim_string_right(sentence));
    }
    void trim_string_left_right()
    {
        _value = trim_string_left_right(_value);
    }

    static string join_word_in_vector(vector<string> &sentence, string delimiter = " ")
    {
        string word = "";

        for (string &words : sentence)
        {
            word = word + words + delimiter;
        }

        return word.substr(0, word.length() - delimiter.length());
    }
    
    string join_word_in_vector(string array[], string delimiter, short length)
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
        vector<string> v_sentence = split(sentence, " ");
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
    void reverve_string()
    {
        _value = reverve_string(_value);
    }

    static string replace_word_in_string_case_sensetive(string sentence, string word_to_replace, string replace_word)
    {
        short position = sentence.find(word_to_replace);
        while (position != string::npos)
        {
            sentence = sentence.replace(position, word_to_replace.length(), replace_word);
            position = sentence.find(word_to_replace);
        }

        return sentence;
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
    void remove_punct_from_string()
    {
        _value = remove_punct_from_string(_value);
    }

    static string replace_word_in_string(string sentence, string word_to_replace, string replace_word, bool match_case = true)
    {
        vector<string> v_sentence = split(sentence, " ");

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

    // destructor
    ~cls_string()
    {
    }
};