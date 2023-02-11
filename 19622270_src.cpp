#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <vector>
#include <cctype>
#include <string.h>

using namespace std;
// struct dibawah akan digunakan untuk menyimpan riwayat order
struct Order
{
    string nama;
    vector<string> namaMenu;
    vector<int> kuantitas;
    int total;
};
const int jumlahMenu = 10;
string menu[jumlahMenu] = {
    "Nasi Goreng", "Nasi Bakar", "Nasi Rebus", "Nasi Kuning", "Nasi Uduk", "Nasi Kucing", "Nasi Hainan", "Nasi Tim", "Nasi Kecap", "Nasi Telor"};
string kategori[jumlahMenu] = {"Makanan", "Makanan", "Makanan", "Makanan", "Makanan", "Makanan", "Makanan", "Makanan", "Makanan", "Makanan"};
int hargaMenu[jumlahMenu] = {
    10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000};
char pilihan;
string nama_pelanggan;
int angka;
//vector daftar digunakan untuk menyimpan riwayat order dalam list
vector<Order> daftar;
int main()
{
    while (true)
    {
        system("cls");
        cout << "Apakah anda ingin tutup? (y/n)" << endl;
        cin >> pilihan;
        if (((char)toupper(pilihan)) == 'Y')
        {
            system("cls");
            if (daftar.size() == 0)
            {
                cout << "--Tidak ada penjualan--" << endl;
            }
            else
            {
                cout << "~~RIWAYAT PENJUALAN~~" << endl;
                for (int i = 0; i < daftar.size(); i++)
                {
                    cout << i + 1 << ". " << daftar[i].nama << endl;
                    for (int j = 0; j < daftar.at(i).namaMenu.size(); j++)
                    {
                        cout << "- " << daftar.at(i).namaMenu.at(j) << " (" << daftar.at(i).kuantitas.at(j) << ")" << endl;
                    }
                    cout << "Total : " << daftar.at(i).total << endl;
                    cout << endl;
                }
            }
            system("pause");
            cout << "Terima kasih!" << endl;
            exit(0);
        }
        else if (((char)toupper(pilihan)) == 'N')
        {
            system("cls");
            Order pesanan;
            cout << "Masukkan nama anda yoyoyo!" << endl;
            cin.ignore();
            getline(cin, nama_pelanggan);
            pesanan.nama = nama_pelanggan;
            system("cls");
            while (true)
            {
                system("cls");
                cout << "1. Lihat menu yo!" << endl;
                cout << "2. Mau pesan yo!" << endl;
                cout << "3. Mau cabut yo!" << endl;
                cin >> angka;
                int banyak, nomor;
                int total = 0;
                bool done;
                switch (angka)
                {
                case 1:
                    done = false;
                    system("cls");
                    for (int i = 0; i < jumlahMenu; i++)
                    {
                        cout << i + 1 << ". " << menu[i] << " (" << kategori[i] << ") - " << hargaMenu[i] << endl;
                    };
                    system("pause");
                    break;
                case 2:
                    done = false;
                    while (true)
                    {
                        int counter = 0;
                        cout << "Menu nomor berapa yang mau anda pesan yo? (Masukkan 0 untuk menyelesaikan pesanan)" << endl;
                        cin >> nomor;
                        if (nomor == 0)
                        {
                            break;
                        }
                        cout << "Menu: " << menu[nomor - 1] << endl;
                        cout << "Kuantitas: ";
                        cin >> banyak;
                        total = total + (hargaMenu[nomor - 1] * banyak);
                        pesanan.namaMenu.push_back(menu[nomor - 1]);
                        pesanan.kuantitas.push_back(banyak);
                        counter++;
                        pesanan.total = total;
                    };
                    daftar.push_back(pesanan);
                    break;
                case 3:
                    done = true;
                    break;
                default:
                    cout << "Masukkan nomor 1/2/3 !" << endl;
                    system("pause");
                    break;
                }
                if (done == true)
                {
                    break;
                }
            }
        }
        else
        {
            cout << "Masukkan y/n!";
        }
    }

    return 0;
}
