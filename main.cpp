#include <iostream>
#include <vector>
#include <numeric> // So we can use accumulate formula for mean 

using namespace std; 

int main () {
    
    vector<int> numbers {}; // List of numbers
    char selection {}; // Characters inputted
    
    int add_number {}; // Adding numbers to the list
    int total_numbers {}; // total value of numbers added together in the list
    int amount_numbers {}; // Works out how many numbers are situated in the list
    int smallest_number {};
    int largest_number {};
    int remove_number {}; // Element user would like to remove from the list
    int item {};  // Element the user would like to search for in the list
    
    do {
      cout << "\n========== Menu ==========" << endl; 
      cout << "P - Print Numbers" << endl;
      cout << "A - Add Number" << endl; 
      cout << "M - Display mean of number" << endl; 
      cout << "S - Display smallest number" << endl; 
      cout << "L - Display largest number" << endl; 
      cout << "F - Find a number" << endl; 
      cout << "C - Clear the list" << endl; 
      cout << "O - Sort the list in order from smallest to largest" << endl; 
      cout << "D - Sort the list in order from largest to smallest" << endl; 
      cout << "R - Remove a number from the list" << endl; 
      cout << "T - Find out the total amount of numbers added together in the list" << endl; 
      cout << "Q - Quit" << endl; 
      
      cout << "\nEnter a selection: ";
      cin >> selection; 
      
      if (selection == 'P' || selection == 'p') {
          if (numbers.size() == 0) 
              cout << "\n[] - the list is empty" << endl; 
          else {
            cout << "\n[ ";
               for (int i {0}; i < numbers.size(); i++) {
                   cout << numbers[i] << " ";
               }
            cout << "]" << endl; 
          }
      }
      else if (selection == 'A' || selection == 'a') {
            cout << "Please enter a number you'd like to add to the list: ";
            cin >> add_number; 
            if ( find(numbers.begin(), numbers.end(), add_number) != numbers.end() ) {
               cout << "\nYou can't enter the same number twice!" << endl;
            }
            else {
               numbers.push_back(add_number);
               cout << "\nYour number has been added to the list!" << endl;
            }
      }
      else if (selection == 'M' || selection == 'm') {
            if (numbers.size() == 0) {
               cout << "\nCan't calculate - no data" << endl; 
            }
            else {
               total_numbers = accumulate(numbers.begin(), numbers.end(), 0);
               amount_numbers = numbers.size();
               cout << "\nThe mean of the numbers in the list is: " << static_cast<double>(total_numbers) / amount_numbers << endl;
            }
      }
      else if (selection == 'S' || selection == 's') {
            if (numbers.size() == 0) {
               cout << "\nCan't calculate - no data" << endl; 
            }
            else {
            smallest_number = *min_element(numbers.begin(), numbers.end());
            cout << "\nThe smallest number in the list is: " << smallest_number << endl;
            }
      }
      else if (selection == 'L' || selection == 'l') {
            if (numbers.size() == 0) {
               cout << "\nCan't calculate - no data" << endl; 
            }
            else {
            largest_number = *max_element(numbers.begin(), numbers.end());
            cout << "\nThe largest number in the list is: " << largest_number << endl;
            }
      }
      else if (selection == 'F' || selection == 'f') {
            cout << "Enter a number you'd like to search for: ";
            cin >> item; 
            if (find(numbers.begin(), numbers.end(), item) != numbers.end()) { // Finds if the number is in the list
               cout << "\nYour number is in the list " 
                    << count(numbers.begin(), numbers.end(), item) // Counts how many times the number is in the list
                    << " times" << endl;
            }
            else {
               cout << "\nYour number is not in the list" << endl; 
            }
      }
      else if (selection == 'C' || selection == 'c') {
            if (numbers.size() == 0) {
               cout << "\nThere are no numbers already in the list" << endl; 
            }
            else {
               numbers.clear();
               cout << "\nYou've cleared the list" << endl; 
            }
      }
      else if (selection == 'O' || selection == 'o') {
            if (numbers.size() == 0 || numbers.size() == 1) {
               cout << "\nThere is not enough data in the list to sort" << endl; 
            } 
            else {
               sort(numbers.begin(), numbers.end());
               cout << "\nThe list has been sorted from smallest to largest" << endl; 
            }
      }
      else if (selection == 'D' || selection == 'd') {
            if (numbers.size() == 0 || numbers.size() == 1) {
               cout << "\nThere is not enough data in the list to sort" << endl; 
            } 
            else {
               sort (numbers.begin(), numbers.end(), greater<int>() );
               cout << "\nThe list has been sorted from largest to smallest" << endl; 
            }
      }
      else if (selection == 'R' || selection == 'r') {
            if (numbers.size() == 0) {
               cout << "\nThere is no data in the list to erase" << endl; 
            } 
            else {
               cout << "Please enter a number you would like to erase from the list: ";
               cin >> remove_number; 
               for (int i = 0; i< numbers.size(); i++) {
                   if (numbers[i] == remove_number) {
                   numbers.erase(numbers.begin() + i);
                   i--;
                   }
               } 
            }
      }
      else if (selection == 'T' || selection == 't') {
            if (numbers.size() == 0) {
               cout << "\nThere is no data in the list to calculate" << endl;
            } 
            else {
               total_numbers = accumulate(numbers.begin(), numbers.end(), 0);
               cout << "\nThe total amount is: " << total_numbers << endl; 
            }
      }
      else if (selection == 'Q' || selection == 'q')
            cout << "\nMenu exited" << endl; 
      else 
            cout << "\nError, please select a correct part of the menu" << endl; 
    
      
    } while (selection != 'Q' && selection != 'q');
    
  cout << endl;  
  return 0;   
} 

