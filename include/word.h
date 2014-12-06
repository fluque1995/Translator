#ifndef WORD
#define WORD

#include <string>
#include <set>

using namespace std;
/**
* @class Word. 
* @brief TDA Word. Cada instancia de este TDA Word es una 
* palabra en el idioma origen, que lleva además asociada sus 
* traducciones en el idioma al que se quiere traducir.
**/
class Word{

private:

    string word;

    set <string> translations;

public:
// ------------- Iterador sobre las traducciones ------------
    /** 
    * @class Word::iterator 
    * @brief Iterador para iterar sobre
    * las entradas que tiene el traductor.
    */
    class iterator {

    private:

        set <string>::iterator it;

    public:
/**
    * @brief Sobrecarga del operador ++ prefijo.
    */
        iterator& operator++(){
            ++(this->it);

            return *this;
        }
    /**
    * @brief Sobrecarga del operador ++ postfijo.
    */
        iterator operator++(int){
            
            iterator tmp = *this;

            ++(this->it);

            return tmp;
        }
    /**
    * @brief Sobrecarga del operador -- prefijo.
    */
        iterator& operator--(){
            --(this->it);

            return *this;
        }
    /**
    * @brief Sobrecarga del operador -- postfijo.
    */
        iterator operator--(int){
            
            iterator tmp = *this;

            --(this->it);

            return tmp;
        }
    /**
    * @brief Sobrecarga del operador de referencia.
    */
        string operator*() const {
            
            return *(this->it);
        }
    /**
    * @brief Sobrecarga del operador de igualdad.
    */
        bool operator==(const iterator &it) const {

            return this->it == it.it;

        }
    /**
    * @brief Sobrecarga del operador !=.
    */
        bool operator!=(const iterator &it) const {

            return this->it != it.it;

        }

        friend class Word;
        friend class const_iterator;

    };
    /** 
    * @class Word::const_iterator 
    * @brief Iterador para iterar sobrelas entradas 
    * que tiene el traductor de forma constante.
    */
    class const_iterator {

    private:

        set <string>::const_iterator it;

    public:
    /**
    * @brief Sobrecarga del constructor de copia.
    */
        const_iterator(const iterator &it){

            this->it = it.it;

        }
    /**
    * @brief Sobrecarga del operador ++ prefijo.
    */

        const const_iterator& operator++(){
            ++(this->it);

            return *this;
        }
    /**
    * @brief Sobrecarga del operador ++ postfijo.
    */
        const_iterator operator++(int){
            
            const_iterator tmp = *this;

            ++(this->it);

            return tmp;
        }
    /**
    * @brief Sobrecarga del operador -- prefijo.
    */
        const_iterator& operator--(){
            --(this->it);

            return *this;
        }
    /**
    * @brief Sobrecarga del operador -- postfijo.
    */
        const_iterator operator--(int){
            
            const_iterator tmp = *this;

            --(this->it);

            return tmp;
        }
    /**
    * @brief Sobrecarga del operador de referencia.
    */
        const string operator*() const {
            
            return *(this->it);
        }
    /**
    * @brief Sobrecarga del operador de igualdad.
    */
        bool operator==(const iterator &it) const {

            return this->it == it.it;

        }
    /**
    * @brief Sobrecarga del operador !=.
    */
        bool operator!=(const iterator &it) const {

            return this->it != it.it;

        }

        friend class Word;

    };
// ---------------- Metodos de la clase Word ----------------

/**
* @brief Constructor de la clase Word.
* @param word String que representa la palabra en
* el idioma de origen.
* @param translations Vector de strings que contiene las traducciones
* de la palabra origen.
* @post Se ha creado un nuevo objeto de la clase Word a partir
* de los parametros que se han pasado.
*/
    Word(string word, set <string> translations);
/**
* @brief Sobrecarga del operador de asignacion.
* @param other Word que se quiere copiar.
* @return Instancia de la clase Word.
* @post La palabra se ha copiado en la otra instacia.
*/
    Word & operator=(const Word &other);
/**
* @brief Metodo que devuelve la palabra en el idioma origen.
* @return Referencia a dicho string que representa la palabra.
*/
    string &getWord();
/**
* @brief Metodo que devuelve el set de traducciones completo.
* @return Vector de strings con todas las traducciones.
*/
    set <string> &getTranslations();
/**
* @brief Obtencion del numero de traducciones que tiene una
* palabra.
*/
    int size();
/**
* @brief Sobrecarga del operador de comparacion < entre dos 
* objetos de la clase Word.
*/
    inline bool operator<(const Word &other) const{
        return this->word < other.word;
    }
/**
* @brief Sobrecarga del operador de comparacion < entre un 
* objeto de la clase Word y un string. Se compara el string
* con la palabra del idioma origen.
*/
    inline bool operator<(const string &word) const{
        return this->word < word;
    }
/**
* @brief Sobrecarga del operador de comparacion > entre dos 
* objetos de la clase Word.
*/
    inline bool operator>(const Word &other) const{
        return this->word > other.word;
    }
/**
* @brief Sobrecarga del operador de comparacion > entre un 
* objeto de la clase Word y un string. Se compara el string
* con la palabra del idioma origen.
*/
    inline bool operator>(const string &word) const{
        return this->word > word;
    }
/**
* @brief Sobrecarga del operador de comparacion <= entre dos 
* objetos de la clase Word.
*/
    inline bool operator<=(const Word &other) const{
        return this->word <= other.word;
    }
/**
* @brief Sobrecarga del operador de comparacion <= entre un 
* objeto de la clase Word y un string. Se compara el string
* con la palabra del idioma origen.
*/
    inline bool operator<=(const string &word) const{
        return this->word <= word;
    }
/**
* @brief Sobrecarga del operador de comparacion >= entre dos 
* objetos de la clase Word.
*/
    inline bool operator>=(const Word &other) const{
        return this->word >= other.word;
    }
/**
* @brief Sobrecarga del operador de comparacion >= entre un 
* objeto de la clase Word y un string. Se compara el string
* con la palabra del idioma origen.
*/
    inline bool operator>=(const string &word) const{
        return this->word >= word;
    }
/**
* @brief Sobrecarga del operador de igualdad entre dos 
* objetos de la clase Word.
*/
    inline bool operator==(const Word &other) const{
        return this->word == other.word;
    }
/**
* @brief Sobrecarga del operador de igualdad entre un 
* objeto de la clase Word y un string. Se compara el string
* con la palabra del idioma origen.
*/
    inline bool operator==(const string &word) const{
        return this->word == word;
    }
/**
* @brief Sobrecarga del operador != entre dos 
* objetos de la clase Word.
*/
    inline bool operator!=(const Word &other) const{
        return this->word != other.word;
    }
/**
* @brief Sobrecarga del operador != entre un 
* objeto de la clase Word y un string. Se compara el string
* con la palabra del idioma origen.
*/
    inline bool operator!=(const string &word) const{
        return this->word != word;
    }
/**
* @brief Devuelve un iterador a la primera traduccion de la palabra
*/
    iterator begin(){
        iterator it;
        it.it = this->translations.begin();
        return it;
    }
/**
* @brief Devuelve un iterador a la ultima traduccion de la palabra
*/
    iterator end(){
        iterator it;
        it.it = this->translations.end();
        return it;
    }
/** 
* @brief Sobrecarga del operador de salida.
*/
    friend ostream &operator<<(ostream &output, const Word &word);
};

#endif
