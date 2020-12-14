#include "std_lib_facilities.hpp"
#include <cstdio>
#include <ctime>
#include <cstdlib>

int main()
{
    vector<string> game;
    game.push_back("rock");
    game.push_back("paper");
    game.push_back("scissors");
    string answer;
    string computer_answer;
    int user_point = 0;
    int computer_point = 0;

    cout << "Enter rock, paper or scissors (if you want quit the game please press Ctrl + D (Linux) or Ctrl + Z (Windows)): \n";
    while( cin >> answer ){
    if((answer == "rock") || (answer == "paper") || (answer == "scissors"))
    {
    srand(time(NULL));
    int x = rand()%3;

    switch(x)
    {
        case 0: cout << "Computer: " << game[0] << "\n";
                computer_answer = game[0];
        break;

        case 1: cout << "Computer: " << game[1] << "\n";
                computer_answer = game[1];
        break;

        case 2: cout << "Computer: " << game[2] << "\n";
                computer_answer = game[2];
        break;

    }
    if(answer == computer_answer)
    {
        cout << "score: draw \n";
    }
    if(answer == "rock" &&  computer_answer == "paper")
    {
        cout << "score: Computer WIN \n";
        computer_point++;
    }
    if(answer == "rock" && computer_answer == "scissors")
    {
        cout << "score: You Win \n";
        user_point++;
    }
    if(answer == "paper" && computer_answer == "rock")
    {
        cout << "score: You Win \n";
        user_point++;
    }
    if(answer == "paper" && computer_answer == "scissors")
    {
        cout << "score: Computer Win \n";
        computer_point++;
    }
    if(answer == "scissors" && computer_answer == "paper")
    {
        cout << "score: You Win \n";
        user_point++;
    }
    if(answer == "scissors" && computer_answer == "rock")
    {
        cout << "score: Computer Win \n";
        computer_point++;
    }
    }
    else
    {
        cout << "Bledna odpowiedz \n";
    }
    }

    cout << "Your score " << user_point << " : " << computer_point << " Computer score";
    return 0;
}
//04.03.2020
//Kamil Petk
