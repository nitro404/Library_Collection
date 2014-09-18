#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

const Vector2 Vector2::Zero(0.0f, 0.0f);
const Vector2 Vector2::One(1.0f, 1.0f);

Vector2::Vector2             (float a, float b)        : x(a), y(b) { }
Vector2::Vector2             (const Vector2 & v)       : x(v.x), y(v.y) { }
Vector2::Vector2             (const Vector3 & v)       : x(v.x), y(v.y) { }
Vector2::Vector2             (const Vector4 & v)       : x(v.x), y(v.y) { }
Vector2 &Vector2::operator = (const Vector2 & v)       { x = v.x; y = v.y; return *this; }
Vector2 &Vector2::operator = (const Vector3 & v)       { x = v.x; y = v.y; return *this; }
Vector2 &Vector2::operator = (const Vector4 & v)       { x = v.x; y = v.y; return *this; }
Vector2::~Vector2            ()                        { }

Vector2 Vector2::operator  * (const float & c)   const { return Vector2(x * c, y * c); }
Vector2 Vector2::operator  * (const Vector2 & v) const { return Vector2(x * v.x, y * v.y); }
Vector2 Vector2::operator  * (const Vector3 & v) const { return Vector2(x * v.x, y * v.y); }
Vector2 Vector2::operator  * (const Vector4 & v) const { return Vector2(x * v.x, y * v.y); }

void Vector2::operator    *= (const float & c)		   { x *= c; y *= c; }
void Vector2::operator    *= (const Vector2 & v)       { x *= v.x; y *= v.y; }
void Vector2::operator    *= (const Vector3 & v)       { x *= v.x; y *= v.y; }
void Vector2::operator    *= (const Vector4 & v)       { x *= v.x; y *= v.y; }

Vector2 Vector2::operator  / (const float & c)   const { return Vector2(x / c, y / c); }
Vector2 Vector2::operator  / (const Vector2 & v) const { return Vector2(x / v.x, y / v.y); }
Vector2 Vector2::operator  / (const Vector3 & v) const { return Vector2(x / v.x, y / v.y); }
Vector2 Vector2::operator  / (const Vector4 & v) const { return Vector2(x / v.x, y / v.y); }

void Vector2::operator    /= (const float & c)         { x /= c; y /= c; }
void Vector2::operator    /= (const Vector2 & v)       { x /= v.x; y /= v.y; }
void Vector2::operator    /= (const Vector3 & v)       { x /= v.x; y /= v.y; }
void Vector2::operator    /= (const Vector4 & v)       { x /= v.x; y /= v.y; }

Vector2 Vector2::operator  + (const float & c)   const { return Vector2(x + c, y + c); }
Vector2 Vector2::operator  + (const Vector2 & v) const { return Vector2(x + v.x, y + v.y); }
Vector2 Vector2::operator  + (const Vector3 & v) const { return Vector2(x + v.x, y + v.y); }
Vector2 Vector2::operator  + (const Vector4 & v) const { return Vector2(x + v.x, y + v.y); }

void Vector2::operator    += (const float & c)         { x += c; y += c; }
void Vector2::operator    += (const Vector2 & v)       { x += v.x; y += v.y; }
void Vector2::operator    += (const Vector3 & v)       { x += v.x; y += v.y; }
void Vector2::operator    += (const Vector4 & v)       { x += v.x; y += v.y; }

Vector2 Vector2::operator  - ()                  const { return Vector2(-x, -y); }

Vector2 Vector2::operator  - (const float & c)   const { return Vector2(x - c, y - c); }
Vector2 Vector2::operator  - (const Vector2 & v) const { return Vector2(x - v.x, y - v.y); }
Vector2 Vector2::operator  - (const Vector3 & v) const { return Vector2(x - v.x, y - v.y); }
Vector2 Vector2::operator  - (const Vector4 & v) const { return Vector2(x - v.x, y - v.y); }

void Vector2::operator    -= (const float & c)         { x -= c; y -= c; }
void Vector2::operator    -= (const Vector2 & v)       { x -= v.x; y -= v.y; }
void Vector2::operator    -= (const Vector3 & v)       { x -= v.x; y -= v.y; }
void Vector2::operator    -= (const Vector4 & v)       { x -= v.x; y -= v.y; }

bool Vector2::operator    == (const Vector2 & v)       { return x == v.x && y == v.y; }
bool Vector2::operator    != (const Vector2 & v)       { return x != v.x || y != v.y; }

float Vector2::length		 ()					 const { return sqrt((x * x) + (y * y)); }
float Vector2::dot           (const Vector2 & v) const { return (x * v.x) + (y * v.y); }
void Vector2::normalize		 ()					       { float l = length(); if(l == 0) { x = y = 0.0f; } else { x /= l; y /= l; } }
Vector2 Vector2::normalized  ()					 const { float l = length(); if(l == 0) { return Vector2(0.0f, 0.0f); } else { return Vector2(x / l, y / l); } }
