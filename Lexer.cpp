/*More of a pseudo-codish style of a lexer, inspired 
  by 2 other lexers found on github: 
  1) simple c++ lexer. 
  2) Pnecone language lexer. 
  P.S: only good resoruces found to see how lexers work.
*/

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

class CharClassifier {

    // This is where we define the different types of tokens used ??
public:
    enum Type {
        WHITESPACE,
        LINEBREAK,
        OPERATOR,
        NEWLINE,
        LETTER,
        DIGIT,
        MULTICOMMENT_START,
        MULTICOMMENT_END,
        SINGLECOMMENT,
        STRINGQ,
        UNKNOW,
    };

    // TO DO:
    // I need to check what inline classes are.. 
    // We will need 2 methods, one to get the Token type and another to get the char classifier token type

// Private method to setup the map + unordered map to store our classification + bool to check setup.
private:
    void setUp();
    unordered_map<char, CharClassifier::Type> tkMap;
    bool hasSetUp = false;
};

// We need a function to do the setup of the tkMap
void CharClassifier::setUp() {
    tkMap[' '] = WHITESPACE;
    tkMap['\r'] = WHITESPACE; // a comment says this is windows style line ending (trust)
    tkMap['\t'] = WHITESPACE;

    tkMap[';'] = LINEBREAK;

    tkMap['\n'] = NEWLINE;
    
    tkMap['\\'] = SINGLECOMMENT;
    
    tkMap['"'] = STRINGQ;

    //add [a-z][A-Z] to our map in a single loop + _ as a letter
    char capitalLetter = 'A';
    for (char letter = 'a'; letter <= 'z'; letter++) {
        tkMap[letter] = LETTER;
        tkMap[capitalLetter] = LETTER;
        capitalLetter++;
    }
    tkMap['_'] = LETTER;

    //add all digits to the map, using char as map takes a char
    for (int n = 0; n <= 9; n++) {
        tkMap[(char)n] = DIGIT; // TODO: try without casting char ?? 
    }

    //TO DO:
    //I need to find a way to classify the OPERATORS AS WELL

    hasSetUp = true;
}
