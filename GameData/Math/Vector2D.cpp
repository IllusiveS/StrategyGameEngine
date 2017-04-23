//
// Created by wysockipatryk on 4/23/17.
//

#include "Vector2D.h"

float Vector2D::Length() {
	return 0;
}

Vector2D Vector2D::Normalized() {
	return Vector2D();
}

Vector2D::Vector2D(float x, float y) : x(x), y(y){

}

Vector2D::Vector2D() : x(0), y(0){

}
