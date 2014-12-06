#include "translator.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

    if (argc!=2 && argc!=3){
        cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
        cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
        return 0;
    }

    ifstream f (argv[1]);
    if (!f){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    Translator source_trans;
    f >> source_trans; //Cargamos en memoria, en el traductor.
    Translator dest_trans;

    dest_trans = Translator::getInverse(source_trans);

    if (argc==2)
        cout << dest_trans;
    else{
        
        ofstream fout(argv[2]);
        if (!fout){
            
            cout<<"No puedo crear el fichero "<<argv[2]<<endl;
            return 0;
        
        }
        fout << dest_trans;

    }
}