/*
 * SimpleDraw.c
 *
 * Example program illustrating a simple use
 * of OpenGL to draw straight lines in 2D, and
 * to draw overlapping triangles in 3D.
 *
 * Author: Samuel R. Buss
 *
 * Software accompanying the book
 *      3D Computer Graphics: A Mathematical Introduction with OpenGL,
 *      by S. Buss, Cambridge University Press, 2003.
 *
 * Software is "as-is" and carries no warranty.  It may be used without
 *   restriction, but if you modify it, please change the filenames to
 *   prevent confusion between different versions.
 * Bug reports: Sam Buss, sbuss@ucsd.edu.
 * Web page: http://math.ucsd.edu/~sbuss/MathCG
 *
 * Version 1.1.  Updated September 28, 2003.
 *    1.1. 9/28/30: Added glEnable(GL_DEPTH_TEST).  Thanks to Rob Wilkens.
 *    1.0. Original version released Spring 2003.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>    // OpenGL Graphics Utility Library
#include "SimpleDraw.h"


typedef struct {
    double x;
    double y;
} POINT2D;

// These variables control the current mode
int CurrentMode = 0;
const int NumModes = 11;
const double pi = 3.1415926535897932384;

// These variables set the dimensions of the rectanglar region we wish to view.
const double Xmin = 0.0, Xmax = 3.0;
const double Ymin = 0.0, Ymax = 3.0;

static POINT2D g5points[12];

// glutKeyboardFunc is called below to set this function to handle
//      all "normal" ascii key presses.
// Only space bar and escape key have an effect.
void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key ) {

    case ' ':                                   // Space bar
        // Increment the current mode, and tell operating system screen needs redrawing
        CurrentMode = (CurrentMode+1)%NumModes;
        break;

    case 27:                                    // "27" is theEscape key
        glutDestroyWindow(glutGetWindow());
        return;
    }

    glutPostRedisplay();
}

static void cal_5points(void)
{
    double R = 1.0;
    double r = R / 4;
    double x0 = 1.0;
    double y0 = 1.0;
    double angle5 = 2 * pi / 5;
    double angle10 = 2 * pi / 10;

    g5points[0].x = x0;
    g5points[0].y = y0 + R;
    g5points[2].x = x0 - R * sin(angle5);
    g5points[2].y = y0 + R * cos(angle5);
    g5points[4].x = x0 - R * sin(angle5 / 2);
    g5points[4].y = y0 - R * cos(angle5 / 2);
    g5points[6].x = x0 + R * sin(angle5 / 2);
    g5points[6].y = y0 - R * cos(angle5 / 2);
    g5points[8].x = x0 + R * sin(angle5);
    g5points[8].y = y0 + R * cos(angle5);

    g5points[1].x = x0 - r * sin(angle10);
    g5points[1].y = y0 + r * cos(angle10);
    g5points[3].x = x0 - r * sin(angle5);
    g5points[3].y = y0 - r * cos(angle5);
    g5points[5].x = x0;
    g5points[5].y = y0 - r;
    g5points[7].x = x0 + r * sin(angle5);
    g5points[7].y = y0 - r * cos(angle5);
    g5points[9].x = x0 + r * sin(angle10);
    g5points[9].y = y0 + r * cos(angle10);

    g5points[10].x = g5points[0].x;
    g5points[10].y = g5points[0].y;

    g5points[11].x = x0;
    g5points[11].y = y0;
}

void drawFiveStar_1(void)
{
    int i;
    glBegin( GL_LINE_LOOP );
    for (i = 0; i < 10; i++)
        glVertex2f(g5points[i].x, g5points[i].y);
    glEnd();
}

void drawFiveStar_2(void)
{
    int i;
    glBegin( GL_LINE_LOOP );

    glVertex2f(g5points[0].x, g5points[0].y);
    glVertex2f(g5points[5].x, g5points[5].y);
    glVertex2f(g5points[6].x, g5points[6].y);
    glVertex2f(g5points[1].x, g5points[1].y);
    glVertex2f(g5points[2].x, g5points[2].y);
    glVertex2f(g5points[7].x, g5points[7].y);
    glVertex2f(g5points[8].x, g5points[8].y);
    glVertex2f(g5points[3].x, g5points[3].y);
    glVertex2f(g5points[4].x, g5points[4].y);
    glVertex2f(g5points[9].x, g5points[9].y);

    glEnd();
}

void drawFiveStar_3(void)
{
    int i;
    glBegin( GL_LINE_LOOP );

    glVertex2f(g5points[0].x, g5points[0].y);
    glVertex2f(g5points[5].x, g5points[5].y);
    glVertex2f(g5points[6].x, g5points[6].y);
    glVertex2f(g5points[1].x, g5points[1].y);
    glVertex2f(g5points[2].x, g5points[2].y);
    glVertex2f(g5points[7].x, g5points[7].y);
    glVertex2f(g5points[8].x, g5points[8].y);
    glVertex2f(g5points[3].x, g5points[3].y);
    glVertex2f(g5points[4].x, g5points[4].y);
    glVertex2f(g5points[9].x, g5points[9].y);

    glVertex2f(g5points[0].x, g5points[0].y);
    glVertex2f(g5points[5].x, g5points[5].y);
    glVertex2f(g5points[4].x, g5points[4].y);
    glVertex2f(g5points[9].x, g5points[9].y);
    glVertex2f(g5points[8].x, g5points[8].y);
    glVertex2f(g5points[3].x, g5points[3].y);
    glVertex2f(g5points[2].x, g5points[2].y);
    glVertex2f(g5points[7].x, g5points[7].y);
    glVertex2f(g5points[6].x, g5points[6].y);
    glVertex2f(g5points[1].x, g5points[1].y);

    glEnd();
}


void drawFiveStar_4(void)
{
    int i;
    GLfloat colors[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };

    glBegin( GL_TRIANGLES );
    for (i = 0; i < 10; ++i) {
        glColor3fv(colors[i % 3]);
        glVertex2f(g5points[i].x, g5points[i].y);
        glVertex2f(g5points[i + 1].x, g5points[i + 1].y);
        glVertex2f(g5points[11].x, g5points[11].y);
    }
    glEnd();
}

void drawFiveStar_5(void)
{
    int i;
    glBegin( GL_TRIANGLE_FAN );
    glVertex2f(g5points[11].x, g5points[11].y);
    for (i = 0; i < 11; ++i)
        glVertex2f(g5points[i].x, g5points[i].y);
    glEnd();
}

void drawFiveStar_6(void)
{
    int i;
    GLfloat colors[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };

    glBegin( GL_TRIANGLE_STRIP );
    for (i = 0; i < 10; ++i) {
        glColor3fv(colors[i % 3]);
        glVertex2f(g5points[i].x, g5points[i].y);
        glVertex2f(g5points[i + 1].x, g5points[i + 1].y);
        glVertex2f(g5points[11].x, g5points[11].y);
    }
    glEnd();
}

/*
 * drawScene() handles the animation and the redrawing of the
 *      graphics window contents.
 */
