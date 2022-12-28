//Title: Cipher.cpp
//Author: Nabeel Syed
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC

#include "Cipher.h"


// Name: Cipher (Default Constructor)
// Desc - Stores a message and if it is encrypted (or not)
// Preconditions - None
// Postconditions - A message is stored in a Cipher object
Cipher::Cipher() {

    m_isEncrypted = 0;
    m_message = "This is a Cipher";
}



// Name: Cipher (Overloaded Constructor)
// Desc - Passed a message and if it is encrypted (or not)
// Preconditions - A message is passed to this constructor, and if it is encrypted
// Postconditions - A message is stored in a Cipher object
Cipher::Cipher(string message, bool isEncrypted) {

    m_message = message;
    m_isEncrypted = isEncrypted;
}





// Name: ~Cipher (Destructor)
// Desc - Virtual destructor
// Preconditions - A derived class is being deleted
// Postconditions - A base class is deleted
Cipher::~Cipher() {}




// Name: GetMessage
// Desc - Returns the message
// Preconditions - The message exists
// Postconditions - A message is returned
string Cipher::GetMessage() {

    // Returns current message of Cipher
    return m_message;
}





// Name: GetIsEncrypted
// Desc - Returns isEncrypted (0 is not encrypted and 1 is encrypted)
// Preconditions - The cipher exists
// Postconditions - A bool is returned
bool Cipher::GetIsEncrypted() {

    // Returns bool if message is encrypted or not
    return m_isEncrypted;
}






// Name: SetMessage
// Desc - Updates a message
// Preconditions - The message exists
// Postconditions - A message is updated
void Cipher::SetMessage(string message) {

    // Sets message to given message
    m_message = message;
}






// Name: ToggleEncrypted
// Desc - Turns (true to false) or (false to true)
// Preconditions - The cipher exists
// Postconditions - The m_isEncrypted is toggled
void Cipher::ToggleEncrypted() {

    // Boolean toggle
    m_isEncrypted = !m_isEncrypted;
}





// Name: ToString
// Desc - A purely virtual function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned
//virtual string ToString() = 0;



// Name: FormatOutput
// Desc - A purely virtual function that returns the formatted data for Output
// Preconditions - The object exists
// Postconditions - The type, message, and key are output
//virtual string FormatOutput() = 0;



// Name: Overloaded << Operator
// Desc - Outputs the message
// Preconditions - The object exists
// Postconditions - The message from the object is returned
//friend ostream &operator<<( ostream &output, Cipher &C);

ostream &operator<<(ostream &output, Cipher &C){

    // Overloaded << operator
    output << C.m_message << " (" << C.ToString() << ")" << endl;
    return output;
}













