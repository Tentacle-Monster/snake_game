#include "rock.h"
rock::rock(/* args */) : gameobject(f3point(0, 0, 0.01), f3point(0, 0, 0), f3point(0.2, 0.2, 0.5)) {}
rock::rock(f3point p, f3point s, f3point r) : gameobject(p, s, r) {}
rock::rock(f3point target) : gameobject(target, f3point(0, 0, 0), f3point(0.2, 0.2, 0.5)) {}

void rock::collision(gameobject *target)
{
}
void rock::draw()
{
    glPushMatrix();
    // glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
    glScalef(scaling.x, scaling.y, scaling.z);
    glColor3f(0.3, 0.2, 0.2);
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
}
rock::~rock()
{
}