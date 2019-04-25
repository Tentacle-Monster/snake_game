#include "f3point.h"
#include "collision_source.h"
#include <iostream>
#include "gameobject.h"
#include <cmath>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "lend.h"
#include "food.h"
#include "rock.h"
gameobject mfucker;
lend earth;
food apple;
rock hawel;
void display()
{
    glLoadIdentity();
    // clear the draw buffer .
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //point mycamera = shlong.gethead();

    f3point mycamera = f3point(0, 0, 0);
    // float ang = shlong.getangle();
    //point campos = {mycamera.x - 0.5 * sin(ang * PI / 180.0), mycamera.y - 0.5 * cos(ang * PI / 180.0), 0};
    //point ass;
    //ass.x = mycamera.x + (campos.x - mycamera.x) * 10;
    //ass.y = mycamera.y + (campos.y - mycamera.y) * 10;
    //ass.z = 1.2;
    f3point campos = f3point(-1, -1, 1);
    gluLookAt(/*cos(rotate_y * PI / 360.0) * h * radius*/ mycamera.x,         /*sin(rotate_x * PI / 360.0) * radius*/
              mycamera.y /* snake[0][1] - 3 * cos(snakeangle * PI / 360.0)*/, /* -radius * h * sin(rotate_y * PI / 360.0)*/
              mycamera.z /* -snake[0][0] - 3 * sin(snakeangle * PI / 360.0)*/,
              campos.x,
              campos.y,
              0.7,
              0.0,
              0.0,
              1.0);

    // set the color to use in draw

    /* glColor3f(0.5, 0.5, 0.0);
    // create a polygon ( define the vertexs)
    glBegin(GL_POLYGON);
    {
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    }
    glEnd();*/

    mfucker.draw();
    earth.draw();
    apple.draw();
    hawel.draw();
    polygon anus = apple.getCollision();
    glColor3f(0.2, 0.9, 0.1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < anus.getsize(); i++)
    {
        anus[i].useinglut();
    }
    glEnd();
    polygon stone = hawel.getCollision();
    polygon nothing = mfucker.getCollision();

    std ::cout << poligoninside2dppolygon(stone, anus) << "==|==" << poligoninside2dppolygon(nothing, anus) << '\n';
    // point fug{0, 0, 0};
    // Segment pidr(fug, 0.9);
    // fug.x += 0.005;
    // fug.y += 0.015;
    // fug.z += 0.05;
    // pidr.modelto(loh);
    // point you{0, 0, 0};
    // Segment obossanok(loh, 0.3);
    //  fug.y += 7;
    //obossanok.modelto(fug);

    //    draw_loop(pidr);
    //  draw_loop(obossanok);
    //  shlong.moveto(loh);
    //  shlong.turn();
    //  glLoadIdentity();
    //glPushMatrix();
    // glRotatef(90, 0.0f, 0.0f, 1.0f);
    // glTranslatef(0.0f, 0.0f, 0.2f);
    // glScalef(1.8f, 1.8f, 0.2f);

    //  shlong.draw();
    //glPopMatrix();
    // glLoadIdentity();
    // glRotatef(0, 1.0f, 0.0f, 0.0f);
    //  shlong.draw();
    // flush the drawing to screen .
    //  glFlush();
    glFlush();
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{

    /*if (gamemode == 0)
      newgame();*/
    //else
    switch (key)
    {
    case GLUT_KEY_LEFT:
        //loh.y += 0.05;
        //shlong.rot(+3.5);

        break;
    case GLUT_KEY_RIGHT:
        //loh.y -= 0.05;
        //  shlong.rot(-3.5);

        break;
    case GLUT_KEY_UP:
        //loh.x += 0.05;
        //   shlong.scalespeed(1.01);
        ///    cube_x -= 0.025;
        //  snakespeed *= 1.01;
        break;
    case GLUT_KEY_DOWN:
        //  loh.x -= 0.05;
        // shlong.scalespeed(0.99);
        //   cube_x += 0.025;
        //snakespeed *= 0.99;
        break;
    case GLUT_KEY_F1:
        //   turn(1);
        // shlong.feed();
        break;
    case GLUT_KEY_F2:
        // turn(0);
        apple.bite();
        break;
    case GLUT_KEY_F3:
        // turn(3);
        break;
    case GLUT_KEY_F4:
        // turn(2);
        break;
    case GLUT_KEY_F5:
        // turn(5);
        break;
    case GLUT_KEY_F6:
        // turn(4);
        break;
    case GLUT_KEY_F10:
        //  newgame();
        break;
    case GLUT_KEY_HOME:
        //  gamemode = 1;
        //  memcpy(&inuse, &back, sizeof(gamespace));
        // modyfied = 0;
        break;
    }
    //snakemove();
    glutPostRedisplay();

    //display();
}

// Keyboard callback function ( called on keyboard event handling )
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(EXIT_SUCCESS);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    GLfloat fAspect;
    // Prevent a divide by zero
    if (h == 0)
        h = 1;
    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;
    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Produce the perspective projection
    gluPerspective(52.0f, fAspect, 1.0, 2000.0);
    //  glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char *argv[])
{

    f3point a = f3point(5, 7, -9);
    f3point b = f3point(0.5f, 0.7f, -900);
    //collision_source phyth = collision_source();
    std::cout << a.x << '\n';
    a.x *= 0.2f;
    a[0] += 0.001f;
    std::cout << a.x << '\n';
    a *= 5;
    std::cout << a.x << '\n';
    a += b;
    std::cout << a.x << '\n';
    f3point c = b - a;
    std::cout << c.y << '\n';
    c = a;
    std::cout << c.x << '|' << c.y << '|' << c.z << '\n';
    std::cout << (c == a) << '\n';
    std::cout << lines2dcollision(f3point(0.0f, 0.0f, 0.0f), f3point(5.0f, 4.0f, 1.0f), f3point(3.0f, 0.0f, 0.5f), f3point(3.0f, 7.0f, 1.5f)) << '\n';
    polygon linea = polygon(3);
    f3point jopa = linea[0];
    linea[0] = f3point(0.0f, 7.0f, 0.0f);
    linea[1] = f3point(3.0f, 0.0f, 0.0f);
    linea[2] = a;
    polygon lineb = polygon(2);
    lineb[0] = f3point(0.0f, 4.0f, 99.5f);
    lineb[1] = f3point(5.08f, 35.4f, 99.5f);
    std::cout << polygon2dcollision(linea, lineb) << '\n';
    gameobject petya = gameobject(a, lineb[1], b);

    mfucker = gameobject(linea[1] / 3.1, f3point(0, 0, 0), f3point(0.2, 0.2, 0.2));
    earth = lend();
    polygon hitbox1 = petya.getCollision();
    for (int i = 0; i < hitbox1.getsize(); i++)
        std::cout << hitbox1[i].x << '|' << hitbox1[i].y << '|' << hitbox1[i].z << '\n';
    petya.collision(&petya);
    petya.collision(&earth);
    petya.collision(&mfucker);
    earth.collision(&earth);
    earth.collision(&apple);
    earth.collision(&hawel);
    std::cout << b.x << '|' << b.y << '|' << b.z << '\n';
    std::cout << pointinside2dpolygon(b, hitbox1) << '\n';
    std::cout << poligoninside2dppolygon(lineb, hitbox1) << '\n';
    apple = food();
    hawel = rock();
    /*gameobject *fugot[3];
    fugot[0] = &petya;
    fugot[1] = &earth;
    fugot[2] = &mfucker;
    for (int i = 0; i < 3; i++)
    {
        std::cout << fugot[i]->call() << '\n';
    }*/
    // std::cout << earth.call() << '\n';
    //  petya.collision(linea[0]);
    //  petya.collision(linea);

    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glMatrixMode(GL_MODELVIEW);
    glutCreateWindow("snake ass"); // Create a window
    glEnable(GL_DEPTH_TEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glutDisplayFunc(display); // Register display callback
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutReshapeFunc(ChangeSize);

    glutMainLoop(); // Enter main event loop

    return (EXIT_SUCCESS);
}