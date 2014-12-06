#ifndef TRANSLATOR
#define TRANSLATOR

#include <iostream>
#include "word.h"
#include <fstream>
#include <string>
#include <set>
#include <map>

using namespace std;
/**
* @class Translator
* @brief TDA Translator. Cada instancia de Translator es 
* un diccionario traductor que contiene todas las palabras de un 
* idioma junto con sus traducciones en el idioma al que se quiere
* traducir.
*/
class Translator{
private:

    multimap <string, string> translator;

public:

// ---------------------- Iteradores ----------------------

    /** 
    * @class Translator::iterator 
    * @brief Iterador para iterar sobre
    * las entradas que tiene el traductor.
    */
    class iterator {

    private:

        multimap <string, string>::iterator it;

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
        const pair <string, string> operator*() const {
            
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

        friend class Translator;
        friend class const_iterator;

    };
    
    /** 
    * @class Translator::const_iterator 
    * @brief Iterador para iterar sobrelas entradas 
    * que tiene el traductor de forma constante.
    */
    class const_iterator {

    private:

        multimap <string, string>::const_iterator it;

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
        const pair <string, string> operator*() const {
            
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

        friend class Translator;

    };

/**
* @brief Constructor por defecto de la clase Translator.
* Crea un traductor vacio, que no contiene ninguna palabra.
*/    
    Translator();
/**
* @brief Constructor de copia de la clase Translator.
*/
    Translator(const Translator &other);
/**
* @brief Constructor por parámetros de la clase Translator.
* @param dict Multimap que se va a copiar en el traductor.
*/
    Translator(const multimap <string, string> &dict);
/**
* @brief Metodo que permite agregar un objeto de la clase Word
* al traductor.
*/
    void addWord(Word new_word);
/**
* @brief Metodo que permite construir una instancia de la clase
* Word a partir de una linea. Este metodo es auxiliar a la 
* sobrecarga del operator>>(istream &input, Translator &translator).
* @param line String que contiene una linea a partir de la cual
* se crea la nueva palabra.
* @return Objeto de la clase Word que se ha creado. 
*/
    Word makeWord(string line);
/**
* @brief Metodo que devuelve todas las traducciones de una palabra.
* Busca si hay alguna palabra en el Translator que tenga como palabra
* base el string que se pasa como argumento, y si existe una
* coincidencia, devolver el set de traducciones asociado.
* @param word String que representa la palabra sobre la que se
* busca la traduccion.  
* @return Un set de strings con las traducciones buscadas.
*/
    set <string> getTranslations(string word);
/**
* @brief Metodo que invierte el traductor que tenemos.
* @param src Traductor que va a invertirse.
* @return Un traductor cuyo idioma origen es el idioma de destino
* del primero, y el idioma destino es el idioma origen del primero.
*/
    static Translator getInverse(Translator &src);
/**
* @brief Metodo que compone dos traductores. Dados dos traductores
* como argumento, el primero que traduce del idioma A al B, y el
* segundo que traduce del B al C, se obtiene como resultado un 
* traductor que traduce del A al C.
* @pre El idioma destino del primer traductor ha de ser el de origen
* del segundo.
* @param first Traductor A->B
* @param second Traductor B->C
* @return Traductor A->C
*/
    static Translator compose(Translator &first, Translator &second);
/**
* @brief Metodo que interseca dos traductores, de forma que se 
* devuelve un nuevo traductor que contiene las palabras que son
* comunes en el idioma de origen y tienen al menos una traducción
* igual en el idioma de destino.
* @pre Los idiomas origen de los traductores a intersecar han de 
* ser distintos, y el destino de ambos el mismo.
* @return Un traductor con las coincidencias de ambos idiomas.
*/
    static Translator intersect(Translator &first, Translator &second);
/**
* @brief Sobrecarga del operador de entrada de datos. Permite que
* se rellene un Translator a partir de un archivo que se pasa.
* @param input Archivo al que se accede para crear el Translator.
* @param translator Translator que se va a rellenar.
* @pre El archivo de entrada tiene que tener el siguiente esquema
* en cada linea:
* palabra_base;traduccion;traduccion;...
* @post Translator tiene que tener un objeto de la clase Word
* por cada linea del archivo de entrada, y ademas estar ordenado.
* @return Se devuelve el archivo de entrada, para que pueda
* utilizarse de nuevo.
*/
    friend istream &operator>>(istream &input, Translator &translator);
/**
* @brief Sobrecarga del operador de entrada de datos. Nos va a
* servir para imprimir por pantalla el traductor, o volcarlo en
* un archivo.
*/
    friend ostream &operator<<(ostream &output, Translator &translator);
};
#endif