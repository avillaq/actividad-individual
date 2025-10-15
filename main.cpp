#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Vector2D {
private:
	double x;
	double y;

public:
	Vector2D(const double x0,const double y0) : x(x0), y(y0) {}
    Vector2D operator+(const Vector2D &v) {     // operator +
        return Vector2D(x + v.getX(), y + v.getY());
    }
    
	double getX() const {  
		return x;
	}

	double getY() const {
		return y;
	}
	
	void mostrarVector () const { // const
	    cout << "(" << x << ", " << y << ")\n";
	}

	friend double calcularProductoPunto(Vector2D &v1, Vector2D &v2); // friend
};

double calcularProductoPunto(Vector2D &v1, Vector2D &v2) { // friend
    double x_final = v1.getX()*v2.getX();
    double y_final = v1.getY()*v2.getY();
	return x_final + y_final;
}

inline double calcularMagnitud(Vector2D &v) { // inline
    double x = v.getX();
    double y = v.getY();
    return sqrt(x*x + y*y);
}

int main() {
	Vector2D vector1(2,6);
	Vector2D vector2(5,10);
	
	cout<< " -- Vectores --" << "\n";
	cout<< "vector1 -> "; vector1.mostrarVector();
	cout<< "vector2 -> "; vector2.mostrarVector();
	
	cout<< "friend: producto punto -> " << calcularProductoPunto(vector1, vector2) << "\n";
	cout<< "inline: magnitud -> " << calcularMagnitud(vector1) << "\n";
	
	Vector2D vector3 = vector1 + vector2;
	cout << "operator+: la suma de los vectores -> "; vector3.mostrarVector();
	
	// lambda
	double umbral = 50.5; 
	double magnitud = calcularMagnitud(vector3);
	auto supera = [] (double mag, double umb) { return mag > umb; };
	string resp = supera(magnitud, umbral) ? "SI" : "NO";
	
	cout << "lambda: la magnitud " << magnitud << " " << resp << " supera el umbral " << umbral << "\n";

	return 0;
}
