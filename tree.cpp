#include<iostream>
using namespace std;
int a[101][101];
int power[101];
int fpower[101];
int num, maxpower[101], minpower=999;
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int min(int&a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
int find(int i)
{
	if (power[i])
		return power[i];
	else
	{
		for (int j = i + 1; j < num + 2; j++)
			if (a[i][j])
			{
				power[i] += find(j);
				maxpower[i] = max(maxpower[i], find(j));
			}

		power[i] += 1;
	}
	fpower[i] = num+1 - power[i];
	maxpower[i] = max(maxpower[i], fpower[i]);
	minpower = min(minpower, maxpower[i]);
	return power[i];
}
int main()
{
	int time;
	cin >> time;
	while (time) 
	{
		for (int i = 0; i < 101; i++)
			memset(a[i], 0, sizeof(a[i]));
		memset(power, 0, sizeof(power));
		memset(fpower, 0, sizeof(fpower));
		memset(maxpower, 0, sizeof(maxpower));
		cin >> num;
		int x, y;
		for (int i = 0; i < num; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
		}
		int m = find(1);
		cout << minpower;
		time--;
	}
	return 0;
}