void drawScene(void)
{
    // Clear the rendering window

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set drawing color to white
    glColor3f( 1.0, 1.0, 1.0 );     

    switch (CurrentMode)
    {

    case 0:
        // Draw three points
        glBegin(GL_POINTS);
        glVertex2f( 1.0, 1.0 );
        glVertex2f( 2.0, 1.0 );
        glVertex2f( 2.0, 2.0 );
        glEnd();
        break;

    case 1:
    case 2:
    case 3:
        if ( CurrentMode==1 ) {
            // Draw lines in GL_LINES mode
            glBegin( GL_LINES );
        }
        else if ( CurrentMode==2 ) {
            // Draw lines in GL_LINE_STRIP mode
            glBegin( GL_LINE_STRIP );
        }
        else {
            // Draw lines in GL_LINE_LOOP mode
            glBegin( GL_LINE_LOOP );
        }
        glVertex2f( 0.5, 1.0 );
        glVertex2f( 2.0, 2.0 );
        glVertex2f( 1.8, 2.6 );
        glVertex2f( 0.7, 2.2 );
        glVertex2f( 1.6, 1.2 );
        glVertex2f( 1.0, 0.5 );
        glEnd();
        break;

    case 4:         // Overlapping triangles
        glBegin( GL_TRIANGLES );
        glColor3f( 1.0, 0.0, 0.0 );
        glVertex3f( 0.3, 1.0, 0.5 );
        glVertex3f( 2.7, 0.85, 0.0 );
        glVertex3f( 2.7, 1.15, 0.0 );

        glColor3f( 0.0, 1.0, 0.0 );
        glVertex3f(2.53, 0.71, 0.5 );
        glVertex3f(1.46, 2.86, 0.0 );
        glVertex3f(1.2, 2.71, 0.0 );

        glColor3f( 0.0, 0.0, 1.0 );
        glVertex3f(1.667, 2.79, 0.5);
        glVertex3f(0.337, 0.786, 0.0);
        glVertex3f(0.597, 0.636, 0.0);
        glEnd();
        break;
    case 5:
        drawFiveStar_1();
        break;
    case 6:
        drawFiveStar_2();
        break;
    case 7:
        drawFiveStar_3();
        break;
    case 8:
        drawFiveStar_4();
        break;
    case 9:
        drawFiveStar_5();
        break;
    case 10:
        drawFiveStar_6();
        break;
    }

    // Flush the pipeline.  (Not usually necessary.)
    glFlush();

}

