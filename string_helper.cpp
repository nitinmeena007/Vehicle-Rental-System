// including custom headers
#include "string_helper.h"

vector<string> split (const string &s, char delimiter) {
    vector<string> tokens;
    string token;

    // stringstream is a derived class of iostream;
    // it makes a i/o stream of string , it allows the user to work with a string
    // it makes the parsing of input easy and user can convert any primitve data type to string easily
    istringstream tokenStream (s);

    // getline function for char array, istream &getline (char*, int size);
    
    // istream &getline (istream &is, string &str, char delimiting)
    // in above line istream can be replaced by istringstream
    while(getline(tokenStream,token,delimiter)){
        tokens.push_back(token);
    }

    return tokens;

}