// Header
#include <iostream>
#include <conio.h>
using namespace std;

// Struct Roti
struct Roti{
    string nama;
    double harga;
    int stok;
};
// Prototipe Prosedur yang ada
void menu(); void menuSorting();void Insertionsort(), Shellsort();
void Quicksort(Roti dummyroti[], int low, int high);
void Binarysearch(Roti toko_roti[],int Jumlah_Roti);
void Interpolationsearch(Roti toko_roti[], int Jumlah_Roti);
void PilihanSearching();
// Set up Array
const int max_roti = 50;
int Jumlah_Roti = 0;
Roti toko_roti[max_roti];


// Prosedur Tambah roti
void tambahRoti(){
    system("cls");
    Roti r; string harga,stok,LotsofData; int isi;
    if (Jumlah_Roti == max_roti){ 
        cout<<"Kapasitas Roti sudah Penuh"<<endl;
        return;
    }
    try{
        try{
        cout<<"Masukkan Jumlah data yang Ingin Diinput>> ";getline(cin, LotsofData);
        isi = stoi(LotsofData);
        if(isi < 0){
            cout<<"Nilai tidak Valid"; getch(); cout<<endl;
            tambahRoti();}
        }catch(std::invalid_argument& e){
            cout<<"Inputan harus Integer";getch();cout<<endl;
            tambahRoti();}

        cout<<"\n====== Tambah Roti ======"<<endl;
        for (int i = 0; i < isi; i++){
        cout<<endl;
        cout<<"Masukkan Nama Roti>> ";getline(cin,r.nama);
        try{
        cout<<"Masukkan Harga Roti>> ";getline(cin,harga);
        r.harga = stoi(harga);
        if(r.harga<1){cout<<"Harga Tidak valid";getch();cout<<endl;tambahRoti();}
        }catch(std::invalid_argument& e){
            cout<<"Inputan harus Integer";getch();cout<<endl;
            tambahRoti();
        }
        try{
        cout<<"Masukkan Stok Roti>> ";getline(cin,stok);
        r.stok = stoi(stok);
        if(r.stok<1){cout<<"Stok Tidak valid";getch();cout<<endl;tambahRoti();}
        }catch(std::invalid_argument& e){
            cout<<"Inputan harus Integer";getch();cout<<endl;
            tambahRoti();
        }
        cout<<"=============================="<<endl;
        toko_roti[Jumlah_Roti] = r;
        Jumlah_Roti++;
        }
        cout<<"\n---Roti Berhasil Ditambahkan---"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    
    }catch(std::invalid_argument& e){
            cout<<"Inputan harus Integer";getch();cout<<endl;
            tambahRoti();
    }
}

// Prosedur Melihat list roti
void listRoti(){
    system("cls");
    if (Jumlah_Roti == 0){
        cout<<"Roti Kosong, Mohon mengisi persediaan Roti"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    }
    cout << "------------------------------------------------------" << endl;
    cout << "No.) | Nama Roti                       | Stok  | Harga" << endl; //mempercantik aja
    cout << "------------------------------------------------------" << endl;
    for(int i=0; i<Jumlah_Roti; i++){
        cout<<i+1<<"\t"<<toko_roti[i].nama<<"\t\t\t"<<toko_roti[i].stok<<"\tRp. " << toko_roti[i].harga<<endl;
    }
}

