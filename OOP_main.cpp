#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "OOP_mahasiswa.cpp"

using namespace std;

// Macro
#define MxN 255
#define symbl cout<<"--> ";

// Prototype Function
void clear_buff();
void cobaOopMahasiswa();

// Function Main
int main() {
	while (true) { cobaOopMahasiswa(); }
	return 0;
}

// Function
void clear_buff() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
  };
}

void cobaOopMahasiswa() {
	system("cls");
	string nama, NIM, jurusan;
	string ubahNama, ubahNIM, ubahJurusan;

	cout << "Nama\t: "; cin >> nama; clear_buff();
	cout << "NIM\t: "; cin >> NIM; clear_buff();
	cout << "Jurusan\t: "; cin >> jurusan; clear_buff();

	Mahasiswa mahasiswa = Mahasiswa(nama,NIM,jurusan);

	cout << endl << "Data berhasil ditambahkan!" << endl;
	cout << "Tekan enter untuk melanjutkan..."; getch();

	system("cls");
	cout << "Data Mahasiswa" << endl;
	mahasiswa.displayMahasiswa();
	cout << "Tekan enter untuk melanjutkan..."; getch();

	system("cls");
	cout << "Ubah nama\t: "; cin >> ubahNama; clear_buff();
	cout << "Ubah jurusan\t: "; cin >> ubahJurusan; clear_buff();
	mahasiswa.ubahNama(ubahNama);
	mahasiswa.ubahJurusan(ubahJurusan);
	cout << endl << endl << "Data sekarang" << endl;
	mahasiswa.displayMahasiswa();
	cout << "Tekan enter untuk melanjutkan..."; getch();

	system("cls");
	DataBase database = DataBase("data.txt");
	database.save(mahasiswa);
	cout << "Data " << mahasiswa.nama << " berhasil disimpan" << endl;
	cout << "Tekan enter untuk melanjutkan..."; getch();

	system("cls");
	database.printAllData();
	cout << "Tekan enter untuk melanjutkan..."; getch();
}