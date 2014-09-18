#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

class Vector3;
class Vector4;

class Vector2 {
public:
	Vector2             (float a = 0, float b = 0);
	Vector2             (const Vector2 & v);
	Vector2             (const Vector3 & v);
	Vector2             (const Vector4 & v);
	Vector2 &operator = (const Vector2 & v);
	Vector2 &operator = (const Vector3 & v);
	Vector2 &operator = (const Vector4 & v);
	virtual ~Vector2();

	Vector2 operator  * (const float & c)   const;
	Vector2 operator  * (const Vector2 & v) const;
	Vector2 operator  * (const Vector3 & v) const;
	Vector2 operator  * (const Vector4 & v) const;

	void operator    *= (const float & c);
	void operator    *= (const Vector2 & v);
	void operator    *= (const Vector3 & v);
	void operator    *= (const Vector4 & v);

	Vector2 operator  / (const float & c)   const;
	Vector2 operator  / (const Vector2 & v) const;
	Vector2 operator  / (const Vector3 & v) const;
	Vector2 operator  / (const Vector4 & v) const;

	void operator    /= (const float & c);
	void operator    /= (const Vector2 & v);
	void operator    /= (const Vector3 & v);
	void operator    /= (const Vector4 & v);

	Vector2 operator  + (const float & c)   const;
	Vector2 operator  + (const Vector2 & v) const;
	Vector2 operator  + (const Vector3 & v) const;
	Vector2 operator  + (const Vector4 & v) const;

	void operator    += (const float & c);
	void operator    += (const Vector2 & v);
	void operator    += (const Vector3 & v);
	void operator    += (const Vector4 & v);

	Vector2 operator  - () const;

	Vector2 operator  - (const float & c)   const;
	Vector2 operator  - (const Vector2 & v) const;
	Vector2 operator  - (const Vector3 & v) const;
	Vector2 operator  - (const Vector4 & v) const;

	void operator    -= (const float & c);
	void operator    -= (const Vector2 & v);
	void operator    -= (const Vector3 & v);
	void operator    -= (const Vector4 & v);

	bool operator    == (const Vector2 & v);
	bool operator    != (const Vector2 & v);

	float length() const;
	float dot(const Vector2 & v) const;
	void normalize();
	Vector2 normalized() const;

public:
	static const Vector2 Zero;
	static const Vector2 One;

	float x, y;
};

#endif // VECTOR2_H
