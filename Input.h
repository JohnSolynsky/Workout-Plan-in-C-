#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief Generic input function to read and validate user input within a specified range.
 *
 * This template function reads input from the user, validates if it is a valid numeric value,
 * and checks if it falls within the specified range.
 *
 * @tparam T The type of the input value (e.g., int, float, double).
 * @param min The minimum allowed value for the input.
 * @param max The maximum allowed value for the input.
 * @param arg A string argument for providing a predefined input (optional).
 * @return The validated user input within the specified range or -1 if input is invalid.
 */
template <typename T>
T input(int min, int max, string arg = "")
{
    string temp;
    T ch;
    ostringstream oss;

    if (arg == "")
        getline(cin, temp);
    else
        temp = arg;

    try {
        ch = stof(temp);
        oss << ch;
        string temp2 = oss.str();

        if (temp != temp2)
            throw 100;
        else if (ch < min || ch > max)
            throw 200;
    }
    catch (out_of_range)
    {
        return -1;
    }
    catch (invalid_argument)
    {
        return -1;
    }
    catch (int)
    {
        return -1;
    }

    return ch;
}