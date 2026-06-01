// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

const double PI = 3.1415;

double ropeGap(double earth_radius_km) {
    const double R_earth_m = earth_radius_km * 1000.0;

    Circle earth(R_earth_m);
    const double old_ference = earth.getFerence();
    const double new_ference = old_ference + 1.0;

    Circle extended(0.0);
    extended.setFerence(new_ference);

    return extended.getRadius() - earth.getRadius();
}

double poolConcreteCost(double pool_radius_m, double walkway_width_m,
    double concrete_price_per_m2) {
    Circle inner(pool_radius_m);
    Circle outer(pool_radius_m + walkway_width_m);

    double walkway_area = outer.getArea() - inner.getArea();
    return walkway_area * concrete_price_per_m2;
}

double poolFenceCost(double pool_radius_m, double walkway_width_m,
    double fence_price_per_m) {
    Circle outer(pool_radius_m + walkway_width_m);
    return outer.getFerence() * fence_price_per_m;
}

double poolTotalCost(double pool_radius_m, double walkway_width_m,
    double concrete_price_per_m2, double fence_price_per_m) {
    return poolConcreteCost(pool_radius_m, walkway_width_m, concrete_price_per_m2)
        + poolFenceCost(pool_radius_m, walkway_width_m, fence_price_per_m);
}
