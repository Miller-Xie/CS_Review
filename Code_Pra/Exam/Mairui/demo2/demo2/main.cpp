#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<bool>>& visited){
	if (index == word.size())return true;
	if (i >= board.size() || j >= board[0].size() || i<0 || j<0)return false;
	if (board[i][j] != word[index])return false;
	if (visited[i][j])return false;
	visited[i][j] = true;
	bool res = dfs(board, word, index + 1, i - 1, j, visited) || dfs(board, word, index + 1, i + 1, j, visited)
		|| dfs(board, word, index + 1, i, j - 1, visited) || dfs(board, word, index + 1, i, j + 1, visited);
	visited[i][j] = false;
	return res;
}

bool f(vector<vector<char> >& board, string word){
	/* dfs */
	if (board.empty() || board[0].empty())return false;
	int row = board.size();
	int col = board[0].size();
	vector<vector<bool> > visited(row, vector<bool>(col, false));
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			if (dfs(board, word, 0, i, j, visited))return true;
		}
	}
	return false;
}

int main() {
	int m, n, k;
	fstream fin("test.txt");
	fin >> m >> n >> k;
	vector<string> kstr;
	//string s;
	for (int i=0;i<k;i++)
	{
		string s;
		fin >> s;
		kstr.push_back(s);
	}

	vector<vector<char> > zdch(n,vector<char>(m));
	vector<char> t;
	
	/*while (n--){
		while (m--){
			fin >> ch;
			t.push_back(ch);
		}
		zdch.push_back(t);
		t.clear();
	}*/
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			char ch;
			fin >> ch;
			zdch[i][j] = ch;
		}
	}

	vector<string> res;
	for (int i = 0; i < kstr.size(); i++){
		if (f(zdch, kstr[i])){
			res.push_back(kstr[i]);
		}
	}
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;;
	}
	//getchar();
	return 0;
}
