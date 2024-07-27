#ifndef DEF_Matrix
#define DEF_Matrix
class Matrix{
private:
    int data[2][2];
public:
    //constructors and destructor
    Matrix(void);
    Matrix(const int [][2]);
    ~Matrix();
    //public function
    const int determinant(void) const;
    const Matrix transpose(void) const;
    //overloadings
    const Matrix operator+(const Matrix &) const;
    const Matrix operator*(const int &) const;
    const Matrix operator*(const Matrix &) const;
    const bool operator==(const Matrix &) const;
    const bool operator!=(const Matrix &) const;
    //also overloadings
    friend std::ostream & operator<<(std::ostream & , const Matrix & );
    friend Matrix operator*( const int & , const Matrix & );
    //Bonus overloadings
    Matrix& operator=(const Matrix&);
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);
};
#endif
