//Title: Caesar.cpp
//Author: Nabeel Syed
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#include "Caesar.h"



// Name: Caesar (Default Constructor)
// Desc: Constructor to build an empty Caesar Cipher (Defaults to shift 3)
// Preconditions - None
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar():Cipher() {

    // Set shift to 3 by default
    m_shift = 3;
}



// Name: Caesar (Overloaded Constructor)
// Desc: Constructor to build a populated Caesar Cipher (Defaults to shift 3)
// Preconditions - Pass it the message, isEncrypted, and shift (any integer)
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar(string message, bool isEncrypted, int shift): Cipher(message, isEncrypted) {

    // Overload shift
    m_shift = shift;
}





// Name: Caesar (Destructor)
// Desc: Destructor - Anything specific to Caesar to delete?
// Preconditions - ~Caesar exists
// Postconditions - Caesar destroyed
Caesar::~Caesar(){}




// Name: Encrypt
// Desc: Shifts characters right based on shift (lower stay lower, upper stay upper)
// Preconditions - Message exists
// Postconditions - Shifts each character "right".
void Caesar::Encrypt() {

    // Strings to store encrypted and decrypted messages
    string message = GetMessage();
    string newMessage;

    // Loop through message to be encrypted
    for(char c : message){

        // Shift letters to the right (lowercase and uppercase)
        if((c >= 'a' and c <= 'z')){
            if(m_shift%26 > 'z' - c){
                newMessage += ('a' + ((m_shift%26) - ('z' - c)) - 1);
            }else{
                newMessage += (c+(m_shift%26));
            }

        }else if(c >= 'A' and c <= 'Z') {
            if(m_shift%26 > 'Z' - c){
                newMessage += ('A' + ((m_shift%26) - ('Z' - c)) - 1);
            }else{
                newMessage += (c+(m_shift%26));
            }

        }else{
                // If letter is not in the alphabet, leave as is
                newMessage += c;
        }

    }

    SetMessage(newMessage);
}




// Name: Decrypt
// Desc: Shifts characters left based on shift (lower stay lower, upper stay upper)
// Preconditions - Message exists
// Postconditions - Shifts each character "left".
void Caesar::Decrypt() {

    // Strings to hold messages
    string message = GetMessage();
    string newMessage;

    // Loop through message to be decrypted
    for(char c : message){

        // Shift to the left
        if((c >= 'a' and c <= 'z')){
            if(m_shift%26 > c - 'a'){
                newMessage += ('z' - ((m_shift%26) - (c - 'a')) + 1);
            }else{
                newMessage += (c-(m_shift%26));
            }

        }else if(c >= 'A' and c <= 'Z') {
            if(m_shift%26 > c - 'A'){
                newMessage += ('Z' - ((m_shift%26) - (c - 'A')) + 1);
            }else{
                newMessage += (c-(m_shift%26));
            }

        }else{

            // Unaltered non-letter left as is
            newMessage += c;
        }

    }

    // Set message
    SetMessage(newMessage);


}




// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (Caesar in this case)
string Caesar::ToString() {

    return "Caesar";

}



// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - c, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_shift are returned for output
string Caesar::FormatOutput() {


    // Using string stream to format cipher for export
    stringstream ss;

    ss << "c|" << GetIsEncrypted() << "|" << GetMessage() << "|" << m_shift << endl;
    return ss.str();


}
















