#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
//Déclaration Type File : Représentation Liste Chainée!
typedef struct FileL
{
 int info;
 FileL *suivant;
};
/**Fonction enfiler correspond insertDebut, dans une file l'insertion est réalisée à partir
de la tête **/
void enfilerL(FileL* &debut, int x )
{
 FileL * nouveau=new FileL;//Allouer un element, son adresse est affect? nouveau
 nouveau->info=x;
 nouveau->suivant=debut;
 debut=nouveau;
}
/**Fonction defiler correspond suppFin, dans une file l'extraction d'un élément
consiste à éliminer le dernier élément de la liste **/
void defilerL(FileL *& debut, int &x)
{
 FileL * sup;
 if(debut!=0)
 { if(debut->suivant==0)
 {
 x=debut->info;
 delete debut ;
 debut=0;
 }
 else
 { FileL * courant=debut;
 while(courant->suivant->suivant!=0)
 {
 courant= courant->suivant ;
 }
 x=courant->suivant->info;
 delete courant->suivant ;
 courant->suivant=0;
 }
 }
}

/**Fonction creation de la File (Liste) avec la primitive enfilerL**/
void creationFileL (FileL* &debut, int nbreElements)
{
 int x;
 for (int i=0; i< nbreElements; i++)
 {
 cout<<"Donner un entier : ";
 cin>>x;
 enfilerL(debut, x);
 }
}
/**Fonction Afficher le contenu de la file représentée par une liste**/
void afficherFileL(FileL *courant)
{
 if(courant==0) cout<<"Liste vide";
 else
 while (courant!= 0)
 {
 cout<<"["<<courant->info<<"]\t";
 courant=courant->suivant;
 }
}
/**Extraire m éléments d'une File(Liste) et les insérés dans une autres File(Liste)***/
void ExtraireInsert(FileL *&F1, FileL* &F2, int &m)
{
 int val;
 FileL* courant=F1;
 cout<<"\nDonner le nombre d elements a extraire de File1 pour les inserer dans La File ";

 cin>>m;
 for(int i=0; i<m && courant!=0; i++)
 {
 defilerL(F1, val);
 enfilerL(F2, val);
 courant=courant->suivant;
 }
}
/**Partitionner une File F en deux Files F1, F2 pour contenir les éléments impairs et pairs
respectivement*/
void partitionner(FileL *F, FileL *&F1, FileL *&F2)
{
 int val;
 FileL *courant =F;
 while (courant!=0)
 {
 defilerL(F, val);
 if(val%2!=0)
 enfilerL(F1,val);
 else enfilerL(F2, val);
 courant=courant->suivant;
 }
}
/**Fonction principale main()*/
int main()
{
 /*Déclarations têtes des files */
 FileL *F1, *F2, *Fi, *Fp;
 int n, m;
 /*Initialisation des têtes à 0*/
 F1=0;
 F2=0;
 Fi=0;
 Fp=0;
10 ;
 /*creation files*/
 cout<<"Donner le nombre d elements a enfiler: ";
 cin>>n;
 cout<<"Saisir F1:\n";
 creationFileL(F1, n);
 cout<<"\nSaisir F2:\n";
 creationFileL(F2, n);
 /*Affichage F1 et F2*/
 cout<<"\nF1:\n"; afficherFileL(F1);
 cout<<"\nF2:\n"; afficherFileL(F2);
 /*Etendre F2 en enfilant les m premiers éléments de F1*/
 ExtraireInsert (F1,F2,m);
 /*Affichage F1, F2 après extraction de m éléments*/
 cout<<"\nF1:\n"; afficherFileL(F1);
 cout<<"\nF2:\n"; afficherFileL(F2);
 /*partitionner F1 en deux files: Fi éléments impairs et Fp éléments pairs*/
 partitionner(F1, Fi, Fp);
 /*Affichage de de Fi, FP*/

 cout<<"\nFi:\n"; afficherFileL(Fi);
 cout<<"\nFp:\n"; afficherFileL(Fp);
 return 0;
}
