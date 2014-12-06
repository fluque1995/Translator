#include "translator.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

    if (argc!=4){
        cout << "Dime el nombre de los dos ficheros de origen " <<
                "y el nombre del fichero de salida" << endl;
        return 0;
    }

    ifstream f_first(argv[1]);
    ifstream f_second(argv[2]);
    
    if (!f_first || !f_second){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    Translator first_source, second_source, composed_trad;
    f_first >> first_source; //Cargamos en memoria, en el traductor.
    f_second >> second_source;

    composed_trad = Translator::compose(first_source, second_source);
    ofstream fout(argv[3]);

    if (!fout){
        cout << "No puedo crear el fichero " << argv[3] << endl;
        return 0;
    }
    fout << composed_trad;
}