#ifndef MAHASISWA_INCLUDE
#define MAHASISWA_INCLUDE

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mahasiswa {
	public:
		string nama;
		string NIM;
		string jurusan;

	// Constructor
	Mahasiswa(
		string inputNama, 
		string inputNIM, 
		string inputJurusan
	) {
		Mahasiswa::nama = inputNama;
		Mahasiswa::NIM = inputNIM;
		Mahasiswa::jurusan = inputJurusan;
	}

	// Methods
	void displayMahasiswa() {
		cout << "Nama\t\t: " << Mahasiswa::nama << endl;
		cout << "NIM\t\t: " << Mahasiswa::NIM << endl;
		cout << "Jurusan\t\t: " << Mahasiswa::jurusan << endl << endl;
	}

	void ubahNama(string nama) { Mahasiswa::nama = nama; }
	void ubahNIM(string NIM) { Mahasiswa::NIM = NIM; }
	void ubahJurusan(string jurusan) { Mahasiswa::jurusan = jurusan; }

	string getAllData() {
		return nama + '#' + NIM + '#' + jurusan + '\n';
	}
};

class DataBase {
	public:
		ifstream in;
		ofstream out;
		string fileName;

		DataBase(string fileName) {
			DataBase::fileName = fileName;
		}

		void save(Mahasiswa data) {
			DataBase::out.open(DataBase::fileName,ios::app);
			DataBase::out << data.getAllData();
		}
};

#endif