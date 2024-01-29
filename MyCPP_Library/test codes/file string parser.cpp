#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	// file names variables
	string out_name = "";
	string file_name = "";

	// string var
	string to_change = "";
	string to_find = "";
	
	string buffer;

	// file stream object
	ifstream fin;
	ofstream fout;

	// create file foundation
	try {
		cout << "파일명 입력 : ";
		getline(cin, file_name);

		fin.open(file_name);
		out_name = file_name.substr(0, file_name.find("."));
		out_name += "_refactored." + file_name.substr(file_name.find(".") + 1, file_name.length());
		
		fout.open(out_name);
	}
	catch(exception e) {
		cout << "ERROR! : " << e.what() << endl;
		cout << "프로그램 종료." << endl;
		fin.close();
		fout.close();
		return 0;
	}
	
	// to change string
	cout << "바꾸고 싶은 문자열 입력 : ";
	cin >> to_find;
	cout << "대체할 문자열 입력 : ";
	cin >> to_change;
	cout << " -> 입력 완료." << endl;

	// operate
	try {
		while (1)
		{
			fin >> buffer;
			if (fin.eof())
				break;
			const char* tmp_ptr = buffer.c_str();

			while (*tmp_ptr++ != '\n') {
				if (buffer.find(to_find) == string::npos)
					break;
				buffer.replace(buffer.find(to_find), to_find.length(), to_change);
			}

			fout << buffer << '\n';
		}
	}
	catch (exception e) {
		cout << "ERROR!" << e.what() << endl;
		fin.close();
		fout.close();
		return 0;
	}

	fin.close();
	fout.close();

	return 0;
}