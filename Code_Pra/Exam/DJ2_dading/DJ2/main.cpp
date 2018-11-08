#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> sol(vector<string> arr){
	vector<int> recin;
	vector<vector<int>> rec;
	int len = arr.size();
	int l1, l2, l3;
	for (int i = 0; i < len; i++){
		l1 = arr[i][0] * arr[i][2];
		recin.push_back(l1);
		l2 = arr[i][1] * (arr[i][3]-arr[i][2]);
		recin.push_back(l2);
		recin.push_back(arr[i][3]);
		rec.push_back(recin);
	}
	return rec;
}
vector<string> sol2(vector<vector<int>> rec){
	vector<string> result;
	string s;
	int len = rec.size();
	for (int i = 0; i < len; i++){
		int cha,num;
		cha=rec[i][1] - rec[i][0];
		s = to_string(cha) + "/" +to_string( rec[i][2]);
		result.push_back(s);
	}
	return result;
}
vector<string> sol4(vector<string> rec){
	vector<string> res;
	string s;
	int len = rec.size();
	int fmu = 1;
	for (int i = 0; i < len; i++){
		fmu *= rec[i][2];
	}
	int fz = 1;
	for (int i = 0; i < len; i++){
		int k = fmu / rec[i][2];
		fz = rec[i][0] * k;
		s = to_string(fz) + "/" + to_string(fmu);
		res.push_back(s);
	}
	return res;
}
string sol3(vector<string> rec,int w){
	string result;
	vector<string> Rec;
	string s;
	Rec = sol4(rec);
	s = sol5(Rec);
	int num = 90 + s[0];
	result = to_string(num) + "+" + s[2] + +"/" + s[4];
	return result;
}
vector<string> sol4(vector<string> rec){
	vector<string> res;
	string s;
	int len = rec.size();
	int fmu=1;
	for (int i = 0; i < len; i++){
		fmu *= rec[i][2];
	}
	int fz=1;
	for (int i = 0; i < len; i++){
		int k = fmu / rec[i][2];
		fz = rec[i][0] * k;
		s = to_string(fz) + "/" + to_string(fmu);
		res.push_back(s);
	}
	return res;
}
int Maxy(int a, int b){
	int min, max;
	max = a>b ? a : b;
	min = a > b ? b : a;
	if (max%min == 0)
		return min;
	else return Maxy(min,max%min);
}
int* sol6(int a, int b){
	int arr[2];
	int maxy=Maxy(a,b);
	a /= maxy;
	b /= maxy;
	arr[0] = a;
	arr[1] = b;
	return arr;
}
string sol5(vector<string> rec){
	string s;
	int fz=0;
	int len = rec.size();
	for (int i = 0; i < len; i++){
		fz += rec[i][0];
	}
	int a = fz / rec[0][2];
	fz = fz - a*rec[0][2];
	int *p=sol6(fz,rec[0][2]);
	//s = to_string(a) + "+" + fz + "/" + fu;
}

int main(){

	int n, w;
	int line;
	cin >> n;
	cin >> w;
	vector<string> arr;
	vector<vector<int>> liarr;
	vector<string> rec;
	string s;
	while (n>0){
		getline(cin,s);
		arr.push_back(s);
		n--;
	}
	liarr=sol(arr);
	rec = sol2(liarr);
	string num;
	num = sol3(rec,w);
	cout << num<<endl;
	//getchar();
	return 0;

}
