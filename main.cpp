#include <iostream>
#include <stdlib.h>

void start(int *max_note, int (*v)[101], int *note_introduse);
void schimbare_nota_maxima(int *max_note, int (*v)[101], int *note_introduse);
void calcul(int *max_note, int (*v)[101], int *note_introduse);
void reset(int *max_note, int (*v)[101], int *note_introduse);
void nota_noua(int *max_note, int (*v)[101], int *note_introduse);
bool check(int *max_note, int (*v)[101], int *note_introduse);

int main(){
    int v[101];
    int max_note = 5;
    int note_introduse = 0;
    reset(&max_note, &v, &note_introduse);
    start(&max_note, &v, &note_introduse);

    return 0;
}

void start(int *max_note, int (*v)[101], int *note_introduse){
    int actiune;
    while(actiune != 3){
        std::cout << "------------------CALCULATOR PROMOVARE CLASA-------------------";
        std::cout << "\nNumarul de note maxim(pentru a schimba introduce 1): " << *max_note;
        std::cout << "\nIntrodu o nota noua(pentru a schimba introdu 2)";
        std::cout << "\nNumarul de note introduse momentan(se reseteaza la schimbarea notelor maxime): " << *note_introduse;
        std::cout << "\nCalculeaza(pentru a incepe introdu 3)";
        std::cout << "\n";
        std::cin >> actiune;
        switch(actiune){
            case 1:
                schimbare_nota_maxima(max_note, v, note_introduse);
                reset(max_note, v, note_introduse);
                break;
            case 2:
                nota_noua(max_note, v, note_introduse);
                break;
            case 3:
                calcul(max_note, v, note_introduse);
                break;
            default:
                std::cout << "error";
                break;
        }
    }
}

void reset(int *max_note, int (*v)[101], int *note_introduse){
    for(int i = 0; i < (*max_note); i++)
        (*v)[i] = 1;
    *note_introduse = 0;
}

void schimbare_nota_maxima(int *max_note, int (*v)[101], int *note_introduse){
    int new_nota;
    std::cout << "\nIntrodu notele maxime: ";
    std::cin >> new_nota;
    *max_note = new_nota;
    system("cls");
}

void calcul(int *max_note, int (*v)[101], int *note_introduse){
    int cnt = *note_introduse;
    while(!(check(max_note, v, note_introduse))){
        (*v)[cnt]++;
        if(cnt==((*max_note) - 1))
            cnt=*note_introduse;
        else
            cnt++;
    }
    float media_aritmetica = 0.0;
    std::cout << "Notele care trebuie sa le ai pentru a trece materia sunt: ";
    for(int i = 0; i < (*max_note); i++){
        media_aritmetica += (*v)[i];
        std::cout << (*v)[i] << " ";
    }

    std::cout << "\nRezultand astfel la media: " << (media_aritmetica / (*max_note)) << "\n";
}

bool check(int *max_note, int (*v)[101], int *note_introduse){
    float media_aritmetica = 0.0;
    for(int i = 0; i < (*max_note); i++)
        media_aritmetica += (*v)[i];

    return ((media_aritmetica / (*max_note)) > 4.49);
}

void nota_noua(int *max_note, int (*v)[101], int *note_introduse){
    int nota;
    std::cout << "Introdu nota ta noua: ";
    std::cin >> nota;
    (*v)[*note_introduse] = nota;
    (*note_introduse)++;
    system("cls");

}

