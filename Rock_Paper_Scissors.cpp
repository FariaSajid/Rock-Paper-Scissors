#include<iostream>
#include<cstdlib>  // For rand() and srand()
#include<ctime>    // For time()
using namespace std;
int main(){
    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    string choices[3] = {"Rock", "Paper", "Scissors"};
    char playAgain;
    // Seed the random number generator only once
    srand(time(0));
    cout << "\n|| Welcome to Rock, Paper, Scissors Game ||" <<endl;
    do{
        cout << "\nMake your move:" <<endl;
        cout << "0: Rock\n1: Paper\n2: Scissors" <<endl;
        cout << "Enter your choice (0, 1, or 2): ";
        cin >> userChoice;
        if(userChoice<0 || userChoice>2){
            cout << "Invalid choice! Try again" <<endl;
            continue;  
        }
        // Generate computer choice
        computerChoice = rand() % 3;
        cout << "You chose: " <<choices[userChoice] <<endl;
        cout << "Computer chose: " <<choices[computerChoice] <<endl;
        if(userChoice == computerChoice){
            cout << "Result: It's a draw!" <<endl;
        }else if((userChoice == 0 && computerChoice == 2) ||
                 (userChoice == 1 && computerChoice == 0) ||
                 (userChoice == 2 && computerChoice == 1)){
            cout << "Result: You win this round!" <<endl;
            userScore++;
        }else{
            cout << "Result: Computer wins this round!" <<endl;
            computerScore++;
        }
        cout << "Score => You: " <<userScore << " | Computer: " <<computerScore <<endl;
        cout << "\nDo you want to play another round? (y/n): ";
        cin >> playAgain;
    }while(playAgain=='y' || playAgain=='Y');
    cout << "\n|| Game Over! Final Score ||" <<endl;
    cout << "You: " <<userScore << " | Computer: " <<computerScore <<endl;
    if(userScore>computerScore){
        cout << "~ Congratulations! You won the game! ~" <<endl;
    }else if(userScore<computerScore){
        cout << "~ Computer won the game. Better luck next time! ~" <<endl;
    }else{
        cout << "~ It's a tie game! ~" <<endl;
    }
    return 0;
}
