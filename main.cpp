#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int n=0,b=0;

struct abonament{
        char nume[20];
        int pret;
        int canale;
}abonamente[10];

struct abonat{


    char nume[50];
    char prenume[50];
    char abonament[50];
    int nr_abonat;

}abonati[1001];

void Citire(int &n,abonat abonati[]){
    ifstream fin("abonati.dat");
    do
    {
        fin.getline(abonati[n].nume,50);
        //fin.get();
        fin.getline(abonati[n].prenume,50);
        //fin.get();
        fin.getline(abonati[n].abonament,50);
        //fin.get();
        abonati[n].nr_abonat=n+1;
        fin.get();
        n++;
    }
    while(fin);
    fin.close();
}

void CitireAbn(int &b, abonament abonamente[]){
    ifstream gin("abonamente.dat");
    while(gin)
    {
        gin.getline(abonamente[b].nume,50);
        gin>> abonamente[b].pret;
        gin>> abonamente[b].canale;
        gin.get();
        b++;
    }

    gin.close();
}

void Afisare(int n, abonat abonati[]){
    for(int i=0; i<n; i++)
    {
        cout<<"Nume: "<<abonati[i].nume<<endl;
        cout<<"Prenume: "<<abonati[i].prenume<<endl;
        cout<<"Tip abonament: "<<abonati[i].abonament<<endl;
        cout<<"Numar abonat: "<<abonati[i].nr_abonat<<endl;
        cout<<endl;
    }
}

void AfisareAbn(int b, abonament abonamente[]){
    for(int i=0; i<b-1; i++)
    {
        cout<<"Nume abonament: "<<abonamente[i].nume<<"\n";
        cout<<"Pret abonament: "<<abonamente[i].pret<<"\n";
        cout<<"Numar de canale: "<<abonamente[i].canale<<"\n"<<"\n";
    }
}

void AfisarePoz(int poz, abonat abonati[]){

    cout<<abonati[poz].nr_abonat<<endl;
    cout<<abonati[poz].nume<<endl;
    cout<<abonati[poz].prenume<<endl;
    cout<<abonati[poz].abonament<<endl;

}

void RstEcr(){
    system("cls");
}

void Adaugare(int &n, abonat abonati[]){
    cout<<"Nume:";
    cin>>abonati[n].nume;
    cout<<"Prenume: ";
    cin>>abonati[n].prenume;
    cout<<"Abonament: ";
    cin>>abonati[n].abonament;
    abonati[n].nr_abonat=abonati[n].nr_abonat++;
    cout<<"Va multumim ca ati ales compania noastra"<<endl;
    n++;
}

void AdaugarePoz(int poz){
    abonat aux;
    int i;
    cin>>aux.nume;
    cin>>aux.prenume;
    cin>>aux.abonament;
    for(i=n; i>=poz; i--)
    {
        abonati[i+1]=abonati[i];
    }
    abonati[poz]=aux;

}

void Salvare(int n, abonat abonati[]){
    ofstream fout("abonati.dat");
    for(int i=0;i<n;i++){
        if(i==n-1)
        {
            fout<<abonati[i].nume<<"\n";
            fout<<abonati[i].prenume<<"\n";
            fout<<abonati[i].abonament;
        }
        else{
            fout<<abonati[i].nume<<"\n";
            fout<<abonati[i].prenume<<"\n";
            fout<<abonati[i].abonament<<"\n"<<"\n";
        }
    }
    fout.close();
}

void Stergere(int poz, abonat abonati[]){
    for(int i=--poz; i<n; i++)
    {
        abonati[i]=abonati[i+1];
    }
    n--;
}

void CautareNume(){
    char nume[50];
    cout<<"Introduceti numele persoanei cautate: ";
    int k=0;
    cin.getline(nume,50);
    for(int i=0; i<n; i++){
        if(strcmp(abonati[i].nume,nume)==0){
            cout<<abonati[i].nr_abonat<<endl;
            cout<<abonati[i].nume<<endl;
            cout<<abonati[i].prenume<<endl;
            cout<<abonati[i].abonament<<endl;
            k++;
        }
    }
    if(k==0)
        cout<<"Ne pare rau dar persoana dorita nu exista"<<"\n";
}

