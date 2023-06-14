#include <iostream>
#include "Angajat.h"
#include "Client.h"
#include "Camera.h"
#include "Hotel.h"
#include "bits/stdc++.h"
#include "fstream"
using namespace std;


void relationalOperation(string s1, string s2)
{

    if (s1 != s2)
    {
        cout << s1 << " is not equal to " << s2 << endl;
        if (s1 > s2)
            cout << s1 << " is greater than " << s2 << endl;
        else
            cout << s2 << " is greater than " << s1 << endl;
    }
    else
        cout << s1 << " is equal to " << s2 << endl;
}

int main()
{


    system("CLS");
    char opt,opt1,opt2,opt3;
    int countClient=6,countAngajat=6,countHote=0,countCamere=5;
    int nrClient,nrAngajat,nrCamera;
    Camera *camera1 = new Camera();
    string numeCautat ="";
     bool searchCLient = false;
    Client *c[50];
    c[0] = new Client("Vavrici","Ana","0745567864");
    c[1]=new Client("Hertanu","Razvan","0723575487");
    c[2]=new Client("Spita","Mihai","0789564664");
    c[3]=new Client("Rapan","Ariana","0767854234");
    c[4]=new Client("Balan","Victor","07235543543");
    c[5]=new Client("Boian","Lucian","0797887578977");
    Angajat *a[50];
    a[0]=new Angajat("Popescu","Maria",2988);
    a[1]=new Angajat("Ionescu","Andrei",34554);
    a[2]=new Angajat("Mihaescu","Elena",78755);
    a[3]=new Angajat("Radu","Florin",676456);
    a[4]=new Angajat("Stoica","Ana",67895);
    a[5]=new Angajat("Popa","Ioana",78999);
    Hotel *h[50];
    Camera *cam[50];
    cam[0] = new Camera();
    cam[0]->Settip(10,0);
    cam[1] = new Camera();
    cam[1]->Settip(10,1);
    cam[2] = new Camera();
    cam[2]->Settip(10,2);
    cam[3] = new Camera();
    cam[3]->Settip(10,3);
    cam[4] = new Camera();
    cam[4]->Settip(10,4);

    string buffer;
    do
    {

        cout<<"1.Introduceti date "<<endl;
        cout<<"2.Afisare "<<endl;
        cout<<"3.Cautare"<<endl;
        cout<<"4.Exit"<<endl;

        cout<<"Alegeti o optiune"<<endl;
        cin>>opt;
        switch(opt)
        {
        case '1':
            do
            {
                system("CLS");
                cout<<"1.Introduceti date clienti"<<endl;
                cout<<"2.Introduceti date angajati"<<endl;
                cout<<"3.Introducere date rezervare camera"<<endl;
                cout<<"4.Revenire la meniu principal"<<endl;

                cout<<"Alegeti o optiune"<<endl;
                cin>>opt1;
                switch(opt1)
                {
                case '1':
                    system("cls");

                    c[countClient] = new Client();
                    cin>>*c[countClient];
                    countClient++;




                    system("pause");
                    system("CLS");
                    break;
                case '2':
                    system("cls");
                    a[countAngajat]=new Angajat();
                    cin>>*a[countAngajat++];
                    system("pause");
                    system("CLS");

                    break;
                case '3':
                    system("cls");
                    cout<<"Alegeti camera"<<endl;
                    cout<<"Clientii Hotelului sunt:"<<endl;
                    for(int i=0; i<countClient; i++)
                    {
                        if(c[i]!=NULL)
                        {
                            cout<<i<<"."<<*c[i]<<endl;
                        }
                    }
                    cout<<"Angajatii Hotelului sunt:"<<endl;
                    for(int i=0; i<countAngajat; i++)
                    {
                        if(a[i]!=NULL)
                        {
                            cout<<i<<"."<<*a[i]<<endl;
                        }
                    }
                    cout<<"Camerele disponibile sunt:"<<endl;
                    for(int i=0; i<countCamere; i++)
                    {
                        if(cam[i]!=NULL)
                        {
                            cout<<i<<"."<<*cam[i]<<endl;
                    }
                    }

                    cout<<"Selectati clientul:"<<endl;
                    cin>>nrClient;
                    cout<<"Selectati angajatul:"<<endl;
                    cin>>nrAngajat;
                    cout<<"Selectati camera:"<<endl;
                    cin>>nrCamera;
                    h[countHote] = new Hotel();
                    cin>>*h[countHote];
                    h[countHote]->rezervaCamera(*c[nrClient],*a[nrAngajat],*cam[nrCamera]);
                    cam[nrCamera]->Setnumar_camera(cam[nrCamera]->Getnumar_camera() - 1);
                    countHote++;


                    system("pause");
                    system("CLS");
                    break;
                case '4':


                    break;
                default:
                    system("cls");
                    cout<<"Optiune inexistenta"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(1 && opt1!='4');
            system("CLS");
            break;

        case '2':
            system("CLS");
            do
            {

                cout<<"1.Afisare date clienti"<<endl;
                cout<<"2.Afisare date angajati"<<endl;
                cout<<"3.Afisare date camere rezervate"<<endl;
                cout<<"4.Revenire la meniu principal"<<endl;
                cout<<"Alegeti o optiune"<<endl;
                cin>>opt2;
                switch(opt2)
                {
                case '1':
                    system("cls");
                    cout<<"Clienti Hotelului sunt:"<<endl;
                    for(int i=0; i<countClient; i++)
                    {
                     if(c[i]!=NULL)
                        {
                            cout<<i<<"."<<*c[i]<<endl;
                        }
                    }


                    system("pause");
                    system("CLS");
                    break;
                case '2':
                    system("cls");
                    cout<<"Angajati Hotelului sunt:"<<endl;
                    for(int i=0; i<countAngajat; i++)
                    {
                        if(a[i]!=NULL)
                        {
                            cout<<i<<"."<<*a[i]<<endl;
                        }
                        }

                    system("pause");
                    system("CLS");
                    break;
                case '3':
                    system("cls");
                    cout<<"test";
                    for(int i=0; i<countHote; i++)
                    {
                        if(h[i]!=NULL)
                        {
                            Client bufferClient = h[i]->Getclient();
                            Camera bufferCamera = h[i]->Getcamera();
                            cout<<"client: "<<bufferClient<<" camera:"<<bufferCamera<<*h[i]<<endl;
                        }

                    }
                    system("pause");
                    system("CLS");
                    break;


                case '4':
                    break;
                default:
                    system("cls");
                    cout<<"Optiune inexistenta"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(1 && opt2!='4');
            system("CLS");
            break;
        case '3':

            do
            {
                system("CLS");
                cout<<"1.Cautare client"<<endl;
                cout<<"2.Cautare camere libere"<<endl;
                cout<<"3.Revenire la meniul principal"<<endl;
                cout<<"Alegeti o optiune"<<endl;
                cin>>opt3;
                switch(opt3)
                {
                case '1':
                    system("cls");
                    cout<<"Introduceti numele de familie al clientului:"<<endl;
                    cin>>numeCautat;
                    searchCLient  = false;
                    for(int i =0; i<countClient; i++)
                    {
                        if( numeCautat == c[i]->Getnume())
                        {
                            searchCLient = true;
                            break;
                        }
                    }
                    if(searchCLient)
                    {
                        cout<<"Client gasit"<<endl;
                    }
                    else
                    {
                        cout<<"Clientul nu a fost gasit"<<endl;
                    }
                    system("pause");
                    system("CLS");
                    break;
                case '2':
                    system("cls");
                    cout<<"Introduceti camera cautata:"<<endl;
                    cout<<"0-camera_matrimoniala"<<endl;
                    cout<<"1-camera_pat_separat"<<endl;
                    cout<<"2-camera_triple_room"<<endl;
                    cout<<"3-camera_single"<<endl;
                    cout<<"4-camera_apartamente"<<endl;
                    cin>>nrCamera;
                    if(nrCamera>4 || nrCamera<0)
                    {
                        cout<<"Tip camera invalid"<<endl;
                        system("pause");
                        system("CLS");
                        break;
                    }
                    else
                    {
                        camera1->Settip(10,nrCamera);
                        for(int i=0; i<countCamere; i++)
                        {
                            if(camera1->Gettip() == cam[i]->Gettip())
                            {
                                cout<<"mai sunt "<<cam[i]->Getnumar_camera()<<" de tipul "<<cam[i]->Gettip()<<endl;
                            }
                        }
                        system("pause");
                        system("CLS");
                    }

                    break;
                case '3':
                    break;
                default:
                    system("cls");
                    cout<<"Optiune inexistenta"<<endl;
                    system("pause");
                    system("cls");
                    break;

                }
            }
            while(1&& opt3!='3');
            system("CLS");
            break;
        case '4':
            exit(0);

            break;
        default:
            system("CLS");
            cout<<"Optiune inexistenta}";
            system("pause");
            system("cls");
            break;

        }

    }
    while(1);

    return 0;
}
