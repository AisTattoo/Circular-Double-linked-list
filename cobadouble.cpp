#include <iostream>

using namespace std;

// struktur linked list
struct dataFilm{
  string namaFilm;
  int durasi, hargaTiket;

  // pointer
  dataFilm *prev;
  dataFilm *next;
};

dataFilm *kepala, *ekor, *saatIni, *hapus, *nodeBaru, *setelahNode;

// fungsi membuat circular double Linked list
void createDataFilm( string namaFilm, int durasiFilm, int hargaTiket ){
  kepala = new dataFilm();
  kepala->namaFilm = namaFilm;
  kepala->durasi = durasiFilm;
  kepala->hargaTiket = hargaTiket;
  kepala->prev = kepala;
  kepala->next = kepala;
  ekor = kepala;
}

// add First
void addFirst( string namaFilm, int durasiFilm, int hargaTiket ){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    nodeBaru = new dataFilm();
    nodeBaru->namaFilm = namaFilm;
    nodeBaru->durasi = durasiFilm;
    nodeBaru->hargaTiket = hargaTiket;
    nodeBaru->prev = ekor;
    nodeBaru->next = kepala;
    kepala->prev = nodeBaru;
    ekor->next = nodeBaru;
    kepala = nodeBaru;
  }
}

// add Last
void addLast( string namaFilm, int durasiFilm, int hargaTiket ){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    nodeBaru = new dataFilm();
    nodeBaru->namaFilm = namaFilm;
    nodeBaru->durasi = durasiFilm;
    nodeBaru->hargaTiket = hargaTiket;
    nodeBaru->prev = ekor;
    nodeBaru->next = kepala;
    kepala->prev = nodeBaru;
    ekor->next = nodeBaru;
    ekor = nodeBaru;
  }
}

// add Middle
void addMiddle( string namaFilm, int durasiFilm, int hargaTiket, int posisi ){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      nodeBaru = new dataFilm();
      nodeBaru->namaFilm = namaFilm;
      nodeBaru->durasi = durasiFilm;
      nodeBaru->hargaTiket = hargaTiket;

      // tranversing
      saatIni = kepala;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        saatIni = saatIni->next;
        nomor++;
      }
      setelahNode = saatIni->next;
      saatIni->next = nodeBaru;
      setelahNode->prev = nodeBaru;
      nodeBaru->prev = saatIni;
      nodeBaru->next = setelahNode;
    }
  }
}

// change first
void changeFirst(string namaFilm, int durasiFilm, int hargaTiket) {
  if (kepala == NULL) {
    cout << "Create the Linked List first!" << endl;
  } else {
    kepala->namaFilm = namaFilm;
    kepala->durasi = durasiFilm;
    kepala->hargaTiket = hargaTiket;
  }
}


// change last
void changeLast(string namaFilm, int durasiFilm, int hargaTiket) {
  if (kepala == NULL) {
    cout << "Create the Linked List first!" << endl;
  } else {
    ekor->namaFilm = namaFilm;
    ekor->durasi = durasiFilm;
    ekor->hargaTiket = hargaTiket;
  }
}

// change Middle
void changeMiddle(int posisi, string namaFilm, int durasiFilm, int hargaTiket){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      // tranversing
      saatIni = kepala;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        saatIni = saatIni->next;
        nomor++;
      }
      hapus = saatIni->next;
      hapus->namaFilm = namaFilm;
      hapus->durasi = durasiFilm;
      hapus->hargaTiket = hargaTiket;
    }
  }
}

// remove First
void removeFirst(){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    hapus = kepala;
    kepala = kepala->next;
    ekor->next = kepala;
    kepala->prev = ekor;
    delete hapus;
  }
}

// remove Last
void removeLast(){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    hapus = ekor;
    ekor = ekor->prev;
    ekor->next = kepala;
    kepala->prev = ekor;
    delete hapus;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      // tranversing
      saatIni = kepala;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        saatIni = saatIni->next;
        nomor++;
      }
      hapus = saatIni->next;
      setelahNode = hapus->next;
      saatIni->next = setelahNode;
      setelahNode->prev = saatIni;
      delete hapus;
    }
  }
}

// fungsi print
void printDataFilm()
{
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    cout << "<===== Data Film Bioskop =====> " << endl;
    saatIni = kepala;
    while( saatIni->next != kepala ){
      // print
      cout << "Nama Film : " << saatIni->namaFilm << endl;
      cout << "Durasi Film : " << saatIni->durasi << " menit" << endl;
      cout << "Harga Tiket : Rp." << saatIni->hargaTiket << "\n" << endl;

      // step
      saatIni = saatIni->next;
    }
    // print last node
      cout << "Nama Film : " << saatIni->namaFilm << endl;
      cout << "Durasi Film : " << saatIni->durasi << " menit" << endl;
      cout << "Harga Tiket : Rp." << saatIni->hargaTiket << "\n" << endl;
  }
}

int main(){

  createDataFilm("Avengers", 120, 50000);
  printDataFilm();

  addFirst("Thor", 100, 40000);
  printDataFilm();

  addLast("Spiderman", 90, 35000);
  printDataFilm();

  addMiddle("Hulk", 110, 45000, 6);
  printDataFilm();

  changeMiddle(6, "Ironman", 115, 55000);
  printDataFilm();

  changeFirst("wolverine", 110, 45000);
  printDataFilm();

  changeLast("superman", 180, 87000);
  printDataFilm(); 

  removeMiddle(6);
  printDataFilm();
}