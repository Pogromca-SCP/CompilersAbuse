#include <iostream>

class Vector
{
public:
    float X;
    float Y;
    Vector(float x, float y) : X(x), Y(y) {}

    void print()
    {
        std::cout << X << " : " << Y << std::endl;
    }
};

class Point
{
public:
    float X;
    float Y;
    Point(float x, float y) : X(x), Y(y) {}

    // No printing method here.
};

class Vector3D
{
public:
    float X;
    float Y;
    float Z;
    Vector3D(float x, float y, float z) : X(x), Y(y), Z(z) {}

    void print()
    {
        std::cout << X << " : " << Y << " : " << Z << std::endl;
    }
};

int main()
{
    float num = 3.14f;
    int asInt = num;
    
    // Normally when a value of certain type is assigned to another type, the data gets converted.
    std::cout << num << std::endl;
    std::cout << asInt << std::endl;

    // The conversion also happens when pointers are used.
    asInt = *(float*) &num;
    std::cout << asInt << std::endl;

    // However, thanks to pointers nature we can abuse them to avoid conversion.
    asInt = *(int*) &num;
    std::cout << asInt << std::endl;

    // This trick works in both ways.
    asInt = 8;
    num = *(float*) &asInt;
    std::cout << num << std::endl;

    // Pointers can also be used to reinterpret complex data types.
    Vector vec(1.0f, 2.0f);
    Point pt(5.0f, -3.0f);
    std::cout << vec.X << " : " << vec.Y << std::endl;
    std::cout << pt.X << " : " << pt.Y << std::endl;

    vec.print();
    Vector* pointAsVector = (Vector*) &pt;
    std::cout << pointAsVector->X << " : " << pointAsVector->Y << std::endl;

    // You can even call methods that (in theory) don't exist.
    pointAsVector->print();

    // Types don't have to have the same size.
    ((Vector3D*) pointAsVector)->print();
    return 0;
}
