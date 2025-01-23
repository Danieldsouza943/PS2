// Copyright 2024 Daniel Dsouza
#ifndef PENTA_HPP
#define PENTA_HPP

#include <SFML/Graphics.hpp>

class Penta : public sf::Drawable {
 public:
    Penta(double sideLength, int recursionDepth, double initialRotation = 0.0);

 private:
    double L;         // Side length of the base pentagon
    int N;            // Recursion depth
    double rotation;  // Initial rotation of the pentaflake

    // Correctly overriding the pure virtual draw() method from sf::Drawable
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void drawPentagon(sf::RenderTarget& target, sf::Vector2f position,
    double sideLength, int depth, double angle, sf::Color color) const;
};

#endif


