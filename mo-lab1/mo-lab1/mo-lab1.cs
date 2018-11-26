using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_mo
{
    class Program
    {
        static Boolean CheckForOptimal(double[,] Simplex)
        {
            // Проверка оптимальности решения по индексной строке (проверка отсутствия положительных элементов)
            Boolean check = true;
            for (int i = 0; i < Simplex.GetLength(1); i++)
            {
                if (Simplex[Simplex.GetLength(0) - 1, i] > 0)
                {
                    check = false;
                    break;
                }
            }
            return check;
        }

        static int FindResolvingColumn(double[,] Simplex)
        {
            // Нахождение разрешающего столбца (первого положительного элемента)
            int place = 0;
            double check = 0;
            for (int i = 1; i < Simplex.GetLength(1); i++)
            {
                if (Simplex[Simplex.GetLength(0) - 1, i] > 0)
                {
                    check = Simplex[Simplex.GetLength(0) - 1, i];
                    place = i;
                    break;
                }
            }

            return place;
        }

        static int FindResolvingRow(int Column, double[,] Simplex)
        {
            // Нахождение разрешающей строки, через минимальное положительное отношение 
            double min = 15000;
            int place = 0;
            for (int i = 0; i < Simplex.GetLength(0) - 1; i++)
            {
                if ((Simplex[i, 0] / Simplex[i, Column] < min) && (Simplex[i, 0] / Simplex[i, Column] > 0) && (Simplex[i, 0] != 0) && (Simplex[i, Column] != 0))
                {
                    min = Simplex[i, 0] / Simplex[i, Column];
                    place = i;
                }
            }
            return place;
        }

        static double[,] RecalculationOfTable(int r, int k, double[,] Simplex)
        {
            //Пересчет таблицы 
            // r - разрешающая строка 
            // k - разрешающий столбец 
            double[,] SimplexBuf = new double[Simplex.GetLength(0), Simplex.GetLength(1)]; //[4,4]

            for (int i = 0; i < Simplex.GetLength(1); i++)
            {
                SimplexBuf[r, i] = Simplex[r, i] / Simplex[r, k]; //пересчет на разрешающей строке
            }
            for (int i = 0; i < Simplex.GetLength(0); i++)
            {
                for (int j = 0; j < Simplex.GetLength(1); j++)
                {
                    if (i != r)
                    {//разрешающую строку уже учли
                        if (j == k) SimplexBuf[i, j] = -(Simplex[i, k] / Simplex[r, k]); //отдельный расчет для разрешающего столбца
                        else SimplexBuf[i, j] = Simplex[i, j] - (Simplex[r, j] * Simplex[i, k] / Simplex[r, k]); //обычный метод прямоугольник
                    }
                }
            }
            SimplexBuf[r, k] = 1 / Simplex[r, k];//разрешающий элемент
            return SimplexBuf;
        }

        static void StartingConditions(double[] c, double[,] A, double[] b)
        {
            // Вывод начальных условий 
            Console.WriteLine("Starting conditions:");
            Console.WriteLine("F = {0}X1+{1}X2+{2}X3 —> max", c[0], c[1], c[2]);
            Console.WriteLine("{0}X1+{1}X2+{2}X3 <= {3} \n{4}X1+{5}X2+{6}X3 <= {7} \n{8}X1+{9}X2+{10}X3 <= {11}", A[0, 0], A[0, 1], A[0, 2], b[0], A[1, 0], A[1, 1], A[1, 2], b[1], A[2, 0], A[2, 1], A[2, 2], b[2]);
        }

        static void Basicform(double[] c, double[,] A, double[] b)
        {
            //Запись каноничной формы 
            Console.WriteLine("\nPhase I-finding basic solution:");
            Console.WriteLine("\nBasic form:");
            Console.WriteLine("F = -({0}X1+{1}X2+{2}X3) —>min ", c[0], c[1], c[2]);
            Console.WriteLine("{0}X1+{1}X2+{2}X3+X4 = {3} \n{4}X1+{5}X2+{6}X3+X5 = {7} \n{8}X1+{9}X2+{10}X3+X6 = {11}", A[0, 0], A[0, 1], A[0, 2], b[0], A[1, 0], A[1, 1], A[1, 2], b[1], A[2, 0], A[2, 1], A[2, 2], b[2]);
            Console.WriteLine("X1...X6>=0\n");
            //выражение через свободные переменные
            Console.WriteLine("F = -({0}X1+{1}X2+{2}X3) —>min ", c[0], c[1], c[2]);
            Console.WriteLine("X4 = {3}-({0}X1+{1}X2+{2}X3) \nX5 = {7}-({4}X1+{5}X2+{6}X3) \nX6 = {11}-({8}X1+{9}X2+{10}X3)", A[0, 0], A[0, 1], A[0, 2], b[0], A[1, 0], A[1, 1], A[1, 2], b[1], A[2, 0], A[2, 1], A[2, 2], b[2]);
            Console.WriteLine("X1...X6>=0\n");
        }

        static double[,] MakeSimplexTable(double[] c, double[,] A, double[] b, int variablesnum)
        {
            // Создание симплекс таблицы(без вывода) 
            double[,] SimplexTable = new double[variablesnum + 1, variablesnum + 1];
            for (int i = 0; i < 3; i++)
            {
                SimplexTable[i, 0] = b[i];
            }
            for (int i = 0; i < 3; i++)
                for (int j = 1; j < 4; j++)
                {
                    SimplexTable[i, j] = A[i, j - 1];
                }
            for (int i = 1; i < 4; i++)
            {
                SimplexTable[3, i] = c[i - 1];
            }
            return SimplexTable;
        }

        static void SimplexOutput(double[,] Simplex, string[] column, string[] row)
        {
            //Вывод симплекс таблицы 
            Console.WriteLine("Simplex table:");
            Console.Write("\t");
            for (int j = 0; j < 4; j++)
            {
                Console.Write(column[j] + "\t");
            }
            Console.WriteLine(" ");
            for (int i = 0; i < 4; i++)
            {
                Console.Write(row[i] + "\t");
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(Math.Round(Simplex[i, j], 2) + "\t");
                }
                Console.WriteLine(" ");
            }
        }

        static void SimplexMethod(double[,] Simplex, string[] column, string[] row, double[] c)
        {
            // проверка на оптимальность 
            Boolean CheckOptimal = CheckForOptimal(Simplex);
            int
            counter = 0;
            while (!CheckOptimal)
            {
                counter++;
                if (counter == 6) break;
                // Поиск разрешающего стобца и строки 
                int k = FindResolvingColumn(Simplex);
                int r = FindResolvingRow(k, Simplex);
                // Замена в названии строк и столбцов 
                string buf = row[r];
                Console.WriteLine("Iteration {0}:", counter);
                Console.WriteLine("{0} is resolving column", column[k]);
                Console.WriteLine("{0} is resolving row", buf);
                Console.WriteLine("{0} is now basic variable while {1} is free now", column[k], buf);
                row[r] = column[k];
                column[k] = buf;
                // Пересчет таблицы 
                Simplex = RecalculationOfTable(r, k, Simplex);
                SimplexOutput(Simplex, column, row);
                //Проверка на оптимальность 
                CheckOptimal = CheckForOptimal(Simplex);
                if (CheckOptimal) Console.WriteLine("Solution is optimal");
                else Console.WriteLine("Solution is not optimal");
                Console.WriteLine();
            }
            double p = Simplex[Simplex.GetLength(0) - 1, 0];
            Console.WriteLine("Solution : {0:#.###}", p);
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("{0} = {1}",
                row[i], Simplex[i, 0]);
            }
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("{0} = 0", column[i + 1]);
            }
            Console.WriteLine("\nChecking:");
            Console.WriteLine("F = {0}X1+{1}X2+{2}X3=", c[0], c[1], c[2]);
            //поиск значений X1, X2 и X3
            double[] chkval = new double[3];
            for (int i = 1; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (row[j] == ("X" + i.ToString()))
                    {
                        chkval[j] = Simplex[i - 1, 0];
                        break;
                    }

                    if (column[j] == ("X" + i.ToString()))
                    {
                        chkval[j] = 0;
                    }
                }
            }
            Console.WriteLine(" = {0}*{3}+{1}*{4}+{2}*{5}={6}", c[0], c[1], c[2], chkval[0], chkval[1], chkval[2], c[0] * chkval[0] + c[1] * chkval[1] + c[2]* chkval[2]);
        }




        static void Main(string[] args)
        {
            // Начальные условия: 
            int VariablesNumber = 3;

            double[] c = new double[3] { 5, 6, 4 };
            double[,] A = new double[3, 3] { { 1, 1, 1 }, { 1, 3, 0 }, { 0, 0.5, 4 } };
            double[] b = new double[3] { 7, 8, 6 };

            //Создание симплекс таблицы: 
            StartingConditions(c, A, b);
            //Вывод каноничной формы: 
            Basicform(c, A, b);
            //Создание симплекс таблицы: 
            double[,] Simplex = MakeSimplexTable(c, A, b, VariablesNumber);
            // Названия строк 
            string[] row = { "X4", "X5", "X6", "F" };
            // Названия столбцов 
            string[] column = { "B", "X1", "X2", "X3" };
            //Вывод симплекс таблицы: 
            SimplexOutput(Simplex, column, row);
            Console.WriteLine("\nPhase II-optimization:\n");
            //Использование симплекс метода: 
            SimplexMethod(Simplex, column, row, c);
        }
    }
}