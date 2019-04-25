#include <iostream>
#include <string>
#include <cmath>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <typeinfo>
#include "fakeklass.h"
//#define _USE_MATH_DEFINES
const double PI = 3.141592653589793238463;
typedef struct
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
} point;

class Graph
{
};

class Food
{
  public:
    point center;
    Food()
    {
        center = {0, 0, 0};
    }
    Food(point target)
    {
        center.x = target.x;
        center.y = target.y;
        center.z = target.z;
    }
    bool chew()
    {
        // destroy(this);
        return true;
    }
    void draw()
    {
        glColor3f(0.7, 0.2, 0.2);
        glBegin(GL_POLYGON);
        glVertex3f(center.x + 0.02, center.y + 0.02, 0.08);
        glVertex3f(center.x + 0.02, center.y - 0.02, 0.08);
        glVertex3f(center.x - 0.02, center.y - 0.02, 0.08);
        glVertex3f(center.x - 0.02, center.y + 0.02, 0.08);
        glEnd();
    }

  private:
    point *model;
};

/*class Feed_base
{
  public:
    Feed_base()
    {
        init();
    }
    Feed_base(int z)
    {
        init(z);
    }
    void draw()
    {
        for (int i = 0; i < length; i++)
        {
            if (array[i] != NULL)
                array[i]->draw();
        }
    }
    int collision_check(point eater)
    {
        int result;
        for (int i = 0; i < length; i++)
        {
            if (array[i] != NULL)
            {
                if ((array[i]->center.x - eater.x) * (array[i]->center.x - eater.x) + (array[i]->center.y - eater.y) * (array[i]->center.y - eater.y) < 0.01)
                {
                    result++;
                    eat(i);
                }
            }
        }
        return result;
    }
    Food **array;
    int length;
    void init()
    {
        length = 1;
        array = new Food[length];
        array[0] = NULL;
    }
    void init(int n)
    {
        length = n;
        delete (array);
        array = new *Food[length];
        for (int i = 0; i < length; i++)
        {
            food[i] = NULL;
        }
    }
    int add()
    {
        for (int i = 0; i < length; i++)
        {
            if (food[i] == NULL)
            {
                food[i] = Food();
                return i;
            }
        }
        Food &array2 = new *Food[length + 1];
        for (int i = 0; i < length; i++)
        {
            food2[i] = food[i];
        }
        array2[length] = Food();
        delete (array);
        array = array2;
        length++;
    }
    int add(point target)
    {
        for (int i = 0; i < length; i++)
        {
            if (food[i] == NULL)
            {
                food[i] = Food(target);
                return i;
            }
        }
        Food &array2 = new *Food[length + 1];
        for (int i = 0; i < length; i++)
        {
            food2[i] = food[i];
        }
        array2[length] = Food(target);
        delete (array);
        array = array2;
        length++;
    }
    void eat(int i)
    {
        delete (array[i]);
        array[i] = NULL;
    }
};
*/
class Segment
{
  public:
    point model[5];
    //std::string m_name;
    // int m_id;
    point getcenter()
    {
        return center;
    }

