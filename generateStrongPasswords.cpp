/*IMPORTANT NOTES:-
1.#include <cstdlib> → unlocks rand() and srand()
2.#include <ctime> → gives you time(0) to make each run unique
3.srand(time(0)) - you're seeding the randomness with the current time (which is always changing), so rand() gives you a new sequence every time you run your program. It’s like reshuffling a deck before each game.
4.rand() gives a big number (like 483924) - % charLength limits it to the range [0, charLength-1]. Because rand() gives different numbers (thanks to srand(time(0))), you get a new combo of characters every time → new password each run.
*/



#include<iostream>
#include<cstdlib> 
#include<ctime> 
#include<string>
using namespace std;

//ANSII color codes
#define RESET  "\033[0m" // for setting it to default color each time
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"

string getPassword( int length){
    string Password = "";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string allChars = lowercase + uppercase + digits;

    srand(time(0)); // New shuffle every time the program runs

  //Guarantee at least one of each type
  Password += lowercase[rand() % lowercase.length()];
  Password += uppercase[rand() % uppercase.length()];
  Password += digits[rand() % digits.length()];

  //fill the rest randomly
  for(int i = 3 ; i< length ; i++){
    Password += allChars[rand() % allChars.length()];
  }
    return Password;
}
string getStrength(int length){
    if(length < 5) 
      return string(RED) + "Very Weak !!" + RESET;
    else if(length < 7 ) 
      return string(YELLOW) + "Weak !" + RESET;
    else if(length < 9) 
      return string(YELLOW) + "Moderate -" + RESET;
    else if(length < 12) 
      return string(GREEN) + "Strong !" + RESET;
    else 
      return string(CYAN) + "Very Strong !!" + RESET;

}
int main(){
    int length;
    cout << "Enter password length ::  ";
    cin >> length;
    if(length < 3){
        cout <<  " X " << "Password must be at least 3 characters to include lowercase, uppercase, and digit." << endl;
    } 
    else {
        string password = getPassword(length);
        string strength = getStrength(length);
    
    cout << " * " << "Generated Password: " << password << endl;
    cout << " || " << "Strength: " << strength << endl;
    }
    return 0;
}

