#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
  int f=0, x=0, p=11, a=0, k=0; //Inizializzazione delle variabili
  time_t tempo;
  char ch;
  char plaintext[129]; //Array per la stringa plaintext
  char key[129]; //Array per la key
  char encrypted[129]; //Array per la parola decriptata
  char decrypted[129]; //Array per la parola decriptata
  printf("Inserisci il plaintext: \n");
  fgets(plaintext, 129, stdin); //Inserimento del plaintext
  p = strlen(plaintext); //Calcololo della lunghezza del plaintext
  printf("----Menù----\n");
  printf("Scegli 1 se vuoi inserire tu stesso la key\n");
  printf("Scegli 2 se vuoi generare randomicamente una key\n");
  scanf("%d", &a); //Scelta nel menù
  while((ch = getchar()) != '\n' && ch != EOF); //Azzera il buffer
  switch(a){
    case 1:
      while(f==0){
        if(k<p){
          printf("Inserisci la key, però deve essere maggiore o uguale al plaintext: \n");
          fgets(key, 129, stdin); //Inserimento della chiave da utente
          k = strlen(key); //Calcolo della lunghezza della key
        }
        else{
          f=1; //Uscità dal while perché la chiave è più lunga del plaintext
        }
      }
      break;
    case 2:
      srand((unsigned) time(&tempo));
      for(x=0; x!=p; x++){
        key[x] = rand() % (128)+32; //Generazione e inserimento dei caratteri della key
      }
      printf("Ecco la key generata randomicamente: %s\n", key); //Restituzione della key
      break;
  }
  for(x=0; x!=p; x++){
    encrypted[x]=plaintext[x]^key[x]; //Calcolo dello XOR per la parola criptata
  }
  printf("Ecco la stringa criptata: %s\n", encrypted); //Restituzione della parola criptata
  for(x=0; x!=p; x++){
    decrypted[x]=encrypted[x]^key[x]; //Calcolo dello XOR per la parola decriptata
  }
  printf("Ecco la stringa decriptata: %s", decrypted); //Restituzione della parola decriptata
}
