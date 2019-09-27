//Cuba Lajo Ruben Adrian
//Flores Pari Fabrizio Rodrigo

#include <iostream>
#include <vector>

using namespace std;

//AL Begin

void strCopy(char *a_out, char *a_in, int n) {
	for (int i = 0; i < n; i++) {
		a_out[i] = a_in[i];
	}
	a_out[n] = '\0';
}

struct Token {
	char *palabra; //almacena una copia de la palabra
	int indice;
	char tipo; //E(entero), V(variable), O(operador), I(igual),
	//L(parentesis_izquierdo, R(parentesis_derecho)
};

Token reconoceNumero(char **ptr) {
	Token token;
	bool revisar = true;
	int i = 0;
	int letras = 0;
	while ((revisar == true) && (*(*ptr + i) != '\0')) {
		if ((*(*ptr + i) == '0') || (*(*ptr + i) == '1') || (*(*ptr + i) == '2') ||
			(*(*ptr + i) == '3') || (*(*ptr + i) == '4') || (*(*ptr + i) == '5') ||
			(*(*ptr + i) == '6') || (*(*ptr + i) == '7') || (*(*ptr + i) == '8') ||
			(*(*ptr + i) == '9')) {
			letras++;
		}
		else {
			revisar = false;
		}
		i++;
	}
	char* palabra = new char[letras + 1];
	strCopy(palabra, *ptr, letras);
	token.palabra = palabra;
	token.indice = letras;
	token.tipo = 'E';
	return token;
}

Token reconoceVariable(char **ptr) {
	Token token;
	bool revisar = true;
	int i = 0;
	int letras = 0;
	while ((revisar == true) && (*(*ptr + i) != '\0')) {
		if ((*(*ptr + i) == '0') || (*(*ptr + i) == '1') || (*(*ptr + i) == '2') ||
			(*(*ptr + i) == '3') || (*(*ptr + i) == '4') || (*(*ptr + i) == '5') ||
			(*(*ptr + i) == '6') || (*(*ptr + i) == '7') || (*(*ptr + i) == '8') ||
			(*(*ptr + i) == '9') ||
			(*(*ptr + i) == 'a') || (*(*ptr + i) == 'b') || (*(*ptr + i) == 'c') ||
			(*(*ptr + i) == 'd') || (*(*ptr + i) == 'e') || (*(*ptr + i) == 'f') ||
			(*(*ptr + i) == 'g') || (*(*ptr + i) == 'h') || (*(*ptr + i) == 'i') ||
			(*(*ptr + i) == 'j') || (*(*ptr + i) == 'k') || (*(*ptr + i) == 'l') ||
			(*(*ptr + i) == 'm') || (*(*ptr + i) == 'n') || (*(*ptr + i) == 'o') ||
			(*(*ptr + i) == 'p') || (*(*ptr + i) == 'q') || (*(*ptr + i) == 'r') ||
			(*(*ptr + i) == 's') || (*(*ptr + i) == 't') || (*(*ptr + i) == 'u') ||
			(*(*ptr + i) == 'v') || (*(*ptr + i) == 'w') || (*(*ptr + i) == 'x') ||
			(*(*ptr + i) == 'y') || (*(*ptr + i) == 'z') ||
			(*(*ptr + i) == 'A') || (*(*ptr + i) == 'B') || (*(*ptr + i) == 'C') ||
			(*(*ptr + i) == 'D') || (*(*ptr + i) == 'E') || (*(*ptr + i) == 'F') ||
			(*(*ptr + i) == 'G') || (*(*ptr + i) == 'H') || (*(*ptr + i) == 'I') ||
			(*(*ptr + i) == 'J') || (*(*ptr + i) == 'K') || (*(*ptr + i) == 'L') ||
			(*(*ptr + i) == 'M') || (*(*ptr + i) == 'N') || (*(*ptr + i) == 'O') ||
			(*(*ptr + i) == 'P') || (*(*ptr + i) == 'Q') || (*(*ptr + i) == 'R') ||
			(*(*ptr + i) == 'S') || (*(*ptr + i) == 'T') || (*(*ptr + i) == 'U') ||
			(*(*ptr + i) == 'V') || (*(*ptr + i) == 'W') || (*(*ptr + i) == 'X') ||
			(*(*ptr + i) == 'Y') || (*(*ptr + i) == 'Z')) {
			letras++;
		}
		else {
			revisar = false;
		}
		i++;
	}
	char* palabra = new char[letras + 1];
	strCopy(palabra, *ptr, letras);
	token.palabra = palabra;
	token.indice = letras;
	token.tipo = 'V';
	return token;
}

Token reconoceOperador(char** ptr) {
	Token token;
	char* palabra = new char[2];
	strCopy(palabra, *ptr, 1);
	token.palabra = palabra;
	token.indice = 1;
	token.tipo = 'O';
	return token;
}

Token reconoceIgual(char** ptr) {
	Token token;
	char* palabra = new char[2];
	strCopy(palabra, *ptr, 1);
	token.palabra = palabra;
	token.indice = 1;
	token.tipo = 'I';
	return token;
}