void OrdNume(int n, abonat abonati[]){
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(strcmp(abonati[i].nume,abonati[j].nume)>0)
            {
                abonat aux;
                aux=abonati[i];
                abonati[i]=abonati[j];
                abonati[j]=aux;
            }
        }
    Afisare(n, abonati);
}


void OrdPrenume(int n, abonat abonati[]){
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(strcmp(abonati[i].prenume,abonati[j].prenume)>0)
            {
                abonat aux;
                aux=abonati[i];
                abonati[i]=abonati[j];
                abonati[j]=aux;
            }
        }
    Afisare(n,abonati);
}

void Meniu(){
    int ok=1,x;
    Citire(n,abonati);
    CitireAbn(b,abonamente);
    while(ok)
    {
        RstEcr();
        cout<<"-------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                   Bine ati venit la Gigi TV"<<endl;
        cout<<"                                   Suntem aici pentru tine"<<endl;
        cout<<"-------------------------------------------------------------------------------------------------"<<endl<<endl;
        cout<<"1.Vedeti lista abonatilor"<<endl;
        cout<<"2.Vedeti abonamentele"<<endl;
        cout<<"3.Adaugati un abonament"<<endl;
        cout<<"4.Cautati dupa nume"<<endl;
        cout<<"5.Stergeti un abonat"<<endl;
        cout<<"6.Ordonati crescator dupa nume"<<endl;
        cout<<"7.Ordonati crescator dupa prenume"<<endl;
        cout<<"8.Inchidere program"<<endl<<"Optiunea dumneavoastra:";
        cin>>x;
        cin.get();
        switch(x)
        {
        case 1 :
        {
            RstEcr();
            Afisare(n,abonati);
            cout<<"Press 1 to go back to menu "<<endl;
            cin>>x;
            if(x==1)
            {
                break;
                RstEcr();
            }
        }

        case 2 :
        {
            RstEcr();
            AfisareAbn(b, abonamente);
            cout<<"Press 1 to go back to menu "<<endl;
            cin>>x;
            if(x==1)
            {
                break;
                RstEcr();
            }
        }
        break;
        case 3 :
        {
            RstEcr();
            Adaugare(n,abonati);
            cout<<"Press 1 to go back to menu "<<endl;
            cin>>x;
            if(x==1)
            {
                break;
                RstEcr();
            }
        }
        break;
        case 4 :
        {
            RstEcr();
            CautareNume();
            cout<<"Press 1 to go back to menu "<<endl;
            cin>>x;
            if(x==1)
            {
                break;
                RstEcr();
            }
        }
        break;
        case 5 :
        {
            RstEcr();
            int poz;
            cout<<"Inserati codul abonatului: ";
            cin>>poz;
            Stergere(poz,abonati);
            cout<<"Press 1 to go back to menu "<<endl;
            cin>>x;
            if(x==1)
            {
                break;
                RstEcr();
            }
        }
        break;
        case 6 :
        {
            RstEcr();
            OrdNume(n,abonati);
            cout<<"Press 1 to go back to menu "<<endl;
            cin>>x;
            if(x==1)
            {
                break;
                RstEcr();
            }
        }

        break;
        case 7:
            {
                RstEcr();
                OrdPrenume(n,abonati);
                cout<<"Press 1 to go back to menu "<<endl;
                cin>>x;
                if(x==1)
                {
                    break;
                    RstEcr();
                }
            }
        case 8:
            {
                RstEcr();
                ok=0;
            }
        break;
        default :
            RstEcr();
            cout<<"\nAti gresit. Reintroduceti optiunea. ";
            Sleep(2000);
            Meniu();
        }

    }
    Salvare(n,abonati);
}

int main()
{
    Meniu();
    cout<<"La revedere!";
    return 0;
}
