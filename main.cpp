// Copyright 2024 Daniel Dsouza
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "penta.hpp"

const double PHI = (1 + sqrt(5)) / 2;  // The golden ratio

int main(int argc, char* argv[]) {
    if (argc != 3 && argc != 4) {  // Optionally allow for rotation angle
        std::cerr << "Usage: " << argv[0] <<
        " <L (double)> <N (int)> [<rotation (double)>]" << std::endl;
        return 1;
    }

    double L = std::stod(argv[1]);
    int N = std::stoi(argv[2]);
    double rotation = (argc == 4) ? std::stod(argv[3]) : 0.0;  // Optional rotation

    // Setup window size based on L
    const int windowWidth = static_cast<int>(6 * L);  // Adjust size as necessary
    const int windowHeight = static_cast<int>(6 * L);

    // Create the window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "PentaFlake");

    // Set up the Penta object and initialize with length, recursion depth, and rotation
    Penta pentaflake(L, N, rotation);

    // Optional: For animation, set an initial rotation angle
    double angle = 0.0;

    // Main loop to keep the window open and display the pentaflake
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);  // Clear the window

        // Update the rotation angle for animation (optional)
        angle += 0.1;  // Adjust speed as needed

        // Draw the pentaflake with an updated rotation angle for animation
        window.draw(pentaflake);  // Use only the required two arguments

        window.display();  // Display the content
    }

    return 0;
}
