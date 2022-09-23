#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int size{};
    vector<vector<int>> matrix;
public:
    // Конструкторы
    Matrix(): size(1) {}
    Matrix(const Matrix  &matrix) = default;
    Matrix(int size, int diagonal_element);
    explicit Matrix(int size): size(size) {}

    // Overload операторов
    Matrix operator+(Matrix &) const;
    Matrix operator-(Matrix &) const;
    Matrix operator*(Matrix &) const;
    Matrix transpose();
    ~Matrix();

    int& operator()(const int &RowNumeral, const int &ColNumeral);

    int getSize() const;

    void init();

    void diagonalize(int k);

    void print();

    void fill();
};

Matrix Matrix::operator+(Matrix &B) const {
    Matrix sum(size);
    sum.init();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            sum(i, j) = this->matrix[i][j] + B(i, j);
        }
    }
    return sum;
}

Matrix Matrix::operator-(Matrix &B) const {
    Matrix diff(size);
    diff.init();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            diff(i, j) = this->matrix[i][j] - B(i, j);
        }
    }
    return diff;
}

Matrix Matrix::operator*(Matrix &B) const {
    Matrix multiplication(size);
    multiplication.init();
    int temp = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp = 0;
            for (int k = 0; k < size; ++k) {
                temp += matrix[i][k] * B(k, j);
            }
            multiplication(i, j) = temp;
        }
    }
    return multiplication;
}

Matrix Matrix::transpose() {
    Matrix trans(size);
    trans.init();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            trans(i, j) = this->matrix[j][i];
        }
    }
    return trans;
}

Matrix::~Matrix()= default;

int Matrix::getSize() const {
    return this->size;
}

int &Matrix::operator()(const int &RowNumeral, const int &ColNumeral) {
    return this->matrix[RowNumeral][ColNumeral];
}

void Matrix::init() {
    matrix.resize(size);
    for (int i=0;i<size; i++) {
        matrix[i].resize(size);
    }
}

void Matrix::fill() {
    for (int i=0; i<size;i++) {
        for (int j=0; j<size;j++) {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::print() {
    for (int i=0;i<size; i++) {
        for (int j=0; j<size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::diagonalize(int k) {
    matrix.resize(size);
    for (int i=0;i<size; i++) {
        matrix[i].resize(size);
    }
    for (int i=0; i<size;i++) {
        for (int j=0; j<size;j++) {
            if (i == j) {
                matrix[i][j] = k;
                }
        }
    }
}

Matrix::Matrix(int size, int diagonal_element) {
    this->size = size;
    matrix.resize(size);
    for (int i=0;i<size; i++) {
        matrix[i].resize(size);
    }
    for (int i=0; i<size;i++) {
        for (int j=0; j<size;j++) {
            if (i == j) {
                matrix[i][j] = diagonal_element;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    Matrix A(n);
    A.init();
    A.fill();
    Matrix B(n);
    B.init();
    B.fill();
    Matrix C(n);
    C.init();
    C.fill();
    C = C.transpose();
    Matrix D(n);
    D.init();
    D.fill();
    D = D.transpose();
    Matrix K(n, k);
    Matrix result;
    result = B * C;
    result = result + A + K;
    result = result * D;
    result.print();
}
