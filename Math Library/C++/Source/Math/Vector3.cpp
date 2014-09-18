#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

const Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::One(1.0f, 1.0f, 1.0f);

Vector3::Vector3             (float a, float b, float c) : x(a), y(b), z(c)  { }
Vector3::Vector3             (const Vector2 & v)       : x(v.x), y(v.y), z(0)   { }
Vector3::Vector3             (const Vector3 & v)       : x(v.x), y(v.y), z(v.z) { }
Vector3::Vector3             (const Vector4 & v)       : x(v.x), y(v.y), z(v.z) { }
Vector3 &Vector3::operator = (const Vector2 & v)       { x = v.x; y = v.y; z = 0; return *this; }
Vector3 &Vector3::operator = (const Vector3 & v)       { x = v.x; y = v.y; z = v.z; return *this; }
Vector3 &Vector3::operator = (const Vector4 & v)       { x = v.x; y = v.y; z = v.z; return *this; }
Vector3::~Vector3            ()                        { }

Vector3 Vector3::operator  * (const float & c)   const { return Vector3(x * c, y * c, z * c); }
Vector3 Vector3::operator  * (const Vector2 & v) const { return Vector3(x * v.x, y * v.y, z); }
Vector3 Vector3::operator  * (const Vector3 & v) const { return Vector3(x * v.x, y * v.y, z * v.z); }
Vector3 Vector3::operator  * (const Vector4 & v) const { return Vector3(x * v.x, y * v.y, z * v.z); }

void Vector3::operator    *= (const float & c)         { x *= c; y *= c; z *= c; }
void Vector3::operator    *= (const Vector2 & v)       { x *= v.x; y *= v.y; }
void Vector3::operator    *= (const Vector3 & v)       { x *= v.x; y *= v.y; z *= v.z; }
void Vector3::operator    *= (const Vector4 & v)       { x *= v.x; y *= v.y; z *= v.z; }

Vector3 Vector3::operator  / (const float & c)   const { return Vector3(x / c, y / c, z / c); }
Vector3 Vector3::operator  / (const Vector2 & v) const { return Vector3(x / v.x, y / v.y, z); }
Vector3 Vector3::operator  / (const Vector3 & v) const { return Vector3(x / v.x, y / v.y, z / v.z); }
Vector3 Vector3::operator  / (const Vector4 & v) const { return Vector3(x / v.x, y / v.y, z / v.z); }

void Vector3::operator    /= (const float & c)         { x /= c; y /= c; z /= c; }
void Vector3::operator    /= (const Vector2 & v)       { x /= v.x; y /= v.y; }
void Vector3::operator    /= (const Vector3 & v)       { x /= v.x; y /= v.y; z /= v.z; }
void Vector3::operator    /= (const Vector4 & v)       { x /= v.x; y /= v.y; z /= v.z; }

Vector3 Vector3::operator  + (const float & c)   const { return Vector3(x + c, y + c, z + c); }
Vector3 Vector3::operator  + (const Vector2 & v) const { return Vector3(x + v.x, y + v.y, z); }
Vector3 Vector3::operator  + (const Vector3 & v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
Vector3 Vector3::operator  + (const Vector4 & v) const { return Vector3(x + v.x, y + v.y, z + v.z); }

void Vector3::operator    += (const float & c)         { x += c; y += c; z += c; }
void Vector3::operator    += (const Vector2 & v)       { x += v.x; y += v.y; }
void Vector3::operator    += (const Vector3 & v)       { x += v.x; y += v.y; z += v.z; }
void Vector3::operator    += (const Vector4 & v)       { x += v.x; y += v.y; z += v.z; }

Vector3 Vector3::operator  - ()                  const { return Vector3(-x, -y, -z); }

Vector3 Vector3::operator  - (const float & c)   const { return Vector3(x - c, y - c, z - c); }
Vector3 Vector3::operator  - (const Vector2 & v) const { return Vector3(x - v.x, y - v.y, z); }
Vector3 Vector3::operator  - (const Vector3 & v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
Vector3 Vector3::operator  - (const Vector4 & v) const { return Vector3(x - v.x, y - v.y, z - v.z); }

void Vector3::operator    -= (const float & c)         { x -= c; y -= c; z -= c; }
void Vector3::operator    -= (const Vector2 & v)       { x -= v.x; y -= v.y; }
void Vector3::operator    -= (const Vector3 & v)       { x -= v.x; y -= v.y; z -= v.z; }
void Vector3::operator    -= (const Vector4 & v)       { x -= v.x; y -= v.y; z -= v.z; }

bool Vector3::operator    == (const Vector3 & v)       { return x == v.x && y == v.y && z == v.z; }
bool Vector3::operator    != (const Vector3 & v)       { return x != v.x || y != v.y || z != v.z; }

float Vector3::length		 ()					 const { return sqrt((x * x) + (y * y) + (z * z)); }
float Vector3::dot           (const Vector3 & v) const { return (x * v.x) + (y * v.y) + (z * v.z); }
Vector3 Vector3::cross       (const Vector3 & v) const { return Vector3((y * v.z) - (z * v.y), (z * v.x) - (x * v.z), (x * v.y) - (y * v.x)); }
void Vector3::normalize		 ()						   { float l = length(); if(l == 0) { x = y = z = 0.0f; } else { x /= l; y /= l; z /= l; } }
Vector3 Vector3::normalized  ()					 const { float l = length(); if(l == 0) { return Vector3(0.0f, 0.0f, 0.0f); } else { return Vector3(x / l, y / l, z / l); } }