    void modelto(point target)
    {
        /*
        .middle                                                                                         
        _                                                  ________________                             
    __-- --___                                            //((((((((((((((//\                           ((
 ---         ---                                         //((((((((((((((//  \                           ))
//left_up      \\right_up                               //((((((((((((((//    \                         ((
\\             //                                       \\((((((((((((((\\    //                         
 \\    center //                                         \\\\\\\\\\\\\\\\\\  // 
   =====.=====                                            \\\\\\\\\\\\\\\\\__/
legt_down     right_down
*/
        // float rotx = sin(-snakeangle * PI / 360.0 + 0.0001);
        // float roty = cos(+snakeangle * PI / 360.0 + 0.0001);

        float dx = (target.x - center.x) + 0.00001;
        float dy = (target.y - center.y + 0.00001);
        float sinx = (dy) / (dx);
        float delta = sqrt(dx * dx + dy * dy);
        //float sinx =

        // x1 - dx *sinx / delta, y1 + dy / sinx / delta float
        float x_turn = fat * dx * sinx / delta;
        float y_turn = fat * dy / sinx / delta;
        model[0].x = center.x;
        model[0].y = center.y;
        model[0].z = center.z + fat;

        model[1].x = center.x - x_turn * 0.5;
        model[1].y = center.y + y_turn * 0.5;
        model[1].z = center.z + fat * 0.75;

        model[4].x = center.x + x_turn * 0.5;
        model[4].y = center.y - y_turn * 0.5;
        model[4].z = center.z + fat * 0.75;

        model[2].x = center.x - x_turn * 0.33;
        model[2].y = center.y + y_turn * 0.33;
        model[2].z = center.z;

        model[3].x = center.x + x_turn * 0.33;
        model[3].y = center.y - y_turn * 0.33;
        model[3].z = center.z;

        // drawbody(-snake[0][0], -snake[0][0] + sin(-snakeangle * PI / 360.0 + 0.0001) * 0.5, snake[0][1], snake[0][1] + cos(+snakeangle * PI / 360.0 + 0.0001) * 0.5, 5, 0);

        /*  for (int i = 0; i < 5; i++)
        {
            model[i] = target;
        }
        target.x = -28;
*/
        //std::cout << "Name: " << m_name << "\nId: " << m_id << "\nWage: $" << m_wage << '\n';
    }
    //line collision detection//

    void moveto(point target)
    {
        center.x = center.x * 0.9 + target.x * 0.1;
        center.y = center.y * 0.9 + target.y * 0.1;
        center.z = center.z * 0.9 + target.z * 0.1;
    }
    void setfat(float fat)
    {
        this->fat = fat;
    }
    void printmodel()
    {

        for (int i = 0; i < 5; i++)
            std::cout << "point №" << i << '\n'
                      << " x" << model[i].x << "| y" << model[i].y << "| z" << model[i].z << '\n';
    }
    Segment()
    {
        //  m_name = "gay";
        //m_id = 5;
        // m_wage = 73.8;
        center = {0, 0, 0};
        fat = 0;
    }
    Segment(Segment &parent)
    {
        //  m_name = "gay";
        //m_id = 5;
        // m_wage = 73.8;
        center = parent.center;
        //for(int i=0;)
        //model = parent.model;
        fat = parent.fat;
    }
    Segment(point targ, float f)
    {
        //  m_name = "gay";
        //m_id = 5;
        // m_wage = 73.8;
        center.x = targ.x;
        center.y = targ.y;
        center.z = targ.z;
        fat = f;
    }

  private:
    point center;
    float fat;
    //double m_wage;
};

class Snake
{
  public:
    static bool IsLinePartsIntersected(point a, point b, point c, point d)
    {
        double common = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);

        if (common == 0)
            return false;

        double rH = (a.y - c.y) * (d.x - c.x) - (a.x - c.x) * (d.y - c.y);
        double sH = (a.y - c.y) * (b.x - a.x) - (a.x - c.x) * (b.y - a.y);

        double r = rH / common;
        double s = sH / common;

