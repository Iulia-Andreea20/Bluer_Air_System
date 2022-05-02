#include <iostream>
#include<stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include<cstring>
#include <vector>
#include <numeric>
#include <typeinfo>
#include <cctype>
#include "Rsa.h" 

using namespace std;


//!!!Important
//      USER-ul pentru OPERATOR este: Grigore Iulia-Andreea
//      PAROLA pentru OPERATOR este: Parolam3asiincac3va27!


class Flights
{
    public:
        string country_departure;
        string hours_fix_departure;
        int hour_departure;
        int minutes_departure;
        int month_departure;
        int day_departure;
        int year_departure;

        int ID;
        string country_arrival;
        string hours_fix_arrival;
        int hour_arrival;
        int minutes_arrival;
        int month_arrival;
        int day_arrival;
        int year_arrival;
        int available_seats;


        Flights(string country_departure, string country_arrival, int day_departure, int month_departure, int year_departure, int hour_departure, int minutes_departure, int day_arrival, int month_arrival, int year_arrival, int hour_arrival, int minutes_arrival, int available_seats, int ID)
        {
            this->country_departure = country_departure;
            this->country_arrival = country_arrival;
            this->day_departure = day_departure;
            this->month_departure = month_departure;
            this->year_departure = year_departure;
            this->hour_departure = hour_departure;
            this->minutes_departure = minutes_departure;

            this->day_arrival = day_arrival;
            this->month_arrival = month_arrival;
            this->year_arrival = year_arrival;
            this->hour_arrival = hour_arrival;
            this->minutes_arrival = minutes_arrival;  
            this->available_seats = available_seats;
            this->ID = ID;
        }
        
        int seeAvailableSeats()
        {
            return this->available_seats;
        }
        int getID()
        {
            return ID;
        }
        string seeCountryDeparture()
        {
            return this->country_departure;
        }

        string seeCountryArrival()
        {
            return this->country_arrival;
        }
        void setAvailableSeats(int available_seats)
        {
            this->available_seats = available_seats;
        }

        void see_fly()
        {
            cout << "Numar zbor: " << ID << endl;
            cout << "Din " << country_departure << " in " << country_arrival << endl;
            cout << "\tData plecare: " << day_departure << "/" << month_departure << "/" << year_arrival << "\t\t" << "Data sosire: " << day_arrival << "/" << month_arrival << "/" << year_arrival << endl;
            cout << "\tOra plecare:  " << hour_departure << ":" << minutes_departure << "\t\t" << "Ora sosire: " << hour_arrival << ":" << minutes_arrival << endl;
            cout << "\tLocuri disponibile: " << available_seats << endl;
            cout << "\n";
            
        }
};

vector <Flights> fly;

class Time
{
    public:
        time_t now;
        struct tm *my_time;
        Time();
        ~Time();
                
};

Time::Time()
    {
        now = time(0);
        my_time = localtime(&now);
    }

Time::~Time()
{
    delete [] my_time;
}

class Operator
{
    private:
        string operator_user = "Grigore Iulia-Andreea";
        
        //parola criptata pentru operator
        string encrypted_password = "020502190309030C03030219030A01180219030403120312030B0300021903000118031C0219011D01160100";
        char operations;
               
    public:
        friend class System;

        string get_encrypted_password()
        {
            return encrypted_password;
        }                   
        
};

class User
{
    private:
        string username;
        string encrypted_user_password;
        string first_name;
        string last_name;
        string mail;
    
    public:

        User(string username, string encrypted_user_password, string first_name, string last_name, string mail)
        {
            this->username = username;
            this->encrypted_user_password = encrypted_user_password;
            this-> first_name = first_name;
            this->last_name = last_name;
            this->mail = mail;
        }

        string get_username()
        {
            return this->username;
        }

        string get_encrypted_user_password()
        {
            return this->encrypted_user_password;
        }

        string get_first_name()
        {
            return this->first_name;
        }

        string get_last_name()
        {
            return this->last_name;
        }

        string get_mail()
        {
            return this->mail;
        }

        void see_user_data()
        {
            cout << "Numele utilizator: " << last_name << endl;
            cout << "Prenume utilizator: " << first_name << endl;
            cout << "Username: " << username << endl;
            cout << "Parola criptata a utilizatorului: " << encrypted_user_password << endl;
            cout << "Mail: " << mail << endl;
            cout << "\n";
            
        }
        
};

