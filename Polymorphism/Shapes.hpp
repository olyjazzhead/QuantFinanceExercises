/*
    Copyright (c) 2021, Daniel Hanson
    CFRM 520 University of Washington
    For instructional purposes only
    See license information at bottom of file
*/

#ifndef Shapes_hpp
#define Shapes_hpp

#include <iostream>
#include <memory>


//SHAPE CLASS//

class Shape
{
public:
    virtual double operator()() const = 0;        // Returns the area of the shape
    virtual ~Shape() = default;                    // Virtual Destructor
};


//SHAPE SHIFTER CLASS//
class ShapeShifter
{
public:
    ShapeShifter(std::unique_ptr<Shape> shape, const double area); //Constructor
    
    //Rule of Five (Disable copy operations due to presence of unique pointer)
    ShapeShifter(const ShapeShifter& shape) = delete;
    ShapeShifter& operator = (const ShapeShifter& shape) = delete;
    ShapeShifter(ShapeShifter&& shape) = default;
    ShapeShifter& operator = (ShapeShifter&& shape) = default;
    ~ShapeShifter() = default;
    
    //multiplier Member Function
    double multiplier(double x);
    
private:
    std::unique_ptr<Shape> shape_;
    double area_;

};

//RECTANGLE CLASS//

class Rectangle : public Shape
{
public:
    Rectangle(double length, double height);
    virtual double operator()() const override;            // Area of the rectangle
    
private:
    double length_;
    double height_;
};


//CIRCLE CLASS//

class Circle : public Shape
{
public:
    Circle(double radius);
    virtual double operator()() const override;            // Area of the circle
    

private:
    double radius_;
    double pi_;
};

//shape_shifter_test function
//void shape_shifter_tests();


#endif

