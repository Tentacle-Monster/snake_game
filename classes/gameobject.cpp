#include "gameobject.h"
#include <typeinfo>

gameobject::gameobject()
{
    position = f3point(0, 0, 0);
    rotation = f3point(0, 0, 0);
    scaling = f3point(0, 0, 0);
}
gameobject::gameobject(f3point p, f3point r, f3point s)
{
    position = f3point(p);
    rotation = f3point(r);
    scaling = f3point(s);
}
gameobject::~gameobject()
{
}
void gameobject::draw()
{
    glPushMatrix();
    // glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
    glScalef(scaling.x, scaling.y, scaling.z);
    glColor3f(1.0, 0.0, 1.0);
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
polygon gameobject::getCollision()
{
    float radius = sqrtf(scaling.x * scaling.x + scaling.y * scaling.y) * 1.0;
    polygon mycollision = polygon(8);
    for (int i = 0; i < 8; i++)
        mycollision[i] = f3point(position);
    mycollision[0].x += radius;
    mycollision[4].x -= radius;
    mycollision[1].x = mycollision[7].x += radius * 0.66;
    mycollision[3].x = mycollision[5].x -= radius * 0.66;

    mycollision[2].y += radius;
    mycollision[6].y -= radius;
    mycollision[1].y = mycollision[3].y += radius * 0.66;
    mycollision[7].y = mycollision[5].y -= radius * 0.66;

    return mycollision;
}
void gameobject::moveto(f3point target)
{
    position = f3point(target);
}
void gameobject::rotate(f3point angles)
{
    rotation = f3point(angles);
}
void gameobject::scale(f3point parametres)
{
    scaling = f3point(parametres);
}
//template <class T>
void gameobject::collision(gameobject *target)
{
    //int i = typeid(target);
    // printf(target.call(), "tebe\n");
    //std::string a = typeid(target).name;
    std::cout
        << typeid(*target).name() << '\n';
    /*  if (!a.compare("хуй соси губой тряси"))
        std::cout
            << "сам соси" << '\n';*/
}
