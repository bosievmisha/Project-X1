#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;


void QuadraticEquation (double &a, double &b, double &c)
{
    double D = (b * b) - (4 * a * c);
    if (D < 0)
        cout << "No solution";
    else if (D == 0)
        cout << "Solution: x = " << -b / 2 * a << endl;
    else if (D > 0)
        cout << "Solution: x1 = " << (-(b)+sqrt(D)) / (a * 2) << " || x2 = " << (-(b)-sqrt(D)) / (a * 2) << endl;
        
}   

void QuadraticEquation(double a, double b, double c)
{
    double D = (b * b) - (4 * a * c);
    if (D < 0)
        cout << "No solution";
    else if (D == 0)
        cout << "Solution: x = " << -b / 2 * a << endl;
    else if (D > 0)
        cout << "Solution: x1 = " << (-(b)+sqrt(D)) / (a * 2) << " || x2 = " << (-(b)-sqrt(D)) / (a * 2) << endl;

}


class IntArray 
{
protected:
    size_t Size;
    int* array;
public:
    IntArray(size_t Size): Size(Size), array(array = new int[Size]) {
        for (size_t i = 0; i < Size; i++)
            array[i] = 0;
    }
    IntArray() : Size(1), array(array = new int[Size]) {}

    IntArray(const IntArray& other) : Size(other.Size), array(new int[Size]) { // Конструктор копирования
        for (size_t i = 0; i < Size; i++)
            array[i] = other.array[i];
    }

    IntArray& operator = (const IntArray& other) {
        Size = other.Size;
        if (this != &other)
            IntArray(other).Swap(*this);
        return *this;
    }

    void Print() {
        for (size_t i = 0; i < Size; i++)
            cout << array[i] << " ";
        cout << '\n';
    }

    void FillArray(size_t a) {
        for (size_t i = 0; i < Size; i++)
            array[i] = a;
    }

    void FillArray() {
        for (size_t i = 0; i < Size; i++)
            array[i] = i;
    }
    void Swap(IntArray& other) {
        swap(Size, other.Size);
        swap(array, other.array);
      
    }
    ~IntArray() {
        delete [] array;
    }
};


class IntArray2d : public IntArray
{
protected:
    size_t Size2;
    int** array2d;
public:
    IntArray2d(size_t Size, size_t Size2): Size2(Size2), array2d(array2d = new int *[Size2]) {
        this->Size = Size;
        for (size_t i = 0; i < Size2; i++)
            array2d[i] = new int[Size];

        for (size_t i = 0; i < Size2; i++)
            for (size_t j = 0; j < Size; j++)
                array2d[i][j] = 0;
            
    }
    IntArray2d(size_t Size, size_t Size2, int a) : Size2(Size2), array2d(array2d = new int* [Size2]) {
        this->Size = Size;
        for (size_t i = 0; i < Size2; i++)
            array2d[i] = new int[Size];

        for (size_t i = 0; i < Size2; i++)
            for (size_t j = 0; j < Size; j++)
                array2d[i][j] = a;

    }
    IntArray2d(size_t Size, size_t Size2, string s) : Size2(Size2), array2d(array2d = new int* [Size2]) {
        this->Size = Size;
        int a = 0;
        for (size_t i = 0; i < Size2; i++)
            array2d[i] = new int[Size];

        for (size_t i = 0; i < Size2; i++) 
            for (size_t j = 0; j < Size; j++) {
                array2d[i][j] = a;
                a++;
            }
        

    }

    IntArray2d(const IntArray2d &other) : Size2(other.Size2), array2d(new int *[Size2]) { // Конструктор копирования
        this->Size = other.Size;
        for (size_t i = 0; i < Size2; i++)
            array2d[i] = new int[Size];

        for (size_t i = 0; i < Size2; i++)
            for (size_t j = 0; j < Size; j++)
                array2d[i][j] = other.array2d[i][j];
    }
    void Print() {
        for (size_t i = 0; i < Size2; i++) {
            for (size_t j = 0; j < Size; j++)
                cout << array2d[i][j] << " ";
            cout << "\n";
        }
    }

    ~IntArray2d() {
        for (size_t i = 0; i < Size2; i++)
            delete [] array2d[i];
        delete[] array2d;
    }
};












int main()
{
    //setlocale(LC_ALL, "RUS");
   // double a, b, c;
    //cin >> a >> b >> c;
    //IntArray a(5);
   // IntArray2d b(5, 5, "s");
    //IntArray2d c(10, 10, 5);
   // b.Print();
   // c.Print();
    QuadraticEquation(4, -10, -32);

    return 0; 
}