// Prosedur Mengubah roti
void ubahRoti(){
    system("cls");
    listRoti();
    if (Jumlah_Roti == 0){
        cout<<"Roti Kosong, Mohon mengisi persediaan Roti"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    }
    int no;
    string input,harga,stok;
    try{
    cout<<"\n============== Ubah Roti ==============="<<endl;
    cout<<"Masukkan No Roti yang ingin diubah>> ";getline(cin,input);
    no = stoi(input);
    if(no<1 || no>Jumlah_Roti){
        cout<<"No tidak ada, Ulangi !!";getch();cout<<endl;
        ubahRoti();}
    }catch(std::invalid_argument& e){
            cout<<"Inputan harus Integer";getch();cout<<endl;
            ubahRoti();}
    Roti r = toko_roti[no-1];
    cout<<"Masukkan Nama Roti yg Baru>> ";getline(cin,r.nama);
    try{
        cout<<"Masukkan Harga Roti yg baru>> ";getline(cin,harga);
        r.harga = stoi(harga);
        if(r.harga<1){cout<<"Harga Tidak valid";getch();cout<<endl;tambahRoti();}
    }catch(std::invalid_argument& e){
        cout<<"Inputan harus Integer";getch();cout<<endl;
        ubahRoti();}
    try{
        cout<<"Masukkan Stok Roti yang Baru>> ";getline(cin,stok);
        r.stok = stoi(stok);
        if(r.harga<1){cout<<"Harga Tidak valid";getch();cout<<endl;tambahRoti();}
    }catch(std::invalid_argument& e){
        cout<<"Inputan harus Integer";getch();cout<<endl;
        ubahRoti();}
    toko_roti[no-1] = r;
    cout<<"\nRoti Berhasil diubah"<<endl;
    cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
    menu();
}

// Prosedur Menghapus roti
void hapusRoti(){
    system("cls");
    int no; string input;
    listRoti();
    if (Jumlah_Roti == 0){
        cout<<"Roti Kosong, Mohon mengisi persediaan Roti"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    }
    try{
    cout<<"\n============== Hapus Roti ==============="<<endl;
    cout<<"Masukkan No Roti yang ingin dihapus>> ";getline(cin,input);
    no = stoi(input);
    if(no<1 || no>Jumlah_Roti){
        cout<<"No tidak ada, Ulangi !!";getch();cout<<endl;
        hapusRoti();}
    }catch(std::invalid_argument& e){
        cout<<"Inputan harus Integer";getch();cout<<endl;
        hapusRoti();
    }
    for(int i = no-1; i<Jumlah_Roti; i++){ 
        toko_roti[i] = toko_roti[i+1];
    }
    Jumlah_Roti--;
    cout<<"\nRoti Berhasil Dihapus"<<endl;
    cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
    menu();
}

// Prosedur Melihat Alamat roti
void Pnt(){
    system("cls");
    int no; string input; Roti *r; r = &toko_roti[max_roti];
    listRoti();
    if (Jumlah_Roti == 0){
        cout<<"Alamat Array Kosong !, Mohon mengisi persediaan Roti"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    }
    try{
        cout<<"\n=================== Lokasi Memori ===================="<<endl;
        cout<<"Masukkan No untuk mengetahui letak Memori Array>> ";getline(cin,input);
        no = stoi(input);
        if(no<1 || no>Jumlah_Roti){cout<<"No tidak ada, Ulangi !!";getch();cout<<endl;Pnt();}
        for(int i = no-1; i<Jumlah_Roti; i++){
            r = &toko_roti[i]; 
            cout<<"\nAlamat dari Roti No "<<i+1<<" adalah> "<<r<<endl;
            cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
            menu();}
    }catch(std::invalid_argument& e){
        cout<<"Inputan harus Integer";getch();cout<<endl;
        Pnt();}
}

// Prosedur Untuk pilihan jenis sorting roti
void sortingData(){
    if (Jumlah_Roti == 0){
        cout<<"Roti Kosong !, Mohon mengisi persediaan Roti"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    }
    string input; int pilih;
    menuSorting();
    try{
    cout<<"Pilih Metode Sorting>> ";getline(cin, input);
    pilih = stoi(input);
    if(pilih < 1){cout<<"Inputan Tidak Valid!";getch();cout<<endl; sortingData();}
    pilih = stoi(input);
    }catch(std::invalid_argument& e){
        cout<<"Inputan harus Integer";getch();cout<<endl;
        sortingData();
    }
    switch(pilih){
        case 1:
        Insertionsort();
            cout<<"Data Telah Disortir"<<endl;
            listRoti();
            cout<<"\n------Tekan Enter untuk Ke Menu-------";getch();cout<<endl;
            menu();
            break;
        case 2:
            Quicksort(toko_roti,0,Jumlah_Roti-1);
            cout << "Data Telah Disortir" << endl;
            listRoti();
            cout<<"\n------Tekan Enter untuk Ke Menu-------";getch();cout<<endl;
            menu();
        case 3:
        Shellsort();
            break;
        default:
            cout<<"Pilihan tidak ada !";getch();cout<<endl;
            sortingData();
    }

}

