#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

class Vector2;
class Vector4;

class Vector3 {
public:
	Vector3             (float a = 0, float b = 0, float c = 0);
	Vector3             (const Vector2 & v);
	Vector3             (const Vector3 & v);
	Vector3             (const Vector4 & v);
	Vector3 &operator = (const Vector2 & v);
	Vector3 &operator = (const Vector3 & v);
	Vector3 &operator = (const Vector4 & v);
	virtual ~Vector3();

	Vector3 operator  * (const float & c)   const;
	Vector3 operator  * (const Vector2 & v) const;
	Vector3 operator  * (const Vector3 & v) const;
	Vector3 operator  * (const Vector4 & v) const;

	void operator    *= (const float & c);
	void operator    *= (const Vector2 & v);
	void operator    *= (const Vector3 & v);
	void operator    *= (const Vector4 & v);

	Vector3 operator  / (const float & c)   const;
	Vector3 operator  / (const Vector2 & v) const;
	Vector3 operator  / (const Vector3 & v) const;
	Vector3 operator  / (const Vector4 & v) const;

	void operator    /= (const float & c);
	void operator    /= (const Vector2 & v);
	void operator    /= (const Vector3 & v);
	void operator    /= (const Vector4 & v);

	Vector3 operator  + (const float & c)   const;
	Vector3 operator  + (const Vector2 & v) const;
	Vector3 operator  + (const Vector3 & v) const;
	Vector3 operator  + (const Vector4 & v) const;

	void operator    += (const float & c);
	void operator    += (const Vector2 & v);
	void operator    += (const Vector3 & v);
	void operator    += (const Vector4 & v);

	Vector3 operator  - () const;

	Vector3 operator  - (const float & c)   const;
	Vector3 operator  - (const Vector2 & v) const;
	Vector3 operator  - (const Vector3 & v) const;
	Vector3 operator  - (const Vector4 & v) const;

	void operator    -= (const float & c);
	void operator    -= (const Vector2 & v);
	void operator    -= (const Vector3 & v);
	void operator    -= (const Vector4 & v);

	bool operator    == (const Vector3 & v);
	bool operator    != (const Vector3 & v);

	float length() const;
	float dot(const Vector3 & v) const;
	Vector3 cross(const Vector3 & v) const;
	void normalize();
	Vector3 normalized() const;

public:
	static const Vector3 Zero;
	static const Vector3 One;

	float x, y, z;
};

#endif // VECTOR3_H
