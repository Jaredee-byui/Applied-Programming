// geometryCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

/*
struct to handle constants, can be expanded to handle more such as physics, trig or otherwise.

*/

struct {
    double pi = 3.14159265359;
    double e = 2.71828;


} constants;

/*
The parent shape class, this class is rather simple in its function. I gave it some base
attributes such as area, perimeter, side length, etc. It also posses some basic methods
that would allow for attributes to be called and set. I made the classes and all its 
attributes public since this was my first time writing an object orientated program in
C++. 

*/

class shape {
public:
    
    double area = 0.0;
    double perimeter = 0.0;
    double sideLength = 0.0;
    double height = 0.0;
    string shapeName;
    
    
    double getSide() {
        return sideLength;
    }
    double getArea() {
        return area;
    }
    double getPerimeter() {
        return perimeter;
    }
    double getHeight() {
        return height;
    }
    double setSide(double side) {
        sideLength = side;
    }
    double setArea(double areaInput) {
        area = areaInput;
    }
    double setPerimeter(double perimeterInput) {
        perimeter = perimeterInput;
    }
    double setHeight(double heightInput) {
        height = heightInput;
    }
    void findArea() {
        return;
    }
    void findPerimeter() {
        return;
    }
    // get shape, outputs the stats of a given shape to user
    void getShape() {
        cout << "\nShape: " << shapeName << endl;
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
        cout << "Side Length: " << sideLength << endl;
    }
    // menu, is modified according to the needs of each daughter class
    void menu() {
        return;
    }
    


};


/*
The first child class, Circle. The circle ultimately behaves like 
an other shape in terms of how it inherits from parent. findDiameter
is a unique function to this class. 
*/
class circle: public shape {
public:
    double diameter = 0.0;
    string shapeName = "Circle";

    void findCircumfrence() {
        double userCircumfrence;

        cout << "\nPlease enter the Radius: ";
        cin >> userCircumfrence;
        sideLength = userCircumfrence;
        perimeter = 2 * constants.pi * sideLength;
        cout << "Circumfrence is: " << perimeter << endl;
    }
    void findDiameter() {
        double userRadius;

        cout << "\nPlease enter the Radius: ";
        cin >> userRadius;
        sideLength = userRadius;
        diameter = 2 * sideLength;
        cout << "Diameter is: " << diameter << endl;

    }
    void findArea() {
        double userRadius;

        cout << "\nPlease enter the Radius: ";
        cin >> userRadius;
        sideLength = userRadius;
        area = constants.pi * pow(sideLength, 2);
        cout << "Area is: " << area << endl;
    }
    void getShape() {
        cout << "\nShape: " << shapeName << endl;
        cout << "Area: " << area << endl;
        cout << "Circumfrence is: " << perimeter << endl;
        cout << "Radius: " << sideLength << endl;
    }
    void menu() {
        int menuInput = 1;
        while (menuInput != 0) {
            cout << "\nCircle" << endl;
            cout << "Find area               (1)" << endl;
            cout << "Find Circumfrence       (2)" << endl;
            cout << "Find Diameter           (3)" << endl;
            cout << "Output Stats            (4)" << endl;
            cout << "Return                  (0)" << endl;
            cout << "\nPlease make a selection now: ";
            cin >> menuInput;

            if (menuInput == 1) {
                findArea();
            }
            else if (menuInput == 2) {
                findCircumfrence();
            }
            else if (menuInput == 3) {
                findDiameter();
            }
            else if (menuInput == 4) {
                getShape();
            }
            else {
                return;
            }
        }
        
    }
};
/*
Square class, inherits from shape. 
*/

class square: public shape {
public:
    string shapeName = "Square";

    void findArea() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        area = pow(sideLength, 2);
        cout << "Area: " << area << endl;
    }
    void findPerimeter() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        perimeter = 4 * sideLength;
        cout << "Perimeter: " << perimeter << endl;
    }
    
    void menu() {
        int menuInput = 1;
        while (menuInput != 0) {
            cout << "\nSquare" << endl;
            cout << "Find area               (1)" << endl;
            cout << "Find Perimeter          (2)" << endl;
            cout << "Output Stats            (3)" << endl;
            cout << "Return                  (0)" << endl;
            cout << "\nPlease make a selection now: ";
            cin >> menuInput;


            if (menuInput == 1) {
                findArea();
            }
            else if (menuInput == 2) {
                findPerimeter();
            }

            else if (menuInput == 3) {
                getShape();
            }
            else {
                return;
            }
        }
        
    }
    



};
/*
Rectangle, inherits from shape. Has the unqiue property of using 
side length and height for its calculations. It behaves in many
ways similarly to a square. 
*/
class rectangle: public shape {
public:
    string shapeName = "Rectangle";


