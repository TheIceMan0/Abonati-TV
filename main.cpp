#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int n=0,b=0;

struct abonament{
        char nume[50];
        int pret;
        int canale;
}abonamente[10];

struct abonat{


    char nume[50];
    char prenume[50];
    char abonament[50];
    int nr_abonat;

}abonati[101];

void Citire(int &n){
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

void CitireAbn(int &b){
    ifstream gin("abonament.dat");
    do
    {
        gin.getline(abonamente[n].nume,50);
        gin>>abonamente[n].pret;
        gin>>abonamente[n].canale;
        //gin.get();
        b++;
    }
    while(gin);
    gin.close();
}

void Afisare(){
    for(int i=0; i<n; i++)
    {
        cout<<"Nume: "<<abonati[i].nume<<endl;
        cout<<"Prenume: "<<abonati[i].prenume<<endl;
        cout<<"Tip abonament: "<<abonati[i].abonament<<endl;
        cout<<"Numar abonat: "<<abonati[i].nr_abonat<<endl;
        cout<<endl;
    }
}

void AfisareAbn(){
    for(int i=0; i<b; i++)
    {
        cout<<"Nume abonament: "<<abonamente[i].nume<<endl;
        cout<<"Pret abonament: "<<abonamente[i].pret<<endl;
        cout<<"Numar de canale: "<<abonamente[i].canale<<endl;
        cout<<endl;
    }

}

void AfisarePoz(int poz){

    cout<<abonati[poz].nr_abonat<<endl;
    cout<<abonati[poz].nume<<endl;
    cout<<abonati[poz].prenume<<endl;
    cout<<abonati[poz].abonament<<endl;

}

void RstEcr(){
    system("cls");
}

void Adaugare(){
    abonat aux;
    cout<<"Nume:";
    cin>>aux.nume;
    cout<<"Prenume: ";
    cin>>aux.prenume;
    cout<<"Abonament: ";
    cin>>aux.abonament;
    aux.nr_abonat=abonati[n].nr_abonat++;
    abonati[n+1]=aux;
    n++;
    cout<<"Va multumim ca ati ales compania noastra"<<endl;
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

void Salvare(){
    ofstream fout("abonati.dat");
    for(int i=1;i<n;i++)
    {
        fout<<abonati[i].nume<<"\n";
        fout<<abonati[i].prenume<<"\n";
        fout<<abonati[i].abonament<<"\n"<<"\n";
        //fout<<abonati[i].nr_abonat<<endl<<endl;
    }
}

void Stergere(int poz){
    for(int i=--poz; i<n; i++)
    {
        abonati[i]=abonati[i+1];
    }
    n--;
}

void CautareNume(){
    char nume[50];
    cout<<"Baga: ";
    cin.getline(nume,50);
    for(int i=0; i<n; i++)
    {
        if(strcmp(abonati[i].nume,nume)==0)
        {
            cout<<abonati[i].nr_abonat<<endl;
            cout<<abonati[i].nume<<endl;
            cout<<abonati[i].prenume<<endl;
            cout<<abonati[i].abonament<<endl;
        }
    }
}

void OrdNume(){
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
    Afisare();
}


void OrdPrenume(){
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
}

void Meniu(){
    int ok=1,x;
    Citire(n);
    CitireAbn(b);
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
        cout<<"7.Inchidere program"<<endl<<"Optiunea dumneavoastra:";
        cin>>x;
        cin.get();
        switch(x)
        {
        case 1 :
        {
            RstEcr();
            Afisare();
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
            AfisareAbn();
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
            Adaugare();
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
            //cout<<"Inserati numele persoanei cautate:";

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
            Stergere(poz);
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
            OrdNume();
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
                ok=0;
            }
        break;
        default :
            cout<<"\n Ati gresit. Reintroduceti optiunea. ";
        }

    }
    Salvare();
}



int main()
{
    Meniu();
    cout<<"La revedere!";
    return 0;
}
