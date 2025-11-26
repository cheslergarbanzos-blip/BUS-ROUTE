#include <iostream>
#include <string>
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
string FavouriteOrigin [10];
string FavouriteDestination [10];

//REGISTRATION MENU
void registerUser() {
    cout << "\n[[[[[[[= REGISTER =]]]]]]]\n";

     if(accountCount >= 10) {
        cout << "Sorry, maximum 10 accounts only!\n";
        cout << "\nPress Enter...";
        cin.ignore();
        cin.get();
        return;
     }

    string newUsername;
    cout << "Enter your full name: ";
    cin.ignore();
    getline (cin, newUsername);

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

    cout << "Enter your Username: ";
    getline(cin, name[accountCount]);

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
    cout << "\n-----PASSENGER TYPE-----\n";
    cout << "[1] Student\n";
    cout << "[2] Senior Citizen\n";
    cout << "[3] PWD\n";
    cout << "[4] Regular\n";
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

    cout << "\nAccount Created!\n";
    cout << "You are account #" << accountCount << "\n";
    cout << "\nPress Enter to continue....";
    cin.ignore();
    cin.get();
}

//LOGIN MENU
void loginUser() {
    string inputUser, inputPass;

    cout << "\n[[[[[= LOGIN =]]]]]\n";

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
    cout << "\n[[[[[= MY PROFILE =]]]]]\n";
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
    cout << "\n[[[[[= UPDATE PROFILE =]]]]]\n";
    cout << "[1] Change Name\n";
    cout << "[2] Change Phone\n";
    cout << "Pick: ";
    int pick;
    cin >> pick;
    
    if(pick == 1) {
        cout << "New name: ";
        cin.ignore();
        getline(cin, name[currentUser]);
        cout << "Name updated!\n";
    } else if(pick == 2) {
        cout << "New phone: ";
        cin.ignore();
        getline(cin, phone[currentUser]);
        cout << "Phone updated!\n";
    }
    
    cout << "\nPress Enter to continue....";
    cin.ignore();
    cin.get();
}

// FAV ROUTE MENU

void favRoute() {

}

//DELETE ACCOUNT MENU
void deleteAccount() {
    cout << "\n[[[[[= DELETE ACCOUNT =]]]]]\n";
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
        
        cout << "Account deleted.\n";
    } else {
        cout << "Cancelled.\n";
    }
    
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

// VIEW ALL ROUTE MENU

void viewAll() {


}

//SEARCH ROUTE MENU
void searchRoute() {
    string from, to;

    cout << "\n[[[[[= SEARCH ROUTE =]]]]]\n";
    cout << "Available Locations:\n"; 
    cout << "- \n";
    cout << "- \n";
    cout << "- \n";
    cout << "- \n";
    cout << "- \n";
    cout << "- \n\n";

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

    // ROUTE 1 (BUS 101)
    if ((from == "CPU" || from == "Jaro Plaza" || from == "Robinson's Jaro" || from == "WVSU" || from == "Luna St." || 
        from == "Iloilo Provincial Capitol" || from == "St. Paul's Hospital" || from == "University of San Augustine" || 
        from == "John B. Lacson" || from == "Molo Plaza") && (to == "CPU" || to == "Jaro Plaza"))

        for(int i = 0; i < stopCount; i++) {
            if(stops[i] == from) startIndex = i;
            if(stops[i] == to) endIndex = i;
            }
        
        if(startIndex != -1 && endIndex != -1 && startIndex != endIndex) {
            found = true;
        }   
}



 // MAIN MENU
    void mainMenu() {
    
        int co;
        cout << "\n[[[[[= MAIN MENU =]]]]]\n";
        cout << "[1] Search Routes\n";
        cout << "[2] View All Routes\n";
        cout << "[3] Favorite Routes\n";
        cout << "[4] View Profile\n";
        cout << "[5] Update Porifle\n";
        cout << "[6] Delete Profile\n";
        cout << "[7] Logout\n";
       
    
        switch (co) { 
            case 1:
                searchRoute();
                break;
            case 2:
                viewAll();
                break;
            case 3:
                favRoute();
                break;
            case 4:
                viewProfile();
                break;
            case 5: 
                updateProfile();
                break;
            case 6:
                deleteAccount();
                break;
            case 7: 
                loginUser();
                break;
            default:
                cout << "Invalid Input Try Again!\n";
                break;
            }
    }  

    void startUp() {

        int ch;

        cout << "\n[[[[[= START UP MENU =]]]]]\n";
        cout << "[1] Login\n";
        cout << "[2] Register\n";
        cout << "[3] Exit\n";
        cout << "\nYour Choice: ";
        cin >> ch;

        switch (ch) {
            case 1: 
                loginUser();
                if (loggedIn) {
                    mainMenu ();
                } 
                break;
            case 2:
                registerUser();
                break;
            case 3:
                break;
            default:
            cout << "INVALID INPUT TRY AGAIN!";
            break;
        }
    }

    int main() {
    startUp();
    return 0;
    }


    


    

