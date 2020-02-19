#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1*2+34)*123");

   Lexer l(chaine);
   Automate * automate = new Automate(&l);
   //Symbole * s;
   //while(*(s=l.Consulter())!=FIN) {
   //   s->Affiche();
   //   cout<<endl;
   //   l.Avancer();
   //}
   automate->lancer();
   return 0;
}

