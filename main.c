#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ovaj opener prompt
void opener() {
  FILE *optxt = fopen("opener.txt", "r");
  if (optxt == NULL) {
    printf("Failed to open opener.txt\n");
    return;
  }

  char buffer[128];
  while (fgets(buffer, sizeof(buffer), optxt) != NULL) {
    printf("%s", buffer);
  }
  
  fclose(optxt);
  
}

//funkcija za biranje opcije posto je manje komplikovano nego pisati sve ovo svaki put
void option(unsigned *opt){

  unsigned OPCIJA;
  printf("Please select one of the available options \n");
  scanf("%u", &OPCIJA);
  *opt = OPCIJA;
 
}

/*#####################################################################################################
* Funckije za option
* Za removeContent: string koji treba da se obrise, svako pojavljivanje u 1 fajlu/prvo sa leve/prvo sa desne
* Za addContent: String koji treba da se doda, da li na pocetak ili kraj
* Za enumAlpha: Alpha ili InverseAlpha order
*
#####################################################################################################*/

void removeContent(){

  char obrisati[121]; //za sada 121 posto je win10 file name limit oko 32k
  unsigned opt;

  printf("Enter the string you want to remove(120 char limit): \n");
  fgets(obrisati, 121, stdin);
  getchar();

  puts("[1] Every occurance");
  puts("[2] First from the right");
  puts("[3] First from the left");

  option(&opt);

}

void main() {

  unsigned opt;

  opener();
  printf("\n");
  
  option(&opt);

  switch(opt){          //Printf je privremen, kako budem pisao funckije samo cu menjati sa function callovima

    case 1: 
          printf("Selected Remove Content \n");
          removeContent();
          break;
          

    case 2: 
          printf("Selected Add Content \n");
          break;

    case 3: 
          printf("Selected Enumerate Files Alphabetically \n");
          break;

    default: option(&opt);

  }
  

  getchar();
  system("pause"); //Flashback na nedine katabaze posto izgleda da CMD samo umre ako ne stavim ova 2
}
