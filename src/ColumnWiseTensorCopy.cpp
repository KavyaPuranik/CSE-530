#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}

vector<vector<int> > createMatrix(int n) {
    vector<int> tmp(n, 0);
    vector<vector<int> > matrix(n, tmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 1000 + n;
        }
    }
    return matrix;
}


vector<vector<int>> columnWiseTensorCopy(vector<vector<int>> A) {
    int n = A.size();
    vector<int> tmp(n, 0);
    vector<vector<int> > C(n, tmp);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            C[i][j] = A[i][j];
        }
    }
    return C;
}


void printMatrix(vector< vector<int> > matrix) {
	vector< vector<int> >::iterator it;
	vector<int>::iterator inner;
	for (it=matrix.begin(); it != matrix.end(); it++) {
		for (inner = it->begin(); inner != it->end(); inner++) {
			cout << *inner;
			if(inner+1 != it->end()) {
				cout << "\t";
			}
		}
		cout << endl;
	}
}

int main (int argc, char* argv[]) {

	int size;
    if (argc < 2) {
        size = 2;
    } else {
        size = atoi(argv[1]);
    }
    vector<vector<int>> result = createMatrix(size);
    parsec_roi_begin();
	vector< vector<int> > C = columnWiseTensorCopy(result);
    parsec_roi_end();
    //printMatrix(C);
    return 0;

}