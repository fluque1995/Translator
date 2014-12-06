#include <set>
#include "translator.h"
#include "word.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <utility>

Translator::Translator(){}

Translator::Translator(const Translator &other){
    this->translator = other.translator;
}

Translator::Translator(const multimap <string, string> &dict){
    this->translator = dict;
}

void Translator::addWord(Word new_word){
    
    string word, translation;
    word = new_word.getWord();
    Word::iterator it = new_word.begin(), end = new_word.end();
    pair <string, string> curr_word(word,""); 

    for (; it != end; ++it){
        
        curr_word.second = *it;
        translator.insert(curr_word);
    }
}

Word Translator::makeWord(string line){
    
    const char limit = ';';
    bool inserted = false;
    string curr, word;
    set <string> translations;
    int size = line.size();
    
    for (int i = 0; i < size; i++){
    
        if (line[i] != limit){
        
            curr.push_back(line[i]);

        }else if(inserted){
        
            translations.insert(curr);
            curr.clear();
        
        }else{
        
            word = curr;
            inserted = true;
            curr.clear();
        
        }
    }
    
    Word new_word(word, translations);
    return new_word;
}

set <string> Translator::getTranslations(string word){
    
    set <string> translations;
    multimap <string, string>::iterator begin = this->translator.lower_bound(word),
                                        end = this->translator.upper_bound(word),
                                        it;
    for(it = begin; it != end; ++it){

        translations.insert(it->second);
    }

    return translations;
    
}

Translator Translator::getInverse(Translator &src){

    multimap <string, string> inverse_trans,
                              src_trans = src.translator;
    multimap <string, string>::iterator it = src_trans.begin(),
                                        end = src_trans.end();
    pair <string, string> curr_word;
    string base, translation;

    for(; it != end; ++it){
        base = it->first;
        translation = it->second;
        curr_word = pair <string, string> (translation, base);
        inverse_trans.insert(curr_word);
    }

    return Translator(inverse_trans);

};

Translator Translator::compose(Translator &first, Translator &second){

    multimap <string, string> first_trans = first.translator,
                              second_trans = second.translator,
                              result_trans;

    multimap <string, string>::iterator f_it = first_trans.begin(),
                                        f_end = first_trans.end(),
                                        curr_stop,
                                        s_it, 
                                        s_stop;

    string begin, mid, end;

    pair <string, string> curr_word;

    while(f_it != f_end){

        begin = f_it->first;
        curr_stop = first_trans.upper_bound(begin);

        while(f_it != curr_stop){
            mid = f_it->second;
            s_it = second_trans.lower_bound(mid);
            s_stop = second_trans.upper_bound(mid);
            
            while(s_it != s_stop){
                end = s_it->second;
                curr_word = pair <string, string>(begin, end);
                result_trans.insert(curr_word);
                ++s_it;
            }
            f_it = curr_stop;
        }
    }
    return Translator(result_trans);
};

Translator Translator::intersect(Translator &first, Translator &second){

    multimap <string, string> first_trans = first.translator,
                              second_trans = second.translator,
                              result_trans;

    multimap <string, string>::iterator f_it = first_trans.begin(),
                                        f_end = first_trans.end(),
                                        s_it,
                                        f_curr_stop,
                                        s_curr_stop;

    string first_key, first_value, second_value;

    pair <string, string> curr_word;

    while(f_it != f_end){
    
        first_key = f_it->first;
        f_curr_stop = first_trans.upper_bound(first_key);

        while(f_it != f_curr_stop){
    
            first_value = f_it->second;
            s_it = second_trans.lower_bound(first_key);
            s_curr_stop = second_trans.upper_bound(first_key);
            
            while(s_it != s_curr_stop){
    
                second_value = s_it->second;
                
                if(first_value == second_value){
                
                    curr_word = pair <string, string>(first_key, first_value);
                    result_trans.insert(curr_word);
                }
                ++s_it;
            }

            ++f_it;
        }
    }

    return Translator(result_trans);
}

istream &operator>>(istream &input, Translator &translator){
    string line;
    
    while(getline(input, line)){
        Word new_word = translator.makeWord(line);
        translator.addWord(new_word);
    }

    return input;
}

ostream &operator<<(ostream &output, Translator &trans){

    string curr_line, base;
    multimap <string, string>::iterator it = trans.translator.begin(),
                                        end = trans.translator.end(),
                                        curr_stop;

    while(it != end){

        base = it->first;
        curr_stop = trans.translator.upper_bound(base);
        curr_line = base;
        curr_line.append(";");
        
        while(it != curr_stop){
            curr_line.append(it->second);
            curr_line.append(";");
            ++it;
        }

        output << curr_line << endl;
        curr_line.clear();
    }

    return output;
}