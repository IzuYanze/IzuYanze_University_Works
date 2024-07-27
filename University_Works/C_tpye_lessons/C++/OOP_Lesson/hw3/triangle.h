class Triangle{
    int side;
    char border;
    char fill;
    char name[20];
public:
    Triangle(int);
    Triangle(int,char);
    Triangle(int,char,char);
    ~Triangle();
    int GetSize(void);      // take side
    int Perimeter(void);    // take side * 3
    double Area(void);      // take root(3)/4 * a^2
    void Grow(void);        // side := side + int (no more than 39)
    void Shrink(void);      // side := side - int (no less than 1)
    void SetBorder(char);   // set border character appearance
    void SetFill(char);     // set fill character appearance
    void Draw(void);        // draw the triangle
    void Summary(void);     // final

    void SetName(const char*);   // set the name of this obj
    void GetName(char*);    // get the name of this obj
};
