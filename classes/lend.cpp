#include "lend.h"
lend::lend()
{
    gameobject();
}
lend::~lend()
{
}
polygon lend::getCollision()
{
    return polygon(0);
}
void lend::draw()
{
    {

        glPushMatrix();
        //glLoadIdentity();
        glTranslatef(0, 0, 0);
        /*glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
        glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
        glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);*/
        glScalef(1, 1, 1);
        glColor3f(0.5, 0.5, 0.0);
        glBegin(GL_POLYGON);
        {
            glVertex3f(-1.5, -1.5, 0);
            glVertex3f(-1.5, 1.5, 0);
            glVertex3f(1.5, 1.5, 0);
            glVertex3f(1.5, -1.5, 0);
        }
        glEnd();
        glPopMatrix();
    }
}
