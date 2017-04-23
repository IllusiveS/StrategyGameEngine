//
// Created by wysockipatryk on 4/23/17.
//

#ifndef STRATEGYGAME_VECTOR2D_H
#define STRATEGYGAME_VECTOR2D_H


class Vector2D {
public:
	Vector2D(float x, float y);
	Vector2D();

public:
	float x;
	float y;

public:
	float Length();
	Vector2D Normalized();

	Vector2D operator-(const Vector2D& b) {
		Vector2D box(
				this->x + b.x,
		        this->y + b.y
		);
		return box;
	}
};


#endif //STRATEGYGAME_VECTOR2D_H