// Insertion Sort (nama)
void Insertionsort(){
    Roti dummyroti;
    for (int i = 1; i< Jumlah_Roti; i++){
        dummyroti = toko_roti[i];
        int j = i-1;

        while (j>=0 && toko_roti[j].nama > dummyroti.nama){
            toko_roti[j+1] = toko_roti[j];
            j -= 1;
        }
        toko_roti[j+1] = dummyroti;
    }
}

// fungsi Pivot dari Quick Sort
int partitionQS(Roti toko_roti[], int low,int high){
    int pivot = toko_roti[high].harga;
    int i = low-1;
    for (int j = low; j<= high-1; j++){
        if(toko_roti[j].harga < pivot){
            i++;
            swap(toko_roti[i],toko_roti[j]);
        }
    }
    swap(toko_roti[i+1], toko_roti[high]);
    return (i+1);
}

void Quicksort(Roti toko_roti[], int low, int high){
    if(low<high){
        int pi = partitionQS(toko_roti, low, high);
        Quicksort(toko_roti, low, pi-1);
        Quicksort(toko_roti, pi+1, high);
    }
}

// Shell Sort (Stok)
void Shellsort(){
    Roti dummyroti;
    for (int gap = Jumlah_Roti/2; gap > 0; gap /= 2){
        for (int i = gap; i < Jumlah_Roti; i++){
            dummyroti = toko_roti[i];
            int j;
            for (j =i; j >= gap && toko_roti[j-gap].stok > dummyroti.stok; j-= gap){ //  Descending itu ubah di toko_roti[j-gap] < temp;
                toko_roti[j] = toko_roti[j-gap];
            }
            toko_roti[j] = dummyroti;
        }
    }
    cout<<"Data Telah Disortir"<<endl;
    listRoti();
    cout<<"\n------Tekan Enter untuk Ke Menu-------";getch();cout<<endl;
    menu();
}

