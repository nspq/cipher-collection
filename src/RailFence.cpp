//Title: RailFence.cpp
//Author: Nabeel Syed
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC

#include "RailFence.h"



// Name: RailFence (Default Constructor)
// Desc: Constructor to build an empty RailFence Cipher (Defaults to 3 rails)
// Preconditions - None
// Postconditions - Creates a RailFence cipher
RailFence::RailFence(): Cipher() {

    m_rails = 3;
}





// Name: RailFence (Overloaded Constructor)
// Desc: Constructor to build a populated RailFence Cipher (Defaults to 3 rails)
// Preconditions - Pass it the message, isEncrypted, and number of rails (any integer)
// Postconditions - Creates a RailFence cipher to be encrypted
RailFence::RailFence(string message, bool isEncrypted, int rails): Cipher(message, isEncrypted) {

    m_rails = rails;
}







// Name: RailFence (Destructor)
// Desc: Destructor - Anything specific part of RailFence to delete?
// Preconditions - ~RailFence exists
// Postconditions - RailFence destroyed
RailFence::~RailFence(){}



// Name: Encrypt
// Desc: Letters are placed on a fence rail based on the number of rails
//       Letters are read from one rail at a time into a single string
// Preconditions - Message exists
// Postconditions - A single encrypted string is stored
void RailFence::Encrypt() {

    // Strings to store messages
    string message = GetMessage();
    string newMessage;

    // Create matrix for decrypting
    char matrix[m_rails][message.length()];

    // Fill matrix with dashes to help identifying later on
    for(int i = 0; i < m_rails; i++){
        for(unsigned int j = 0; j < message.length(); j++){
            matrix[i][j] = '_';
        }
    }


    bool dir = false;
    int row = 0;
    int col = 0;

    // Fill matix with letter from message in fences
    for(unsigned int i = 0; i < message.length(); i++){

        if (row == 0 || row == m_rails-1){
            dir = !dir;
        }

        matrix[row][col] = message[i];
        col++;

        if(dir){
            row++;
        }else{
            row--;
        }
    }

    // Read matrix line by line to get decrypted message (not including dashes)
    for(int i = 0; i < m_rails; i++){
        for(unsigned int j = 0; j < message.length(); j++){
            if(matrix[i][j] != '_'){
                newMessage += matrix[i][j];
            }
        }
    }

    // update message
    SetMessage(newMessage);

}





// Name: Decrypt
// Desc: Single encrypted string is pushed back on the rails and reversed
// Preconditions - Message exists
// Postconditions - The decrypted string is stored
void RailFence::Decrypt() {

    // Strings to hold messages
    string message = GetMessage();
    string newMessage;

    // Matrix for decrypteing
    char matrix[m_rails][message.length()];

    // Fill matrix with dashes
    for(int i = 0; i < m_rails; i++){
        for(unsigned int j = 0; j < message.length(); j++){
            matrix[i][j] = '_';
        }
    }

    bool dir = false;
    int row = 0;
    int col = 0;

    // Place marker along fences
    for (unsigned int i = 0; i < message.length(); i++) {

        if(row == 0){
            dir = true;
        }
        if(row == m_rails-1){
            dir = false;
        }

        // place the marker
        matrix[row][col] = '*';
        col++;

        // find the next row using direction flag
        if(dir){
            row++;
        }else{
            row--;
        }

    }

    // Fill markers with letters from encrypted message
    unsigned int index = 0;
    for(int i = 0; i < m_rails; i++){
        for(unsigned int j = 0; j < message.length(); j++){
            if(matrix[i][j] == '*' and index < message.length()){
                matrix[i][j] = message[index];
                index++;
            }
        }
    }

    row = 0;
    col = 0;

    // Read off message in fences to show hidden message
    for(unsigned int i = 0; i < message.length(); i++){

        if(row == 0){
            dir = true;
        }
        if(row == m_rails-1){
            dir = false;
        }

        if(matrix[row][col] != '*'){
            newMessage += matrix[row][col];
            col++;
        }

        if(dir){
            row++;
        }else{
            row--;
        }
    }

    // Update message
    SetMessage(newMessage);


}





// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (RailFence in this case)
string RailFence::ToString() {

    return "RailFence";
}






// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - r, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_rails are returned for output
string RailFence::FormatOutput() {

    // Using string stream to format cipher for export
    stringstream ss;

    ss << "r|" << GetIsEncrypted() << "|" << GetMessage() << "|" << m_rails << endl;
    return ss.str();

}





























