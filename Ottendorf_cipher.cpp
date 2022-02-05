#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
// #include <cstdlib>
using namespace std;
class Ottendorf_Cipher {
    public:
        bool checkString(string current, string search);
        bool checkPos(int currentPos, int neededPos);
        void getFile(string doing, string file, string search, bool Nfile);
        void interface();
};
    bool Ottendorf_Cipher::checkString(string current, string search) {
        if (current == search) {
            // cout << "found " << search << endl;
            return true;
        }
        // cout << current << "|" << search << "|" << endl;
        return false;
    }

    bool Ottendorf_Cipher::checkPos(int currentPos, int neededPos) {
        if (currentPos == neededPos) {
            return true;
        }
        return false;
    }

    void Ottendorf_Cipher::getFile(string doing, string file, string search, bool Nfile) {
        // Initialize variables
        int wordcount = 0;
        string content;
        int position;

        // remove punctuation.
        if ((search.find(".") != string::npos) || (search.find(",") != string::npos) || (search.find("?") != string::npos) || (search.find("!") != string::npos) || (search.find(";") != string::npos) || (search.find(":") != string::npos)) {
            search.pop_back();
        }

        // Set up if deciphering.
        if (doing == "decipher") {
            position = stoi(search);
        }

        ifstream indata;
        indata.open(file);
        if (!indata) {
            cerr << "Error: file could not be opened.\n";
            return;
        }
        indata >> content;
        while (!indata.eof()) {
            if (Nfile) {
                // if (char(content[0]) <= 90) {
                //     content[0] == char(content[0]) + 32;
                // }
                if ((content.find(".") != string::npos) || (content.find(",") != string::npos) || (content.find("?") != string::npos) || (content.find("!") != string::npos) || (content.find(";") != string::npos) || (content.find(":") != string::npos)) {
                    content.pop_back();
                }
            }
            wordcount++;
            if (doing != "decipher") {
                if (checkString(content, search)) {
                    cout << wordcount << " ";
                    return;
                }
            } else {
                if (checkPos(wordcount, position)) {
                    cout << content << " ";
                    return;
                }
            }
            indata >> content;
        }
        cout << search << " ";
        return;
    }

    void Ottendorf_Cipher::interface() {
        // initialize variables.
        string file;
        vector<string> inputWords;
        string input, word;
        string doing;
        string checkNewFile;
        bool Nfile;

        // Check if the user wants to use their own file.
        cout << "Do you want to use you own file? (Y/N) ";
        getline(cin, checkNewFile);
        if (checkNewFile == "Y" || checkNewFile == "y") {
            Nfile = true;
            // Give warning about reading capabilities, and capitulization. 
            cout << "Please be aware that we currently can only access the first line of files,\n and capital letters are different from their non-capital counter-parts.";
            // get file name.
            cout << "What file do you want to use: ";
            getline(cin, file);
        } else {
            // Set up for usage of inherent text file.
            Nfile = false;
            file = "text.txt";
        }

        // get what the user is doing
        cout << "Are you deciphering something? (Y/N) ";
        getline(cin, doing);
        if (doing == "Y" || doing == "y") {
            doing = "decipher";
        }
        // get search items to convert to cipher.
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
            getFile(doing, file, *it, Nfile);
            // cout << endl;
        }
        cout << endl;
    }

int main () {
    Ottendorf_Cipher cipher;
    cipher.interface();
}