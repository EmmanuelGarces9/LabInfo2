#include "../../../hdr/prereglas/funcionesparametodos.h"

bool* pre_reglas(const char* file_name, unsigned long long& tam) {
	bool* text_bits = nullptr;
	char* text = nullptr;
	try {
		text = leer_archivo(file_name, tam);
		if(text != nullptr) {
			text_bits = archivo_a_binario(text, tam);
			delete[] text;
			text = nullptr;
			tam *= 8;
			return text_bits;
		}
		throw runtime_error("Error al leer el archivo.");
	}
	catch(const exception& e) {
		if(text != nullptr) {
			delete[] text;
		}
		if(text_bits != nullptr) {
			delete[] text_bits;
		}
		cerr << "Error: " << e.what() << endl;
	}
	return nullptr;
}

char* leer_archivo(const char* file_name, unsigned long long& tamal) {
	fstream file;
	char* text;

	file.open(file_name, ios_base::in | ios_base::ate);
	if(!file.is_open()) {
		return nullptr;
	}
	tamal = file.tellg();
	text = new char[tamal + 1];
	file.seekg(0);
	file.read(text, tamal);
	file.close();
	text[tamal] = '\0';
	return text;
}

bool* archivo_a_binario(const char* text, const unsigned long long& tam) {
	const int BITS_PER_BYTE = 8;
	bool* booleans = new bool[tam * BITS_PER_BYTE];
	unsigned long long index = 0;
	for(const char* ptr = text; *ptr != '\0'; ++ptr) {
		char letter = *ptr;
		for(int j = BITS_PER_BYTE - 1; j >= 0; --j, ++index) {
			booleans[index] = (letter >> j) & 1;
		}
	}
	return booleans;
}
