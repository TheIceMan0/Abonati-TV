#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int n=1;

struct abonat{
    char nume[50];
    char prenume[50];
    char abonament[50];
    int nr_abonat;

}abonati[100];

void Citire(int &n){
    ifstream fin("abonati.dat");
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
    fin.close();
}

void Afisare(){
    for(int i=1;i<n;i++){
        cout<<abonati[i].nume<<endl;
        cout<<abonati[i].prenume<<endl;
        cout<<abonati[i].abonament<<endl;
        cout<<abonati[i].nr_abonat<<endl;
        cout<<endl;
    }

}

void AfisarPoz(int poz){
        cout<<abonati[poz].nume<<endl;
        cout<<abonati[poz].prenume<<endl;
        cout<<abonati[poz].abonament<<endl;
        cout<<abonati[poz].nr_abonat<<endl;
}

void Adaugare(){
    abonat aux;
    cin>>aux.nume;
    cin>>aux.prenume;
    cin>>aux.abonament;
    aux.nr_abonat=abonati[n].nr_abonat++;
    abonati[n+1]=aux;
    n++;

}

void AdaugarePoz(int poz){
    abonat aux,aux2;
    int i;
    cin>>aux.nume;
    cin>>aux.prenume;
    cin>>aux.abonament;
    for(i=n;i>=poz;i--)
    {
        abonati[i++]=abonati[i];
    }
    abonati[poz]=aux;

}

void Stergere(int poz){
    for(int i=poz;i<=n;i++)
    {
        abonati[i]=abonati[i+1];
    }
}

void CautareNume()
{
    char c[50];
    cin.get(c,50);
    for(int i=1;i<n;i++)
    {
        if(strstr(c,abonati[i].nume))
            AfisarPoz(i);
    }
}
void Meniu(){
    int ok=1,x;
    Citire(n);
    while(ok)
    {
        cout<<"Sall"<<endl;
        cout<<"CF"<<endl;
        cout<<"1.Vedeti lista"<<endl;
        cout<<"2.Adaugati un abonament"<<endl;
        cout<<"3.Cautati dupa nume"<<endl;
        cin>>x;
        if(x==1)
            Afisare();
        else if(x==2)
            Adaugare();
        else if(x==3)
            CautareNume();
        system("cls");
    }
}



int main(){
    Meniu();
    return 0;
}
