#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
// #include <cstdlib>
using namespace std;

bool checkString(string current, string search) {
    if (current == search) {
            // cout << "found " << search << endl;
            return true;
    }
    // cout << current << "|" << search << "|" << endl;
    return false;
}

int getFile(string file, string search) {
    ifstream indata;
    indata.open(file);
    if (!indata) {
        cerr << "Error: file could not be opened.\n";
        return 0;
    }
    int wordcount = 0;
    string content;
    indata >> content;
    while (!indata.eof()) {
        wordcount++;
        // cout << content << endl;
        if ((search.find(".") != string::npos) || (search.find(",") != string::npos) || (search.find("?") != string::npos) || (search.find("!") != string::npos) || (search.find(";") != string::npos) || (search.find(":") != string::npos)) {
            search.pop_back();
            // cout << "*";
            // cout << content << "*\n";
        } 
        if (checkString(content, search)) {
            return wordcount;
        }        
        indata >> content;
    }
    cout << endl << "Unknown \n";
    return 0;
}

int main() {
    // initialize variables.
    string file;
    vector<string> inputWords;
    string input, word;

    // get file name.
    cout << "What file do you want to use: ";
    getline(cin, file);
    
    // get words to convert to cipher.
    cout << "What do you want to search for: ";
    getline(cin, input);
    stringstream s(input);
    while (getline(s, word, ' ')) {
        inputWords.push_back(word);
        // cout << word << endl;
    } //  Talk to bro. Macbeth
    // atoi(someIntAsString) converts to int.

    // set up iterator for words.
    vector<string>::iterator it;

    // iterate through words, converting to cipher.
    for(it=inputWords.begin();it!=inputWords.end();it++){
        // cout << *it << endl;
        cout << getFile(file, *it) << " ";
        // cout << endl;
    }
    cout << endl;

    return 0;
}
