#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

//OPERATOR

class Operator
{
public:
    char id[100];
    char password[100];

    void getId()
    {
        cout << "Introduceti numele dumneavoastra de operator: \t";
        cin >> id ;
    }

    int searchInfo(int value1)
    {
        value1=0;
        ifstream fin;
        string fname = "Operatori.csv";

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file (fname, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }
        int i;
        int j;
        int aux = 0;
        string answer;

        for(i=1; i<int(content.size()); i++)
        {
            if(content[i][0] == id )
            {
                aux++;
                j=i;
            }
            if(aux == 1) break;
        }

        while(aux == 0)
        {
            cout << "Numele de operator nu a fost gasit!" << endl ;
            cout << "Doriti sa introduceti din nou numele de operator?\t" << endl;
            cin >> answer ;
            if(answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
            {
                cout << "Introduceti numele dumneavoastra de utilizator: \t";
                cin >> id ;
                for(i=1; i<int(content.size()); i++)
                {

                    if(content[i][0] == id )
                    {
                        aux++;
                        j=i;
                    }
                    if(aux == 1) break;
                }
                if(aux == 1) break;
            }
            else if(answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")
            {
                exit(EXIT_FAILURE);
            }
        }

        if(aux == 1)
        {
            cout << "Numele de operator a fost gasit!"<< endl;
            cout << "Introduceti parola dumneavoastra: \t";
            cin >> password;

            if(content[j][1] == password)
            {
                cout << "Parola a fost gasita!\t" << endl;
                aux++;
                value1++;
            }

            while(aux == 1)
            {
                cout << "Parola este gresita!\t" << endl;
                cout << "Doriti sa introduceti din nou parola?\t" << endl;
                cin >> answer ;
                if(answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
                {
                    cout << "Introduceti parola dumneavoastra: \t" <<endl;
                    cin >> password;
                    if(content[j][1] == password)
                    {
                        cout << "Parola a fost gasita!\t" << endl;
                        aux++;
                        value1++;
                    }
                }
                else if (answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")
                {
                    exit(EXIT_FAILURE);
                }
            }
        }
        file.close();
        return value1;
    }

    // Adaugare rute

    void AddRoutes()
    {
        string source;
        string dest;
        int day;
        int month;
        int hour;
        int minutes;
        int period;

        fstream file;
        string fname = "Orase.csv";

        cout << "Introduceti orasul sursa:";
        cin >> source;

        bool containsNonLetter = false;

        for (char c : source)
        {
            if (!std::isalpha(c))
            {
                containsNonLetter = true;
                break;
            }
        }
        cout << "Orasul sursa introdus este gresit! Va trebui sa il introduceti din nou. \t";
        while(containsNonLetter == true)
            {
        cout << "Introduceti orasul sursa:";
        cin >> source;

        for (char c : source)
        {
            if (!std::isalpha(c))
            {
                containsNonLetter = true;
                cout << "Orasul sursa introdus este gresit! Va trebui sa il introduceti din nou. \t";
                break;
            }
            else containsNonLetter = false;
        }
        }

        cout << "Introduceti orasul destinatie:";
        cin >> dest;

        for (char c : source)
        {
            if (!std::isalpha(c))
            {
                containsNonLetter = true;
                break;
            }
        }
        cout << "Orasul destinatie introdus este gresit! Va trebui sa il introduceti din nou. \t";
        while(containsNonLetter == true){
        cout << "Introduceti orasul destinaie:";
        cin >> dest;

        for (char c : source)
        {
            if (!std::isalpha(c))
            {
                containsNonLetter = true;
                cout << "Orasul destinatie introdus este gresit! Va trebui sa il introduceti din nou. \n";
                break;
            }
            else containsNonLetter = false;
        }
        }

        cout << "Luna:";
        cin>> month;
        while(month > 12 || month == 0)
        {
            cout << "Luna incorecta! Introduceti din nou:";
            cin>>month;
        }

        cout << "Ziua:";
        cin >> day;
        while(( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day == 0 || day > 31) )
        {

            cout << "Zi gresita! Introduceti din nou:";
            cin>> day;
        }

        while(( month == 4 || month == 6 || month == 9 || month == 11 ) && (day == 0 || day > 30) )
        {

            cout << "Zi gresita! Introduceti din nou:";
            cin>> day;
        }
        while( month == 2 && (day == 0 || day >29 ))
        {

            cout << "Zi gresita! Introduceti din nou:";
            cin>> day;
        }


        cout << "Ora:";
        cin >> hour;
        while(hour >= 24)
        {
            cout << "Ora incorecta! Introduceti din nou:";
            cin>>hour;
        }

        cout << "Minute:";
        cin >> minutes;
        while(minutes >= 60)
        {
            cout << "Minute incorecte! Introduceti din nou:";
            cin>>minutes;
        }

        cout << "Durata (minute):";
        cin >> period;


        file.open(fname, fstream::app);
        file << source << "," << dest << "," << day << "," << month << "," << hour << "," << minutes << "," << period << '\n';

        file.close();
    }

    // Stergere rute

    void DeleteRoutes(){

    std::string filename = "Orase.csv";

    std::string sursaToDelete;
    std::string destinatieToDelete;
    int ziToDelete;
    int lunaToDelete;
    int oraToDelete;
    int minuteleToDelete;
    int durataToDelete ;

    cout << "Introduceti sursa:\n";
    cin >> sursaToDelete;

    cout << "Introduceti destinatia:\n";
    cin >> destinatieToDelete;


    cout << "Introduceti ziua:\n";
    cin >> ziToDelete;

    cout << "Introduceti luna:\n";
    cin >> lunaToDelete;

    cout << "Introduceti ora:\n";
    cin >> oraToDelete;

    cout << "Introduceti minutele:\n";
    cin >> minuteleToDelete;

    cout << "Introduceti durata:\n";
    cin >> durataToDelete;


    std::vector<std::vector<std::string>> data;
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    inputFile.close();

    auto rowToDelete = std::find_if(data.begin(), data.end(), [sursaToDelete, destinatieToDelete, ziToDelete, lunaToDelete, oraToDelete, minuteleToDelete, durataToDelete](const std::vector<std::string>& row) {
        return row.size() >= 7 &&
               row[0] == sursaToDelete &&
               row[1] == destinatieToDelete &&
               std::stoi(row[2]) == ziToDelete &&
               std::stoi(row[3]) == lunaToDelete &&
               std::stoi(row[4]) == oraToDelete &&
               std::stoi(row[5]) == minuteleToDelete &&
               std::stoi(row[6]) == durataToDelete;
    });


    if (rowToDelete != data.end()) {

        data.erase(rowToDelete);
        std::ofstream outputFile(filename);

        if (!outputFile) {
            std::cerr << "Error opening file for writing." << std::endl;
        }

        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                outputFile << row[i];
                if (i < row.size() - 1) {
                    outputFile << ',';
                }
            }
            outputFile << std::endl;
        }

        outputFile.close();

        std::cout << "Ruta a fost stearsa cu succes!" << std::endl;
    } else {
        std::cout << "Ruta nu a fost gasita!" << std::endl;
    }
    }
};

//USER

class User
{
public:
    char id[100];
    char password[100];

    void getId()
    {
        cout << "Introduceti numele dumneavoastra de utilizator: \t";
        cin >> id ;
    }

    int searchInfo(int value1)
    {
        value1=0;
        ifstream fin;
        string fname = "Users and Passwords.csv";

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file (fname, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }
        int i;
        int j;
        int aux = 0;
        string answer;

        for(i=1; i<int(content.size()); i++)
        {
            if(content[i][0] == id )
            {
                aux++;
                j=i;
            }
            if(aux == 1) break;
        }

        while(aux == 0)
        {
            cout << "Numele de utilizator nu a fost gasit!" << endl ;
            cout << "Doriti sa introduceti din nou numele de utilizator?\t" << endl;
            cin >> answer ;
            if(answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
            {
                cout << "Introduceti numele dumneavoastra de utilizator: \t";
                cin >> id ;
                for(i=1; i<int(content.size()); i++)
                {

                    if(content[i][0] == id )
                    {
                        aux++;
                        j=i;
                    }
                    if(aux == 1) break;
                }
                if(aux == 1) break;
            }
            else if(answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")
            {
                exit(EXIT_FAILURE);
            }
        }

        if(aux == 1)
        {
            cout << "Numele de utilizator a fost gasit!"<< endl;
            cout << "Introduceti parola dumneavoastra: \t";
            cin >> password;

            if(content[j][1] == password)
            {
                cout << "Parola a fost gasita!\t" << endl;
                aux++;
                value1++;
            }

            while(aux == 1)
            {
                cout << "Parola este gresita!\t" << endl;
                cout << "Doriti sa introduceti din nou parola?\t" << endl;
                cin >> answer ;
                if(answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
                {
                    cout << "Introduceti parola dumneavoastra: \t" <<endl;
                    cin >> password;
                    if(content[j][1] == password)
                    {
                        cout << "Parola a fost gasita!\t" << endl;
                        aux++;
                        value1++;
                    }
                }
                else if (answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")
                {
                    exit(EXIT_FAILURE);
                }
            }
        }
        file.close();
        return value1;
    }

    int Routes(int value2)
    {
        value2 = 0;
        string source;
        string dest;

        cout << "Introduceti orasul sursa:\t" << endl;
        cin >> source;
        cout << "Introduceti orasul destinatie: \t" << endl;
        cin >> dest;

        ifstream fin;
        string fname = "Orase.csv";

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file (fname, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }

        int i;
        int j[100];
        int aux = 0;
        string answer;

        for(i=1; i<int(content.size()); i++)
        {
            if(content[i][0] == source && content[i][1] == dest )
            {
                cout << "Ruta a fost gasita! \t" << endl ;
                j[aux]=i;
                aux++;
            }
        }

        while(aux == 0)
        {
            cout << "Ruta nu a fost gasita!" << endl;
            cout << "Doriti sa introduceti informatiile din nou?" << endl;
            cin >> answer;
            if(answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
            {
                cout << "Introduceti orasul sursa:\t" << endl;
                cin >> source;
                cout << "Introduceti orasul destinatie: \t" << endl;
                cin >> dest;
                for(i=1; i<int(content.size()); i++)
                {
                    if(content[i][0] == source && content[i][1] == dest )
                    {
                        cout << "Ruta fost gasita!\t" << endl;
                        j[aux]=i;
                        aux++;
                    }

                    else if(content[i][0] != source || content[i][1] != dest) cout << "Ruta nu a fost gasita!\t" << endl;
                }
            }
            else if (answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")
            {
                exit(EXIT_FAILURE);
            }
        }

        if( aux != 0 )
        {
            cout << "Vi se vor afisa detalii precum ziua, luna, ora si durata calatoriei:" << endl;
            for(i=0; i<aux; i++)
            {
                cout << "Ziua: " << content[j[i]][2] << "\t" << "Luna: " << content[j[i]][3] << "\t" << "Ora: "  << content[j[i]][4] << ":" << content[j[i]][5] << "\t" << "Durata aproximata in ore: " << content[j[i]][6] << endl;
                value2++;
            }
        }
        file.close();
        return value2;
    }

    void ticketInfo()
    {

        string ticket;

        cout << "Alegeti una dintre urmatoarele: " << endl;
        cout << "As dori bilet: " << endl;
        cout << "normal\t" << " elev\t" << " student\t" << "pensionar\t" << endl;

        cin >> ticket;

        if(ticket == "normal") cout << "Pretul biletului ramane nemodificat!" << endl;
        else if (ticket == "elev" || ticket == "student" || ticket == "pensionar") cout << "Aveti o reducere de 50%!" << endl;

    }

};

//CREATE USER
class Create
{

public:
    char id[100];
    char password1[100];
    char password2[100];
    char str1[100] = "_-[]\{}|/*-+=?>.<,!`~";
    char str2[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str3[100] = "1234567890";
    int aux1;
    int aux2;
    int aux3;

    void getIdAndAddtoFile()
    {
        cout << "Introduceti numele de utilizator dorit: \t";
        cin >> id ;
        cout << "Introduceti parola (aceasta trebuie sa contina cel putin un caracter special, o cifra si o litera mare):\t";
        cin >> password1;
        aux1=strcspn(password1,str1);
        aux2=strcspn(password1,str2);
        aux3=strcspn(password1,str3);
        int length = strlen(password1);
        while(aux1 == length || aux2 == length || aux3 == length )
        {

            cout << "Parola nu respecta cele 3 conditii! Va rugam sa introduceti alta parola:\t";
            cin >> password1;
            aux1=strcspn(password1,str1);
            aux2=strcspn(password1,str2);
            aux3=strcspn(password1,str3);
            length = strlen(password1);

        }
        cout << "Repetati parola:"<< endl;
        cin >> password2;
        while( strcmp(password1,password2)!= 0)
        {
            cout << "Parola este incorecta! Va rugam sa o repetati: \t";
            cin >> password2;
        }
    }

    void encryptPassword()
    {
        int i;
        for(i = 0; (i < 100 && password2[i] != '\0'); i++) password2[i] = password2[i] + 2;
    }


    void getData()
    {
        fstream file;
        string fname = "Users and Passwords.csv";

        file.open(fname, fstream::app);
        file << id << "," << std::string(password2) << '\n';

        file.close();
    }
};

int main()
{
    string answer;
    int aux1=0;
    int aux2=0;
    int y1;
    int y2;

    cout << "Alegeti dintre urmatoarele: utilizator/operator.";
    cin >> answer;

    //se presupune ca operatorii exista deja in sistem, asadar nu e algoritm de adaugare a acestora in sistem

    if(answer == "operator")
    {
        Operator op;
        op.getId();
        y1=op.searchInfo(aux1);

        cout << "Doriti sa adaugati rute noi? ";
        cin >> answer;

        if(y1!= 0 && (answer == "da" || answer == "Da" || answer == "DA" || answer == "dA"))
        {

            op.AddRoutes();
        }
        else if(y1== 0 || (answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")) cout << "La revedere!";

        cout << "Doriti sa stergeti rute? ";
        cin >> answer;

        if(y1!= 0 && (answer == "da" || answer == "Da" || answer == "DA" || answer == "dA"))
        {

            op.DeleteRoutes();
        }
        else if(y1== 0 || (answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")) cout << "La revedere!";
    }


    ///////////////////////////////////////////
    else if(answer == "utilizator")
    {

        cout << "Bine ati venit! Aveti cont de utilizator?" << endl;
        cin >> answer;

        if (answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
        {
            User login;
            login.getId();
            y1=login.searchInfo(aux1);
            if(y1!= 0) y2=login.Routes(aux2);
            else if(y1 == 0)
            {
                y2 = 0;
                cout << "Eroare autentificare!" << endl;
            }
            cout<< "Doriti bilet pe una dintre rute?";
            cin >> answer;
            if(y2!=0 &&  (answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")) login.ticketInfo();

        }
        else if (answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU")
        {
            cout << "Doriti sa va realizati un cont?\t" << endl;
            cin >> answer;
            if(answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
            {
                Create create;
                create.getIdAndAddtoFile();
                create.encryptPassword();
                create.getData();
                cout << "Doriti sa va autentificati?" << endl;
                cin >> answer;
                if(answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")
                {
                    User login1;
                    login1.getId();
                    y1=login1.searchInfo(aux1);
                    if(y1!= 0) y2=login1.Routes(aux2);
                    else if(y1 == 0)
                    {
                        y2 = 0;
                        cout << "Eroare autentificare!" << endl;
                    }
                    cout<< "Doriti bilet pe una dintre rute?";
                    cin >> answer;
                    if(y2!=0 &&  (answer == "da" || answer == "Da" || answer == "DA" || answer == "dA")) login1.ticketInfo();
                }
            }
            else if (answer == "nu" || answer == "Nu" || answer == "NU" || answer == "nU") cout << "Va dorim o zi buna! " << endl;
        }
    }

    return 0;
}
