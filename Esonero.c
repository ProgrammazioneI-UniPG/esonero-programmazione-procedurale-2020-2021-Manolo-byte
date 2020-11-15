#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
  int f=0, x=0, p=0, a=0, k=0; //Inizializzazione delle variabili
  time_t tempo;
  char ch, ch2;
  char plaintext[128], key[128], encrypted[128], decrypted[128]; //Array di caratteri
  printf("Inserisci il plaintext: \n");
  fgets(plaintext, 128, stdin); //Inserimento del plaintext
  p = strlen(plaintext); //Calcololo della lunghezza del plaintext
  if(p>126){
    while((ch = getchar()) != '\n' && ch != EOF); //Azzera il buffer
  }
  printf("----Menù----\n");
  printf("Scegli 1 se vuoi inserire tu stesso la key\n");
  printf("Scegli 2 se vuoi generare randomicamente una key\n");
  scanf("%d", &a); //Scelta nel menù
  while((ch2 = getchar()) != '\n' && ch2 != EOF); //Azzera il buffer
  switch(a){
    case 1:
      while(f==0){
        if(k<p){
          printf("Inserisci la key, però deve essere maggiore o uguale al plaintext: \n");
          fgets(key, 128, stdin); //Inserimento della chiave da utente
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
  printf("Ecco la stringa decriptata: %s\n", decrypted); //Restituzione della parola decriptata
}
