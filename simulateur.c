#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct instruction{
    int adresse; // 0 -> 4999
    char code; // code de l'instruction de 0 à 13 ou 99 pour signaler la fin (1 octet)
    short donnée; // paramètres de l'instruction (2 octets)
    struct instruction* next;
    struct instruction* prev;
}Instruction;

typedef struct {
    Instruction* debut;
    Instruction* fin;
    Instruction* PC;
    Instruction* SP;
}Liste_instructions;

Liste_instructions* creation_liste_instructions(){
    Liste_instructions* instructions = malloc(sizeof(Liste_instructions));
    instructions->debut = NULL;
    instructions->fin = NULL;
    instructions->PC = NULL;
    instructions->SP = NULL;
    return instructions;
}

Instruction* creation_instruction(int adresse, char code, short donnée){
    Instruction* instruction = malloc(sizeof(Instruction));
    instruction->adresse = adresse;
    instruction->code = code;
    instruction->donnée = donnée;
    instruction->next = NULL;
    instruction->prev = NULL;
    return instruction;
}

void ajout_instruction(Liste_instructions* l_instructions,Instruction* instruction){
    if (l_instructions->fin == NULL){
        l_instructions->debut = instruction;
        l_instructions->fin = instruction;
        l_instructions->PC = instruction;
    }
    else {
        l_instructions->fin->next = instruction;
        instruction->prev = l_instructions->fin;
        l_instructions->fin = instruction;
    }
}

void tout_supprimer(Liste_instructions* l_instructions){
    Instruction* instruction_actuelle = l_instructions->debut;
    while (instruction_actuelle!=NULL){
        l_instructions->debut = instruction_actuelle->next;
        free(instruction_actuelle);
        instruction_actuelle = l_instructions->debut;
    }
    free(l_instructions);
}

void execution_instruction(Liste_instructions* l_instructions){
    Instruction* instruction = l_instructions->PC;
    l_instructions->PC = l_instructions->PC->next;

    switch(instruction->code){
        case(0):
    }
}

int main(){
    Liste_instructions* l_instructions = creation_liste_instructions();
    Instruction* instru1 = creation_instruction(1,12,56);
    Instruction* instru2 = creation_instruction(2,8,130);
    ajout_instruction(l_instructions,instru1);
    ajout_instruction(l_instructions,instru2);
    tout_supprimer(l_instructions);
    return 0;
}
