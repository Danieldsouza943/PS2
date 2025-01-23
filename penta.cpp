// Copyright 2024 Daniel Dsouza
#include "penta.hpp"
#include <cmath>

// Define the golden ratio
const double PHI = (1 + std::sqrt(5)) / 2;

// Constructor
Penta::Penta(double sideLength, int recursionDepth, double initialRotation)
    : L(sideLength), N(recursionDepth), rotation(initialRotation) {}

// Overriding the draw() method from sf::Drawable
void Penta::draw(sf::RenderTarget& target, sf::RenderStates /*states*/) const {
    // Initial call to draw the pentaflake starting from the center of the window
    drawPentagon(target, sf::Vector2f(target.getSize().x / 2,
    target.getSize().y / 2), L, N, rotation, sf::Color::Blue);
}

// Recursive draw function for pentagons
void Penta::drawPentagon(sf::RenderTarget& target, sf::Vector2f position,
double sideLength, int depth, double angle, sf::Color color) const {
    if (depth == 0) return;

    // Create the pentagon shape using sf::ConvexShape
    sf::ConvexShape pentagon;
    pentagon.setPointCount(5);
    for (int i = 0; i < 5; i++) {
        float theta = (2 * M_PI * i / 5) + (angle * M_PI / 180);  // Convert angle to radians
        pentagon.setPoint(i, sf::Vector2f(sideLength * cos(theta), sideLength * sin(theta)));
    }

    // Set the color for the pentagon (vary this based on depth or position)
    pentagon.setFillColor(color);

    // Set the position and rotation
    pentagon.setPosition(position);
    pentagon.setRotation(angle);

    // Draw the pentagon
    target.draw(pentagon);

    // Calculate side length for smaller pentagons
    double newSideLength = sideLength / (1 + PHI);

    // Recursively draw smaller pentagons at the calculated positions
    for (int i = 0; i < 5; i++) {
        // Calculate new positions based on pentagon geometry
        float theta = (2 * M_PI * i / 5) + (angle * M_PI / 180);
        sf::Vector2f newPos(position.x + sideLength * cos(theta),
        position.y + sideLength * sin(theta));

        // Choose a new color for the next pentagon (optional)
        sf::Color newColor = sf::Color(100 + i * 30, 50 + i * 20, 150 + i * 40);

        // Recursive call with reduced depth
        drawPentagon(target, newPos, newSideLength, depth - 1, angle + 36, newColor);
    }
}

