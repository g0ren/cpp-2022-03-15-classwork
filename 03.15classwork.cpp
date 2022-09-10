#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void fioWrite(char *path) {

	FILE *f;
	f = fopen(path, "w+");
	if (!f) {
		cout << "Couldn't create file!" << endl;
		return;
	}
	fputs("Lunkovsky\n", f);
	fputs("Mikhail\n", f);
	fputs("Nikolayevich\n", f);
	fclose(f);
}

void fioPrint(char *path) {
	char *str = new char[256];
	FILE *f;
	f = fopen(path, "r");
	if (!f) {
		cout << "Couldn't open file!" << endl;
		return;
	}
	while (!feof(f)) {
		char *fg;
		fg = fgets(str, 255, f);
		if (strlen(fg)) {
			if (str[strlen(str) - 1] == '\n')
				str[strlen(str) - 1] = '\0';
			cout << str << endl;
		}
	}
	fclose(f);
}

void timeWrite(char *path) {
	FILE *b;
	b = fopen(path, "wb");
	if (!b) {
		cout << "The file " << path << " cannot be opened\n";
	} else {
		int mtime[3] { 21, 31, 55 };
		for (int i = 0; i < 3; i++) {
			fwrite(mtime, sizeof(int), sizeof(mtime), b);
		}
	}
	fclose(b);
}

void timePrint(char *path) {
	int mtime[3] { };
	FILE *b;
	b = fopen(path, "rb");
	if (!b) {
		cout << "The file cannot be opened for " << path << "\n";
	} else {
		fread(mtime, sizeof(int), 3, b);
	}
	for (int i = 0; i < 3; i++)
		cout << mtime[i] << " ";
	cout << endl;
	fclose(b);
}

int main() {
	char *path { "fio.txt" };
	char *bpath { "b_data.txt" };

	/*fioWrite(path);
	fioPrint(path);
	cout << endl;*/

	timeWrite(bpath);
	timePrint(bpath);

	return 0;
}