// Initialize OpenGL's rendering modes
void initRendering()
{

    glEnable ( GL_DEPTH_TEST );

    // Uncomment out the first block of code below, and then the second block,
    //      to see how they affect line and point drawing.
/*
    // The following commands should cause points and line to be drawn larger
    //  than a single pixel width.
    glPointSize(8);
    glLineWidth(5);
*/

    // The following commands should induce OpenGL to create round points and 
    //  antialias points and lines.  (This is implementation dependent unfortunately).
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);    // Make round points, not square points
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);     // Antialias the lines
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

// Called when the window is resized
//      w, h - width and height of the window in pixels.
void resizeWindow(int w, int h)
{
    double scale, center;
    double windowXmin, windowXmax, windowYmin, windowYmax;

    // Define the portion of the window used for OpenGL rendering.
    glViewport( 0, 0, w, h );   // View port uses whole window

    // Set up the projection view matrix: orthographic projection
    // Determine the min and max values for x and y that should appear in the window.
    // The complication is that the aspect ratio of the window may not match the
    //      aspect ratio of the scene we want to view.
    w = (w==0) ? 1 : w;
    h = (h==0) ? 1 : h;
    if ( (Xmax-Xmin)/w < (Ymax-Ymin)/h ) {
        scale = ((Ymax-Ymin)/h)/((Xmax-Xmin)/w);
        center = (Xmax+Xmin)/2;
        windowXmin = center - (center-Xmin)*scale;
        windowXmax = center + (Xmax-center)*scale;
        windowYmin = Ymin;
        windowYmax = Ymax;
    }
    else {
        scale = ((Xmax-Xmin)/w)/((Ymax-Ymin)/h);
        center = (Ymax+Ymin)/2;
        windowYmin = center - (center-Ymin)*scale;
        windowYmax = center + (Ymax-center)*scale;
        windowXmin = Xmin;
        windowXmax = Xmax;
    }
    
    // Now that we know the max & min values for x & y that should be visible in the window,
    //      we set up the orthographic projection.
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( windowXmin, windowXmax, windowYmin, windowYmax, -1, 1 );

}


// Main routine
// Set up OpenGL, define the callbacks and start the main loop
int main( int argc, char** argv )
{
    cal_5points();
    glutInit(&argc,argv);

    // The image is not animated so single buffering is OK. 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );

    // Window position (from top corner), and size (width and hieght)
    glutInitWindowPosition( 20, 60 );
    glutInitWindowSize( 360, 360 );
    glutCreateWindow( "SimpleDraw - Press space bar to toggle images" );

    // Initialize OpenGL as we like it..
    initRendering();

    // Set up callback functions for key presses
    glutKeyboardFunc( myKeyboardFunc );         // Handles "normal" ascii symbols
    // glutSpecialFunc( mySpecialKeyFunc );     // Handles "special" keyboard keys

    // Set up the callback function for resizing windows
    glutReshapeFunc( resizeWindow );

    // Call this for background processing
    // glutIdleFunc( myIdleFunction );

    // call this whenever window needs redrawing
    glutDisplayFunc( drawScene );

    fprintf(stdout, "Press space bar to toggle images; escape button to quit.\n");
    
    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop(  );

    return(0);  // This line is never reached.
}
