#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
bool is_luck(ll num)
{
	string str = to_string(num);
	int len = str.size();
	if(len == 1)
		return true;

	ll l = 0,r = len-1;
	while(l < r)
	{
		if(str[l] == str[r])
			return false;
		else{
			l++;
			r--;
		}
	}

	return true;
}

int main()
{
	int a,b;
	cin >> a >> b;

	ll cnt = 0;
	for(ll i=a;i<=b;i++)
	{
		if(is_luck(i))
			cnt++;
	}

	cout << cnt << endl;
	system("pause");
	return 0;
}