        if (r >= 0 && r <= 1 && s >= 0 && s <= 1)
            return true;
        else
            return false;
    }
    void moveto(point target)
    {
        tail[0].moveto(target);
        for (int i = 1; i < length; i++)
        {
            tail[i].moveto(tail[i - 1].getcenter());
        }
    }
    void turn()
    {
        if (sliseangle > 60.0 || sliseangle < -60.0)
            slisenow = 0 - slisenow;
        sliseangle += slisenow;

        realangle = snakeangle + sliseangle; // fmod(sliseangle, 180.0);
        moveto(nextstap);
        //realangle = snakeangle;
        nextstap.x += snakespeed * sin(realangle * PI / 180.0);
        nextstap.y += snakespeed * cos(realangle * PI / 180.0);
        float headsize = 0.12f;
        tail[0].modelto(nextstap);
        for (int i = 1; i < length; i++)
        {
            tail[i].modelto(tail[i - 1].getcenter());
        }
        hitbox[0].x = tail[0].model[0].x + headsize * sin((realangle + 15) * PI / 180.0);
        hitbox[0].y = tail[0].model[0].y + headsize * cos((realangle + 15) * PI / 180.0);
        hitbox[1].x = tail[0].model[0].x + headsize * sin((realangle - 15) * PI / 180.0);
        hitbox[1].y = tail[0].model[0].y + headsize * cos((realangle - 15) * PI / 180.0);
        hitbox[2].x = tail[0].model[0].x; //+ headsize * 3 * sin((realangle)*PI / 180.0);
        hitbox[2].y = tail[0].model[0].y; //+ headsize * 3 * cos((realangle)*PI / 180.0);
                                          //   collision(tail[2]);
                                          //   collision(tail[2].model[1]);
        collision_check();
    }
    void rot(float a)
    {
        snakeangle += a;
    }
    void scalespeed(float a)
    {
        snakespeed *= a;
    }

    Snake()
    {
        init();
    }
    void draw()
    {
        //tail[0].modelto(nextstap);
        /*
        glColor3f(0.7, 0.2, 0.2);
        glBegin(GL_POLYGON);
        glVertex3f(hitbox[0].x, hitbox[0].y, 0.08);
        glVertex3f(hitbox[1].x, hitbox[1].y, 0.08);
        glVertex3f(hitbox[2].x, hitbox[2].y, 0.08);

        glEnd();*/

        /* if (&niamka != NULL)
        {
            glColor3f(0.7, 0.2, 0.2);
            glBegin(GL_POLYGON);
            glVertex3f(niamka.center.x + 0.02, niamka.center.y + 0.02, 0.08);
            glVertex3f(niamka.center.x + 0.02, niamka.center.y - 0.02, 0.08);
            glVertex3f(niamka.center.x - 0.02, niamka.center.y - 0.02, 0.08);
            glVertex3f(niamka.center.x - 0.02, niamka.center.y + 0.02, 0.08);
            glEnd();
        }*/
        for (int i = 1; i < length; i++)
        {
            // tail[i].modelto(tail[i - 1].getcenter());

            //  draw_loop(tail[i]);

            /*glColor3f(0.7, 0.2, 0.2);

            for (int t = 0; t < 5; t++)
            {
                glBegin(GL_LINES);
                glVertex3f(tail[i].model[t].x, tail[i].model[t].y, tail[i].model[t].z);
                glVertex3f(tail[i - 1].model[t].x, tail[i - 1].model[t].y, tail[i - 1].model[t].z);
                glEnd();
            }
*/
            glColor3f(0.5, 0.5, 0.9);
            glBegin(GL_POLYGON);
            glVertex3f(tail[i].model[3].x, tail[i].model[3].y, tail[i].model[3].z);
            glVertex3f(tail[i].model[2].x, tail[i].model[2].y, tail[i].model[2].z);
            glVertex3f(tail[i - 1].model[2].x, tail[i - 1].model[2].y, tail[i - 1].model[2].z);
            glVertex3f(tail[i - 1].model[3].x, tail[i - 1].model[3].y, tail[i - 1].model[3].z);

            glEnd();

            glColor3f(0.2, 0.8, 0.9);
            /*  if (i > 2 && (IsLinePartsIntersected(tail[i].model[0], tail[i - 1].model[0], hitbox[0], hitbox[1]) || IsLinePartsIntersected(tail[i].model[0], tail[i - 1].model[0], hitbox[0], hitbox[2]) || IsLinePartsIntersected(tail[i].model[0], tail[i - 1].model[0], hitbox[1], hitbox[2])))
            {
                init();
                return;
            }*/
            glBegin(GL_POLYGON);
            glVertex3f(tail[i].model[3].x, tail[i].model[3].y, tail[i].model[3].z);

            glVertex3f(tail[i].model[4].x, tail[i].model[4].y, tail[i].model[4].z);
            glVertex3f(tail[i - 1].model[4].x, tail[i - 1].model[4].y, tail[i - 1].model[4].z);
            glVertex3f(tail[i - 1].model[3].x, tail[i - 1].model[3].y, tail[i - 1].model[3].z);

            glEnd();
            glBegin(GL_POLYGON);
            glVertex3f(tail[i].model[1].x, tail[i].model[1].y, tail[i].model[1].z);

            glVertex3f(tail[i].model[2].x, tail[i].model[2].y, tail[i].model[2].z);
            glVertex3f(tail[i - 1].model[2].x, tail[i - 1].model[2].y, tail[i - 1].model[2].z);
            glVertex3f(tail[i - 1].model[1].x, tail[i - 1].model[1].y, tail[i - 1].model[1].z);

            glEnd();

            glColor3f(0.4, 0.95, 0.5);

            // if (IsLinePartsIntersected(tail[i].model[0], tail[i - 1].model[0], hitbox[0], hitbox[2]))
            //   glColor3f(0.9, 0.3, 0.3);
            glBegin(GL_POLYGON);
            glVertex3f(tail[i].model[0].x, tail[i].model[0].y, tail[i].model[0].z);

            glVertex3f(tail[i].model[4].x, tail[i].model[4].y, tail[i].model[4].z);
            glVertex3f(tail[i - 1].model[4].x, tail[i - 1].model[4].y, tail[i - 1].model[4].z);
            glVertex3f(tail[i - 1].model[0].x, tail[i - 1].model[0].y, tail[i - 1].model[0].z);

            glEnd();
            glBegin(GL_POLYGON);
            glVertex3f(tail[i].model[1].x, tail[i].model[1].y, tail[i].model[1].z);

            glVertex3f(tail[i].model[0].x, tail[i].model[0].y, tail[i].model[0].z);
            glVertex3f(tail[i - 1].model[0].x, tail[i - 1].model[0].y, tail[i - 1].model[0].z);
            glVertex3f(tail[i - 1].model[1].x, tail[i - 1].model[1].y, tail[i - 1].model[1].z);

            glEnd();
        }
        glPopMatrix();
        // glLoadIdentity();

        //  glRotatef(snakeangle, 0.0f, 0.0f, 1.0f);
        glTranslatef(tail[0].model[0].x, tail[0].model[0].y, -0.075f);
        glRotatef(-snakeangle, 0.0f, 0.0f, 1.0f);
        glScalef(0.2, 0.2, 0.2);
        glTranslatef(0.0, -0.12, 0);
        //glRotatef(180, 1.0f, 0.0f, 0.0f);
        draw_head();
        // flush the drawing to screen .
        //  glFlush();
        glPopMatrix();
    }
    point gethead()
    {
        return nextstap;
    }
    point getneck()
    {
        return tail[3].model[0];
    }
    void feed()
    {
        int newlength = length + 1;
        Segment *newtail = new Segment[newlength];
        newtail[0] = Segment(tail[0]);
        for (int i = 1; i < length; i++)
        {
            newtail[i] = Segment(tail[i]);
            newtail[i].setfat((float)(newlength - i - 1) / length * 0.1);
        }
        newtail[length] = Segment(tail[length - 1]);
        delete (tail);
        tail = newtail;
        length = newlength;
        //realangle = snakeangle = 0;
        //snakespeed = 0.02;
        //slisenow = 0;
        //nextstap = {0, 0, 0};
        //turn();
    }
    float getangle()
    {
        return realangle;
    }

  private:
    float realangle;
    float snakeangle;
    float sliseangle;
    float snakespeed;
    float slisenow;
    int length;
    //Food niamka = Food({1, 1, 0});

    point hitbox[3];
    point nextstap;
    Segment *tail;
    // Snake shlong = Snake();
    void init()
    {
        length = 7;
        delete (tail);
        tail = new Segment[length];

        tail[0] = Segment();
        tail[0].setfat(0.05);
        for (int i = 1; i < length; i++)
        {
            tail[i] = Segment();
            tail[i].setfat((float)(length - i - 1) / length * 0.1);
        }
        realangle = snakeangle = 0;
        snakespeed = 0.015;
        slisenow = 0;
        nextstap = {0, 0, 0};
        turn();
    }
    void collision_check()
    {
        self_collision();
        //      if (&niamka != NULL)
        //         bite(niamka);
    }
    template <typename T>
    void collision(T target)
    {
        std::cout << "\n";
        if (typeid(target) == typeid(Segment))
            init();
        else
            std::cout << "fuck me";
    }
    void bite(Food a)
    {
        if ((a.center.x - hitbox[2].x) * (a.center.x - hitbox[2].x) + (a.center.y - hitbox[2].y) * (a.center.y - hitbox[2].y) < 0.01)
        {
            feed();
            a.chew();
        }
    }
    void self_collision()
    {
        for (int i = 3; i < length; i++)
        {
            if (IsLinePartsIntersected(tail[i].model[0], tail[i - 1].model[0], hitbox[0], hitbox[1]) || IsLinePartsIntersected(tail[i].model[0], tail[i - 1].model[0], hitbox[0], hitbox[2]) || IsLinePartsIntersected(tail[i].model[0], tail[i - 1].model[0], hitbox[1], hitbox[2]))
                collision(tail[i]);
        }
    }
    void draw_loop(Segment currientloop)
    {
        glColor3f(0.1, 0.2, 0.8);
        for (int i = 0; i < 5; i++)
        {
            glBegin(GL_LINES);
            glVertex3f(currientloop.model[i].x, currientloop.model[i].y, currientloop.model[i].z);
            glVertex3f(currientloop.model[(i + 1) % 5].x, currientloop.model[(i + 1) % 5].y, currientloop.model[(i + 1) % 5].z);
        }
        glEnd();
    }

    void draw_head()
    {
        glColor3f(0.4, 0.95, 0.5);
        glBegin(GL_POLYGON);
        glVertex3f(0.18, 0.7, 0.7);
        glVertex3f(-0.18, 0.7, 0.7);
        glVertex3f(-0.3, 0.1, 0.7);
        glVertex3f(0.3, 0.1, 0.7);

        glEnd();
        glColor3f(0.5, 0.95, 0.6);
        glBegin(GL_POLYGON);
        glVertex3f(-0.13, -0.1, 0.3);
        glVertex3f(0.13, -0.1, 0.3);
        glVertex3f(0.3, 0.1, 0.7);
        glVertex3f(-0.3, 0.1, 0.7);

        glEnd();

        glColor3f(0.3, 0.6, 0.3);
        glBegin(GL_POLYGON);
        glVertex3f(-0.13, -0.1, 0.3);
        glVertex3f(-0.3, 0.1, 0.7);
        glVertex3f(-0.18, 0.7, 0.7);

        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0.13, -0.1, 0.3);
        glVertex3f(0.3, 0.1, 0.7);
        glVertex3f(0.18, 0.7, 0.7);

        glEnd();
        glColor3f(0.8, 0.9, 0.0);
        glBegin(GL_POLYGON);

        glVertex3f(0.18, 0.7, 0.7);
        glVertex3f(-0.18, 0.7, 0.7);
        glVertex3f(0.0, 0.65, 0.4);

        glEnd();

        glColor3f(0.5, 0.5, 0.0);
        glBegin(GL_POLYGON);

        glVertex3f(0.0, 0.65, 0.4);
        glVertex3f(-0.18, 0.7, 0.7);
        glVertex3f(-0.13, -0.1, 0.3);

        glEnd();
        glBegin(GL_POLYGON);

        glVertex3f(0.0, 0.65, 0.4);
        glVertex3f(0.18, 0.7, 0.7);
        glVertex3f(0.13, -0.1, 0.3);

        glEnd();
        glColor3f(0.3, 0.4, 0.0);
        glBegin(GL_POLYGON);

        glVertex3f(0.0, 0.65, 0.4);
        glVertex3f(0.13, -0.1, 0.3);
        glVertex3f(-0.13, -0.1, 0.3);

        glEnd();
    }
};

