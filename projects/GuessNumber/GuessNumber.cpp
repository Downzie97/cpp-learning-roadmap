// GuessNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

const int difficultySettings[4][3] = {{1,1,20},
                                      {2,1,100},
                                      {3,1,200},
                                      {4,1,500}};

const int attemptsSettings[4][2] = {{1,25},
                                    {2,10},
                                    {3,5}};

std::vector<std::vector<int>>leaderboard; // name , attempt, score


void initialScreen(int &userDifficulty, int &userAttempts)
{

    std::cout << "Please enter difficulty..." << std::endl;
    std::cout << "1 - Beginner (" << difficultySettings[0][1] << " - " << difficultySettings[0][2] << ")" << std::endl;
    std::cout << "2 - Normal (" << difficultySettings[1][1] << " - " << difficultySettings[1][2] << ")" << std::endl;
    std::cout << "3 - Hard (" << difficultySettings[2][1] << " - " << difficultySettings[2][2] << ")" << std::endl;
    std::cout << "4 - Very Hard (" << difficultySettings[3][1] << " - " << difficultySettings[3][2] << ")" << std::endl;
    std::cout << "" << std::endl;

    std::cin >> userDifficulty;

    
    std::cout << "You chose difficulty level " << userDifficulty << std::endl;
    std::cout << "Please choose the amount of allowable attempts:" << std::endl;

    std::cout << "1 - " << attemptsSettings[0][1]<< " attempts" << std::endl;
    std::cout << "2 - " << attemptsSettings[1][1] << " attempts" << std::endl;
    std::cout << "3 - " << attemptsSettings[2][1] << " attempts" << std::endl;
    std::cout << "" << std::endl;

    std::cin >> userAttempts;
}

int calculateScore(int guesses, int difficulty)
{
    //Gives a maximum score of 100 for a single guess at maximum diificulty
    return std::max(0, (26 - guesses) * difficulty);
}

void displayLeaderboard()
{
    std::cout << "Leaderboard:" << std::endl <<  std::endl;
    std::cout << "Attempt Number        " << "Score" << std::endl;
    for (int i = 0; i < leaderboard.size(); i++)
    {
        if (leaderboard[i][0] < 10)
        {
            std::cout << leaderboard[i][0] << "                     " << leaderboard[i][1] << std::endl;
        }
        else if (leaderboard[i][0] < 100)
        {
            std::cout << leaderboard[i][0] << "                    " << leaderboard[i][1] << std::endl;
        }
        else
        {
            std::cout << leaderboard[i][0] << "                   " << leaderboard[i][1] << std::endl;
        }
    }
}

int main()
{

    bool replay = true;
    char replaychoice = 0;
    int playTimes = 0;
    int score;

    while (replay == true)
    {
        int userInput = 0;
        int generatednumber = 0;
        int guessSettings = 0;
        int maxNoOfGuesses = 0;
        int numberofGuesses = 0;
        int numberRange = 0;
        int lowerRange = 0;
        int upperRange = 0;
        
        srand(time(0));
        initialScreen(numberRange, guessSettings);

        playTimes++;

        if (replaychoice != '\n')
        {

            for (int i = 0; i < (sizeof(difficultySettings) / sizeof(difficultySettings[0])); i++)
            {
                if (difficultySettings[i][0] == numberRange)
                {
                    lowerRange = difficultySettings[i][1];
                    upperRange = difficultySettings[i][2];
                    break;
                }
            }

            for (int i = 0; i < (sizeof(attemptsSettings) / sizeof(attemptsSettings[0])); i++)
            {
                if (attemptsSettings[i][0] == guessSettings)
                {
                    maxNoOfGuesses = attemptsSettings[i][1];
                    break;
                }
            }
        }

        std::cout << "Guess my number!" << std::endl;
    

        generatednumber = rand() % (upperRange - lowerRange + 1) + lowerRange;

        while ((userInput != generatednumber) && numberofGuesses < maxNoOfGuesses)
        {
            std::cin >> userInput;

            if (userInput != generatednumber)
            {
                std::cout << "Wrong number! ";

                if (userInput < lowerRange)
                {
                    std::cout << "Value outside of Range. Should be above " << lowerRange << std::endl;
                }
                else if (userInput > upperRange)
                {
                    std::cout << "Value outside of Range. Should be below " << upperRange << std::endl;
                }
                else if (userInput > generatednumber)
                {
                    std::cout << "Value too High" << std::endl;
                }
                else if (userInput < generatednumber)
                {
                    std::cout << "Value too Low" << std::endl;
                }

            }
            numberofGuesses += 1;
        }

        if ((userInput != generatednumber) && numberofGuesses >= maxNoOfGuesses)
        {
            std::cout << "You are out of guesses! Better luck next time! " << std::endl << std::endl; 
        }
        else if (userInput == generatednumber && numberofGuesses <= maxNoOfGuesses)
        {
            score = calculateScore(numberofGuesses, numberRange);
            std::cout << "Congrats you completed it in " << numberofGuesses << " guesses!" << std::endl;
            std::cout << "Your score is: " << score << " out of 100" << std::endl << std::endl;
            leaderboard.push_back({playTimes, score });
        }

        std::cout << "Would you like to play again? If yes select 1 if no select 0" << std::endl;
        std::cout << "To replay with previous settings press enter" << std::endl;

        std::cin.ignore();
        std::cin.get(replaychoice);


        if (replaychoice == '\n')
        {
            if (userInput == generatednumber) { displayLeaderboard();}
            std::cout << "Restarting...." << std::endl;
            replay = true;
        }
        else if (replaychoice == '1')
        {
            if (userInput == generatednumber) {displayLeaderboard(); }
            std::cout << "Restarting...." << std::endl;
            replay = true;
        }
        else 
        {
            replay = false;
        }
    }
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