    void findArea() {
        double userWidth;
        double userHeight;

        cout << "\nPlease enter the Width: ";
        cin >> userWidth;
        sideLength = userWidth;

        cout << "Please enter the Height: ";
        cin >> userHeight;
        height = userHeight;

        area = sideLength * height;
        cout << "Area: " << area << endl;
    }
    void findPerimeter() {
        double userWidth;
        double userHeight;

        cout << "\nPlease enter the Width: ";
        cin >> userWidth;
        sideLength = userWidth;

        cout << "Please enter the Height: ";
        cin >> userHeight;
        height = userHeight;

        perimeter = 2 * sideLength + 2 * height;
        cout << "Perimeter: " << perimeter << endl;
        // perimeter = 2 * width + 2 * height
    }
    void getShape() {
        cout << "\nShape: " << shapeName << endl;
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
        cout << "Width: " << sideLength << endl;
        cout << "Height: " << height << endl;
    }
    void menu() {
        int menuInput = 1;
        while (menuInput != 0) {
            cout << "\nRectangle" << endl;
            cout << "Find area               (1)" << endl;
            cout << "Find Perimeter          (2)" << endl;
            cout << "Output Stats            (3)" << endl;
            cout << "Return                  (0)" << endl;
            cout << "\nPlease make a selection now: ";
            cin >> menuInput;

            if (menuInput == 1) {
                findArea();
            }
            else if (menuInput == 2) {
                findPerimeter();
            }
            else if (menuInput == 3) {
                getShape();
            }
            else {
                return;
            }
        } 
    }
    
    
    

};
/*
triangle class, also utilizes the sidelength and base properties in
its calculations. 
*/
class triangle : public shape {
public:
    string shapeName = "Triangle";

    void findArea() {
        double userWidth;
        double userHeight;

        cout << "\nPlease enter the Base: ";
        cin >> userWidth;
        sideLength = userWidth;

        cout << "Please enter the Height: ";
        cin >> userHeight;
        height = userHeight;

        area = (1.0/2.0) * sideLength * height;
        cout << "Area: " << area << endl;
        // area = 1/2 * base * height
    }
    void findPerimeter() {
        double userWidth;
        double userHeight;

        cout << "\nPlease enter the Base: ";
        cin >> userWidth;
        sideLength = userWidth;

        cout << "Please enter the Height: ";
        cin >> userHeight;
        height = userHeight;

        perimeter = sqrt(pow(sideLength, 2) + pow(height, 2));
        cout << "Perimeter (assuming a right triangle): " << perimeter << endl;
        // perimeter = 2 * width + 2 * height
    }
    void getShape() {
        cout << "\nShape: " << shapeName << endl;
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
        cout << "Base: " << sideLength << endl;
        cout << "Height: " << height << endl;
    }
    void menu() {
        int menuInput = 1;
        while (menuInput != 0) {
            cout << "\nTriangle" << endl;
            cout << "Find area               (1)" << endl;
            cout << "Find Perimeter          (2)" << endl;
            cout << "Output Stats            (3)" << endl;
            cout << "Return                  (0)" << endl;
            cout << "\nPlease make a selection now: ";
            cin >> menuInput;

            if (menuInput == 1) {
                findArea();
            }
            else if (menuInput == 2) {
                findPerimeter();
            }

            else if (menuInput == 3) {
                getShape();
            }
            else {
                return;
            }
        }
    }
};

/*
Pentagon class, handles cases of equilateral pentagons. 
*/
class pentagon : public shape {
public:
    string shapeName = "Pentagon";