point loh{0, 0, 0};
//Segment snake[40];
Snake shlong = Snake();
fakeklass leha = fakeklass();
//Feed_base havka = Feed_base();
void draw_loop(Segment currientloop)
{
    glColor3f(0.1, 0.2, 0.8);
    for (int i = 0; i < 5; i++)
    {
        glBegin(GL_LINES);
        glVertex3f(currientloop.model[i].x, currientloop.model[i].y, currientloop.model[i].z);
        glVertex3f(currientloop.model[(i + 1) % 5].x, currientloop.model[(i + 1) % 5].y, currientloop.model[(i + 1) % 5].z);
        glEnd();
    }
}
void display()
{
    glLoadIdentity();
    // clear the draw buffer .
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    point mycamera = shlong.gethead();
    float ang = shlong.getangle();
    point campos = {mycamera.x - 0.5 * sin(ang * PI / 180.0), mycamera.y - 0.5 * cos(ang * PI / 180.0), 0};
    point ass;
    ass.x = mycamera.x + (campos.x - mycamera.x) * 10;
    ass.y = mycamera.y + (campos.y - mycamera.y) * 10;
    ass.z = 1.2;
    gluLookAt(/*cos(rotate_y * PI / 360.0) * h * radius*/ mycamera.x,         /*sin(rotate_x * PI / 360.0) * radius*/
              mycamera.y /* snake[0][1] - 3 * cos(snakeangle * PI / 360.0)*/, /* -radius * h * sin(rotate_y * PI / 360.0)*/
              mycamera.z /* -snake[0][0] - 3 * sin(snakeangle * PI / 360.0)*/,
              campos.x,
              campos.y,
              0.7,
              0.0,
              0.0,
              1.0);
    glPushMatrix();

    // set the color to use in draw

    glColor3f(0.5, 0.5, 0.0);
    // create a polygon ( define the vertexs)
    glBegin(GL_POLYGON);
    {
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    }
    glEnd();
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
    shlong.turn();
    //  glLoadIdentity();
    glPushMatrix();
    // glRotatef(90, 0.0f, 0.0f, 1.0f);
    // glTranslatef(0.0f, 0.0f, 0.2f);
    // glScalef(1.8f, 1.8f, 0.2f);

    shlong.draw();
    glPopMatrix();
    // glLoadIdentity();
    // glRotatef(0, 1.0f, 0.0f, 0.0f);
    shlong.draw();
    // flush the drawing to screen .
    //  glFlush();
    glPopMatrix();
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
        shlong.rot(+3.5);

        break;
    case GLUT_KEY_RIGHT:
        //loh.y -= 0.05;
        shlong.rot(-3.5);

        break;
    case GLUT_KEY_UP:
        //loh.x += 0.05;
        shlong.scalespeed(1.01);
        ///    cube_x -= 0.025;
        //  snakespeed *= 1.01;
        break;
    case GLUT_KEY_DOWN:
        //  loh.x -= 0.05;
        shlong.scalespeed(0.99);
        //   cube_x += 0.025;
        //snakespeed *= 0.99;
        break;
    case GLUT_KEY_F1:
        //   turn(1);
        shlong.feed();
        break;
    case GLUT_KEY_F2:
        // turn(0);
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

// Main execution  function
int main(int argc, char *argv[])
{
    /*
    point a, b, c, d;
    a.x = 0;
    a.y = 0;
    b.x = 3;
    b.y = 4;
    c.x = 0;
    c.y = 3;
    d.x = 2;
    d.y = 1;
    std::cout << shlong.IsLinePartsIntersected(a, b, c, d);
*/
    std::cout << leha.gethui();
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
