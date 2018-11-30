//Задача поиска лексикографически первого пути на графе.
#include <iostream>
//#include <queue> // очередь
#include <stack> // стек
using namespace std;
struct Edge {
	int begin;
	int end;
};
int main()
{
	system("chcp 1251");
	system("cls");
	stack<int> Stack;
	stack<Edge> Edges;
	int req;
	Edge e;
	int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
	{ 1, 0, 1, 1, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0 } };
	int nodes[7]; // вершины графа
	for (int i = 0; i < 7; i++) // исходно все вершины равны 0
		nodes[i] = 0;
	cout << "N = ";
	cin >> req;
	req--;
	Stack.push(0); // помещаем в очередь первую вершину
	while (!Stack.empty())
	{ // пока стек не пуст
		int node = Stack.top(); // извлекаем вершину
		Stack.pop();
		if (nodes[node] == 2) continue;
		nodes[node] = 2; // отмечаем ее как посещенную
		for (int j = 6; j >= 0; j--)
		{ // проверяем для нее все смежные вершины
			if (mas[node][j] == 1 && nodes[j] != 2)
			{ // если вершина смежная и не обнаружена
				Stack.push(j); // добавляем ее в cтек
				nodes[j] = 1; // отмечаем вершину как обнаруженную
				e.begin = node; e.end = j;
				Edges.push(e);
				if (node == req) break;
			}
		}
		cout << node + 1 << endl; // выводим номер вершины
	}
	cout << "Путь до вершины " << req + 1 << endl;
	cout << req + 1;
	while (!Edges.empty())
	{
		e = Edges.top();
		Edges.pop();
		if (e.end == req)
		{
			req = e.begin;
			cout << " <- " << req + 1;
		}
	}
	cin.get(); cin.get();
	return 0;
}