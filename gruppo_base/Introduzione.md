# Introduzione

## Ambiente di sviluppo
Come IDE potete usare quello che volete. Alcune opzioni sono DevC++, CodeBlocks o Visual Studio Code (oppure la sua versione più leggera).
L'unica cosa che conta è che aggiungiate il supporto per la versione 11 di c++ sul vostro IDE. Vi lascio le istruzioni per CodeBlocks e DevC++. Su Visual Studio dovrebbe essere abilitato in automatico.

### Su CodeBlocks

### Su DevC++
Andate su Tools -> Compiler Option -> General
Cliccate la prima spunta e inserite "-std=c++11", in questo modo:
FOTO
Nella sezione "Program" invece, controllate che sia come da immagine, altrimenti modificate:
FOTO

## Template di gara
```C
#include <bits/stdc++.h>
using namespace std;

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  in.close();
  out.close();
  return 0;
}
```

Questa è più o meno la base per tutto il codice che scriverete per gli esercizi delle olimpiadi. Analizziamo un attimo un paio di cose.

La prima riga include una libreria che comprende tutte le librerie del c++ (non funzionerà se non avete abilitato c++11). Questo vi renderà le cose molto più veloci rispetto a cercare ogni volta quali librerie da includere (non usatelo in classe, non è un buon modo di programmare normalmente).

La seconda riga forse saprete già cos'è, ma vi basti sapere che serve metterla, il perchè non è importante.


Passiamo poi al corpo del main. Escludendo il return 0, le altre istruzioni servono per la lettura e scrittura da/a file, richiesta per i problemi delle olimpiadi.

ifstream in("input.txt"); indica che l'input verrà letto dal file chiamato input.txt. Questo file si deve trovare nella stessa cartella dove avete salvato il programma, oppure dovete specificare l'intero percorso.

Avete presente come usate cin >> var per prendere in input da tastiera una variabile var?

D'ora in poi, se al posto di cin userete "in", farete la stessa cosa ma leggendo dal file di input.


Esempio:  
Avete un file che contiene:  
1 2 3 

Se nel vostro programma scrivete: 

in >> a >> b >> c 

Avrete un 1 nella variabile a, un 2 nella variabile b e un 3 nella variabile c. 


Allo stesso modo ofstream out("output.txt"); specifica che quando userete out al posto di cout starete scrivendo sul file output.txt. 

Se il file non esiste, il programma lo creerà in automatico. 

