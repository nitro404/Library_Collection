#ifndef VECTOR4_H
#define VECTOR4_H

#include <math.h>

class Vector2;
class Vector3;

class Vector4 {
public:
	Vector4                    (float a = 0, float b = 0, float c = 0, float d = 0);
	Vector4                    (const Vector2 & v);
	Vector4                    (const Vector3 & v);
	Vector4                    (const Vector4 & v);
	Vector4 &operator = (const Vector2 & v);
	Vector4 &operator = (const Vector3 & v);
	Vector4 &operator = (const Vector4 & v);
	virtual ~Vector4();

	Vector4 operator  * (const float & c)   const;
	Vector4 operator  * (const Vector2 & v) const;
	Vector4 operator  * (const Vector3 & v) const;
	Vector4 operator  * (const Vector4 & v) const;

	void operator    *= (const float & c);
	void operator    *= (const Vector2 & v);
	void operator    *= (const Vector3 & v);
	void operator    *= (const Vector4 & v);

	Vector4 operator  / (const float & c)   const;
	Vector4 operator  / (const Vector2 & v) const;
	Vector4 operator  / (const Vector3 & v) const;
	Vector4 operator  / (const Vector4 & v) const;

	void operator    /= (const float & c);
	void operator    /= (const Vector2 & v);
	void operator    /= (const Vector3 & v);
	void operator    /= (const Vector4 & v);

	Vector4 operator  + (const float & c)   const;
	Vector4 operator  + (const Vector2 & v) const;
	Vector4 operator  + (const Vector3 & v) const;
	Vector4 operator  + (const Vector4 & v) const;

	void operator    += (const float & c);
	void operator    += (const Vector2 & v);
	void operator    += (const Vector3 & v);
	void operator    += (const Vector4 & v);

	Vector4 operator  - () const;

	Vector4 operator  - (const float & c)   const;
	Vector4 operator  - (const Vector2 & v) const;
	Vector4 operator  - (const Vector3 & v) const;
	Vector4 operator  - (const Vector4 & v) const;

	void operator    -= (const float & c);
	void operator    -= (const Vector2 & v);
	void operator    -= (const Vector3 & v);
	void operator    -= (const Vector4 & v);

	bool operator    == (const Vector4 & v);
	bool operator    != (const Vector4 & v);

	float length() const;
	float dot(const Vector4 & v) const;
	void normalize();
	Vector4 normalized() const;

public:
	static const Vector4 Zero;
	static const Vector4 One;

	float x, y, z, w;
};

#endif // VECTOR4_H