vector <User> U;

class System
{
    private:
        char option;
        string user;
        string password;
    public:
       
        void setOption(char character)
        {
            if(character != 'o' && character != 'O' && character != 'u' && character != 'U')
            {
                throw "Nu exista aceasta optiune.\nRefaceti pasii pentru a va loga.";
            }
            this->option = character;
        }
        string get_password()
        {
            return password;
        }
       
        void autentification(char character)
        {

            fflush(stdin);

            cout << "Nume de utilizator: ";
            getline(cin, user);
        
            cout << "Parola: ";
            getline(cin, password);
        
        }

        void display_results_for_operator_autentification(Operator obj)
        {
            loadAscii();
            
            if(user == obj.operator_user && password != deCrypt(obj.encrypted_password, getPublicKey()))
            {
                throw 401;
            }
            else if(user != obj.operator_user && password == deCrypt(obj.encrypted_password, getPublicKey()))
            {
                throw "Nume de utilizator incorect";
            }
            else if(user != obj.operator_user && password != deCrypt(obj.encrypted_password, getPublicKey()))
            {
                throw 'X';
            }
    
            cout << "\nBun venit, Grigore Iulia-Andreea!" << endl;
    
        }

     
};

int main()
{
    
    int i, n = 3, case_add = 0, case_remove = 0, pos;
    int nr_users = 0;
    int remove_flight;
    Operator operator1;
    System acces1;
    // string user, password;
    char option, operation, option_user;
    char operations = 'a';
    auto aux_j = fly.begin();
    string u_auten;
    char p_auten[30];
    char mail[50];
    char aux_mail[50];
    char password[50];
    char copy_password[50];
    string firstName;
    string lastName;
    string username;
    string encrypted_password;
    int err;
    
    

    Flights f1("Romania", "Italia", 15, 1, 2022, 12, 15, 15, 1, 2022, 20,15, 100, 1);
    Flights f2("Romania", "Statele Unite", 15, 3, 2022, 8, 15,16, 3, 2022, 12,15, 150, 2);
    Flights f3("Romania", "Olanda", 15, 2, 2022, 9, 30, 15, 3, 2022, 18,15, 50, 3);

    


    fly.push_back(f1);
    fly.push_back(f2);
    fly.push_back(f3);
    
    cout << "\nBun venit! Autentificati-va in contul asociat dumneavoastra.\n";
    cout << "Aveti doua optiuni: o --> Operator\n\t\t    u --> Utilizator\n";
    cout << "Introduceti caracterul corespunzator contului in care doriti sa va autentificati.\n";
    cout << "Introduceti optiunea: ";
    cin >> option;


    if(option == 'o' || option == 'O')
    {
         try
        {
            acces1.setOption(option);
        }
        catch(const char* msg1)
        {
            cerr << msg1 << endl;
            return 0;
        }

        acces1.autentification(option);

        try
        {
            acces1.display_results_for_operator_autentification(operator1);
        } catch(int password_err)
        {
            cout << "Parola incorecta";
        }
        catch(const char* msg2)
        {
            cerr << msg2 << endl;
        }
        catch(...)
        {
            cout << "Nume de utilizator si parola gresit" << endl;
        }

            cout << "Puteti efectua urmatoarele operatii: a --> Adaugati zboruri\n\t\t\t\t     r --> Stergeti zboruri\n\t\t\t\t     x --> Incheiati activitatea" << endl; 
            

            if(operations != 'a' && operations != 'r' && operations != 'x')
            {
                cout << "Nu exista aceasta operatie";
                return 0;
            }
            while(operations != 'x')
            {
                cout << "Introduceti operatia pe care doriti s-o efectuati: ";
                cin >> operations;
                switch(operations)
                {
                    case 'a':
                    {
                        char information_array[14][30];
                        char aux_information[100];
                        char *word;
                        Time time_obj;

                        if(case_add == 0)
                        {
                            cout << "\nAdaugati un zbor: " << endl;
                            cout << "Modul in care puteti introduce zoborul este urmatorul" << endl;
                            cout << "Tara de plecare/Tara de sosire/Ziua de plecare/Luna de plecare/Anul de plecare/Ora de plecare/";
                            cout << "Minutele la care se pleca/Ziua desosire/Luna de sosire/Anul de sosire/";
                            cout << "Ora de sosire/Minutele la care se soseste/Locuri disponibile/Numar zbor" << endl;
                            cout << "Exemplu: ";
                            cout << "Romania/Spania/15/6/2022/8/30/15/6/2022/19/30/50/4" << endl;
                            cout << "\nIntroduceti datele zborului pe care vreti sa-l adaugati: ";
                            case_add = 1;
                        }
                        else
                        {
                            cout << "\nIntroduceti datele zborului pe care vreti sa-l adaugati: ";
                        }  
                        n++;

                        fflush(stdin);
                        cin >> aux_information;

                        word = strtok(aux_information, "/");
                        i = 0;
                        while(word)
                        {
                            strcpy(information_array[i], word);
                            i++;
                            word = strtok(NULL , "/");
                        }

                        try
                        {
                            for(pos = 0; pos < strlen(information_array[0]); pos++)
                            {
                                if(isalpha(information_array[0][pos]) == 0)
                                {
                                    throw "Caractere inexistente in numele tarii"; 
                                }
                            }
                            for(pos = 0; pos < strlen(information_array[1]); pos++)
                            {
                                if(isalpha(information_array[1][pos]) == 0)
                                {
                                    throw "Caractere inexistente in numele tarii"; 
                                }
                            }
                        }
                        catch(const char* msg3)
                        {
                            cerr << msg3 << endl;
                            return 0;
                        }

                        try
                        {
                            for(pos = 0; pos < strlen(information_array[2]); pos++)
                            {
                                if(isdigit(information_array[2][pos]) == 0)
                                {
                                    throw "Data contine caractere care nu sunt numere/cifre";
                                }
                            }

                            for(pos = 0; pos < strlen(information_array[3]); pos++)
                            {
                                if(isdigit(information_array[3][pos]) == 0)
                                {
                                    throw "Data contine caractere care nu sunt numere/cifre";
                                }
                            }

                            for(pos = 0; pos < strlen(information_array[4]); pos++)
                            {
                                if(isdigit(information_array[4][pos]) == 0)
                                {
                                    throw "Data contine caractere care nu sunt numere";
                                }
                            }

                            for(pos = 0; pos < strlen(information_array[7]); pos++)
                            {
                                if(isdigit(information_array[7][pos]) == 0)
                                {
                                    throw "Data contine caractere care nu sunt numere";
                                }
                            }

                            for(pos = 0; pos < strlen(information_array[8]); pos++)
                            {
                                if(isdigit(information_array[8][pos]) == 0)
                                {
                                    throw "Data contine caractere care nu sunt numere";
                                }
                            }

                            for(pos = 0; pos < strlen(information_array[9]); pos++)
                            {
                                if(isdigit(information_array[9][pos]) == 0)
                                {
                                    throw "Data contine caractere care nu sunt numere";
                                }
                            }
                            
                        }
                        catch(const char* msg4)
                        {
                            cerr << msg4 << endl;
                            return 0;
                        }

                        // cout << "Data curenta este: " <<time_obj.my_time->tm_mday <<"/"<<1 + time_obj.my_time->tm_mon <<"/" << 1900 + time_obj.my_time->tm_year << endl;
                        try
                        {
                            if(stoi(information_array[4]) < 1900 + time_obj.my_time->tm_year)
                            {
                                throw "Data este in trecut";
                            }
                            else if(stoi(information_array[4]) == 1900 + time_obj.my_time->tm_year && stoi(information_array[3]) < 1 + time_obj.my_time->tm_mon)
                            {

                                throw "Data este in trecut";
                            }
                            if(stoi(information_array[4]) == 1900 + time_obj.my_time->tm_year && stoi(information_array[3]) == 1 + time_obj.my_time->tm_mon && stoi(information_array[2]) < time_obj.my_time->tm_mday)
                            {
                                throw "Data este in trecut";
                            }
                        }
                        catch(const char* msg5)
                        {
                            cerr << msg5 << endl;
                            return 0;
                        }

                        fflush(stdin);
                        Flights new_obj(information_array[0], information_array[1], stoi(information_array[2]), 
                        stoi(information_array[3]), stoi(information_array[4]), stoi(information_array[5]), 
                        stoi(information_array[6]), stoi(information_array[7]), stoi(information_array[8]), 
                        stoi(information_array[9]), stoi(information_array[10]), stoi(information_array[11]), 
                        stoi(information_array[12]), stoi(information_array[13]));
                        
                        fly.push_back(new_obj);

                        break;
                    }
                    case 'r':
                    {
                        if(case_remove == 0)
                        {
                            cout << "\nStergeti un zbor:" << endl;
                            cout << "Selectati numarul zbotului pe care vreti sa-l stergeti: " << endl;
                            cout << "Exemplu: ";
                            cout << "1" << endl;
                            cout << "Zborurile curente sunt: " << endl;
                            for(i = 0; i < n; i++)
                            {
                                
                                fly[i].see_fly();
                            }

                            cout << "\nIntroduceti numarul zborului pe care vreti sa-l stergeti(1/2/3/...): ";
                            cin >> remove_flight;
                            case_remove = 1;
                        }
                        else
                        {
                            cout << "\nIntroduceti numarul zborului pe care vreti sa-l stergeti(1/2/3/...) ";
                            cin >> remove_flight;
                        }

                        for(auto j = fly.begin(); j != fly.end(); ++j)
                        {
                            if(j->getID() == remove_flight)
                            {
                                aux_j = j;
                            }
                        }

                        fly.erase(aux_j);
                        n--;

                    if(n == 0)
                    {
                        cout << "Nu exista zboruri curente" << endl;
                    }
                    else
                    {
                        cout << "Zborurile curente sunt:" << endl;
                        for(i = 0; i < n; i++)
                        {
                            
                            fly[i].see_fly();
                        }
                    }

                        break;
                    }
                    case 'x':
                    {
                        break;
                    }
                }
            }
            
    }
    else if(option == 'u' || option == 'U')
    {
        cout << "\nAutentificati-va sau creati-va un cont.\n";
        cout << "Aveti doua optiuni: a --> Autentificare in contul personal\n\t\t    c --> Creere cont\n";
        cout << "Introduceti caracterul corespunzator operatiei pe care vreti s-o realizati.\n";
        cout << "Introduceti optiunea: ";
        cin >> option_user;

        try
        {
            if(option_user != 'a' && option_user != 'c')
            {
                throw "Nu exista aceasta optiune";
            }
        }
        catch(const char* msg6)
        {
            cerr << msg6 << endl;
            return 0;
        }

        if(option_user == 'c')
        {
            
            err = 1;

            cout << "\nIntroduceti urmatoarele date:\n" << endl;

            cout << "Nume de familie: ";
            cin >> lastName;

            cout << "Prenume: ";
            cin >> firstName;

            fflush(stdin);
            cout << "\nMail-ul trebuie sa fie de forma andreeagrigore@gmail.com" << endl;
            cout << "Introduceti mail-ul: ";
            cin >> mail;

        while(err == 1)
        {
            try
            {
                char *p;
                int words_nr = 0;
                int ok1 = 0, ok2 = 0, iter;

                //se verifica daca mail-ul este de forma utilizator@domeniu.TLD
                for(iter = 0; iter < strlen(mail); iter++)
                {
                    //verificarea existentei caracterului @ si . in ordinea aceasta
                    if(mail[iter] == '@')
                    {
                        ok1 = 1;
                        if(ok2 == 1)
                        {
                            ok1 = 0;
                            break;
                        }
                    }
                    else if(mail[iter] == '.')
                    {
                        ok2 = 1;
                    }
                }
                //verificarea numarului de cuvinte separate de caracterele . si @
                strcpy(aux_mail, mail);
                p = strtok(mail, "@.");
                while(p)
                {
                    words_nr++;
                    p = strtok(NULL, "@.");
                }
                
                if(words_nr != 3 || ok1 != 1 || ok2 != 1)
                {
                    throw "Mail-ul trebuie sa fie de forma andreeagrigore@gmail.com";
                }
                else if(words_nr == 3 && ok1 == 1 && ok2 == 1)
                {
                    err = 0;
                }
            }
            catch(const char* msg7)
            {
                cerr << msg7 << endl;
                cout << "Reintroduceti un mail potrivit: ";
                cin >> mail;
                strcpy(aux_mail, mail);
                
            }
        }
            

            fflush(stdin);
            cout << "Nume de utilizator: ";
            cin >> username;
            
            fflush(stdin);
            cout << "\nParola trebuie sa contina:" << endl;
            cout << "-> minim 8 caractere" << endl;
            cout << "-> minim o litera mica" << endl;
            cout << "-> minim o litera mare" << endl;
            cout << "-> minim o cifra" << endl;
            cout << "-> minim un caracter special\n" << endl;
            cout << "Introduceti parola: ";
            cin >> password;
            fflush(stdin);

        err = 1;
        while(err == 1)
        {
            try
            {
                int first_try = 1;
                int ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0, iter;
                
                if(strlen(password) < 8)
                {
                    throw "Parola trebuie sa contina minim 8 caractere";
                }
                else
                {
                    for(iter = 0; iter < strlen(password); iter++)
                    {
                        if(isalpha(password[iter]) == 1 && isupper(password[iter]) == 0)
                        {
                            ok1 = 1;
                        }
                        else if(isdigit(password[iter]) == 1)
                        {
                            ok2 = 1;
                        }
                        else if(isupper(password[iter]) == 1)
                        {
                            ok3 = 1;
                        }
                        else if(isalpha(password[iter]) == 0 && isdigit(password[iter]) == 0)
                        {
                            ok4 = 1;
                        }
                    }

                    if(ok1 == 0)
                    {
                        throw 'e';
                    }
                    else if(ok2 == 0)
                    {
                        throw 401;
                    }
                    else if(ok3 == 0)
                    {
                        throw operator1;
                    }
                    else if(ok4 == 0)
                    {
                        throw 4.1;
                    }
                    else
                    {
                        err = 0;
                    }
                    
                }
                
            }
            catch(const char* msg8)
            {
                cerr << msg8 << endl;
                cout << "Reintroduceti o parola potrivita: ";
                cin >> password;
            }
            catch(char x)
            {
                cout << "Parola trebuie sa contina litere mici" << endl;
                cout << "Reintroduceti o parola potrivita: ";
                cin >> password;
            }
            catch(int x)
            {
                cout << "Parola trebuie sa contina minim o cifra" << endl;
                cout << "Reintroduceti o parola potrivita: ";
                cin >> password;
            }
            catch(Operator o)
            {
                cout << "Parola trebuie sa contina o litera mare" << endl;
                cout << "Reintroduceti o parola potrivita: ";
                cin >> password;
            }
            catch(...)
            {
                cout << "Parola trebuie sa contina un caracter special" << endl;
                cout << "Reintroduceti o parola potrivita: ";
                cin >> password;
            }
        }
            
            
            fflush(stdin);
            cout << "Repetati parola: ";
            cin >> copy_password;
            fflush(stdin);

            err = 1;
            while(err == 1)
            {
                try
                {
                    if(strcmp(password, copy_password) != 0)
                    {
                        throw "Parolele nu coincid";
                    }
                    else
                    {
                        err = 0;
                    }
                }
                catch(const char* msg9)
                {
                    cerr << msg9 << endl;
                    cout << "Reintroduceti a doua parola: ";
                    cin >> copy_password;
                }
            }

            loadAscii();
            encrypted_password = enCrypt(password, getPrivateKey());

            nr_users++;

            User new_user(username, encrypted_password, firstName, lastName, aux_mail);
            U.push_back(new_user);

            cout << "\nFelicitari, " << firstName << " contul tau a fost creat cu succes!" << endl;
            cout << "\nCautati un zbor sau rezervati un loc.\n";
            cout << "Aveti doua optiuni: a --> Autentificare in contul personal\n\t\t    x --> Incheiati activitatea" << endl;
            cout << "Introduceti caracterul corespunzator operatiei pe care vreti s-o realizati.\n";
             
        }
       

        while(option_user != 'x')
        {
            cout << "Introduceti operatia pe care doriti s-o efectuati: ";
            cin >> option_user;

            switch(option_user)
            {
                case 'a':
                {
                    int first = 1;

                    if(first == 1)
                    {
                        cout << "Introduceti username-ul: ";
                        cin >> u_auten;

                        fflush(stdin);
                        cout << "Introduceti parola: ";
                        cin >> p_auten;

                    }

                    err = 1;

                    while(err == 1)
                    {
                        for(i = 0; i < nr_users; i++)
                        {
                            if(U[i].get_username() == u_auten && deCrypt(U[i].get_encrypted_user_password(), getPublicKey()) == p_auten)
                            {
                                err = 0;
                                first = 0;
                                cout << "Te-ai autentificat cu suces, " << u_auten << "!" << endl;
                                break;
                            }
                        }
                        try
                        {
                            if(err == 1)
                            {
                                throw "Nu exista persoane inregistrate cu aceste credentiale";
                                
                            }
                        }
                        catch(const char* msg10)
                        {
                            cerr << msg10 << endl;
                            return 0;
                            
                        }
                    }       

                    char fly_option, country_d[50], country_a[50];
                    cout << "Poti cauta si rezerva un zobor" << endl;
                    cout << "Doresti sa cauti un zvor? y --> Da\n\t\t          n --> Inca nu, mersi" << endl;
                    cout << "Introduceti optiunea: ";
                    cin >> fly_option;

                    if(fly_option == 'y')
                    {
                        cout << "Introduceti tara de plecare: ";
                        fflush(stdin);
                        cin >> country_d;

                        cout << "Introduceti tara destinatie: ";
                        fflush(stdin);
                        cin >> country_a;

                        int ok = 0;
                         
                        err = 1;
                        while(err == 1)
                        {
                            for(i = 0; i < n; i++)
                            {
                                if(fly[i].seeCountryDeparture() == country_d && fly[i].seeCountryArrival() == country_a)
                                {
                                    ok = 1;
                                    err = 0;
                                    break;
                                }
                            }
                            try
                            {
                                if(ok == 0)
                                {
                                    throw "Zbor inexistent";
                                }
                            }
                            catch(const char* msg11)
                            {
                                cerr << msg11 << endl;

                                cout << "Reintroduceti tara de plecare: ";
                                fflush(stdin);
                                cin >> country_d;

                                cout << "Reintroduceti tara destinatie: ";
                                fflush(stdin);
                                cin >> country_a;
                            }
                        }
                        cout << "Datele zborului cautat:" << endl;
                        fly[i].see_fly();
                        
                        char fly_option_rez;
                        string fname_res, lname_res, mail_res;
                        int aux_available_seats;

                        cout << "Doriti sa rezervati un loc? y --> Da\n\t\t            n --> Inca nu, mersi" << endl;
                        cout << "Introduceti optiunea: ";
                        cin >> fly_option_rez;

                        if(fly_option_rez == 'y')
                        {
                            cout << "Introduceti numele dumnevoastra: ";
                            cin >> lname_res;

                            cout << "Introduceti prenumele: ";
                            cin >> fname_res;

                            cout << "Introduceti mail-ul: ";
                            cin >> mail_res;

                            err = 1;
                            while(err == 1)
                            {
                                if(lname_res == lastName && fname_res == firstName && mail_res == aux_mail)
                                {
                                    err = 0;
                                    aux_available_seats = fly[i].seeAvailableSeats();
                                    aux_available_seats--;
                                    fly[i].setAvailableSeats(aux_available_seats);
                                    fly[i].see_fly();
                                    cout << "\nLocul a fost rezervat cu succes!" << endl;
                                    cout << "Au mai ramas " << fly[i].seeAvailableSeats() << " locuri libere" << endl;
                                    cout << "Veti fi contactat in curand pentru achitarea serviciului de calatorie." << endl;
                                    cout << "Va multumim ca ati ales BlueAir, zbor placut!" << endl;
                                    return 0;

                                }
                                else
                                {
                                    try
                                    {
                                        if(lname_res != lastName || fname_res != firstName || mail_res != aux_mail)
                                        {
                                            throw "Date incorecte";
                                        }
                                    }
                                    catch(const char* msg12)
                                    {
                                        cerr << msg12 << endl;

                                        cout << "\nVa rugam introduceti date dumneavoastra corect!" << endl;

                                        cout << "Introduceti numele dumnevoastra: ";
                                        cin >> lname_res;

                                        cout << "Introduceti prenumele: ";
                                        cin >> fname_res;

                                        cout << "Introduceti mail-ul: ";
                                        cin >> mail_res;
                                    }
                                }
                            }
                            

                        }
                    }
                    else if(fly_option == 'n')
                    {
                        cout << "Va asteptam cu drag data viitoare!" << endl;
                        
                    }

                    break;
                }
                case 'x':
                {
                    break;
                }

            }
        }

    }

    fly.clear();
    U.clear();

    return 0;
}