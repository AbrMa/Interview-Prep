#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> zero_matrix(vector<vector<int>>& matrix) {
	unordered_map<int,int> rows, cols;
	const int max_row = matrix.size();
	const int max_col = matrix[0].size();
	for (int row = 0; row < max_row; row++) {
		for (int col = 0; col < max_col; col++) {
			if (matrix[row][col] == 0) {
				rows[row]++;
				cols[col]++;	
			}
		}
	}
	for (auto col : cols) {
		for (int row = 0; row < max_row; row++) {
			matrix[row][col.first] = 0;
		}
	}
	for (auto row : rows) {
		for (int col = 0; col < max_col; col++) {
			matrix[row.first][col] = 0;
		}
	}
	return matrix;
}

void print_matrix(vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int>> M;
	vector<int> A = {1,1,1,1};
	vector<int> B = {1,1,0,1};
	vector<int> C = {1,1,1,1};
	vector<int> D = {1,1,1,1};
	M.push_back(A);
	M.push_back(B);
	M.push_back(C);
	M.push_back(D);
	zero_matrix(M);
	print_matrix(M);
	return 0;
}
