#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


//String for aquiring user info
string name [10];
string phone [10];
string username [10];
string password [10];
string passengertype [10];
int accountCount = 0;

//Currently logged in users
int currentUser = -1;
bool loggedIn = false;

//Favourites string
string favoriteOrigin [10];
string favoriteDestination [10];
int favoriteCount = 0;

// Clear Sceen Function
void clearScreen() {
    cout << "\033[2J\033[H";
}

//REGISTRATION MENU
void registerUser() {
    
    clearScreen();
    cout << "\n▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" << endl;
    cout << "██                                                             ██" << endl;
    cout << "██    █████▄  ██████  ▄████  ██ ▄█████ ██████ ██████ █████▄    ██" << endl;
    cout << "██    ██▄▄██▄ ██▄▄   ██  ▄▄▄ ██ ▀▀▀▄▄▄   ██   ██▄▄   ██▄▄██    ██" << endl;
    cout << "██    ██   ██ ██▄▄▄▄  ▀███▀  ██ █████▀   ██   ██▄▄▄▄ ██   ██   ██" << endl;
    cout << "██                                                             ██" << endl;
    cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
    cout << "\n ";

     if(accountCount >= 10) {
        cout << "Sorry, Maximum of 10 Accounts Only!";
        cout << "\nPress Enter...";
        cin.ignore();
        cin.get();
        return;
     }

    string newUsername;
    cout << "Enter your full name: ";
    cin.ignore();
    getline (cin, name [accountCount]);

    cout << "Enter your Username: ";
    getline(cin, newUsername);

    bool exists = false;
    for(int i = 0; i < accountCount; i++) {
        if(username[i] == newUsername) {
            exists = true;
            break;
        }
    }

    if(exists) {
        cout << "Username already taken!\n";
        cout << "\nPress Enter...";
        cin.get();
        return;
    }

    string phoneInput;
    bool validPhone = false;
    
    while(!validPhone) {
        cout << "Enter phone number (11 digits): ";
        getline(cin, phoneInput);
        
        if(phoneInput.length() == 11) {
            // Check if all characters are digits
            bool allDigits = true;
            for(int i = 0; i < 11; i++) {
                if(phoneInput[i] < '0' || phoneInput[i] > '9') {
                    allDigits = false;
                    break;
                }
            }
            
            if(allDigits) {
                phone[accountCount] = phoneInput;
                validPhone = true;
            } else {
                cout << "Error: Phone number must contain only numbers!\n";
            }
        } else {
            cout << "Error: Phone number must be exactly 11 digits!\n";
        }
    }

    username[accountCount] = newUsername;
    
    cout << "Enter password: ";
    getline(cin, password[accountCount]);

    //SELECTING PASSENGER TYPE
        clearScreen();
  	    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
		cout << "██                                                                                                                         ██\n";
		cout << "██   ▄▄▄▄▄ ▄▄  ▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄    ▄▄▄▄   ▄▄▄   ▄▄▄▄  ▄▄▄▄ ▄▄▄▄▄ ▄▄  ▄▄  ▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄    ▄▄▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄  ▄▄▄▄▄   ██\n";
		cout << "██   ██▄▄  ███▄██   ██   ██▄▄  ██▄█▄   ██▄█▀ ██▀██ ███▄▄ ███▄▄ ██▄▄  ███▄██ ██ ▄▄ ██▄▄  ██▄█▄     ██   ▀███▀ ██▄█▀ ██▄▄    ██\n";
		cout << "██   ██▄▄▄ ██ ▀██   ██   ██▄▄▄ ██ ██   ██    ██▀██ ▄▄██▀ ▄▄██▀ ██▄▄▄ ██ ▀██ ▀███▀ ██▄▄▄ ██ ██     ██     █   ██    ██▄▄▄   ██\n";
		cout << "██                                                                                                                         ██\n";
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
	    cout << "▄▄▄▄▄▄▄▄▄▄▄▄                                                            ▄▄▄▄▄▄▄▄▄▄▄▄▄                                                                                                    \n";
		cout << "██        ██                                                            ██         ██        \n";  
		cout << "██ ▄███   ██    ▄▄▄▄ ▄▄▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄  ▄▄▄▄▄ ▄▄  ▄▄ ▄▄▄▄▄▄             ██  ████▄  ██   █████▄ ██     ██ ████▄      \n";
		cout << "██   ██   ██   ███▄▄   ██   ██ ██ ██▀██ ██▄▄  ███▄██   ██               ██   ▄▄██  ██   ██▄▄█▀ ██ ▄█▄ ██ ██  ██     \n";
		cout << "██ ██████ ██   ▄▄██▀   ██   ▀███▀ ████▀ ██▄▄▄ ██ ▀██   ██               ██  ▄▄▄█▀  ██   ██      ▀██▀██▀  ████▀     \n";
		cout << "██        ██                                                            ██         ██         \n";
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀                                                            ▀▀▀▀▀▀▀▀▀▀▀▀▀        \n";   
		cout << "\n";
		cout << "\n";  
		cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄    ▄▄▄▄ ▄▄▄▄▄ ▄▄  ▄▄ ▄▄  ▄▄▄  ▄▄▄▄                        ▄▄▄▄▄▄▄▄▄▄▄▄▄                                                                 \n";
		cout << "██         ██   ███▄▄ ██▄▄  ███▄██ ██ ██▀██ ██▄█▄                       ██         ██                                                                   \n";  
		cout << "██  ▄███▄  ██   ▄▄██▀ ██▄▄▄ ██ ▀██ ██ ▀███▀ ██ ██                       ██  ██  █  ██    ▄▄▄▄  ▄▄▄▄▄  ▄▄▄▄ ▄▄ ▄▄ ▄▄     ▄▄▄  ▄▄▄▄  \n";     
		cout << "██   ▄██▀  ██                                                           ██  ▀████  ██    ██▄█▄ ██▄▄  ██ ▄▄ ██ ██ ██    ██▀██ ██▄█▄\n";
		cout << "██  ███▄▄  ██    ▄▄▄▄ ▄▄ ▄▄▄▄▄▄ ▄▄ ▄▄▄▄▄ ▄▄▄▄▄ ▄▄  ▄▄                   ██     ██  ██    ██ ██ ██▄▄▄ ▀███▀ ▀███▀ ██▄▄▄ ██▀██ ██ ██                   \n";
		cout << "██         ██   ██▀▀▀ ██   ██   ██   ▄█▀ ██▄▄  ███▄██                   ██         ██                                                                    \n";
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀   ▀████ ██   ██   ██ ▄██▄▄ ██▄▄▄ ██ ▀██                   ▀▀▀▀▀▀▀▀▀▀▀▀▀                                                                        \n";  
		cout << "\n";
		cout << "\n";  
           
		                                                                                  
       cout << "Pick one: ";
    int type;
    cin >> type;

    if (type == 1) {
        passengertype [accountCount] = "Student";
    }
    else if (type == 2) {
        passengertype [accountCount]= "Senior";
    } 
    else if (type == 3) {
        passengertype [accountCount] = "PWD";
    }
    else {
        passengertype [accountCount] = "Regular";
    }

    accountCount++;

    cout << "\n";
	cout << "▄▄                                                                                                            ▄▄\n";
    cout << "██   ▄████▄ ▄█████ ▄█████ ▄████▄ ██  ██ ███  ██ ██████   ▄█████ █████▄  ██████ ▄████▄ ██████ ██████ ████▄     ██\n";
    cout << "██   ██▄▄██ ██     ██     ██  ██ ██  ██ ██ ▀▄██   ██     ██     ██▄▄██▄ ██▄▄   ██▄▄██   ██   ██▄▄   ██  ██    ██\n";
    cout << "▄▄   ██  ██ ▀█████ ▀█████ ▀████▀ ▀████▀ ██   ██   ██     ▀█████ ██   ██ ██▄▄▄▄ ██  ██   ██   ██▄▄▄▄ ████▀     ▄▄\n";
    cout << "\n";
    cout << "You are account #" << accountCount << "\n";
    cout << "Press Enter to Continue...";
 
    cin.ignore();
    cin.get();
}

