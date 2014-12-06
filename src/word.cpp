#include "word.h"
#include <iostream>

using namespace std;

Word::Word(string word, set <string> translations){
    this->word = word;
    int size = translations.size();
    set <string>::iterator it = translations.begin(),
                           end = translations.end();
   
    for(; it != end; ++it){
        this->translations.insert(*it);
    }
}

Word & Word::operator= (const Word &other){
    this->word = other.word;
    this->translations = other.translations;
    return *this;
}

string &Word::getWord(){
    return this->word;
}

set <string> &Word::getTranslations(){
    return this->translations;
}

int Word::size(){
    return this->translations.size();
}

ostream &operator<<(ostream &output, const Word &new_word){

    output << new_word.word << "-->";
   
    set <string>::iterator start = new_word.translations.begin(),
                           end = new_word.translations.end(),
                           it;

    for(it = start; it != end; ++it){
        output << *it << ';';
    }
    output << endl;

    return output;
}
