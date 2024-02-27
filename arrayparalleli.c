#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define N 25
#define NAME_LENGTH 20
#define NAME_LENGTH_SCAN "%20s"

int main() {
    int n;
    char nome_studenti[N][NAME_LENGTH+1];
    int voto_verifica[N], scelta, i = 0, j = 0, temp1;
    char* temp2;
    
	do{
      printf("Inserisci il numero di studenti (compreso tra 10 e 25): ");
      scanf("%d", &n);
    } while (n <3 || n > N);
    for (i = 0; i < n; i++) {
        printf("Inserisci il nome dello studente %d: ", i + 1);
    //    scanf("%c", &nome_studenti[i]);
        scanf(NAME_LENGTH_SCAN, &nome_studenti[i]);
        printf("Inserisci il voto di %s (0 se assente): ", nome_studenti[i]);
          scanf(" %d", &voto_verifica[i]);
    } 

    while (1) {
        printf("\nMenu:\n");
        printf("1) Stampare tutti i dati degli studenti presenti in ordine decrescente di voto\n");
        printf("2) Calcolare la media generale della classe e stampare gli alunni con voto superiore alla media\n");
        printf("3) Cercare uno studente e visualizzare il voto\n");
        printf("4) Visualizzare gli studenti assenti\n");
        printf("0) Uscire dal programma\n");
        printf("Inserisci il numero corrispondente all'operazione desiderata: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                printf("\nDati degli studenti presenti in ordine decrescente di voto:\n");
                for (i = 0; i < N - 1; i++) {
                    for (j = i + 1; j < N; j++) {
                        if (voto_verifica[i] < voto_verifica[j]) {
                            temp1= voto_verifica[i];
                            voto_verifica[i] = voto_verifica[j];
                            voto_verifica[j] = temp1;					
                            temp2 = nome_studenti[i];
                            nome_studenti[i] = nome_studentDati degli studenti presenti in ordine decrescente di voi[j];
                            nome_studenti[j] = temp2;
                        }
                    }
                    printf("%s: %d\n", nome_studenti[i], voto_verifica[i]);
                }
                break;
            }
            case 2: {
                float media = 0;
                for ( i = 0; i < N; i++) {
                    media += voto_verifica[i];
                }
                media /= N;

                printf("\nMedia generale della classe: %.2f\n", media_generale);
                printf("Studenti con voto superiore alla media:\n");
                for (int i = 0; i < N; i++) {
                    if (voto_verifica[i] > media_generale) {
                        printf("%c: %d\n", nome_studenti[i], voto_verifica[i]);
                    }
                }
                break;
            }
           case 3: {
                char nome_ricerca[NAME_LENGTH+1];
                printf("Inserisci il nome dello studente da cercare: ");
                scanf(NAME_LENGTH_SCAN, nome_ricerca);
                int trovato = 0;
                for ( i = 0; i < N; i++) {
                        if (voto_verifica[i] == 0) {
                            printf("Lo studente %c è assente.\n", nome_ricerca);
                        } else {
                            printf("Lo"%s" studente %c ha ottenuto il voto %d.\n", nome_ricerca, voto_verifica[i]);
                        }
                        trovato = 1;
                    
                    }
                break;
            }
            case 4:{
                printf("Studenti assenti alla verifica:\n");
                for ( i = 0; i < N; i++) {
                    if (voto_verifica[i] == 0) {
                        printf("%c\n", nome_studenti[i]);
                    }
                }
                break;
            }        
            case 0:{
                printf("Programma terminato.\n");
                return 0;
                }
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }
}