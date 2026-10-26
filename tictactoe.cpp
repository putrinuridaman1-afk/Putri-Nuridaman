#include<iostream>
using namespace std;

char papan[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void tampilkanPapan() {
    cout<<"\n";
    for(int i = 0; i < 3; i++) {
        cout << "" << papan[i][0] << "|"
          << papan[i][1] << "|"
          << papan[i][2] << endl;
        if (i < 2)
           cout << "---+---+---" << endl;
    }
    cout << endl;
}

bool cekMenang(char simbol) {
    for (int i = 0; i < 3; i++) {
        if (papan[0][i] == simbol &&
            papan[i][1] == simbol &&
            papan[i][2] == simbol)
            return true;
        
        if (papan[0][i] == simbol &&
            papan[1][i] == simbol &&
            papan[2][i] == simbol)
            return true;
    }

    if (papan[0][0] == simbol &&
        papan[1][1] == simbol &&
        papan[2][2] == simbol)
        return true;

    if (papan[0][2] == simbol &&
        papan[1][1] == simbol &&
        papan[2][0] == simbol)
        return true;

    return false;      
}

int main() {
    int pilihan;
    char pemain = 'X';

    cout << "=== GAME TIC TAC TOE ===\n";

    for ( int giliran = 0; giliran < 9; giliran++) {
     tampilkanPapan();

     cout << "Pemain" << pemain;
     cout << ",pilih kotak (1-9):";
     cin >> pilihan;

    if (pilihan < 1 || pilihan > 9 ||
        papan[(pilihan - 1) / 3]
          [(pilihan - 1) % 3] == 'X' ||
        papan[(pilihan - 1) / 3]
          [(pilihan - 1) % 3] == 'O') {
        cout << "Pilihan tidak valid! Coba lagi.\n";
        giliran--;
        continue;
    }

    papan[(pilihan - 1) / 3]
      [(pilihan - 1) % 3] =  pemain;

    if (cekMenang(pemain)) {
        tampilkanPapan();
        cout << "Pemain" << pemain
          << "MENANG!\n";
        return 0;
    }

    pemain = (pemain == 'X') ? 'O' : 'X';
  }
  tampilkanPapan();
  cout << "Permainan SERI!\n";

return 0;

}
    
        