Token reconoceLParentesis(char** ptr) {
	Token token;
	char* palabra = new char[2];
	strCopy(palabra, *ptr, 1);
	token.palabra = palabra;
	token.indice = 1;
	token.tipo = 'L';
	return token;
}

Token reconoceRParentesis(char** ptr) {
	Token token;
	char* palabra = new char[2];
	strCopy(palabra, *ptr, 1);
	token.palabra = palabra;
	token.indice = 1;
	token.tipo = 'R';
	return token;
}

vector<Token> analizadorLexico(char* linea) {
	vector<Token> tokens;
	Token token;
	int pos = 0;
	int sz = 0;
	while (*linea != '\0') {
		switch (*linea) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			token = reconoceNumero(&linea);
			sz = token.indice;
			token.indice = pos;
			pos += sz;
			tokens.push_back(token);
			linea += sz;
			break;
		case 'a': case 'b': case 'c': case 'd': case 'e':
		case 'f': case 'g': case 'h': case 'i': case 'j':
		case 'k': case 'l': case 'm': case 'n': case 'o':
		case 'p': case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x': case 'y':
		case 'z':
		case 'A': case 'B': case 'C': case 'D': case 'E':
		case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O':
		case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y':
		case 'Z':
			token = reconoceVariable(&linea);
			sz = token.indice;
			token.indice = pos;
			pos += sz;
			tokens.push_back(token);
			linea += sz;
			break;
		case '+': case '-': case '*': case '/':
			token = reconoceOperador(&linea);
			sz = token.indice;
			token.indice = pos;
			pos += sz;
			tokens.push_back(token);
			linea += sz;
			break;
		case '=':
			token = reconoceIgual(&linea);
			sz = token.indice;
			token.indice = pos;
			pos += sz;
			tokens.push_back(token);
			linea += sz;
			break;
		case '(':
			token = reconoceLParentesis(&linea);
			sz = token.indice;
			token.indice = pos;
			pos += sz;
			tokens.push_back(token);
			linea += sz;
			break;
		case ')':
			token = reconoceRParentesis(&linea);
			sz = token.indice;
			token.indice = pos;
			pos += sz;
			tokens.push_back(token);
			linea += sz;
			break;
		default:
			pos++;
			linea++; //Significa que encontro un espacio en blanco
		}
	}
	return tokens;
}
//AL End

//AS Begin
typedef pair<int, int> Coord;

Coord getIgual(vector<Token> tokens, int inicio, int fin) {
	for (int i = inicio; i < fin; i++) {
		if (tokens[i].tipo == 'I') {
			cout << "Igual<" <<
				i << "," <<
				i << ">" << endl;
			return make_pair(i,i);
		}
	}

	return make_pair(-1, -1);
}

//Add Problema de Parentesis
Coord getOP(vector<Token> tokens, int inicio, int fin) {
	int cp = 0;
	for (int i = inicio; i < fin; i++) {
		if (tokens[i].tipo == 'L') {
			cp++;
		}
		if (tokens[i].tipo == 'R') {
			cp--;
		}
		if ((tokens[i].tipo == 'O') && (cp == 0)) {
			cout << "OP<" <<
				i << "," <<
				i << ">" << endl;
			return make_pair(i, i);
		}
	}

	return make_pair(-1, -1);
}

Coord getVAR(vector<Token> tokens, int inicio, int fin) {
	for (int i = inicio; i < fin; i++) {
		if (tokens[i].tipo == 'V') {
			cout << "VAR<" <<
				i << "," <<
				i << ">" << endl;
			return make_pair(i, i);
		}
	}

	return make_pair(-1, -1);
}

Coord getNUM(vector<Token> tokens, int inicio, int fin) {
	for (int i = inicio; i < fin; i++) {
		if (tokens[i].tipo == 'V') {
			cout << "NUM<" <<
				i << "," <<
				i << ">" << endl;
			return make_pair(i, i);
		}
	}

	return make_pair(-1, -1);
}

Coord getPL(vector<Token> tokens, int inicio, int fin) {
	for (int i = inicio; i < fin; i++) {
		if (tokens[i].tipo == 'L') {
			/*cout << "(<" <<
				i << "," <<
				i << ">" << endl;*/
			return make_pair(i, i);
		}
	}

	return make_pair(-1, -1);
}

Coord getPR(vector<Token> tokens, int inicio, int fin) {
	for (int i = inicio; i < fin; i++) {
		if (tokens[i].tipo == 'R') {
			/*cout << ")<" <<
				i << "," <<
				i << ">" << endl;*/
			return make_pair(i, i);
		}
	}

	return make_pair(-1, -1);
}

Coord getEXPR(vector<Token> tokens, int inicio, int fin);

Coord getEXPR1(vector<Token> tokens, int inicio, int fin) {
	bool b = true;
	int tmp = 0;
	Coord op = getOP(tokens, inicio, fin);
	if (op.first != -1)
		tmp = ((op.second - op.first) + 1);
	else b = false;
	if (b == true) {
		Coord expr_l = getEXPR(tokens, inicio, op.first);
		if (expr_l.first != -1)
			tmp = ((expr_l.second - expr_l.first) + 1);
		else b = false;
		Coord expr_r = getEXPR(tokens, op.second+1, fin);
		if (expr_r.first != -1)
			tmp = ((expr_r.second - expr_r.first) + 1);
		else b = false;
		cout << "EXPR1<" <<
			expr_l.first << "," <<
			expr_r.second << ">" << endl;
		if (b == true)
			return make_pair(expr_l.first, expr_r.second);
	}
	return make_pair(-1, -1);
}

