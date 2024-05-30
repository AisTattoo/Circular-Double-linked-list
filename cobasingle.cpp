#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct dataFilm{
    string namaFilm;
    int durasi;
    int harga;

    dataFilm *next;
};

dataFilm* kepala, *ekor, *nodeBaru, *saatIni, *hapus;

// Membuat Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3]){
    kepala = new dataFilm();
    kepala->namaFilm = dataBaru[0];
    kepala->durasi = stoi(dataBaru[1]);
    kepala->harga = stoi(dataBaru[2]);
    ekor = kepala;
    ekor->next = kepala;
}

// add first
void addFirst(string data[3]){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        nodeBaru = new dataFilm();
        nodeBaru->namaFilm = data[0];
        nodeBaru->durasi = stoi(data[1]);
        nodeBaru->harga = stoi(data[2]);
        nodeBaru->next = kepala;
        ekor->next = nodeBaru;
        kepala = nodeBaru;
    }
}

// add Last
void addLast(string data[3]){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        nodeBaru = new dataFilm();
        nodeBaru->namaFilm = data[0];
        nodeBaru->durasi = stoi(data[1]);
        nodeBaru->harga = stoi(data[2]);
        nodeBaru->next = kepala;
        ekor->next = nodeBaru;
        ekor = nodeBaru;
    }
}

// add Middle
void addMiddle(string data[3], int posisi){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        if(posisi == 1){
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        }else{
            nodeBaru = new dataFilm();
            nodeBaru->namaFilm = data[0];
            nodeBaru->durasi = stoi(data[1]);
            nodeBaru->harga = stoi(data[2]);
            // tranversing
            int nomor = 1;
            saatIni = kepala;
            while(nomor < posisi - 1){
                saatIni = saatIni->next;
                nomor++;
            }
            nodeBaru->next = saatIni->next;
            saatIni->next = nodeBaru;
        }
    }
}


// change first
void changeFirst(string data[3]) {
  if (kepala == NULL) {
    cout << "Create the Linked List first!" << endl;
  } else {
        kepala->namaFilm = data[0];
        kepala->durasi = stoi(data[1]);
        kepala->harga = stoi(data[2]);
  }
}


// change last
void changeLast(string data[3]) {
  if (kepala == NULL) {
    cout << "Create the Linked List first!" << endl;
  } else {
        ekor->namaFilm = data[0];
        ekor->durasi = stoi(data[1]);
        ekor->harga = stoi(data[2]);
  }
}

// change Middle
void changeMiddle(int posisi, string newData[3]){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        if(posisi == 1){
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        }else{
            // tranversing
            int nomor = 1;
            saatIni = kepala;
            while(nomor < posisi - 1){
                saatIni = saatIni->next;
                nomor++;
            }
            saatIni->next->namaFilm = newData[0];
            saatIni->next->durasi = stoi(newData[1]);
            saatIni->next->harga = stoi(newData[2]);
        }
    }
}

// remove First
void removeFirst(){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        hapus = kepala;
        kepala = kepala->next;
        ekor->next = kepala;
        delete hapus;
    }
}

// remove last
void removeLast(){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        hapus = ekor;
        saatIni = kepala;
        while(saatIni->next != ekor){
            saatIni = saatIni->next;
        }
        ekor = saatIni;
        ekor->next = kepala;
        delete hapus;
    }
}

// remove middle
void removeMiddle(int posisi){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        // tranversing
        int nomor = 1;
        saatIni = kepala;
        while(nomor < posisi - 1){
            saatIni = saatIni->next;
            nomor++;
        }
        hapus = saatIni->next;
        saatIni->next = hapus->next;
        delete hapus;
    }
}

void printCircular(){
    if(kepala == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        cout << "Data Film " << endl;
        cout << "_________________________________________________________________" << endl;
        cout << "| Nama Film\t\t\t| Durasi\t\t| Harga\t|" << endl;
        cout << "_________________________________________________________________" << endl;
        saatIni = kepala;
        do{
            // print
            cout << "| " << saatIni->namaFilm << "\t\t\t| " << saatIni->durasi << "\t\t\t| " << saatIni->harga << "|" << endl;
            saatIni = saatIni->next;
        } while(saatIni != kepala);
        cout << "_________________________________________________________________" << endl;
    }
}

int main(){
    string dataBaru[3] = {"Endgame", "181", "125000"};
    createCircularSingleLinkedList(dataBaru);

    printCircular();

    string data[3] = {"Spiderman", "148", "100000"};
    addFirst(data);

    printCircular();

    string data2[3] = {"Interstellar", "169", "175000"};
    addLast(data2);

    printCircular();

    string data3[3] = {"Inception", "148", "190000"};
    addMiddle(data3, 5);

    printCircular();

    string newData[3] = {"Batman", "150", "200000"};
    changeMiddle(5, newData);

    printCircular();

    string newData1[3] = {"Antman", "140", "200000"};
    changeFirst(newData1);

    printCircular();

    string newData2[3] = {"lavaman", "210", "100000"};
    changeLast(newData2);

    printCircular();

    removeMiddle(6);

    printCircular();

    removeFirst();

    printCircular();

    removeLast();
}