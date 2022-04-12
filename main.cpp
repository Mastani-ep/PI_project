
#include <iostream>
using namespace std;

class Student{
public:
    string imie;
    string nazwisko;
    int indeks;
    Student *nastepny;
    Student();

};

Student::Student(){
    nastepny=0;
}


class Lista{
public:
    Student *pierwszy;
    void dodaj(string imie, string nazwisko, int indeks);
    void usun(int indeks);
    void wyswietl();
    void sort_ind(int liczba);
    void sort_naz(int liczba);
    Lista();
};

Lista::Lista(){
    pierwszy=0;
};

void Lista::dodaj(string im,string naz, int ind){
    Student *nowy = new Student;

    nowy->imie = im;
    nowy->nazwisko = naz;
    nowy->indeks = ind;

    if (pierwszy==0)
    {
        pierwszy = nowy;
    }
    else
    {
        Student *temp = pierwszy;
        //lecimy na kuniec listyyy
        while (temp->nastepny)
        {
            temp = temp->nastepny;
        }

        temp->nastepny = nowy;
        nowy->nastepny= 0;
    }
    cout<<"Dodano studenta do listy"<<endl;
}

void Lista::wyswietl()
{
    Student *temp = pierwszy;
    int i=1;
    while (temp)
    {
        cout << i << ") Imie: " << temp->imie <<endl;
        cout << " Nazwisko: " << temp->nazwisko <<endl;
        cout << " Indeks studenta: "<< temp->indeks <<endl;
        temp=temp->nastepny;
        i++;
    }
}

void Lista::usun (int ind){
    Student *temp = pierwszy;
    int a=0;
    if ((temp->indeks) == ind) {
        pierwszy = temp->nastepny;
        delete temp;
        cout<<"Usunieto studenta o indeksie: "<<ind<<endl;
    }else{
        cout<<"k"<<endl;//kontrolka
        while((temp->nastepny->nastepny)!=0) {
            cout << "l" << endl;//kontrolka
            if (((temp->nastepny)->indeks) == ind) {
                Student *usuwany = temp->nastepny;
                temp->nastepny = temp->nastepny->nastepny;
                delete usuwany;
                cout << "Usunieto studenta o indeksie: " << ind << endl;
                a=1;
                break;
            }
            temp = temp->nastepny;
        }

        if ((temp->nastepny->nastepny) == 0 && a==0) {
            cout << "sprawdzam dzial" << endl;//kontrolka dzialania
            if (((temp->nastepny)->indeks) == ind) {
                cout << "z" << endl;//kontrolka dzialania
                delete temp->nastepny;
                cout << "Usunieto studenta o indeksie: " << ind << endl;
                temp->nastepny = 0;
            } else {
                cout << "sprawdzam" << endl;//kontrolka dzialania
                cout << "Nie ma studenta o indeksie: " << ind << endl;
            }
        }
    }

}



void Lista::sort_ind(int liczba) {
    Student *tab[liczba];
    Student *temp=pierwszy;
    Student *temp1;
    for(int i=0;i<liczba;i++){
        tab[i]=temp;
        temp=temp->nastepny;
    }
    for(int j=0;j<liczba;j++) {
        for (int i = 1; i < liczba; i++) {
            if ((tab[i-1]->indeks) > (tab[i]->indeks)) {
                temp1=tab[i];
                tab[i]=tab[i-1];
                tab[i-1]=temp1;
            }
        }
    }

    pierwszy=tab[0];
    temp=pierwszy;
    for(int i=1;i<=liczba;i++) {
        temp->nastepny = tab[i];
        if (i == liczba ) {
            temp->nastepny = 0;
        }else{
            temp=temp->nastepny;
        }
    }


}

void Lista::sort_naz(int liczba){
    Student *tab[liczba];
    Student *temp=pierwszy;
    Student *temp1;
    int k=0;


    for(int i=0;i<liczba;i++){
        tab[i]=temp;
        temp=temp->nastepny;
    }

    for(int j=0;j<liczba;j++) {
        for (int i = 1; i < liczba; i++) {
            if ((tab[i-1]->nazwisko[0]) > (tab[i]->nazwisko[0])) {
                temp1=tab[i];
                tab[i]=tab[i-1];
                tab[i-1]=temp1;
            }
            if ((tab[i-1]->nazwisko[0]) == (tab[i]->nazwisko[0])){
                cout<<"A"<<endl;
                while((tab[i-1]->nazwisko[k])!=0 || (tab[i]->nazwisko[k])!=0){
                    cout<<"B"<<endl;
                    if((tab[i]->nazwisko[k])<(tab[i-1]->nazwisko[k])){
                        cout<<"C"<<endl;
                        temp1=tab[i];
                        tab[i]=tab[i-1];
                        tab[i-1]=temp1;
                        break;
                    }
                    k++;
                }
            }
        }
    }

    pierwszy=tab[0];
    temp=pierwszy;
    for(int i=1;i<=liczba;i++) {
        temp->nastepny = tab[i];
        if (i == liczba ) {
            temp->nastepny = 0;
        }else{
            temp=temp->nastepny;
        }
    }

}
int main()
{
    Lista *lista=new Lista;
    Student *temp=new Student;
    int a;
    int b=0;
    int liczba=0;
    string imie, nazwisko;
    int indeks;
    while(1>0){
        cout<<"Wybierz opcje: "<<endl;
        cout<<"1-dodaj studenta do listy"<<endl;
        cout<<"2-usun studenta z listy"<<endl;
        cout<<"3-wyswietl liste"<<endl;
        cout<<"4-sortuj studentow po nazwisku"<<endl;
        cout<<"5-sortuj studentow po indeksie"<<endl;
        cout<<"6-zakoncz program"<<endl;
        cin>>a;

        switch(a){
            case 1:{
                cout<<"Podaj imie studenta: ";
                cin>>imie;
                cout<<"Podaj nazwisko studenta: ";
                cin>>nazwisko;
                cout<<"Podaj indeks studenta: ";
                cin>>indeks;
                temp=lista->pierwszy;
                for(int i=0;i<liczba;i++){
                    if(temp->indeks==indeks){
                        cout<<"Istnieje juz student o takim indeksie"<<endl;
                        b=1;
                        break;
                    }
                    temp=temp->nastepny;
                }
                if(b==0){
                    lista->dodaj(imie, nazwisko, indeks);
                    liczba++;
                }
                b=0;
                break;
            }
            case 2:{
                if((lista->pierwszy)==0){
                    cout<<"Nie ma studentow do usuniecia."<<endl;
                    break;
                }
                cout<<"Podaj indeks studenta, ktorego chcesz usunac: ";
                cin>>indeks;
                cout<<"m"<<endl;//kontrolka dzialania
                lista->usun(indeks);
                cout<<"o"<<endl;//kontrolka dzialania
                liczba--;
                break;
            }
            case 3:{
                if((lista->pierwszy)==0){
                    cout<<"Nie ma zadnych studentow na liscie."<<endl;
                    break;
                }
                cout<<"Lista studentow: "<<endl;
                lista->wyswietl();
                break;
            }
            case 4:{
                lista->sort_naz( liczba);
                break;
            }
            case 5:{
                lista->sort_ind(liczba);
                break;
            }
        }
        if(a==6){
            break;
        }

    }



}