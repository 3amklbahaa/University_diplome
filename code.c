#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int id, Nb_etudiant, credit, credit_price;
    char name[30], name_depart[30], name_dr[30];
}Degree;
void ReadDegrees (Degree *Ldeg[ ], int n){
    for(int i=0;i<n;i++){
        printf("plz enter for %d degree: id, Nb_etudiant, credit, credit_price, name, name_depart, name_dr: \n ",i);
        scanf("%d%d%d%d%s%s%s", &Ldeg[i]->id, &Ldeg[i]->Nb_etudiant, &Ldeg[i]->credit, &Ldeg[i]->credit_price, Ldeg[i]->name, Ldeg[i]->name_depart, Ldeg[i]->name_dr);
    }
}
void find_diplom(Degree *Ldeg[], int n, char nom_diplome[]){
    int found = 0;
    for(int i=0;i<n;i++){
        if(strcmp(Ldeg[i]->name_depart,nom_diplome)==0){
            printf("%d\n%s\n%s\n%d\n%d\n",Ldeg[i]->id,Ldeg[i]->name,Ldeg[i]->name_depart,Ldeg[i]->credit,(Ldeg[i]->credit)*(Ldeg[i]->credit_price));
        found =1;
        }
    }
    if(!found){
        printf("mesh mawjoude");
    }
}
int credit_New_price(Degree *Ldeg[], int n, int id,int new_credit){
    for(int i=0;i<n;i++){
        if(id==Ldeg[i]->id){
            Ldeg[i]->credit_price = new_credit;
        }
    }
}
void printAllDegrees(Degree *Ldeg[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Degree %d:\n", i);
        printf("ID: %d\n", Ldeg[i]->id);
        printf("Number of students: %d\n", Ldeg[i]->Nb_etudiant);
        printf("Credit: %d\n", Ldeg[i]->credit);
        printf("Credit price: %d\n", Ldeg[i]->credit_price);
        printf("Name: %s\n", Ldeg[i]->name);
        printf("Department name: %s\n", Ldeg[i]->name_depart);
        printf("Director name: %s\n", Ldeg[i]->name_dr);
        printf("\n");
    }
}
int main(){
    int n, id, new_credit;
    printf("enter n:");
    scanf("%d",&n);
    Degree **a;
    a=(Degree **)malloc(n*sizeof(Degree*));
    for(int i=0;i<n;i++){
        a[i]=(Degree *)malloc(sizeof(Degree));
    }
    char nom_diplome[30];
    printf(" nom_diplome: ");
    scanf("%s",nom_diplome);
    ReadDegrees(a,n);
    find_diplom(a,n,nom_diplome);
    printAllDegrees(a,n);
    return 0;
}
