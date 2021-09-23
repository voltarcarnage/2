#include "headers/class.h"
#include "gtest/gtest.h"

TEST(CurveConctructor, DefaultConstructor)
{
  Line::Curve point;
  ASSERT_EQ(0, point.getA());
  ASSERT_EQ(0, point.getL());
}

TEST(CurveMethods, Y_Value)
{
  Line::Curve point(4,7);
  double x = -1.809, error = 0.001;
  ASSERT_NEAR(1.216,point.getY(x),error);
}

TEST(CurveMethods, Distance)
{
  Line::Curve point(4,7);
  double phi = 60.0 ,error = 0.001;
  ASSERT_NEAR(15,point.getDistance(phi),error);
}

TEST(CurveMethods, RadusA)
{
  Line::Curve point(4,7);
  double error = 0.001;
  ASSERT_NEAR(17.285, point.getRa(), error);
}

TEST(CurveMethods, RadusC)
{
  Line::Curve point(4,7);
  double error = 0.001;
  ASSERT_NEAR(1.285, point.getRc(), error);
}

TEST(CurveMethods, RadusO)
{
  Line::Curve point(4,7);
  double error = 0.001;
  ASSERT_NEAR(5.026, point.getRo(), error);
}

TEST(CurveMethods, Area)
{
  Line::Curve point(1,123);
  double error = 0.1;
  ASSERT_NEAR(15202.4, point.getSquare(), error);
}

TEST(CurveMethods, InflectionPoints1)
{
  Line::Curve point(1,2);
  double error = 0.1;
  ASSERT_NEAR(2.0, point.getInflectPoints1(), error);
}

TEST(CurveMethods, InflectionPoints2)
{
  Line::Curve point(19,12);
  double error = 0.1;
  ASSERT_NEAR(-1.0, point.getInflectPoints2(), error);
}

int main()
{
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
