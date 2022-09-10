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



vector<int> createGatherIndexVector(int n) {
    int totalSize = n*n;
    vector<int> gatherVector(n, 0);
    for (int i = 0; i <n; i++) {
        gatherVector[i] = rand() % totalSize;
    }
    return gatherVector;
}


void scatterOperation(vector<vector<int>>& matrix, vector<int> scatterIndexValue, vector<int> scatterIndexVector) {
    int size = scatterIndexVector.size();
    for (int i = 0; i < size; i++) {
        int x = scatterIndexVector[i]/size;
        int y = scatterIndexVector[i]%size;
        matrix[x][y] = scatterIndexValue[i];
    }
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

vector<vector<int> > createMatrix(int n, int sparse) {
    vector<int> tmp(n, 0);
    vector<vector<int> > matrix(n, tmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = rand() % 100 + n;
            if(val < sparse) {
                matrix[i][j] = 0;
            }else {
                matrix[i][j] = val;
            }
            
        }
    }
    return matrix;
}

int main (int argc, char* argv[]) {

	int size, sparse;
    if (argc < 3) {
        cout<<"Please enter 3 or more arguments"
    } else {
        size = atoi(argv[1]);
        sparse = atoi(argv[2]);
    }
    vector<vector<int>> result = createMatrix(size, sparse);
    vector<int> scatterIndexVector = createGatherIndexVector(size);
    vector<int> scatterIndexValue = createGatherIndexVector(size);

    parsec_roi_begin();
	vector< vector<int> > C = scatterOperation(result, scatterIndexValue, scatterIndexVector);
    parsec_roi_end();
    //printMatrix(C);
    return 0;

}