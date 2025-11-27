#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
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

//Favourites string (per-user, up to 10 favorites each)
string favoriteOrigin [10][10];
string favoriteDestination [10][10];
int favoriteCount [10] = {0};

// persistence function prototypes
void saveData();
void loadData();

// Clear Sceen Function
void clearScreen() {
    cout << "\033[2J\033[H";
}

void saveData() {
    std::ofstream fout("bus_data.txt");
    if(!fout.is_open()) return;
    fout << accountCount << '\n';
    for(int i = 0; i < accountCount; ++i) {
        fout << name[i] << '\n';
        fout << phone[i] << '\n';
        fout << username[i] << '\n';
        fout << password[i] << '\n';
        fout << passengertype[i] << '\n';
        fout << favoriteCount[i] << '\n';
        for(int j = 0; j < favoriteCount[i]; ++j) {
            fout << favoriteOrigin[i][j] << '\n';
            fout << favoriteDestination[i][j] << '\n';
        }
    }
    fout.close();
}

void loadData() {
    std::ifstream fin("bus_data.txt");
    if(!fin.is_open()) return;
    string line;
    if(!std::getline(fin, line)) return;
     try {
        accountCount = std::stoi(line);
    } catch(...) {
        accountCount = 0;
        return;
    }
    for(int i = 0; i < accountCount; ++i) {
        if(!std::getline(fin, name[i])) break;
        if(!std::getline(fin, phone[i])) break;
        if(!std::getline(fin, username[i])) break;
        if(!std::getline(fin, password[i])) break;
        if(!std::getline(fin, passengertype[i])) break;
        if(!std::getline(fin, line)) break;
        try {
            favoriteCount[i] = std::stoi(line);
        } catch(...) {
            favoriteCount[i] = 0;
        }
        for(int j = 0; j < favoriteCount[i]; ++j) {
            if(!std::getline(fin, favoriteOrigin[i][j])) { favoriteOrigin[i][j] = ""; }
            if(!std::getline(fin, favoriteDestination[i][j])) { favoriteDestination[i][j] = ""; }
        }
    }
    fin.close();
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
    cout << "\n";

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
        cout << "██   ▄▄▄▄▄ ▄▄  ▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄    ▄▄▄▄   ▄▄▄   ▄▄▄▄  ▄▄▄▄ ▄▄▄▄▄ ▄▄  ▄▄  ▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄    ▄▄▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄  ▄▄▄▄▄   ██\n";
        cout << "██   ██▄▄  ███▄██   ██   ██▄▄  ██▄█▄   ██▄█▀ ██▀██ ███▄▄ ███▄▄ ██▄▄  ███▄██ ██ ▄▄ ██▄▄  ██▄█▄     ██   ▀███▀ ██▄█▀ ██▄▄    ██\n";
        cout << "██   ██▄▄▄ ██ ▀██   ██   ██▄▄▄ ██ ██   ██    ██▀██ ▄▄██▀ ▄▄██▀ ██▄▄▄ ██ ▀██ ▀███▀ ██▄▄▄ ██ ██     ██     █   ██    ██▄▄▄   ██\n";
        cout << "██▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄██\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "▄▄▄▄▄▄▄▄▄▄▄▄                                                            ▄▄▄▄▄▄▄▄▄▄▄▄▄                                 \n";
        cout << "██   ▄▄   ██                                                            ██  ▄▄▄▄▄  ██        \n";  
        cout << "██  ▀██   ██    ▄▄▄▄ ▄▄▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄  ▄▄▄▄▄ ▄▄  ▄▄ ▄▄▄▄▄▄             ██     ██  ██   █████▄ ██     ██ ████▄      \n";
        cout << "██   ██   ██   ███▄▄   ██   ██ ██ ██▀██ ██▄▄  ███▄██   ██               ██   ▀▀██  ██   ██▄▄█▀ ██ ▄█▄ ██ ██  ██     \n";
        cout << "██ ▀▀▀▀▀▀ ██   ▄▄██▀   ██   ▀███▀ ████▀ ██▄▄▄ ██ ▀██   ██               ██  ▀▀▀▀▀  ██   ██      ▀██▀██▀  ████▀     \n";
        cout << "▀▀▀▀▀▀▀▀▀▀▀▀                                                            ▀▀▀▀▀▀▀▀▀▀▀▀▀        \n";   
      
        cout << "\n";
        cout << "\n";  
        cout << "▄▄▄▄▄▄▄▄▄▄▄▄    ▄▄▄▄ ▄▄▄▄▄ ▄▄  ▄▄ ▄▄  ▄▄▄  ▄▄▄▄                        ▄▄▄▄▄▄▄▄▄▄▄▄▄                                             \n";
        cout << "██   ▄▄▄  ██   ███▄▄ ██▄▄  ███▄██ ██ ██▀██ ██▄█▄                       ██         ██                                               \n";  
        cout << "██  ▀▀▀██ ██   ▄▄██▀ ██▄▄▄ ██ ▀██ ██ ▀███▀ ██ ██                       ██  ██ ██  ██    ▄▄▄▄ ▄▄▄▄▄  ▄▄▄▄ ▄▄ ▄▄ ▄▄     ▄▄▄  ▄▄▄▄ \n";     
        cout << "██   ▄██▀ ██   ▄▄▄▄▄ ▄▄  ▄▄▄▄  ▄▄ ▄▄▄▄▄ ▄▄▄▄▄ ▄▄  ▄▄                   ██  ██▄██  ██    ██▄▀ ██▄▄  ██ ▄▄ ██ ██ ██    ██ ██ ██▄▀       \n";
        cout << "██  ███▄▄ ██   ██    ██   ██   ██   ▄██ ██▄   ███▄██                   ██     ██  ██    ██ █ ██▄▄▄ ▀███▀ ▀███▀ ██▄▄▄ ██▀██ ██ █               \n";
        cout << "██▄▄▄▄▄▄▄▄██   ██▄▄▄ ██   ██   ██ ▄██▄▄ ██▄▄▄ ██ ▀██                   ██▄▄▄▄▄▄▄▄▄██                                                 \n";
        cout << "                                                                                                                               \n";  
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
    saveData();

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
        string phoneInput;
        bool validPhone = false;
        
        cin.ignore();
        while(!validPhone) {
            cout << "New phone (11 digits): ";
            getline(cin, phoneInput);
            
            if(phoneInput.length() == 11) {
                bool allDigits = true;
                for(int i = 0; i < 11; i++) {
                    if(phoneInput[i] < '0' || phoneInput[i] > '9') {
                        allDigits = false;
                        break;
                    }
                }
                
                if(allDigits) {
                    phone[currentUser] = phoneInput;
                    validPhone = true;
                    cout << "Phone updated!\n";
                } else {
                    cout << "Error: Phone number must contain only numbers!\n";
                }
            } else {
                cout << "Error: Phone number must be exactly 11 digits!\n";
            }
        }
    }
    
    saveData();
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
        for(int i = currentUser; i < accountCount - 1; i++) {
            name[i] = name[i + 1];
            phone[i] = phone[i + 1];
            username[i] = username[i + 1];
            password[i] = password[i + 1];
            passengertype[i] = passengertype[i + 1];
            favoriteCount[i] = favoriteCount[i + 1];
            for (int j = 0; j < favoriteCount[i]; j++) {
                favoriteOrigin[i][j] = favoriteOrigin[i + 1][j];
                favoriteDestination[i][j] = favoriteDestination[i + 1][j];
            }
        }
        
        if (accountCount - 1 >= 0) {
            favoriteCount[accountCount - 1] = 0;
        }
        
        accountCount--;
        saveData ();
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
    cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n";
    cout << "█                                                                                      █\n";
    cout << "█  • Ateneo de Iloilo           • Lapuz                                                █\n";
    cout << "█  • Atria Park                 • Luna St                                              █\n";
    cout << "█  • Avancena St                • Mega World                                           █\n";
    cout << "█  • Calle Real                 • Molo Plaza                                           █\n";
    cout << "█  • CPU                        • Pavia Plaza                                          █\n";
    cout << "█  • Diversion Road             • Plaza Libertad                                       █\n";
    cout << "█  • Esplanade 1                • Plaza Villa                                          █\n";
    cout << "█  • Esplanade 4                • Plazoleta Gay                                        █\n";
    cout << "█  • Freedom Grandstand         • Provincial Capitol                                   █\n";
    cout << "█  • Gaisano City               • Robinsons Jaro                                       █\n";
    cout << "█  • Iloilo City Hall           • Robinson's Place                                     █\n";
    cout << "█  • Iloilo Convention Center   • Robinson's Place Main                                █\n";
    cout << "█  • Infante Street             • Robinson's Place Pavia                               █\n";
    cout << "█  • Jalandoni                  • Smallville                                           █\n";
    cout << "█  • Jaro Plaza                 • SM City                                              █\n";
    cout << "█  • John B Lacson Molo         • SM City Iloilo                                       █\n";
    cout << "█  • La Paz Market              • SM Delgado                                           █\n";
    cout << "█  • La Paz Plaza               • St Paul Hospital                                     █\n";
    cout << "█                               • Sunburst Park                                        █\n";
    cout << "█                               • University of Iloilo                                 █\n";
    cout << "█                               • University of San Augustin                           █\n";
    cout << "█                               • Villa Baybay                                         █\n";
    cout << "█                               • WVSU                                                 █\n";
    cout << "█                                                                                      █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
   
    cout << "From: ";
    cin.ignore();
    getline(cin, from);
    
    cout << "To: ";
    getline(cin, to);
    
    // lowercase converter
    auto toLower = [](const string & s) {
        string r = s;
        for (size_t i = 0; i < r.size(); ++i) r[i] = (char)tolower((unsigned char)r[i]);
        return r;
    };

    string lf = toLower(from);
    string lt = toLower(to);

    const string routes[5][10] = {
        {"CPU","Jaro Plaza","Robinsons Jaro","WVSU","Luna St.","Provincial Capitol","St Paul Hospital","University of San Augustin","John B Lacson Molo","Molo Plaza"}, //101
        {"La Paz Market","La Paz Plaza","Lapuz","Jalandoni","Provincial Capitol","Calle Real","Sunburst Park","Iloilo City Hall","Freedome Grandstand",""}, //102
        {"Molo Plaza","Esplanade 1","Ateneo de Iloilo","Atria Park","Iloilo Convention Center","Mega World","SM City","Gaisano City","Smallville","Esplanade 4"}, //103
        {"Plaza Libertad","University of Iloilo","Robinson's Place Main","SM Delgado","University of San Augustin","John B Lacson Molo","Molo Plaza","Avancena St.","Villa Plaza","Villa Baybay"}, //104
        {"Iloilo City Hall","Plazoleta Gay","Robinson's Place Main","Infante Street","Diversion Road","SM City Iloilo","Jaro Plaza","Robinson's Place Pavia","Pavia Plaza",""} //105
    };
    const int stopsCount[5] = {10,9,10,10,9};
    const string busNames[5] = {"Bus 101","Bus 102","Bus 103","Bus 104","Bus 105"};
    const string travelTimes[5] = {"30 minutes","30 minutes","30 minutes","30 minutes","45 minutes"};

    int bestRoute = -1;
    int bestStart = -1;
    int bestEnd = -1;
    int bestDistance = 1000000; 

    for (int r = 0; r < 5; ++r) {
        int startIndex = -1, endIndex = -1;
        for (int i = 0; i < stopsCount[r]; ++i) {
            string s = toLower(routes[r][i]);
            if (s == lf) startIndex = i;
            if (s == lt) endIndex = i;
        }
            if (startIndex != -1 && endIndex != -1 && startIndex != endIndex) {

            int dist;
            if (startIndex > endIndex) {
                dist = startIndex - endIndex;
            } else {
                dist = endIndex - startIndex;
            }
        
            if (dist < bestDistance) {
                bestDistance = dist;
                bestRoute = r;
                bestStart = startIndex;
                bestEnd = endIndex;
            }
        }
    }

    if (bestRoute != -1) {
        cout << "\nBus: " << busNames[bestRoute] << endl;
        cout << "From: " << from << endl;
        cout << "To: " << to << endl;
        cout << "Distance: " << bestDistance << " stops\n";

        int fare;
        if (bestDistance >= 1 && bestDistance <= 3) {
            fare = (passengertype[currentUser] == "Regular") ? 12 : 10;
        } else if (bestDistance >= 4 && bestDistance <= 6) {
            fare = (passengertype[currentUser] == "Regular") ? 17 : 15;
        } else {
            fare = (passengertype[currentUser] == "Regular") ? 22 : 20;
        }
        cout << "Fare: ₱" << fare << endl;
        cout << "Travel Time: " << travelTimes[bestRoute] << endl;

        cout << "\nRoute: ";
        if (bestStart < bestEnd) {
            for (int i = bestStart; i <= bestEnd; ++i) {
                cout << routes[bestRoute][i];
                if (i < bestEnd) cout << " -> ";
            }
        } else {
            for (int i = bestStart; i >= bestEnd; --i) {
                cout << routes[bestRoute][i];
                if (i > bestEnd) cout << " -> ";
            }
        }
        cout << endl;

        cout << "\nSave to favorites? (Y/N): ";
        char save;
        cin >> save;
        if (save == 'Y' || save == 'y') {
            if (currentUser >= 0 && favoriteCount[currentUser] < 10) {
                favoriteOrigin[currentUser][favoriteCount[currentUser]] = from;
                favoriteDestination[currentUser][favoriteCount[currentUser]] = to;
                favoriteCount[currentUser]++;
                saveData();
                cout << "Saved!\n";
            } else {
                cout << "Favorites full or user not logged in!\n";
            }
        }
    } else {
        cout << "\nNo route found. Check spelling or try different locations.\n";
    }

    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
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

    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "█                                                         █\n";
    cout << "█ ROUTE 1: Jaro - Molo via CPU (Bus 101)                  █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ Stops:                                                  █\n";
    cout << "█  • CPU                                                  █\n";
    cout << "█  • Jaro Plaza                                           █\n";
    cout << "█  • Robinsons Jaro                                       █\n";
    cout << "█  • WVSU                                                 █\n";
    cout << "█  • Luna St                                              █\n";
    cout << "█  • Provincial Capitol                                   █\n";
    cout << "█  • St Paul Hospital                                     █\n";
    cout << "█  • University of San Augustin                           █\n";
    cout << "█  • John B Lacson Molo                                   █\n";
    cout << "█  • Molo Plaza                                           █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ Travel Time: 30 minutes                                 █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "\n";

    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "█                                                         █\n";
    cout << "█ ROUTE 2: La Paz - City Proper (Bus 102)                 █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ Stops:                                                  █\n";
    cout << "█  • La Paz Market                                        █\n";
    cout << "█  • La Paz Plaza                                         █\n";
    cout << "█  • Lapuz                                                █\n";
    cout << "█  • Jalandoni                                            █\n";
    cout << "█  • Provincial Capitol                                   █\n";
    cout << "█  • Calle Real                                           █\n";
    cout << "█  • Sunburst Park                                        █\n";
    cout << "█  • Iloilo City Hall                                     █\n";
    cout << "█  • Freedom Grandstand                                   █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ ⏱  Travel Time: 35 minutes                             █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "\n";
    
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "█                                                         █\n";
    cout << "█ ROUTE 3: Molo - SM City (Bus 103)                       █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ Stops:                                                  █\n";
    cout << "█  • Molo Plaza                                           █\n";
    cout << "█  • Esplanade 1                                          █\n";
    cout << "█  • Ateneo de Iloilo                                     █\n";
    cout << "█  • Atria Park                                           █\n";
    cout << "█  • Iloilo Convention Center                             █\n";
    cout << "█  • Mega World                                           █\n";
    cout << "█  • SM City                                              █\n";
    cout << "█  • Gaisano City                                         █\n";
    cout << "█  • Smallville                                           █\n";
    cout << "█  • Esplanade 4                                          █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ ⏱  Travel Time: 40 minutes                             █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "\n";

    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "█                                                         █\n";
    cout << "█ ROUTE 4: City Proper - Villa (Bus 104)                 █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ Stops:                                                  █\n";
    cout << "█  • Plaza Libertad                                       █\n";
    cout << "█  • University of Iloilo                                 █\n";
    cout << "█  • Robinson's Place Main                                █\n";
    cout << "█  • SM Delgado                                           █\n";
    cout << "█  • University of San Augustine                          █\n";
    cout << "█  • John B Lacson Molo                                   █\n";
    cout << "█  • Molo Plaza                                           █\n";
    cout << "█  • Avancena St                                          █\n";
    cout << "█  • Plaza Villa                                          █\n";
    cout << "█  • Villa Baybay                                         █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ ⏱  Travel Time: 45 minutes                            █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "\n";

    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "█                                                         █\n";
    cout << "█ ROUTE 5: City Proper - Pavia (Bus 105)                  █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ Stops:                                                  █\n";
    cout << "█  • Iloilo City Hall                                     █\n";
    cout << "█  • Plazoleta Gay                                        █\n";
    cout << "█  • Robinson's Place                                     █\n";
    cout << "█  • Infante Street                                       █\n";
    cout << "█  • Diversion Road                                       █\n";
    cout << "█  • SM City Iloilo                                       █\n";
    cout << "█  • Jaro Plaza                                           █\n";
    cout << "█  • Robinson's Place Pavia                               █\n";
    cout << "█  • Pavia Plaza                                          █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ ⏱  Travel Time: 45 minutes                             █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "\n";

