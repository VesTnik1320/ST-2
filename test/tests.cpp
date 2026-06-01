// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.1415;
const double EPS = 1e-6;

TEST(CircleTest, CanConstructionPositiveRadiusCheck) {
    Circle c(13.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 13.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 13.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 169.0, EPS);
}

TEST(CircleTest, CanConstructionZeroRadiusCheck) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, CanSetPositiveRadiusCheck) {
    Circle c(3.0);
    c.setRadius(6.3);
    EXPECT_DOUBLE_EQ(c.getRadius(), 6.3);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 6.3, EPS);
    EXPECT_NEAR(c.getArea(), PI * 6.3 * 6.3, EPS);
}

TEST(CircleTest, CanSetZeroRadiusCheck) {
    Circle c(7.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, CanSetFerencePositiveCheck) {
    Circle c(3.0);
    double f = 23.0;
    c.setFerence(f);
    double expected_r = f / (2 * PI);
    EXPECT_NEAR(c.getRadius(), expected_r, EPS);
    EXPECT_NEAR(c.getFerence(), f, EPS);
    EXPECT_NEAR(c.getArea(), PI * expected_r * expected_r, EPS);
}

TEST(CircleTest, CanSetFerenceZeroCheck) {
    Circle c(7.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, CanSetAreaPositiveCheck) {
    Circle c(3.0);
    double a = 52.0;
    c.setArea(a);
    double expected_r = std::sqrt(a / PI);
    EXPECT_NEAR(c.getRadius(), expected_r, EPS);
    EXPECT_NEAR(c.getArea(), a, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * expected_r, EPS);
}

TEST(CircleTest, CanSetAreaZeroCheck) {
    Circle c(52.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, CanSetAreaNegativeCheck) {
    Circle c(7.0);
    double a = -33.0;
    c.setArea(a);
    EXPECT_TRUE(std::isnan(c.getRadius()));
    EXPECT_TRUE(std::isnan(c.getFerence()));
    EXPECT_DOUBLE_EQ(c.getArea(), a);
}

TEST(CircleTest, CanGetRadiusAfterSetFerenceCheck) {
    Circle c(7.0);
    c.setFerence(23.0);
    double expected_r = 23.0 / (2 * PI);
    EXPECT_NEAR(c.getRadius(), expected_r, EPS);
}

TEST(CircleTest, CanGetAreaAfterSetFerenceCheck) {
    Circle c(7.0);
    c.setFerence(23.0);
    double r = 23.0 / (2 * PI);
    double expected_a = PI * r * r;
    EXPECT_NEAR(c.getArea(), expected_a, EPS);
}

TEST(CircleTest, CanGetFerenceAfterSetAreaCheck) {
    Circle c(7.0);
    c.setArea(33.0);
    double r = std::sqrt(33.0 / PI);
    double expected_f = 2 * PI * r;
    EXPECT_NEAR(c.getFerence(), expected_f, EPS);
}

TEST(CircleTest, CanGetRadiusAfterSetAreaCheck) {
    Circle c(7.0);
    c.setArea(33.0);
    double expected_r = std::sqrt(33.0 / PI);
    EXPECT_NEAR(c.getRadius(), expected_r, EPS);
}

TEST(CircleTest, CanConsistencyAfterMultipleSetsCheck) {
    Circle c(7.0);
    c.setRadius(3.0);
    c.setFerence(9.0);
    double expected_r = 9.0 / (2 * PI);
    EXPECT_NEAR(c.getRadius(), expected_r, EPS);
    c.setArea(13.0);
    double expected_r2 = std::sqrt(13.0 / PI);
    EXPECT_NEAR(c.getRadius(), expected_r2, EPS);
}

TEST(CircleTest, CheckLargeRadius) {
    double r = 6e9;
    Circle c(r);
    EXPECT_DOUBLE_EQ(c.getRadius(), r);
    EXPECT_NEAR(c.getFerence(), 2 * PI * r, EPS);
    EXPECT_NEAR(c.getArea(), PI * r * r, EPS);
}

TEST(CircleTest, CheckSmallRadius) {
    double r = 3e-7;
    Circle c(r);
    EXPECT_DOUBLE_EQ(c.getRadius(), r);
    EXPECT_NEAR(c.getFerence(), 2 * PI * r, EPS);
    EXPECT_NEAR(c.getArea(), PI * r * r, EPS);
}

TEST(CircleTest, CheckPrecisionTest) {
    double r = 2.281337;
    Circle c(r);
    EXPECT_NEAR(c.getFerence(), 2 * PI * r, EPS);
    EXPECT_NEAR(c.getArea(), PI * r * r, EPS);
}

TEST(RopeGapTest, CheckEarthRadius) {
    double earth_radius_km = 6371.0;
    double gap = ropeGap(earth_radius_km);
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expected_gap, EPS);
}

TEST(RopeGapTest, VeryLargeRadius) {
    double gap = ropeGap(3e9);
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expected_gap, EPS);
}

TEST(PoolCostTest, CanConcreteCostBasicCheck) {
    double r = 6.0, w = 3.0, price = 13.0;
    double cost = poolConcreteCost(r, w, price);
    double expected_area = PI * ((r + w) * (r + w) - r * r);
    double expected_cost = expected_area * price;
    EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, CanConcreteCostZeroPoolRadiusCheck) {
    double r = 0.0, w = 3.0, price = 23.0;
    double cost = poolConcreteCost(r, w, price);
    double expected_area = PI * w * w;
    double expected_cost = expected_area * price;
    EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, CanFenceCostBasicCheck) {
    double r = 6.0, w = 7.0, price = 23.0;
    double cost = poolFenceCost(r, w, price);
    double expected_length = 2 * PI * (r + w);
    double expected_cost = expected_length * price;
    EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, CanFenceCostZeroPoolRadiusCheck) {
    double r = 0.0, w = 6.7, price = 23.0;
    double cost = poolFenceCost(r, w, price);
    double expected_length = 2 * PI * w;
    double expected_cost = expected_length * price;
    EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, CanTotalCostBasicCheck) {
    double r = 6.0, w = 3.0, concrete_price = 13.0, fence_price = 23.0;
    double total = poolTotalCost(r, w, concrete_price, fence_price);
    double expected_concrete = poolConcreteCost(r, w, concrete_price);
    double expected_fence = poolFenceCost(r, w, fence_price);
    double expected_total = expected_concrete + expected_fence;
    EXPECT_NEAR(total, expected_total, EPS);
}
