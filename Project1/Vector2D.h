#ifndef _VECTOR_2D_
#define _VECTOR_2D_

#include <math.h>

class Vector2D
{
public:
	Vector2D(float x, float y) : m_x(x), m_y(y) {}
	float getX() { return m_x; }
	float getY() { return m_y; }
	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	//重载+运算符，使用：Vector2D v3 = v1 + v2;  
	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}

	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;
		return v1;
	}

	//重载*运算符
	Vector2D operator*(float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;
		return *this;
	}

	//重载-运算符
	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}

	//重载/运算符
	Vector2D operator/(float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}
	
	//正常化
	void normalize()
	{
		float l = length();
		if (l > 0) // we never want to attempt to divide by 0
		{
			(*this) *= 1 / l;
		}
	}

private:
	float m_x;
	float m_y;
};

#endif //_VECTOR_2D_