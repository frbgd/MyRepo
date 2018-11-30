//обход неориентированного графа в глубину через рекурсию
#include <iostream>
using namespace std;
int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
{ 1, 0, 1, 1, 0, 0, 0 },
{ 1, 1, 0, 0, 0, 0, 0 },
{ 0, 1, 0, 0, 1, 0, 0 },
{ 0, 0, 0, 1, 0, 1, 0 },
{ 0, 0, 0, 0, 1, 0, 1 },
{ 1, 0, 0, 0, 0, 1, 0 } };
int nodes[7]; // вершины графа
void search(int st, int n)
{
	int r;
	cout << st + 1 << " ";
	nodes[st] = 1;
	for (r = 0; r < n; r++)
		if ((mas[st][r] != 0) && (nodes[r] == 0))
			search(r, n);
}
int main()
{
	for (int i = 0; i < 7; i++) // исходно все вершины равны 0
		nodes[i] = 0;
	search(0, 7);
	cin.get();
	return 0;
}