#include <iostream>
#include <conio.h>
using namespace std;
void menu(); void close_app();


class Konversi{
private:
    double suhu;
public:
    void set_suhu(double besaran)
    {suhu = besaran;}
    auto Csuhu(){
        struct rumusKonversiCelcius{
            double reamur;
            double fahrenheit;
            double kelvin;
        };
        return rumusKonversiCelcius{(suhu*4)/5,((9*suhu)/5)+32, suhu+273.15};
    }
    auto Fsuhu(){
        struct rumusKonversiFahrenheit{
            double celcius;
            double reamur;
            double kelvin;
        };
    return rumusKonversiFahrenheit{((suhu-32)*5)/9, ((suhu-32)*4)/9, (((suhu+459.67)*5)/9)};
    }
    auto Rsuhu(){
        struct rumusKonversirReamur{
            double celcius;
            double fahrenheit;
            double kelvin;
        };
        return rumusKonversirReamur{(suhu/0.8),(suhu*2.25)+32,(suhu/0.8)+273.15};
    }
    auto Ksuhu(){
        struct rumusKonversiKelvin{
            double celcius;
            double fahrenheit;
            double reamur;
        };
        return rumusKonversiKelvin{(suhu-273.15), ((suhu*9)/5)-459.67, ((suhu-273.15)*4)/5};
    }
};

int main() {
    system("cls");
    string username, password;
    int attempt = 3;
    while (attempt > 0) {
        cout << "Username>> "; getline(cin, username);
        cout << "Password>> "; getline(cin, password);
        if (username == "Maulana Agus Setiawan" && password == "2209106024") {
            cout << "Login Berhasil!";getch();cout<<endl;
            menu();
        } else {
            cout << "Username/Password Salah. " << --attempt << " Kesempatan tersisa." << endl;
        }
    }
    if (attempt == 0) {
        cout << "Kesempatanmu habis!, Coba lagi lain kali!" << endl;
    }
    return 0;
}

void menu(){
    system("cls");
    int pilihan; double suhu; string input;
    cout<<"|===================|"<<"\n";
    cout<<"|----- Welcome -----|"<<"\n";
    cout<<"|===================|"<<"\n";
    cout<<"| [1] Celcius       |"<<"\n";
    cout<<"| [2] Fahrenheit    |"<<"\n";
    cout<<"| [3] Reamur        |"<<"\n";
    cout<<"| [4] Kelvin        |"<<"\n";
    cout<<"| [0] Exit          |"<<"\n";
    cout<<"|===================|"<<"\n";
    cout<<""<<endl;
    try{
    cout<<"Masukkan Pilihan>> ";getline(cin, input);
    pilihan = stoi(input);
    switch (pilihan){
    case 1:
        system("cls");
        try{
        cout<<"Masukkan Suhu Celsius> ";getline(cin,input);
        suhu = stod(input);
        Konversi setCelcius;
        setCelcius.set_suhu(suhu);
        cout<<"======================================="<<endl;
        cout<<suhu<<" Celcius ke Fahrenheit > "<< setCelcius.Csuhu().fahrenheit<<""<<endl;
        cout<<suhu<<" Celcius ke Reamur     > "<< setCelcius.Csuhu().reamur<<""<<endl;
        cout<<suhu<<" Celcius ke Kelvin     > "<< setCelcius.Csuhu().kelvin<<""<<endl;
        cout<<"======================================="<<endl;
        cout<<"Tekan Enter Untuk kembali ke menu..";getch();cout<<endl;
        menu();
        }
        catch(const std::invalid_argument& e){
        cout << "Inputan salah! , Inputan harus bertipe Double";getch();cout<<endl;
        menu();
    }
    case 2:
        system("cls");
        try{
        cout<<"Masukkan Suhu Fahrenheit> ";getline(cin,input);
        suhu = stod(input);
        Konversi setFahrenheit;
        setFahrenheit.set_suhu(suhu);
        cout<<"======================================="<<endl;
        cout<<suhu<<" Fahrenheit ke Celcius   > "<< setFahrenheit.Fsuhu().celcius<<""<<endl;
        cout<<suhu<<" Fahrenheit ke Reamur    > "<< setFahrenheit.Fsuhu().reamur<<""<<endl;
        cout<<suhu<<" Fahrenheit ke Kelvin    > "<< setFahrenheit.Fsuhu().kelvin<<""<<endl;
        cout<<"======================================="<<endl;
        cout<<"Tekan Enter Untuk kembali ke menu..";getch();cout<<endl;
        menu();
        }
        catch(const std::invalid_argument& e){
        cout << "Inputan salah! , Inputan harus bertipe Double";getch();cout<<endl;
        menu();
    }
    case 3:
        system("cls");
        try{
        cout<<"Masukkan Suhu Reamur> ";getline(cin,input);
        suhu = stod(input);
        Konversi setReamur;
        setReamur.set_suhu(suhu);
        cout<<"======================================="<<endl;
        cout<<suhu<<" Reamur ke Celcius   > "<< setReamur.Rsuhu().celcius<<""<<endl;
        cout<<suhu<<" Reamur ke Fahrenheit> "<< setReamur.Rsuhu().fahrenheit<<""<<endl;
        cout<<suhu<<" Reamur ke Kelvin    > "<< setReamur.Rsuhu().kelvin<<""<<endl;
        cout<<"======================================="<<endl;
        cout<<"Tekan Enter Untuk kembali ke menu..";getch();cout<<endl;
        menu();
        }
        catch(const std::invalid_argument& e){
        cout << "Inputan salah! , Inputan harus bertipe Double";getch();cout<<endl;
        menu();
    }
    case 4:
        system("cls");
        try{
        cout<<"Masukkan Suhu Kelvin> ";getline(cin,input);
        suhu = stod(input);
        Konversi setKelvin;
        setKelvin.set_suhu(suhu);
        cout<<"======================================="<<endl;
        cout<<suhu<<" Kelvin ke Celcius   > "<< setKelvin.Ksuhu().celcius<<""<<endl;
        cout<<suhu<<" Kelvin ke Fahrenheit> "<< setKelvin.Ksuhu().fahrenheit<<""<<endl;
        cout<<suhu<<" Kelvin ke Reamur    > "<< setKelvin.Ksuhu().reamur<<""<<endl;
        cout<<"======================================="<<endl;
        cout<<"Tekan Enter Untuk kembali ke menu..";getch();cout<<endl;
        menu();
        }
        catch(const std::invalid_argument& e){
        cout << "Inputan salah! , Inputan harus bertipe Double";getch();cout<<endl;
        menu();
    }
    case 0:
        close_app();
        break;
    default:
        cout<<"|============================|"<<endl;
        cout<<"| Pilihan tidak ada, Ulangi! |"<<endl;
        cout<<"|============================|"<<endl;
        cout<<"Tekan Enter untuk kembali";getch();cout<<endl;
        menu();
        }
    }
    catch(const std::invalid_argument& e){
        cout << "Inputan salah! , Inputan harus bertipe Double";getch();cout<<endl;
        menu();
    }
}

void close_app(){
    cout<<"==================="<<endl;
    cout<<" Sampai Jumpa lagi"<<endl;
    cout<<"==================="<<endl;
    exit(0);
}
