#include "food.h"
food::food(f3point p, f3point r, f3point s) : gameobject(p, r, s)
{
}
food::food(f3point p) : gameobject(p, f3point(0, 0, 0), f3point(0.2, 0.2, 0.5))
{
}
food::food() : gameobject(f3point(0, 0, 0.01), f3point(0, 0, 0), f3point(0.2, 0.2, 0.5))
{
}
food::~food() {}
void food::draw()
{
    glPushMatrix();
    // glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
    glScalef(scaling.x, scaling.y, scaling.z);
    glColor3f(1.0, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);
    glEnd();
    glPopMatrix();
    rotation.z += 0.5;
}

void food::bite()
{
    position.x += 0.05;
}
void food::collision(gameobject *target)
{
    bite();
}