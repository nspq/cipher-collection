//Title: Ong.cpp
//Author: Nabeel Syed
//Date: 4/20/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC

#include "Ong.h"



// Name: Ong (Default Constructor)
// Desc: Constructor to build an empty Ong Cipher
// Preconditions - None
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong():Cipher() {}




// Name: Ong (Overloaded Constructor)
// Desc: Constructor to build a populated Ong Cipher
// Preconditions - Pass it the message and isEncrypted
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong(string message, bool isEncrypted): Cipher(message, isEncrypted) {}






// Name: Ong (Destructor)
// Desc: Destructor - Anything unique to Ong to delete?
// Preconditions - ~Ong exists
// Postconditions - Ong destroyed
Ong::~Ong(){}




// Name: IsVowel (Helper function)
// Desc: Returns true if vowel, space, or punctuation
// Preconditions - Message exists
// Postconditions - Returns true or false as above
bool Ong::IsVowel(char c) {

    // Check is given character is a vowel
    if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'){
        return true;
    }else{
        return false;
    }
}


// Name: Encrypt
// Desc: If vowel then vowel and dash displayed. dog = dong-o-gong
// If consonant then consonant and ong and dash displayed.
// Preconditions - Message exists
// Postconditions - Encrypts as above
void Ong::Encrypt() {

    // Strings to hold decrypted and encrypted messages
    string message = GetMessage();
    string newMessage;

    // Loop through message to be encyrpted
    for(unsigned int i = 0; i < message.length()-1; i++){

        // If character is a letter than encrypt, otherwise leave as is
        char c = message[i];
        if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z')){

            // Vowels recieve a dash afterwards
            if(IsVowel(c)){

                if((message[i+1] < 'a' or message[i+1] > 'z') and (message[i+1] < 'A' or message[i+1] > 'Z')){
                    newMessage += c;
                }else{
                    newMessage += c;
                    newMessage += "-";
                }

            }else{

                // Consonants become 'ong'
                newMessage += c;
                if((message[i+1] < 'a' or message[i+1] > 'z') and (message[i+1] < 'A' or message[i+1] > 'Z')){
                    newMessage += "ong";
                }else{
                    newMessage += "ong-";
                }

            }
        }else{
            newMessage += c;
        }
    }

    // Encrypt the last letter since it is not covered by for loop
    char c = message[message.length() - 1];
    if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z')){
        if(IsVowel(c)){
            newMessage += c;
        }else{
            newMessage += c;
            newMessage += "ong";
        }
    }else{
        newMessage += c;
    }


    SetMessage(newMessage);


}





// Name: Decrypt
// Desc: Removes the dashes and "ong" when necessary cong-a-tong = cat
// Double check words like "wrong" so that they work correctly!
// Preconditions - Message exists
// Postconditions - Original message is displayed
void Ong::Decrypt() {

    // Strings for holding encrypted and decrypted messages
    string message = GetMessage();
    string newMessage;

    // Add the first letter
    newMessage += message[0];

    // Loop through encrypted message
    for(unsigned int i = 0; i < message.length() - 1; i++){

        // Remove all '-'s and 'ong's from message to reveal hidden message
        if(message[i] == '-'){
            newMessage += message[i+1];
        }else if((message[i] < 'a' or message[i] > 'z') and (message[i] < 'A' or message[i] > 'Z')){
            newMessage += message[i];
            if((message[i+1] >= 'a' and message[i+1] <= 'z') or (message[i+1] >= 'A' and message[i+1] <= 'Z')){
                newMessage += message[i+1];
            }

        }

    }

    // Check the last letter since it is not covered by for loop
    if(message[message.length() - 1] != 'g' and message[message.length() - 1] != '-'){
        newMessage += message[message.length() - 1];
    }


    SetMessage(newMessage);

}







// Name: ToString
// Desc - A function that returns the string of the object type
// Preconditions - The object exists
// Postconditions - The subtype is returned (Ong in this case)
string Ong::ToString() {

    return "Ong";
}





// Name: FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - o, delimiter, isencrypted, delimiter,
//                  message, delimiter, blank are output
string Ong::FormatOutput() {

    // Using string stream to create format for exported ciphers
    stringstream ss;

    ss << "o|" << GetIsEncrypted() << "|" << GetMessage() << "|" << endl;
    return ss.str();
}



