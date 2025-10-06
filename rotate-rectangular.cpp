#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>

int main() {
    // ------------------------------
    // 1. BASIC SETUP
    // ------------------------------
    // Define the width and height of the text-based canvas.
    const int W = 60;
    const int H = 25;

    // Aspect ratio correction factor.
    // Terminal character cells are taller than wide, so we adjust to prevent distortion.
    const double aspect = (double)H / (double)W * 2.0;

    // Initialize the rotation angle in radians.
    double angle = 0.0;

    // Clear the screen and hide the cursor using ANSI escape codes.
    // \x1b[2J  → Clear the screen
    // \x1b[?25l → Hide cursor
    std::cout << "\x1b[2J\x1b[?25l";

    // ------------------------------
    // 2. MAIN RENDERING LOOP
    // ------------------------------
    while (true) {
        // Create a frame buffer filled with spaces.
        // Each character represents one pixel on screen.
        std::string screen(W * H, ' ');

        // Compute rotation matrix values for 2D rotation.
        double c = std::cos(angle);
        double s = std::sin(angle);

        // Define the rectangle in model space (centered at origin).
        // Each corner is defined relative to the center (0, 0).
        double half_w = 0.7;  // Half width
        double half_h = 0.5;  // Half height
        double px[4] = {-half_w, half_w, half_w, -half_w};
        double py[4] = {half_h, half_h, -half_h, -half_h};

        // ------------------------------
        // 3. DRAW RECTANGLE EDGES
        // ------------------------------
        // Connect corners in order: 0→1→2→3→0
        // Instead of Bresenham, we use simple linear interpolation between points.
        for (int i = 0; i < 4; ++i) {
            int j = (i + 1) % 4;  // Next vertex index (wraps around)

            // Apply rotation to both endpoints.
            double x1 = px[i] * c - py[i] * s;
            double y1 = px[i] * s + py[i] * c;
            double x2 = px[j] * c - py[j] * s;
            double y2 = px[j] * s + py[j] * c;

            // Map model-space coordinates (-1..1) to screen-space coordinates (0..W, 0..H)
            x1 = (x1 * 0.9 + 1) * 0.5 * (W - 1);
            y1 = (-y1 * 0.9 * aspect + 1) * 0.5 * (H - 1);
            x2 = (x2 * 0.9 + 1) * 0.5 * (W - 1);
            y2 = (-y2 * 0.9 * aspect + 1) * 0.5 * (H - 1);

            // Interpolate points along the edge line.
            int steps = std::max(std::abs((int)(x2 - x1)), std::abs((int)(y2 - y1)));
            for (int k = 0; k <= steps; ++k) {
                double t = (double)k / steps;  // Fraction along line
                int X = (int)(x1 + (x2 - x1) * t);
                int Y = (int)(y1 + (y2 - y1) * t);

                // Plot if within bounds.
                if (X >= 0 && X < W && Y >= 0 && Y < H)
                    screen[Y * W + X] = '#';
            }
        }

        // ------------------------------
        // 4. DISPLAY THE FRAME
        // ------------------------------
        // Move the cursor to top-left using ANSI code \x1b[H
        std::cout << "\gix1b[H";

        // Write each line of the frame buffer to the terminal.
        for (int y = 0; y < H; ++y) {
            std::cout.write(&screen[y * W], W);
            std::cout << "\n";
        }

        // Display a short status message below the shape.
        std::cout << "Rotating Rectangle (Ctrl+C to quit)" << std::flush;

        // ------------------------------
        // 5. UPDATE STATE AND WAIT
        // ------------------------------
        // Increment angle and wrap around at 2π.
        angle += 0.1;
        if (angle > 6.283) angle = 0.0;

        // Delay to control frame rate (~20 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // ------------------------------
    // 6. CLEANUP (Normally Unreached)
    // ------------------------------
    // Show cursor again before exit.
    std::cout << "\x1b[?25h";
    return 0;
}
