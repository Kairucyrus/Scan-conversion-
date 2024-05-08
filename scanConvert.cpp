#include <GL/glut.h>
#include <iostream>
using namespace std;

// Function to plot a point at (x, y)
void plotPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to draw the parabola
void drawParabola() {
    // Iterate over x values from -5 to 5
    for (int x = -5; x <= 5; x++) {
        // Calculate y value for the given x using the parabola equation
        int y = 50 - x * x;

        // Plot points symmetrically in all octants
        plotPoint(x, y);           // Octant 1
        plotPoint(-x, y);          // Octant 2
        plotPoint(-x, -y);         // Octant 3
        plotPoint(x, -y);          // Octant 4
    }
}

// Function to initialize OpenGL
void init() {
    // Set clear color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // Set fill color to white
    glColor3f(1.0, 1.0, 1.0);
    // Set the initial point size
    glPointSize(1.0);
    // Set up the viewing volume
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -60, 60);
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Call function to draw the parabola
    drawParabola();
    glFlush();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set window size and position
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    // Create the window with the title "Parabola"
    glutCreateWindow("Parabola");
    // Initialize OpenGL
    init();
    // Display callback function
    glutDisplayFunc(display);
    // Start the main loop
    glutMainLoop();
    return 0;
}