Coord getEXPR2(vector<Token> tokens, int inicio, int fin) {
	bool b = true;
	int tmp = 0;
	/*Coord pl = getPL(tokens, inicio, fin);
	if (pl.first != -1)
		tmp = ((pl.second - pl.first) + 1);
	else b = false;
	Coord pr = getPR(tokens, inicio, fin);
	if (pr.first != -1)
		tmp = ((pr.second - pr.first) + 1);
	else b = false;*/
	if ((tokens[inicio].tipo != 'L') || (tokens[fin-1].tipo != 'R')) {
		b = false;
	}
	if (b == true) {
		//Coord expr = getEXPR(tokens, pl.second+1, pr.first);
		Coord expr = getEXPR(tokens, inicio + 1, fin-1);
		if (expr.first != -1)
			tmp = ((expr.second - expr.first) + 1);
		else b = false;
		/*cout << "EXPR2<" <<
			pl.first << "," <<
			pr.second << ">" << endl;
		if (b == true)
			return make_pair(pl.first, pr.second);*/
		cout << "EXPR2<" <<
			inicio << "," <<
			fin-1 << ">" << endl;
		if (b == true)
			return make_pair(inicio, fin-1);
	}
	return make_pair(-1, -1);
}

Coord getEXPR3(vector<Token> tokens, int inicio, int fin) {
	Coord var = getVAR(tokens, inicio, fin);
	Coord num = getNUM(tokens, inicio, fin);
	if (var.first != -1) {
		cout << "EXPR3<" <<
			var.first << "," <<
			var.second << ">" << endl;
		return var;
	}
	if (num.first != -1) {
		cout << "EXPR3<" <<
			num.first << "," <<
			num.second << ">" << endl;
		return num;
	}

	return make_pair(-1, -1);
}

Coord getEXPR(vector<Token> tokens, int inicio, int fin) {
	Coord expr1 = getEXPR1(tokens, inicio, fin);
	Coord expr2 = getEXPR2(tokens, inicio, fin);
	Coord expr3 = getEXPR3(tokens, inicio, fin);
	if (expr1.first != -1) {
		cout << "EXPR<" <<
			expr1.first << "," <<
			expr1.second << ">" << endl;
		return expr1;
	}
	if (expr2.first != -1) {
		cout << "EXPR<" <<
			expr2.first << "," <<
			expr2.second << ">" << endl;
		return expr2;
	}
	if (expr3.first != -1) {
		cout << "EXPR<" <<
			expr3.first << "," <<
			expr3.second << ">" << endl;
		return expr3;
	}

	return make_pair(-1, -1);
}

Coord getIGUALDAD(vector<Token> &tokens, int inicio, int fin) {
	bool b = true;
	int tmp = 0;
	Coord igual = getIgual(tokens, inicio, fin);
	if (igual.first != -1)
		tmp = ((igual.second - igual.first) + 1);
	else b = false;
	if (b == true) {
		Coord var = getVAR(tokens, inicio, igual.first);
		if (var.first != -1)
			tmp = ((var.second - var.first) + 1);
		else b = false;
		Coord expr = getEXPR(tokens, igual.second+1, fin);
		if (expr.first != -1)
			tmp = ((expr.second - expr.first) + 1);
		else b = false;
		cout << "Igualdad<" <<
			var.first << "," <<
			expr.second << ">" << endl;
		if (b == true)
			return make_pair(var.first, expr.second);
	}
	return make_pair(-1, -1);
}

Coord getCOM(vector<Token> &tokens, int inicio, int fin) {
	Coord igualdad = getIGUALDAD(tokens, inicio, fin);
	Coord expr = getEXPR(tokens, inicio, fin);
	if (igualdad.first != -1) {
		cout << "COM<" <<
			igualdad.first << "," <<
			igualdad.second << ">" << endl;
		return igualdad;
	}
	if (expr.first != -1) {
		cout << "COM<" <<
			expr.first << "," <<
			expr.second << ">" << endl;
		return expr;
	}

	return make_pair(-1, -1);
}

//AS End

int main() {
	char linea[256];
	cout << "Ingrese linea: " << endl;
	cin.getline(linea, 255, '\n');
	vector<Token> tokens = analizadorLexico(linea);
	for (int i = 0; i < tokens.size(); i++) {
		cout << i << ">>> " <<
			" Palabra: " << tokens[i].palabra <<
			" Indice: " << tokens[i].indice <<
			" Tipo: " << tokens[i].tipo << endl;
	}

	//Syntax
	Coord SA = getCOM(tokens, 0, tokens.size());

	//delete
	for (int i = 0; i < tokens.size(); i++) {
		delete[] tokens[i].palabra;
	}

	int var = 0;
	cin >> var;
}