//LOGIN MENU
void loginUser() {
    
    string inputUser, inputPass;
    clearScreen();
    	cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                               ██\n";
        cout << "██  ▄▄     ▄▄▄   ▄▄▄▄ ▄▄ ▄▄  ▄▄  ██\n";
        cout << "██  ██    ██▀██ ██ ▄▄ ██ ███▄██  ██\n";
        cout << "██  ██▄▄▄ ▀███▀ ▀███▀ ██ ██ ▀██  ██\n";
        cout << "██                               ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";

    if(accountCount == 0) {
        cout << "No accounts yet! Register first.\n";
        cout << "\nPress Enter to continue....";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Username: ";
    cin.ignore();
    getline (cin, inputUser);

    cout << "Password: ";
    getline (cin, inputPass);

    //CHECKING AVAILABLE ACCOUNTS
     for(int i = 0; i < accountCount; i++) {
        if(username[i] == inputUser && password[i] == inputPass) {
            currentUser = i;
            loggedIn = true;
            cout << "\nWelcome " << name[i] << "!\n";
            cout << "\nPress Enter to continue....";
            cin.get();
            return;
        }
    }

    cout << "\nWrong username or password!\n";
    cout << "\nPress Enter to continue....";
    cin.get();
}

// VIEW PROFILE MENU
void viewProfile() {
    clearScreen();
      	cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                                                          ██\n";
        cout << "██  ▄▄   ▄▄ ▄▄ ▄▄   ▄▄▄▄  ▄▄▄▄   ▄▄▄  ▄▄▄▄▄ ▄▄ ▄▄    ▄▄▄▄▄  ██\n";
        cout << "██  ██▀▄▀██ ▀███▀   ██▄█▀ ██▄█▄ ██▀██ ██▄▄  ██ ██    ██▄▄   ██\n";
        cout << "██  ██   ██   █     ██    ██ ██ ▀███▀ ██    ██ ██▄▄▄ ██▄▄▄  ██\n";
        cout << "██                                                          ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";
    cout << "Name: " << name [currentUser] << endl;
    cout << "Phone: " << phone [currentUser] << endl;
    cout << "Username: " << username [currentUser] << endl;
    cout << "Type: " << passengertype [currentUser] << endl;
    
    cout << "\nPress Enter to continue....";
    cin.ignore();
    cin.get();
    }

// UPDATE PROFILE MENU
void updateProfile() {
    clearScreen();
      	cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                                                                               ██\n";
        cout << "██  ▄▄ ▄▄ ▄▄▄▄  ▄▄▄▄   ▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄  ▄▄▄▄  ▄▄▄▄   ▄▄▄  ▄▄▄▄▄ ▄▄ ▄▄    ▄▄▄▄▄  ██\n";
        cout << "██  ██ ██ ██▄█▀ ██▀██ ██▀██  ██   ██▄▄   ██▄█▀ ██▄█▄ ██▀██ ██▄▄  ██ ██    ██▄▄   ██\n";
        cout << "██  ▀███▀ ██    ████▀ ██▀██  ██   ██▄▄▄  ██    ██ ██ ▀███▀ ██    ██ ██▄▄▄ ██▄▄▄  ██\n";
        cout << "██                                                                               ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";
	    cout << "▄▄▄▄▄▄▄▄▄▄▄▄                                                                                                                                                       \n";
		cout << "██        ██      ██████ ██  ██ ▄████▄ ███  ██  ▄████  ██▀▀▀▀       \n";  
		cout << "██ ▄███   ██      ██     ██████ ██▄▄██ ██ ▀▄██ ██  ▄▄▄ ██▀▀         \n";
		cout << "██   ██   ██      ▀▀▀▀▀▀ ▀▀  ▀▀ ▀▀  ▀▀ ▀▀   ▀▀  ▀▀▀▀▀  ▀▀▀▀▀▀       \n";
		cout << "██ ██████ ██      ███  ██ ▄████▄ ██▄  ▄██ ██▀▀▀▀                    \n";
		cout << "██        ██      ██ ▀▄██ ██▄▄██ ██ ▀▀ ██ ██▀▀▀▀                    \n";
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀      ▀▀  ▀▀▀ ▀▀  ▀▀ ▀▀    ▀▀ ▀▀▀▀▀▀                    \n";   
		cout << "\n";
        cout << "▄▄▄▄▄▄▄▄▄▄▄▄                                                                                                                                                       \n";
		cout << "██        ██      ██████ ██  ██ ▄████▄ ███  ██  ▄████  ██▀▀▀▀       \n";  
		cout << "██ ▄███▄  ██      ██     ██████ ██▄▄██ ██ ▀▄██ ██  ▄▄▄ ██▀▀         \n";
		cout << "██  ▄██▀  ██      ▀▀▀▀▀▀ ▀▀  ▀▀ ▀▀  ▀▀ ▀▀   ▀▀  ▀▀▀▀▀  ▀▀▀▀▀▀       \n";
		cout << "██ ███▄▄  ██      █████▄ ██  ██ ▄████▄ ███  ██ ██▀▀▀▀                     \n";
		cout << "██        ██      ██▄▄█▀ ██████ ██  ██ ██ ▀▄██ ██▀▀▀▀                       \n";
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀      ▀▀     ▀▀  ▀▀  ▀▀▀▀  ▀▀   ▀▀ ▀▀▀▀▀▀       \n";   
		cout << "\n";
        cout << "Pick: ";
    int pick;
    cin >> pick;
    
    if(pick == 1) {
        cout << "\n";
        cout << "New name: ";
        cin.ignore();
        getline(cin, name[currentUser]);
        cout << "Name updated!\n";
    } else if(pick == 2) {
        cout << "\n";
        cout << "New phone: ";
        cin.ignore();
        getline(cin, phone[currentUser]);
        cout << "Phone updated!\n";
    }
    
    cout << "\nPress Enter to continue....";
    cin.ignore();
    cin.get();
}

//DELETE ACCOUNT MENU
void deleteAccount() {
    clearScreen();
        cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                                                                                      ██\n";
        cout << "██  ▄▄▄▄  ▄▄▄▄▄ ▄▄    ▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄    ▄▄▄   ▄▄▄▄  ▄▄▄▄  ▄▄▄  ▄▄ ▄▄ ▄▄  ▄▄ ▄▄▄▄▄▄  ██\n";
        cout << "██  ██▀██ ██▄▄  ██    ██▄▄    ██   ██▄▄    ██▀██ ██▀▀▀ ██▀▀▀ ██▀██ ██ ██ ███▄██   ██    ██\n";
        cout << "██  ████▀ ██▄▄▄ ██▄▄▄ ██▄▄▄   ██   ██▄▄▄   ██▀██ ▀████ ▀████ ▀███▀ ▀███▀ ██ ▀██   ██    ██\n";
        cout << "██                                                                                      ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";
    cout << "Are you sure? (Y/N): ";
    char ans;
    cin >> ans;
    
    if(ans == 'Y' || ans == 'y') {
        // Shift all accounts after deleted one
        for(int i = currentUser; i < accountCount - 1; i++) {
            name[i] = name[i + 1];
            phone[i] = phone[i + 1];
            username[i] = username[i + 1];
            password[i] = password[i + 1];
            passengertype[i] = passengertype[i + 1];
        }
        
        accountCount--;
        loggedIn = false;
        currentUser = -1;
        
        cout << " ▄▄                                                                                                           ▄▄\n";
        cout << " ██   ▄████▄ ▄█████ ▄█████ ▄████▄ ██  ██ ███  ██ ██████   ████▄  ██████ ██     ██████ ██████ ██████ ████▄     ██\n";
        cout << " ██   ██▄▄██ ██     ██     ██  ██ ██  ██ ██ ▀▄██   ██     ██  ██ ██▄▄   ██     ██▄▄     ██   ██▄▄   ██  ██    ██\n";
        cout << " ▄▄   ██  ██ ▀█████ ▀█████ ▀████▀ ▀████▀ ██   ██   ██     ████▀  ██▄▄▄▄ ██████ ██▄▄▄▄   ██   ██▄▄▄▄ ████▀     ▄▄\n";
        cout << "\n";
    } else {
        cout << "▄▄                                                             ▄▄\n";
        cout << "██    ▄▄▄▄  ▄▄▄  ▄▄  ▄▄  ▄▄▄▄ ▄▄▄▄▄ ▄▄    ▄▄    ▄▄▄▄▄ ▄▄▄▄     ██\n";
        cout << "██   ██▀▀▀ ██▀██ ███▄██ ██▀▀▀ ██▄▄  ██    ██    ██▄▄  ██▀██    ██\n";
        cout << "▄▄   ▀████ ██▀██ ██ ▀██ ▀████ ██▄▄▄ ██▄▄▄ ██▄▄▄ ██▄▄▄ ████▀    ▄▄\n";
        cout << "\n";
    }
    
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

//SEARCH ROUTE MENU
void searchRoute() {
    clearScreen();
    string from, to;

    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "██                                                                                    ██\n";
    cout << "██  ▄█████ ██████ ▄████▄ █████▄  ▄█████ ██  ██   █████▄  ▄████▄ ██  ██ ██████ ██████  ██\n";
    cout << "██  ▀▀▀▄▄▄ ██▄▄   ██▄▄██ ██▄▄██▄ ██     ██████   ██▄▄██▄ ██  ██ ██  ██   ██   ██▄▄    ██\n";
    cout << "██  █████▀ ██▄▄▄▄ ██  ██ ██   ██ ▀█████ ██  ██   ██   ██ ▀████▀ ▀████▀   ██   ██▄▄▄▄  ██\n";
    cout << "██                                                                                    ██\n";
    cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
    cout << "\n";
    cout << "Available Locations:\n"; 
    cout << "- CPU, Jaro Plaza, Robinsons Jaro, WVSU\n";
    cout << "- La Paz Market, La Paz Plaza, Lapuz\n";
    cout << "- Molo Plaza, Esplanade, SM City\n";
    cout << "- City Hall, Plaza Libertad, Robinson's Place\n";
    cout << "- Pavia Plaza, Villa Baybay\n\n";

    cout << "From: ";
    cin.ignore();
    getline(cin, from);
    
    cout << "To: ";
    getline(cin, to);
    
    bool found = false;
    string busName = "";
    string stops[15];
    int stopCount = 0;
    int startIndex = -1;
    int endIndex = -1;
    string travelTime = "";

    // ROUTE 1 (BUS 101)
    if ((from == "CPU" || from == "Jaro Plaza" || from == "Robinson's Jaro" || 
        from == "WVSU" || from == "Luna St." || from == "Iloilo Provincial Capitol" || 
        from == "St. Paul's Hospital" || from == "University of San Augustine" || 
        from == "John B. Lacson" || from == "Molo Plaza") && 
        (to == "CPU" || to == "Jaro Plaza" || to == "Robinson's Jaro" || 
        to == "WVSU" || to == "Luna St." || to == "Iloilo Provincial Capitol" || 
        to == "St. Paul's Hospital" || to == "University of San Augustine" || 
        to == "John B. Lacson" || to == "Molo Plaza"))
        
        busName = "Bus 101";
        stops[0] = "CPU";
        stops[1] = "Jaro Plaza";
        stops[2] = "Robinsons Jaro";
        stops[3] = "WVSU";
        stops[4] = "Luna St";
        stops[5] = "Provincial Capitol";
        stops[6] = "St Paul Hospital";
        stops[7] = "University of San Augustin";
        stops[8] = "John B Lacson Molo";
        stops[9] = "Molo Plaza";
        stopCount = 10;
        travelTime = "30 minutes";
        

        for(int i = 0; i < stopCount; i++) {
            if(stops[i] == from) startIndex = i;
            if(stops[i] == to) endIndex = i;
            }
        
        if(startIndex != -1 && endIndex != -1 && startIndex != endIndex) {
            found = true;
        }   

        if(found == true) {
        cout << "\n";
        cout << "   ██   ▄▄▄▄   ▄▄▄  ▄▄ ▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄   ▄▄▄▄▄  ▄▄▄  ▄▄ ▄▄ ▄▄  ▄▄ ▄▄▄▄     ██\n";
        cout << "   ██   ██▄█▄ ██▀██ ██ ██   ██   ██▄▄    ██▄▄  ██▀██ ██ ██ ███▄██ ██▀██    ██\n";
        cout << "   ▄▄   ██ ██ ▀███▀ ▀███▀   ██   ██▄▄▄   ██    ▀███▀ ▀███▀ ██ ▀██ ████▀    ▄▄\n";
        cout << "\n";
        cout << "Bus: " << busName << endl;
        cout << "From: " << from << endl;
        cout << "To: " << to << endl;

        int distance;
        if(startIndex < endIndex) {
            distance = endIndex - startIndex;
        } else {
            distance = startIndex - endIndex;
        }
        
        int fare;
        if(distance >= 1 && distance <= 3) {
            if(passengertype[currentUser] == "Regular") {
                fare = 12;
            } else {
                fare = 10;
            }
        } else if(distance >= 4 && distance <= 6) {
            if(passengertype[currentUser] == "Regular") {
                fare = 17;
            } else {
                fare = 15;
            }
        } else {
            if(passengertype[currentUser] == "Regular") {
                fare = 22;
            } else {
                fare = 20;
            }
        }
        
        cout << "Distance: " << distance << " stops\n";
        cout << "Fare: P" << fare << endl;
        cout << "Travel Time: " << travelTime << endl;
        
        // Show route path
        cout << "\nRoute: ";
        if(startIndex < endIndex) {
            for(int i = startIndex; i <= endIndex; i++) {
                cout << stops[i];
                if(i < endIndex) cout << " -> ";
            }
        } else {
            for(int i = startIndex; i >= endIndex; i--) {
                cout << stops[i];
                if(i > endIndex) cout << " -> ";
            }
        }
        cout << endl;

        cout << "\nSave to favorites? (Y/N): ";
        char save;
        cin >> save;
        
        if(save == 'Y' || save == 'y') {
            if(favoriteCount < 10) {
                favoriteOrigin[favoriteCount] = from;
                favoriteDestination[favoriteCount] = to;
                favoriteCount = favoriteCount + 1;
                cout << "Saved!\n";
            } else {
                cout << "Favorites full!\n";
            }
        }
    } else {
        cout << "\nNo route found. Check spelling or try different locations.\n";
    }
}

// VIEW ALL ROUTE MENU
void viewAll() { 
    clearScreen();
        cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                                                            ██\n";
        cout << "██   ▄▄▄  ▄▄    ▄▄      ▄▄▄▄   ▄▄▄  ▄▄ ▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄  ▄▄▄▄  ██\n";
        cout << "██  ██▀██ ██    ██      ██▄█▄ ██▀██ ██ ██   ██   ██▄▄  ███▄▄  ██\n";
        cout << "██  ██▀██ ██▄▄▄ ██▄▄▄   ██ ██ ▀███▀ ▀███▀   ██   ██▄▄▄ ▄▄██▀  ██\n";
        cout << "██                                                            ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";

    cout << "Route 1: Jaro - Molo via CPU (Bus 101)\n";
    cout << "Stops: CPU -> Jaro Plaza -> Robinsons Jaro -> WVSU\n";
    cout << "       -> Luna St -> Provincial Capitol\n";
    cout << "       -> St Paul Hospital -> University of San Augustin\n";
    cout << "       -> John B Lacson Molo -> Molo Plaza\n";
    cout << "Travel Time: 30 minutes\n\n";

    cout << "Route 2: La Paz - City Proper (Bus 102)\n";
    cout << "Stops: La Paz Market -> La Paz Plaza -> Lapuz\n";
    cout << "       -> Jalandoni -> Provincial Capitol -> Calle Real\n";
    cout << "       -> Sunburst Park -> Iloilo City Hall\n";
    cout << "       -> Freedom Grandstand\n";
    cout << "Travel Time: 35 minutes\n\n";
    
    cout << "Route 3: Molo - SM City (Bus 103)\n";
    cout << "Stops: Molo Plaza -> Esplanade 1 -> Ateneo de Iloilo\n";
    cout << "       -> Atria Park -> Iloilo Convention Center\n";
    cout << "       -> Mega World -> SM City -> Gaisano City\n";
    cout << "       -> Smallville -> Esplanade 4\n";
    cout << "Travel Time: 40 minutes\n\n";
    
    cout << "Route 4: City Proper - Villa (Bus 104)\n";
    cout << "Stops: Plaza Libertad -> University of Iloilo\n";
    cout << "       -> Robinson's Place Main -> SM Delgado\n";
    cout << "       -> University of San Augustine\n";
    cout << "       -> John B Lacson Molo -> Plaza Molo\n";
    cout << "       -> Avancena St -> Plaza Villa -> Villa Baybay\n";
    cout << "Travel Time: 45 minutes\n\n";
    
    cout << "Route 5: City Proper - Pavia (Bus 105)\n";
    cout << "Stops: Iloilo City Hall -> Plazoleta Gay\n";
    cout << "       -> Robinson's Place -> Infante Street\n";
    cout << "       -> Diversion Road -> SM City Iloilo\n";
    cout << "       -> Jaro Plaza -> Robinson's Place Pavia\n";
    cout << "       -> Pavia Plaza\n";
    cout << "Travel Time: 45 minutes\n\n";
    
    cout << "Fare System:\n";
    cout << "Short (1-3 stops): P10 (Discounted) / P12 (Regular)\n";
    cout << "Medium (4-6 stops): P15 (Discounted) / P17 (Regular)\n";
    cout << "Long (7+ stops): P20 (Discounted) / P22 (Regular)\n";
    
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

// VIEW FAVORITES MENU 
void viewFavorites() {
    clearScreen();
      	cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                                                                                        ██\n";
        cout << "██  ▄▄▄▄▄  ▄▄▄  ▄▄ ▄▄  ▄▄▄  ▄▄▄▄  ▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄   ▄▄▄▄   ▄▄▄  ▄▄ ▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄  ▄▄▄▄  ██\n";
        cout << "██  ██▄▄  ██▀██ ██▄██ ██▀██ ██▄█▄ ██   ██   ██▄▄    ██▄█▄ ██▀██ ██ ██   ██   ██▄▄  ███▄▄  ██\n";
        cout << "██  ██    ██▀██  ▀█▀  ▀███▀ ██ ██ ██   ██   ██▄▄▄   ██ ██ ▀███▀ ▀███▀   ██   ██▄▄▄ ▄▄██▀  ██\n";
        cout << "██                                                                                        ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";
    
    if(favoriteCount == 0) {
        cout << "No favorites yet.\n";
    } else {
        int i = 0;
        while(i < favoriteCount) {
            cout << i + 1 << ". " << favoriteOrigin[i] << " to " << favoriteDestination[i] << endl;
            i++;
        }
        
        cout << "\nDelete a favorite? (Y/N): ";
        char del;
        cin >> del;
        
        if(del == 'Y' || del == 'y') {
            cout << "Enter number to delete: ";
            int num;
            cin >> num;
            
            if(num > 0 && num <= favoriteCount) {
                // Shift array
                for(int j = num - 1; j < favoriteCount - 1; j++) {
                    favoriteOrigin[j] = favoriteOrigin[j + 1];
                    favoriteDestination[j] = favoriteDestination[j + 1];
                }
                favoriteCount--;
                cout << "Deleted!\n";
            }
        }
    }
    
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

 // MAIN MENU
    void mainMenu() {
        
        int co;

        do {   
        clearScreen();   
        cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                                                        ██\n";
        cout << "██  ▄▄   ▄▄  ▄▄▄  ▄▄ ▄▄  ▄▄   ▄▄   ▄▄ ▄▄▄▄▄ ▄▄  ▄▄ ▄▄ ▄▄  ██\n";
        cout << "██  ██▀▄▀██ ██▀██ ██ ███▄██   ██▀▄▀██ ██▄▄  ███▄██ ██ ██  ██\n";
        cout << "██  ██   ██ ██▀██ ██ ██ ▀██   ██   ██ ██▄▄▄ ██ ▀██ ▀███▀  ██\n";
        cout << "██                                                        ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";
        cout << "[1] Search Routes\n";
        cout << "[2] View All Routes\n";
        cout << "[3] Favorite Routes\n";
        cout << "[4] View Profile\n";
        cout << "[5] Update Porifle\n";
        cout << "[6] Delete Profile\n";
        cout << "[7] Logout\n";
        cout << "";
        cout << "Enter a Number: ";
        cin >> co;
       
    
        switch (co) { 
            case 1:
                searchRoute();
                break;
            case 2:
                viewAll();
                break;
            case 3:
                viewFavorites();
                break;
            case 4:
                viewProfile();
                break;
            case 5: 
                updateProfile();
                break;
            case 6:
                deleteAccount();
                if(!loggedIn) {
                break; //This is to exit after the account deletion
            }
                break;
            case 7: 
                //This log's the user out
                loggedIn = false;
                currentUser = -1;
                // This clears favorites when logging out
                favoriteCount = 0;
                cout << "\nLogged out.\n";
                cout << "\nPress Enter...";
                cin.ignore();
                cin.get();
                break;
            case 0: 
                cout << "\nThank you!\n";
                break;
            default:
                cout << "Invalid Input Try Again!\n";
                break;
            }
        }  while(co != 0);
    }
    
    //START UP MENU
    void startUp() {
        
        int ch;

        do {
        clearScreen();
        cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
        cout << "██                              ██\n";
        cout << "██   █████▄ █████▄  ██ ▄█████   ██\n";
        cout << "██   ██▄▄██ ██▄▄█▄  ██ ▀▀▀▄▄▄   ██\n";
        cout << "██   ██▄▄█▀ ██  ▀██ ██ █████▀   ██\n";
        cout << "██                              ██\n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
        cout << "\n";
        cout << "Total Accounts: " << accountCount << "/10\n\n";

        cout << "[1] Login\n";
        cout << "[2] Register\n";
        cout << "[0] Exit\n";
        cout << "\nYour Choice: ";
        cin >> ch;

        switch (ch) {
        case 1: 
        loginUser();

            if(loggedIn) {
                mainMenu();
            }
            break;
        case 2:
            registerUser();
            break;
        case 0: 
         cout << "\nBye!\n";

        default:
            cout << "\nInvalid!\n";
        }
        } while(ch != 0);
    }


    int main() {
    startUp();
    return 0;
    }