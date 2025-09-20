// Learncpp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>


// Checks the values range
int valueCheck( std::string startOrEnd, int limit)
{
    int userInput = 0;

    std::cout << "Please enter positive non-zero " << startOrEnd << " value " << (startOrEnd == "start" ? "more than " : "less than ") << limit << std::endl;

    std::cin >> userInput;

    // Does not proceed unless user adds value in range
    while (userInput <= 0)
    { 
        std::cout << "The value is Negative. Please enter a positive non-zero " << startOrEnd << " value: " << std::endl;

        std::cin >> userInput;
    }

    while ((startOrEnd == "start" && userInput < limit) || (startOrEnd == "end" && userInput > limit))
    {
        std::cout << "The value is out of range. Please enter a value in the range: " << std::endl;

        std::cin >> userInput;
    }

    return userInput;
}

//Calculates whether value is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Calculates variance of value set
float variance(std::vector<int> inputValue, int sum)
{
    float avdiff = 0;
    float sumofdifferences = 0;

    // Calculate the difference between each data point and the sample mean


    avdiff = (float) sum / inputValue.size();

    for (int diff : inputValue)
    {
        sumofdifferences += ((diff - avdiff) * (diff - avdiff));
    }

    return (sumofdifferences / (inputValue.size() - 1));
}


int main()
{
    int tempUserInputStart = 0;
    int tempUserInputEnd = 0;
    int userInputStart = 0;
    int userInputEnd = 0;
    int sum = 0;


    const int lowerLimit = 1;
    const int upperLimit = 20;
    
    int range;

    float Average = 0;
    float median = 0;
    float varianceofvalues = 0;

    std::vector<int> holdValues;

    tempUserInputStart = valueCheck("start", lowerLimit);
    tempUserInputEnd = valueCheck("end", upperLimit);

    if (tempUserInputStart > tempUserInputEnd)
    {
        userInputStart = tempUserInputEnd;
        userInputEnd = tempUserInputStart;
    }
    else
    {
        userInputStart = tempUserInputStart;
        userInputEnd = tempUserInputEnd;
    }

    std::cout << "All numbers from " << userInputStart << " to " << userInputEnd << ": ";

    range = userInputEnd - userInputStart + 1;
    std::cout << range << std::endl;

    for (int i = userInputStart; i <= userInputEnd; i++)
    { 
        holdValues.push_back(i);
        std::cout << i;
        if (i != userInputEnd) { std::cout << ", ";}
        sum += i;

        if ((range % 2 == 0))
        {
            int mid1 = holdValues[range / 2 - 1];
            int mid2 = holdValues[range / 2];
            median = (mid1 + mid2) / 2.0f;
        }
        else if ((range % 2 == 1) && i == (range / 2) + 1)
        {
            median = i;
        }
        else
        {
            continue;
        }
    }    
    varianceofvalues = variance(holdValues, sum);

    std::cout << std::endl << "The Variance is: " << varianceofvalues << std::endl;
    std::cout << "The Standard Deviation is: " << sqrt(varianceofvalues) << std::endl;

    std::cout << "The Minimum value is " << userInputStart << " and the max value is " << userInputEnd << std::endl;
    Average = static_cast<float> (sum) / range;

    std::cout << "\nThe Sum is: " << sum << std::endl;
    std::cout << "The Average is: " << Average << std::endl;
    std::cout << "Median number is: " << median << std::endl;

    
    if (sum % 2 == 0)
    {
        std::cout << "Sum is even." << std::endl;
    }
    else
    {
        std::cout << "Sum is odd." << std::endl;
    }

    if (isPrime(sum))
        std::cout << "The sum IS a prime number." << std::endl;
    else
        std::cout << "The sum IS NOT a prime number." << std::endl;

    
}




