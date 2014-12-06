#include "translator.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con las traducciones"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Translator translator;
   f >> translator; //Cargamos en memoria, en el traductor.
   
   string a;
   cout<<"Dime una palabra en el idioma origen:";
   getline(cin,a);
   
   Word new_word(a, translator.getTranslations(a));

   cout << new_word;
   
   



}