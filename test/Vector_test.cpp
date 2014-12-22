#include <Vector.h>
#include <gtest/gtest.h>

typedef Vector<double, 3> Vector3d;
typedef Vector<double, 4> Vector4d;

class Vector_test : public testing::Test {
public:
	Vector3d v;

	virtual void SetUp() {
		v = Vector3d(1, 2, 3);
	}

};

TEST_F(Vector_test, testAccessors)
{
	ASSERT_EQ(1, v[0]);
	ASSERT_EQ(2, v[1]);
	ASSERT_EQ(3, v[2]);
}

TEST_F(Vector_test, testAssignment)
{
	Vector3d w = v;

	ASSERT_EQ(1, w[0]);
	ASSERT_EQ(2, w[1]);
	ASSERT_EQ(3, w[2]);
}

TEST_F(Vector_test, testEquals)
{
	Vector3d v2(1, 2, 3);
	Vector3d w(3, 2, 1);

	ASSERT_EQ(v, v2);
	ASSERT_EQ(v, v2);
	ASSERT_EQ(v2, v);
	ASSERT_NE(v, w);
	ASSERT_NE(w, v);
}

TEST_F(Vector_test, testPlus)
{
	Vector3d w(4, 5, 6);
	Vector3d u = v + w;
	ASSERT_EQ(5, u[0]);
	ASSERT_EQ(7, u[1]);
	ASSERT_EQ(9, u[2]);
}

TEST_F(Vector_test, testDot)
{
	Vector3d w(4, 5, 6);
	ASSERT_EQ(32.0, dot(v, w));
}
