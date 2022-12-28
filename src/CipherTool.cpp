//Title: CipherTool.cpp
//Author: Nabeel Syed
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC

#include "CipherTool.h"


// Name: CipherTool Constructor
// Desc - Creates a new CipherTool and sets m_filename based on string passed
// Preconditions - Input file passed and populated with Cipher
// Postconditions - CipherTool created
CipherTool::CipherTool(string filename) {
    m_filename = filename;
}




// Name: CipherTool Destructor
// Desc - Calls destructor for all ciphers in m_ciphers
// Preconditions - m_ciphers is populated
// Postconditions - m_ciphers deallocated and vector emptied
CipherTool::~CipherTool() {

    // Delete all ciphers form the back and deallocate them
    int counter = m_ciphers.size() - 1;
    while(m_ciphers.size() != 0){

        delete m_ciphers[counter];
        m_ciphers.pop_back();

        counter -= 1;
    }


}



// Name: LoadFile
// Desc - Opens file and reads in each Cipher. Each Cipher dynamically allocated
// and put into m_ciphers (c is Caesar, r is RailFence, and o is Ong)
// Preconditions - Input file passed and populated with Ciphers
// Postconditions - m_ciphers populated with Ciphers
void CipherTool::LoadFile() {


    // Open file object
    ifstream myFile;
    myFile.open(m_filename);


    if(!myFile.is_open()){

        // If file can't be opened for some reason
        myFile.close();
        cout << "Unable to Open File" << endl;

    }else if(myFile.is_open()){

        // Strings to store info from getline
        string type, message, misc, isEncrypted;

        // Getline every line in file
        while(getline(myFile, type, DELIMITER) && getline(myFile, isEncrypted, DELIMITER) && getline(myFile, message, DELIMITER) && getline(myFile, misc, '\n')){

            // Create cipher based on type and add it to cipher pointer vector
            if(type == "c"){

                Cipher* cipher = new Caesar(message, StringToBoolean(isEncrypted), stoi(misc));
                m_ciphers.push_back(cipher);

            }else if(type == "r"){

                Cipher* cipher = new RailFence(message, StringToBoolean(isEncrypted), stoi(misc));
                m_ciphers.push_back(cipher);

            }else if(type == "o"){

                Cipher* cipher = new Ong(message, StringToBoolean(isEncrypted));
                m_ciphers.push_back(cipher);

            }

        }

    }

    // Close file
    myFile.close();


}




// Name: StringToBoolean
// Desc - Helper function that converts a string to a boolean for reading in file
// Preconditions - Passed string of either 0 or 1
// Postconditions - Returns false if 0 else true
bool CipherTool::StringToBoolean(string input) {

    // 1 -> true, 0 -> false
    if(input == "1"){
        return true;
    }else{
        return false;
    }

}






// Name: DisplayCiphers
// Desc - Displays each of the ciphers in the m_ciphers
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Displays ciphers
void CipherTool::DisplayCiphers() {


    // Show total size of cipher array
    cout << "Size: " << m_ciphers.size() << endl;
    int count = 1;


    // Displays all Ciphers in ordered list
    for(auto item : m_ciphers){
        cout << count << ". " <<  *item << endl;
        count ++;
    }




}




// Name: EncryptDecrypt
// Desc - Encrypts or decrypts each of the ciphers in the m_ciphers
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Either Encrypts or Decrypts each cipher in m_ciphers
void CipherTool::EncryptDecrypt(bool b) {

    int num = 0;

    // Encrypt all or Decrypt all
    if(b){

        for(auto c: m_ciphers){

            // Check to see if Cipher is not encrypted
            if(not c->GetIsEncrypted()){

                // Encrypts the Cipher
                c->Encrypt();
                c->ToggleEncrypted();

                num+=1;
            }
        }

        cout << num << " ciphers encrypted\n" << endl;

    }else{

        // Check to see if Cipher is encrypted
        for(auto c: m_ciphers){
            if(c->GetIsEncrypted()){

                // Decrypts the Cipher
                c->Decrypt();
                c->ToggleEncrypted();

                num+=1;
            }
        }

        cout << num << " ciphers decrypted\n" << endl;
    }



}



// Name: Export
// Desc - Exports each of the ciphers in the m_ciphers (so they can be reused)
// Preconditions - Input file passed and m_ciphers populated
// Postconditions - All ciphers exported
void CipherTool::Export() {

    string fname;
    cout << "What would you like to call the export file?" << endl;
    cin >> fname;

    ofstream myFile;
    myFile.open(fname);

    for(auto c : m_ciphers){
        myFile << c->FormatOutput();
    }

    myFile.close();
    cout << m_ciphers.size() << " cipers exported" << endl;

}



// Name: Menu
// Desc - Displays menu and returns choice
// Preconditions - m_ciphers all populated
// Postconditions - Returns choice
int CipherTool::Menu() {

    // Display the Menu
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Ciphers\n";
    cout << "2. Encrypt All Ciphers\n";
    cout << "3. Decrypt All Ciphers\n";
    cout << "4. Export All Ciphers\n";
    cout << "5. Quit" << endl;

    // Ask user for input and validate it
    int choice = 0;
    cin >> choice;
    while (choice < 1 or choice > 5){
        cout << "Enter a number from 1 to 5" << endl;
        cin >> choice;
    }

    // Return User's choice
    return choice;
}





// Name: Start
// Desc - Loads input file, allows user to choose what to do
// Preconditions - m_ciphers populated with ciphers
// Postconditions - none
void CipherTool::Start() {

    LoadFile();

    // Show Menu and get user's choice
    int choice = Menu();
    while(choice != 5){

        if(choice == 1){

            // Displays al Ciphers
            DisplayCiphers();

        }else if(choice == 2){

            // Encrypts all Ciphers
            EncryptDecrypt(1);

        }else if(choice == 3){

            // Decrypt all Ciphers
            EncryptDecrypt(0);

        }else if(choice == 4){

            // Export all Ciphers
            Export();

        }

        // Repeat Menu
        cout << "\n\n" << endl;
        choice = Menu();
    }

    cout << "Thanks for Playing" << endl;
}































