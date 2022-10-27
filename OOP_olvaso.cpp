#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include <locale.h>
#include <string>
using namespace std;

struct Entry {
    int lnum;
    string text;
};
class Reader
{
    ifstream file;
    Entry* entries;
    int numofe;
    int curline;
    int targetline;
    string Line;
    void getToLine() { //kiolvassa a megfelelo sort
        targetline -= curline;
        for (int i = 0; i < targetline; i++) {
            getline(file, Line);
        }
    }
    void eCounter() { //megszamolja az opciokat 
        numofe = 1;
        for (int i = 0; i < Line.length(); i++) {
            if (Line[i] == '#') {
                numofe++;
            }
        }
        cout << numofe << endl;
    }
    void Split() { //feldarabolja a sort 
        entries = new Entry[numofe];
        int curpos = 0;
        for (int i = 0; i < numofe; i++)
        {
            entries[i].lnum = stoi(Line.substr(curpos, Line.find('~', curpos) - curpos));
            // cout<<stoi(Line.substr(curpos,Line.find('~',curpos)-curpos));
            curpos = Line.find('~', curpos) + 1;
            entries[i].text = Line.substr(curpos, Line.find('#', curpos) - curpos);
            curpos = Line.find('#', curpos) + 1;
        }
    }
    void Display() { //kiirja a szoveget es az opciokat
        system("cls");
        cout << entries[0].text << endl << endl;
        for (int i = 1; i < numofe; i++) {
            cout << '\t' << i << ". " << entries[i].text << endl;
        }
    }
    void Choose() { //beolvassa a felhasznalo valasztasat
        string str;
        int szam = 1;
        while (true) {
            cin >> str;
            for (int i = 0; i < (str.size()); i++)
            {
                if (!isdigit(str[i])) {
                    szam = 0;
                }
            }
            if (szam == 0) {
                cout << "Ez nem szam!";
                szam = 1;
                continue;
            }
            else { break; }
        }
        targetline = entries[str[0] - 48].lnum;
        curline = entries[0].lnum;
        delete[] entries;
    }
public:
    Reader(string filename) {
        file.open(filename);
        curline = 0;
        numofe = 0;
        entries = 0;
        targetline = 1;
    }
    bool isOpened() {
        return file.is_open();
    }
    void startGame() { //futtatja a jatekot meg ki nem fogy az opciokbol
        bool end = false;
        while (!end)
        {
            getToLine();
            eCounter();
            cout << numofe << endl;
            Split();
            cout << numofe << endl;
            Display();
            if (numofe != 1) {
                Choose();
            }
            else {
                end = true;
                cout << "A JATEKOS IDONEK VÉGE" << endl;
                system("pause");
            }
        }
    }
    void test() {
        string str;
        file >> str;
        cout << str;
    }
    ~Reader() { delete[] entries; }
};

int main() {
    Reader r("filename.txt");
    if (!r.isOpened()) {
        cout << "Nincs ilyen fajl!";
        return 0;
    }
    r.startGame();
    return 0;