// FARE SYSTEM TABLE (Separate)
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "█                                                         █\n";
    cout << "█                    FARE SYSTEM                          █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    cout << "█                                                         █\n";
    cout << "█ Distance            | Discounted | Regular              █\n";
    cout << "█ ──────────────────────────────────────────────────      █\n";
    cout << "█ Short (1-3 stops)   |    P10     |   P12                █\n";
    cout << "█ Medium (4-6 stops)  |    P15     |   P17                █\n";
    cout << "█ Long (7+ stops)     |    P20     |   P22                █\n";
    cout << "█                                                         █\n";
    cout << "█ Discounted rates apply to: Students, Seniors, PWD       █\n";
    cout << "█                                                         █\n";
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
    
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
    
    if(currentUser < 0 || favoriteCount[currentUser] == 0) {
        cout << "No favorites yet.\n";
    } else {
        int i = 0;
        while(i < favoriteCount[currentUser]) {
            cout << i + 1 << ". " << favoriteOrigin[currentUser][i] << " to " << favoriteDestination[currentUser][i] << endl;
            i++;
        }
        
        cout << "\nDelete a favorite? (Y/N): ";
        char del;
        cin >> del;
        
        if(del == 'Y' || del == 'y') {
            cout << "Enter number to delete: ";
            int num;
            cin >> num;
            
            if(num > 0 && num <= favoriteCount[currentUser]) {
                for(int j = num - 1; j < favoriteCount[currentUser] - 1; j++) {
                    favoriteOrigin[currentUser][j] = favoriteOrigin[currentUser][j + 1];
                    favoriteDestination[currentUser][j] = favoriteDestination[currentUser][j + 1];
                }
                favoriteCount[currentUser]--;
                saveData();
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
        cout << "                                                 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "                                                     ██                                                        ██\n";
    cout << "                                                     ██  ▄▄   ▄▄  ▄▄▄  ▄▄ ▄▄  ▄▄   ▄▄   ▄▄ ▄▄▄▄▄ ▄▄  ▄▄ ▄▄ ▄▄  ██\n";
    cout << "                                                     ██  ██▀▄▀██ ██▀██ ██ ███▄██   ██▀▄▀██ ██▄▄  ███▄██ ██ ██  ██\n";
    cout << "                                                     ██  ██   ██ ██▀██ ██ ██ ▀██   ██   ██ ██▄▄▄ ██ ▀██ ▀███▀  ██\n";
    cout << "                                                     ██                                                        ██\n";
    cout << "                                                     ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
    cout << "\n";
    cout << "\n";
    cout << "▄▄▄▄▄▄▄▄▄▄▄                                                                                          ▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "██   ▄▄  ██    ▄▄▄▄ ▄▄▄▄ ▄▄▄▄ ▄▄▄▄ ▄▄▄▄ ▄  ▄   ▄▄▄▄ ▄▄▄▄ ▄  ▄ ▄▄▄▄ ▄▄▄▄                              ██ ▄▄▄▄▄ ██  ▄▄▄  ▄▄▄▄ ▄    ▄▄▄▄ ▄▄▄▄ ▄▄▄▄    ▄▄▄▄  ▄▄▄▄ ▄▄▄▄ ▄▄▄▄ ▄ ▄    ▄▄▄▄\n";
    cout << "██  ▀██  ██    ██▄  █▄▄  █▄▄█ █▄▄▀ █    █▄▄█   █▄▄▀ █  █ █  █ ▀██▀ █▄▄                               ██  ██▄▄ ██  █  █ █▄▄  █    █▄▄  ▀██▀ █▄▄     █▄▄▄█ █▄▄▀ █  █ █▄▄  █ █    █▄▄\n";
    cout << "██   ▀▀  ██    ▄▄██ █▄▄▄ █  █ █  █ █▄▄▄ █  █   █  █ █▄▄█ █▄▄█  ██  █▄▄▄                              ██ ▀▀▀▀  ██  █▄▄▀ █▄▄▄ █▄▄▄ █▄▄▄  ██  █▄▄▄    █     █  █ █▄▄█ █    █ █▄▄▄ █▄▄▄\n";
    cout << "▀▀▀▀▀▀▀▀▀▀▀                                                                                          ▀▀▀▀▀▀▀▀▀▀▀\n";
    cout << "\n";
    cout << "▄▄▄▄▄▄▄▄▄▄▄                                                                                          ▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "██  ▄▄▄  ██   ▄   ▄ ▄ ▄▄▄▄ ▄   ▄    ▄▄▄▄ ▄    ▄      ▄▄▄▄ ▄▄▄▄ ▄  ▄ ▄▄▄▄ ▄▄▄▄ ▄▄▄▄                   ██   ▄▄▄  ██   ▄  ▄ ▄▄▄▄  ▄▄▄  ▄▄▄▄ ▄▄▄▄ ▄▄▄▄    ▄▄▄▄  ▄▄▄▄ ▄▄▄▄ ▄▄▄▄ ▄ ▄    ▄▄▄▄\n";
    cout << "██ ▀ ▄▀  ██   ██ ██ █ █▄▄  █ ▄ █    █▄▄█ █    █      █▄▄▀ █  █ █  █ ▀██▀ █▄▄  ██▄                    ██  █ ▄▄  ██   █  █ █▄▄▄█ █  █ █▄▄█ ▀██▀ █▄▄     █▄▄▄█ █▄▄▀ █  █ █▄▄  █ █    █▄▄\n";
    cout << "██ ▀▀▀▀▀ ██    ▀█▀  █ █▄▄▄ ▀█▀█▀    █  █ █▄▄▄ █▄▄▄   █  █ █▄▄█ █▄▄█  ██  █▄▄▄ ▄▄██                   ██   ▀▀   ██   █▄▄█ █     █▄▄▀ █  █  ██  █▄▄▄    █     █  █ █▄▄█ █    █ █▄▄▄ █▄▄▄\n";
    cout << "▀▀▀▀▀▀▀▀▀▀▀                                                                                          ▀▀▀▀▀▀▀▀▀▀▀▀\n";
    cout << "\n";
    cout << "▄▄▄▄▄▄▄▄▄▄▄                                                                                          ▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "██  ▄▄▄  ██    ▄▄▄▄ ▄▄▄▄ ▄   ▄ ▄▄▄▄ ▄▄▄▄ ▄ ▄▄▄▄ ▄▄▄▄    ▄▄▄▄ ▄▄▄▄ ▄  ▄ ▄▄▄▄ ▄▄▄▄                     ██  ▄▄▄▄▄ ██   ▄    ▄▄▄▄  ▄▄▄ ▄▄▄▄ ▄  ▄ ▄▄▄▄\n";
    cout << "██    ▄█ ██    █▄▄  █▄▄█ ██ ██ █  █ █▄▄▀ █ ▀██▀ █▄▄     █▄▄▀ █  █ █  █ ▀██▀ █▄▄                      ██    ██▀ ██   █    █  █ █ ▄▄ █  █ █  █ ▀██▀\n";
    cout << "██  ▀▀▀  ██    █    █  █  ▀█▀  █▄▄█ █  █ █  ██  █▄▄▄    █  █ █▄▄█ █▄▄█  ██  █▄▄▄                     ██   ▀▀   ██   █▄▄▄ █▄▄█ ▀▄▄█ █▄▄█ █▄▄█  ██\n";
    cout << "▀▀▀▀▀▀▀▀▀▀▀                                                                                          ▀▀▀▀▀▀▀▀▀▀▀▀\n";
    cout << "\n";
    cout << "▄▄▄▄▄▄▄▄▄▄▄                                                                                          ▄▄▄▄▄▄▄▄▄▄▄▄\n";
    cout << "██ ▄  ▄▄ ██    ▄   ▄ ▄ ▄▄▄▄ ▄   ▄    ▄▄▄▄  ▄▄▄▄ ▄▄▄▄ ▄▄▄▄ ▄ ▄    ▄▄▄▄                                ██   ▄▄   ██   ▄▄▄▄ ▄  ▄ ▄ ▄▄▄▄\n";
    cout << "██ █▄▄██ ██    ██ ██ █ █▄▄  █ ▄ █    █▄▄▄█ █▄▄▀ █  █ █▄▄  █ █    █▄▄                                 ██  █▄▀█  ██   █▄▄  ▀██▀ █ ▀██▀\n";
    cout << "██    ▀▀ ██     ▀█▀  █ █▄▄▄ ▀█▀█▀    █     █  █ █▄▄█ █    █ █▄▄▄ █▄▄▄                                ██   ▀▀   ██   █▄▄▄ ▄▀▀▄ █  ██\n";
    cout << "▀▀▀▀▀▀▀▀▀▀▀                                                                                          ▀▀▀▀▀▀▀▀▀▀▀▀\n";
    cout << "\n";    
    

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
                return;
            }
                break;
            case 7: 
                //This log's the user out
                loggedIn = false;
                currentUser = -1;
                cout << "\nLogged out.\n";
                cout << "\nPress Enter...";
                cin.ignore();
                cin.get();
                return;
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
        

           cout << "▄▄▄▄▄▄▄▄▄▄\n";
           cout << "█   ▄▄▄  █   ▄▄   ▄▄▄▄▄▄  ▄▄▄▄ ▄▄ ▄▄  ▄▄\n";
           cout << "█  ▀▀██  █   ██   ██  ██ ██ ▄▄ ██ ██▀▄██\n";
           cout << "█    ▀▀  █   ▀▀▀▀ ▀▀▀▀▀▀  ▀▀▀  ▀▀ ▀▀  ▀▀\n";
           cout << "▀▀▀▀▀▀▀▀▀▀\n";
           cout << "\n";
           cout << "\n";
           cout << "▄▄▄▄▄▄▄▄▄▄\n";
           cout << "█   ▄▄   █   ▄▄▄▄  ▄▄▄▄▄  ▄▄▄▄ ▄▄  ▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄ ▄▄▄▄\n";
           cout << "█  ▀ ▄▀  █   ██▄█▄ ██▀   ██ ▄▄ ██ ▀██▄▄   ██   ██▀   ██▄█▄\n";
           cout << "█  ▀▀▀▀  █   ▀▀ ▀▀ ▀▀▀▀▀  ▀▀▀  ▀▀ ▀▀▀▀    ▀▀   ▀▀▀▀▀ ▀▀ ▀▀\n";
           cout << "▀▀▀▀▀▀▀▀▀▀\n";
           cout << "\n";
           cout << "\n";
            cout << "▄▄▄▄▄▄▄▄▄▄\n";
            cout << "█   ▄▄   █    ▄▄▄▄  ▄▄ ▄▄  ▄  ▄▄▄▄▄ \n";
            cout << "█  █▄▀█  █    ██▀    ███   █    █\n";
            cout << "█   ▀▀   █    ▀▀▀▀  ▀▀ ▀▀  ▀    ▀\n";
            cout << "▀▀▀▀▀▀▀▀▀▀\n";
            cout << "\n";
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
            cout << "\n";                           
            cout << "██   ██████ ██  ██ ▄████▄ ███  ██ ██ ▄█▀   ██  ██ ▄████▄ ██  ██    ██\n";
            cout << "██     ██   ██████ ██▄▄██ ██ ▀▄██ ████      ▀██▀  ██  ██ ██  ██    ██\n";
            cout << "▄▄     ██   ██  ██ ██  ██ ██   ██ ██ ▀█▄     ██   ▀████▀ ▀████▀    ▄▄\n";
            cout << "\n";
            break;
        default:
            cout << "\nInvalid!\n";
        }
      } while(ch != 0);
    }


    int main() {
    loadData();
    startUp();
    return 0;
    }