    void findArea() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        area = (1.0 / 4.0) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(sideLength, 2);
        cout << "Area: " << area << endl;
        // area = 1/4 * sqrt(5(5+2sqrt(5))) * sidelength^2
        
    }
    void findPerimeter() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        perimeter = 5 * sideLength;
        cout << "Perimeter: " << perimeter << endl;
        // perimeter = sideLength * 5
    }
    void menu() {
        int menuInput = 1;
        while (menuInput != 0) {
            cout << "\nPentagon" << endl;
            cout << "Find area               (1)" << endl;
            cout << "Find Perimeter          (2)" << endl;
            cout << "Output Stats            (3)" << endl;
            cout << "Return                  (0)" << endl;
            cout << "\nPlease make a selection now: ";
            cin >> menuInput;

            if (menuInput == 1) {
                findArea();
            }
            else if (menuInput == 2) {
                findPerimeter();
            }
            else if (menuInput == 3) {
                getShape();
            }
            else {
                return;
            }
        }
        
    }
};
/*
Hexagon class, handles cases of equilateral hexagons. 
*/
class hexagon : public shape{
public:
    string shapeName = "Hexagon";

    void findArea() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        area = ((3 * sqrt(3)) / 2) * pow(sideLength, 2);
        cout << "Area: " << area << endl;
        // area = ((3 * sqrt(3)) / 2) * sidelength^2
    }
    void findPerimeter() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        perimeter = 6 * sideLength;
        cout << "Perimeter: " << perimeter << endl;
        // perimeter = sideLength * 6
    }
    void menu() {
        int menuInput = 1;
        while (menuInput != 0) {
            cout << "\nHexagon" << endl;
            cout << "Find area               (1)" << endl;
            cout << "Find Perimeter          (2)" << endl;
            cout << "Output Stats            (3)" << endl;
            cout << "Return                  (0)" << endl;
            cout << "\nPlease make a selection now: ";
            cin >> menuInput;

            if (menuInput == 1) {
                findArea();
            }
            else if (menuInput == 2) {
                findPerimeter();
            }
            else if (menuInput == 3) {
                getShape();
            }
            else {
                return;
            }
        }
        
    }

};
/*
Octagon class, handles cases of equilateral octagons. 
*/
class octagon : public shape{
public:
    string shapeName = "Octagon";

    void findArea() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        area = 2 * pow(sideLength, 2) * (1 + sqrt(2));
        cout << "Area: " << area << endl;
        // area = 2sidelength^2(1 + sqrt(2))
    }
    void findPerimeter() {
        double userSide;

        cout << "\nPlease enter the Side Length: ";
        cin >> userSide;
        sideLength = userSide;
        perimeter = 8 * sideLength;
        cout << "Perimeter: " << perimeter << endl;
        // perimeter = sideLength * 8
    }
    void menu() {
        int menuInput = 1;
        while (menuInput != 0) {
            cout << "Octagon" << endl;
            cout << "Find area               (1)" << endl;
            cout << "Find Perimeter          (2)" << endl;
            cout << "Output Stats            (3)" << endl;
            cout << "Return                  (0)" << endl;
            cout << "\nPlease make a selection now: ";
            cin >> menuInput;

            if (menuInput == 1) {
                findArea();
            }
            else if (menuInput == 2) {
                findPerimeter();
            }
            else if (menuInput == 3) {
                getShape();
            }
            else {
                return;
            }
        }
        
    }
};


/*
Main function, handles main menu and calling respective shapes
to perform calculations. 
*/
int main()
{
    int userChoice = 1;
    cout << "Welcome to the geometry calculator" << endl;
    while (userChoice != 0) {
        
        cout << "\nHandle Circle           (1)" << endl;
        cout << "Handle Square           (2)" << endl;
        cout << "Handle Triangle         (3)" << endl;
        cout << "Handle Rectangle        (4)" << endl;
        cout << "Handle Pentagon         (5)" << endl;
        cout << "Handle Hexagon          (6)" << endl;
        cout << "Handle Octagon          (7)" << endl;
        cout << "Exit                    (0)" << endl;
        cout << "\nPlease make a selection now: " ;
        cin >> userChoice;


        if (userChoice == 1) {
            circle userCircle;
            userCircle.menu();
        }
        else if (userChoice == 2) {
            square userSquare;
            userSquare.menu();
        }
        else if (userChoice == 3) {
            triangle userTriangle;
            userTriangle.menu();
        }
        else if (userChoice == 4) {
            rectangle userRectangle;
            userRectangle.menu();

        }
        else if (userChoice == 5) {
            pentagon userPentagon;
            userPentagon.menu();
        }
        else if (userChoice == 6) {
            hexagon userHexagon;
            userHexagon.menu();
        }
        else if (userChoice == 7) {
            octagon userOctagon;
            userOctagon.menu();
        }

    };

    return 0;
}