void Binarysearch(Roti toko_roti[],int Jumlah_Roti) {
    system("cls");
    if (Jumlah_Roti == 0){
        cout<<"Roti Kosong !, Mohon mengisi persediaan Roti"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    }
    string input;
    bool found = false;
    cout << "------Binary Search-----------------------------" << endl;
    cout << "Cari Roti (Nama/Harga) >> "; getline(cin, input);

    // Jika input berupa harga roti
    if (isdigit(input[0])) {
        double harga_roti = stod(input);
        Quicksort(toko_roti,0,Jumlah_Roti-1);
        int low = 0;
        int high = Jumlah_Roti;
        // Melakukan binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            if (toko_roti[mid].harga == harga_roti) {
                // Menampilkan data roti yang ditemukan
                cout << "------------------------------------------------------" << endl;
                cout << "No.  | Nama Roti                       | Stok  | Harga" << endl;
                cout << "------------------------------------------------------" << endl;
                for(int i = 0; i < Jumlah_Roti; i++) {
                    if(toko_roti[mid].harga == toko_roti[i].harga) {
                        cout << i + 1 << "\t" << toko_roti[i].nama << "\t\t\t" << toko_roti[i].stok << "\t" << toko_roti[i].harga << endl;
                    }
                }
                found = true;
                break;
            }
            else
            {
                if (harga_roti > toko_roti[mid].harga){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        if (found == false){
            cout << "Roti Tidak Tersedia"; getch(); menu();
        }
    }
    // Jika input berupa nama roti
    else if (isalpha(input[0])){
        string nama_roti = input;
        Insertionsort();
        int low = 0;
        int high = Jumlah_Roti;
        // Melakukan binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            if (toko_roti[mid].nama == nama_roti) {
                // Menampilkan data roti yang ditemukan
                cout << "------------------------------------------------------" << endl;
                cout << "No.  | Nama Roti                       | Stok  | Harga" << endl;
                cout << "------------------------------------------------------" << endl;
                for(int i = 0; i < Jumlah_Roti; i++) {
                    if(toko_roti[mid].nama == toko_roti[i].nama) {
                        cout << i + 1 << "\t" << toko_roti[i].nama << "\t\t\t" << toko_roti[i].stok << "\t" << toko_roti[i].harga << endl;
                    }
                }
                found = true;
                break;
            }
            else
            {
                if (nama_roti > toko_roti[mid].nama){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        if (found == false){
            cout << "Roti Tidak Tersedia"; getch(); menu();
        }
    }
    else {
        cout << "Inputan tidak benar";
    }
}


void Interpolationsearch(Roti toko_roti[], int Jumlah_Roti) {
    system("cls");
    if (Jumlah_Roti == 0){
        cout<<"Roti Kosong !, Mohon mengisi persediaan Roti"<<endl;
        cout<<"---Tekan Enter untuk kembali---";getch();cout<<endl;
        menu();
    }
    string input;
    bool found = false;
    cout << "------Interpolation Search----------------------" << endl;
    cout << "Cari Roti (Nama/Harga) >> "; getline(cin, input); fflush(stdin);

    // Jika input berupa harga roti
    if (isdigit(input[0])) {
        Quicksort(toko_roti, 0, Jumlah_Roti - 1);
        double harga_roti = stod(input);
        int low = 0;
        int high = Jumlah_Roti - 1;
        // Melakukan interpolation search
        while (low <= high) {
            int pos = low + ((high - low) * (harga_roti - toko_roti[low].harga) / (toko_roti[high].harga - toko_roti[low].harga));
            if (pos < 0 || pos >= Jumlah_Roti) {
                break;
            }
            if (harga_roti == toko_roti[pos].harga) {
                // Menampilkan data roti yang ditemukan
                cout << "------------------------------------------------------" << endl;
                cout << "No.  | Nama Roti                       | Stok  | Harga" << endl;
                cout << "------------------------------------------------------" << endl;
                for(int i = low; i <= high; i++) {
                    if(toko_roti[pos].harga == toko_roti[i].harga) {
                        cout << i + 1 << "\t" << toko_roti[i].nama << "\t\t" << toko_roti[i].stok << "\t" << toko_roti[i].harga << endl;
                    }
                }
                found = true;
                break;
            }
            else if (harga_roti > toko_roti[pos].harga && toko_roti[pos].harga >= toko_roti[pos].harga) {
                low = pos + 1;
            }
            else {
                high = pos - 1;
            }
        }
        if (found == false) {
            cout << "Roti Tidak Tersedia"; getch(); menu();
        }
    }
    else if (isalpha(input[0])){
        Insertionsort();
        string nama_roti = input;
        int low = 0;
        int high = Jumlah_Roti;
        // Melakukan interpolation search
        while (low <= high) {
            int pos = low + ((high - low) * (nama_roti[0] - toko_roti[low].nama[0]) / (toko_roti[high].nama[0] - toko_roti[low].nama[0]));
            if (toko_roti[pos].nama == nama_roti) {
                // Menampilkan data roti yang ditemukan
                cout << "------------------------------------------------------" << endl;
                cout << "No.  | Nama Roti                       | Stok  | Harga" << endl;
                cout << "------------------------------------------------------" << endl;
                for (int i = 0; i < Jumlah_Roti; i++) {
                    if (toko_roti[pos].nama == toko_roti[i].nama) {
                        cout << i + 1 << "\t" << toko_roti[i].nama << "\t\t" << toko_roti[i].stok << "\t" << toko_roti[i].harga << endl;
                    }
                }
                found = true;
                break;
            }
            else if (nama_roti > toko_roti[pos].nama ) {
                low = pos + 1;
            }
            else {
                high = pos - 1;
            }
        }
        if (found == false) {
            cout << "Roti Tidak Tersedia"; getch(); menu();
        }
    }
    else {
        cout << "Inputan tidak benar";
    }
}

void PilihanSearching()
{
    system("cls");
    int pilihan; string input;
    cout<<"===================================="<<endl
        <<"           Metode Searching         "<<endl
        <<"===================================="<<endl
        <<" [1] Binary Search                  "<<endl
        <<" [2] Interpolation Search           "<<endl
        <<"===================================="<<endl;
    try{
        cout<<"\nPilih Metode>> ";getline(cin, input);
        pilihan = stoi(input);
        switch(pilihan){
            case 1:
                Binarysearch(toko_roti,Jumlah_Roti);
                cout<<"\nTekan Enter untuk kembali ke menu";getch();cout<<endl;
                menu();
                break;
            case 2:
                Interpolationsearch(toko_roti,Jumlah_Roti);
                cout<<"\nTekan Enter untuk kembali ke menu";getch();cout<<endl;
                menu();
                break;
            default:
                cout<<"\nMenu tidak ada, Enter untuk kembali";getch();cout<<endl;
                PilihanSearching();
        }
    }
    catch(invalid_argument expression){
        cout<<"Inputan harus Integer";getch();cout<<endl;
        PilihanSearching();
    }
}

// Prosedur Menu Utama
void menu(){
    system("cls");
    int pilihan; string input;
    cout<<"===================================="<<endl
        <<"            Toko Rotiku             "<<endl
        <<"===================================="<<endl
        <<" [1] Tambah Roti                    "<<endl
        <<" [2] List Roti                      "<<endl
        <<" [3] Ubah Roti                      "<<endl
        <<" [4] Hapus Roti                     "<<endl
        <<" [5] Alamat Array                   "<<endl
        <<" [6] Sorting Data                   "<<endl
        <<" [7] Searching Roti                 "<<endl
        <<" [0] Keluaran                       "<<endl
        <<"===================================="<<endl;
    try{
        cout<<"\nMasukkan Pilihan roti>> ";getline(cin, input);
        pilihan = stoi(input);
        switch(pilihan){
            case 1:
                tambahRoti();
                break;
            case 2:
                listRoti();
                cout<<"\nTekan Enter untuk kembali ke menu";getch();cout<<endl;
                menu();
                break;
            case 3:
                ubahRoti();
                break;
            case 4:
                hapusRoti();
                break;
            case 5:
                Pnt();
                break;
            case 6:
                sortingData();
                break;
            case 7:
                PilihanSearching();
                break;
            case 0:
                cout<<"\nSampai Jumpa Kembali"<<endl;
                exit(0);
            default:
                cout<<"\nMenu tidak ada, Enter untuk kembali";getch();cout<<endl;
                menu();
        }
    }catch(std::invalid_argument& e){
        cout<<"Inputan harus Integer";getch();cout<<endl;
        menu();
    }
}

// Prosedur tampilan menu sorting
void menuSorting(){
    system("cls");
    cout<<"==================================================="<<endl
        <<"--------------------Sorting Data-------------------"<<endl
        <<"==================================================="<<endl
        <<" [1] Insertion Sort  (Nama)                        "<<endl
        <<" [2] Quick Sort      (Harga)                       "<<endl
        <<" [3] Shell Sort      (Stok)                        "<<endl
        <<"==================================================="<<endl;
}

// fungsi Utama
int main(){
    system("cls");
    string username, password;
    int attempt = 3;
    while (attempt > 0) {
        system("cls");
        cout<<"======================================"<<endl
            <<"                 Login                "<<endl
            <<"======================================"<<endl;
        cout << "Username>> "; getline(cin, username);
        cout << "Password>> "; getline(cin, password);
        if (username == "Maulana Agus Setiawan" && password == "2209106024") {
            cout << "\nLogin Berhasil!";getch();cout<<endl; 
            menu();                                       
        } else {
            cout << "Username/Password Salah. " << --attempt << " Kesempatan tersisa.";
            getch();
        }
    }
    if (attempt == 0) {
        cout << "\nKesempatanmu habis!, Coba lagi lain kali!" << endl;
    }
    return 0;
}
