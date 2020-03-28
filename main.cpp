#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// ======= Function Prototypes ======= // 

void display_menu();
char selection_to_upper(char &c);
void print_list (const vector<double> &v);
void add_number (vector<double> &v);
void calculate_mean(const vector<double> &v);
void find_smallest_number(const vector<double> &v);
void find_largest_number(const vector<double> &v);
void smallest_to_largest(vector<double> &v);
void largest_to_smallest(vector<double> &v);
void total_amount(const vector<double> &v);
void find_a_number(const vector<double> &v);
void remove_a_number(vector<double> &v);
void delete_list(vector<double> &v);
void username_login();
void password_login();

// ======= Main Function ======= // 

int main() {

    vector<double> numbers {};
    char selection {};
    
    // Login to menu
    username_login();
    password_login();
    cout << "\nPermission Granted:" << endl;
    
    do {
        
        display_menu();
        
        cin >> selection;
        selection_to_upper(selection);
        
        if (selection == 'P') 
            print_list(numbers);
        else if (selection == 'A') 
            add_number(numbers);
        else if (selection == 'M') 
           calculate_mean(numbers);
        else if (selection == 'S') 
           find_smallest_number(numbers);
        else if (selection == 'L') 
           find_largest_number(numbers);
        else if (selection == 'O') 
           smallest_to_largest(numbers);
        else if (selection == 'Z') 
           largest_to_smallest(numbers);
        else if (selection == 'T') 
           total_amount(numbers);
        else if (selection == 'F') 
           find_a_number(numbers);
        else if (selection == 'R') 
           remove_a_number(numbers);
        else if (selection == 'D') 
           delete_list(numbers);
        else if (selection == 'Q') 
            cout << "Goodbye" << endl;
        else 
            cout << "Unknown selection, please try again" << endl;
    } while (selection != 'Q');

    cout  << endl;
    return 0;
}

// ======= Function Definitions ======= // 

// Username log in
void username_login() {
    string key_username {"cerisilv123"};
    string username_entered {};
    cout << "Please enter a username: ";
    getline(cin,username_entered);
    if (username_entered == key_username) // Recursive Function - will use more memory as popping off the stack
        return;
    else 
        username_login();
}

// Password log in 
void password_login() {
    string key_password {"123"};
    string password_entered {};
    cout << "Please enter a password: "; 
    getline(cin,password_entered);
    if (password_entered == key_password) // Recursive Function - will use more memory as popping off the stack
        return;
    else
        password_login();
}

// Display Menu
void display_menu() {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "O - Sort the list from smallest to largest" << endl;
    cout << "Z - Sort the list from largest to smallest" << endl; 
    cout << "F - Find a number in the list" << endl; 
    cout << "T - Find out the total amount of numbers added together" << endl;
    cout << "R - Remove a number" << endl; 
    cout << "D - Delete list" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

// Turn selection to uppercase and return
char selection_to_upper(char &c) {
    c = toupper(c);
    return c;
}

// Print list
void print_list (const vector<double> &v) { // Const - this function shouldn't make changes to the vector
      if (v.size() == 0)
          cout << "[] - the list is empty" << endl;
      else {
          cout << "[ ";
          for (auto num: v)
                  cout << num << " ";
          cout << "]" << endl;
          return; 
      }
}

// Add number 
void add_number (vector<double> &v) {
       double num_to_add {};
       cout << "Enter an integer to add to the list: ";
       cin >> num_to_add;
       v.push_back(num_to_add);
       cout << num_to_add << " added" << endl;
}

// Calculate mean 
void calculate_mean(const vector<double> &v) {
       if (v.size() == 0)
           cout << "Unable to calculate mean - no data" << endl;
       else {
           double total {};
           for (auto num: v)
                total += num;
           cout << "The mean is : " << static_cast<double>(total)/v.size() << endl;
       } 
}

// Find smallest number
void find_smallest_number(const vector<double> &v) {
      if (v.size() == 0) 
          cout << "Unable to determine the smallest - list is empty" << endl;
      else {
          double smallest = v.at(0);
          for (auto num: v)
              if (num < smallest)
                  smallest = num;
              cout << "The smallest number is: " << smallest << endl;
      }
}

// Find largest number
void find_largest_number(const vector<double> &v) {
     if (v.size() == 0)
                cout << "Unable to determine largest - list is empty"<< endl;   
     else {
         double largest = v.at(0);
         for (auto num: v)
             if (num > largest)
                 largest = num;
             cout << "The largest number is: " << largest << endl;
     }
}

// Delete List
void delete_list(vector<double> &v) {
     v.clear();
     cout << "The list is now empty" << endl; 
}

// Sorting the list smallest - largest
void smallest_to_largest(vector<double> &v) {
    sort (v.begin(), v.end());
    cout << "The array is now sorted from smallest to largest" << endl; 
}

// Sorting the list largest - smallest
void largest_to_smallest(vector<double> &v) {
    sort(v.begin(), v.end(), greater<double>());
    cout << "The array is now sorted from largest to smallest" << endl;
}

// Finding a number in the list & how many times
void find_a_number(const vector<double> &v) {
    cout << "Enter a number you'd like to search for: ";
    double item {};
    cin >> item; 
    if (find(v.begin(), v.end(), item) != v.end()) { // Finds if the number is in the list
        cout << "\nYour number is in the list " 
             << count(v.begin(), v.end(), item) // Counts how many times the number is in the list
             << " times" << endl;
    }
    else {
        cout << "\nYour number is not in the list" << endl; 
    }
}

// Find out the total amount of numbers added together
void total_amount(const vector<double> &v) {
    double total {};
    for (size_t i {0}; i < v.size(); i++) {
        total += v[i];
    }  
    cout << "The total amount of numbers added together is: " << total << endl; 
}

// Remove a number from the list
 void remove_a_number (vector<double> &v) {
     if (v.size() == 0) {
         cout << "\nThere is no data in the list to erase" << endl; 
     } 
     else {
         cout << "Please enter a number you would like to erase from the list: ";
         double remove_number {};
         cin >> remove_number; 
         for (size_t i = 0; i< v.size(); i++) {
             if (v[i] == remove_number) {
                v.erase(v.begin() + i);
                i--;
             }
         } 
    }
 }

