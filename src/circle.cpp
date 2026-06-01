// Copyright 2025 UNN-CS
#include "circle.h"
#include <cmath>

const double PI = 3.1415;

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2.0 * PI * radius;
    area = PI * radius * radius;
}

void Circle::setFerence(double f) {
    ference = f;
    radius = ference / (2.0 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
    area = a;
    if (area < 0.0) {
        radius = std::nan("");
        ference = std::nan("");
    } else {
        radius = std::sqrt(area / PI);
        ference = 2.0 * PI * radius;
    }
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
