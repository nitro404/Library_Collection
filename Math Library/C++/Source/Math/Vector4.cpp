#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

const Vector4 Vector4::Zero(0.0f, 0.0f, 0.0f, 0.0f);
const Vector4 Vector4::One(1.0f, 1.0f, 1.0f, 1.0f);

Vector4::Vector4             (float a, float b, float c, float d) : x(a), y(b), z(c), w(d)  { }
Vector4::Vector4             (const Vector2 & v)       : x(v.x), y(v.y), z(0), w(0)     { }
Vector4::Vector4             (const Vector3 & v)       : x(v.x), y(v.y), z(v.z), w(0)   { }
Vector4::Vector4             (const Vector4 & v)       : x(v.x), y(v.y), z(v.z), w(v.w) { }
Vector4 &Vector4::operator = (const Vector2 & v)       { x = v.x; y = v.y; z = 0; w = 0; return *this; }
Vector4 &Vector4::operator = (const Vector3 & v)       { x = v.x; y = v.y; z = v.z; w = 0; return *this; }
Vector4 &Vector4::operator = (const Vector4 & v)       { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
Vector4::~Vector4            ()                        { }

Vector4 Vector4::operator  * (const float & c)   const { return Vector4(x * c, y * c, z * c, w * c); }
Vector4 Vector4::operator  * (const Vector2 & v) const { return Vector4(x * v.x, y * v.y, z, w); }
Vector4 Vector4::operator  * (const Vector3 & v) const { return Vector4(x * v.x, y * v.y, z * v.z, w); }
Vector4 Vector4::operator  * (const Vector4 & v) const { return Vector4(x * v.x, y * v.y, z * v.z, w * v.w); }

void Vector4::operator    *= (const float & c)         { x *= c; y *= c; z *= c; w *= c; }
void Vector4::operator    *= (const Vector2 & v)       { x *= v.x; y *= v.y; }
void Vector4::operator    *= (const Vector3 & v)       { x *= v.x; y *= v.y; z *= v.z; }
void Vector4::operator    *= (const Vector4 & v)       { x *= v.x; y *= v.y; z *= v.z; w *= v.w; }

Vector4 Vector4::operator  / (const float & c)   const { return Vector4(x / c, y / c, z / c, w / c); }
Vector4 Vector4::operator  / (const Vector2 & v) const { return Vector4(x / v.x, y / v.y, z, w); }
Vector4 Vector4::operator  / (const Vector3 & v) const { return Vector4(x / v.x, y / v.y, z / v.z, w); }
Vector4 Vector4::operator  / (const Vector4 & v) const { return Vector4(x / v.x, y / v.y, z / v.z, w / v.w); }

void Vector4::operator    /= (const float & c)         { x /= c; y /= c; z /= c; w /= c; }
void Vector4::operator    /= (const Vector2 & v)       { x /= v.x; y /= v.y; }
void Vector4::operator    /= (const Vector3 & v)       { x /= v.x; y /= v.y; z /= v.z; }
void Vector4::operator    /= (const Vector4 & v)       { x /= v.x; y /= v.y; z /= v.z; w /= v.w; }

Vector4 Vector4::operator  + (const float & c)   const { return Vector4(x + c, y + c, z + c, w + c); }
Vector4 Vector4::operator  + (const Vector2 & v) const { return Vector4(x + v.x, y + v.y, z, w); }
Vector4 Vector4::operator  + (const Vector3 & v) const { return Vector4(x + v.x, y + v.y, z + v.z, w); }
Vector4 Vector4::operator  + (const Vector4 & v) const { return Vector4(x + v.x, y + v.y, z + v.z, w + v.w); }

void Vector4::operator    += (const float & c)         { x += c; y += c; z += c; w += c; }
void Vector4::operator    += (const Vector2 & v)       { x += v.x; y += v.y; }
void Vector4::operator    += (const Vector3 & v)       { x += v.x; y += v.y; z += v.z; }
void Vector4::operator    += (const Vector4 & v)       { x += v.x; y += v.y; z += v.z; w += v.w; }

Vector4 Vector4::operator  - ()                  const { return Vector4(-x, -y, -z, -w); }

Vector4 Vector4::operator  - (const float & c)   const { return Vector4(x - c, y - c, z - c, w - c); }
Vector4 Vector4::operator  - (const Vector2 & v) const { return Vector4(x - v.x, y - v.y, z, w); }
Vector4 Vector4::operator  - (const Vector3 & v) const { return Vector4(x - v.x, y - v.y, z - v.z, w); }
Vector4 Vector4::operator  - (const Vector4 & v) const { return Vector4(x - v.x, y - v.y, z - v.z, w - v.w); }

void Vector4::operator    -= (const float & c)         { x -= c; y -= c; z -= c; w -= c; }
void Vector4::operator    -= (const Vector2 & v)       { x -= v.x; y -= v.y; }
void Vector4::operator    -= (const Vector3 & v)       { x -= v.x; y -= v.y; z -= v.z; }
void Vector4::operator    -= (const Vector4 & v)       { x -= v.x; y -= v.y; z -= v.z; w -= v.w; }

bool Vector4::operator    == (const Vector4 & v)       { return x == v.x && y == v.y && z == v.z && w == v.w; }
bool Vector4::operator    != (const Vector4 & v)       { return x != v.x || y != v.y || z != v.z || w != v.w; }

float Vector4::length		 ()					 const { return sqrt((x * x) + (y * y) + (z * z) + (w * w)); }
float Vector4::dot           (const Vector4 & v) const { return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w); }
void Vector4::normalize		 ()						   { float l = length(); if(l == 0) { x = y = z = w = 0.0f; } else { x /= l; y /= l; z /= l; w /= l; } }
Vector4 Vector4::normalized  ()					 const { float l = length(); if(l == 0) { return Vector4(0.0f, 0.0f, 0.0f, 0.0f); } else { return Vector4(x / l, y / l, z / l, w / l); } }
