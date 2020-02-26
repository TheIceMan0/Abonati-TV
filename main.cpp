#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace std;


ifstream outfile;
outfile.open("abonati.dat");

int n=0;

struct abonat{
    char nume[50];
    char prenume[50];
    char abonament[50];
    int nr_abonat;

}abonati[100];
void Citire(int &n){
    do
    {
        fin.getline(abonati[n].nume,50);
        fin.get();
        fin.getline(abonati[n].prenume,50);
        fin.get();
        fin.getline(abonati[n].abonament,50);
        fin.get();
        abonati[n].nr_abonat=n;
        fin.get();
        n++;
    }while(fin);

}
void Afisare(int n){
    for(int i=0;i<n;i++)
    {
        cout<<abonati[i].nume<<endl;
        cout<<abonati[i].prenume<<endl;
        cout<<abonati[i].abonament<<endl;
        cout<<abonati[i].nr_abonat<<endl;
    }

}


void Adaugare(int &n, abonat a[]){
    abonat aux;
    cin>>aux.nume;
    cin>>aux.prenume;
    cin>>aux.abonament;
    aux.nr_abonat=a[n].nr_abonat++;
    a[n+1]=aux;
    n++;

}
void AdaugarePoz(int n, abonat a[],int poz){
    abonat aux,aux2;
    int i;
    cin>>aux.nume;
    cin>>aux.prenume;
    cin>>aux.abonament;
    for(i=n;i>=poz;i--)
    {
        a[i++]=a[i];
    }
    a[poz]=aux;

}


int main(){
    Citire(n);
    Afisare(n);
    return 0;
}
