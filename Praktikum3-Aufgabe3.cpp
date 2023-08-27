

#include <iostream>


using namespace std;


struct point2D // &p !!  point for the point
{
    float x;
    float y;

};


struct circle // &c !! C for the array
{
    point2D center; //center = (x,y)
    float radius;

};

inline float circumference(circle &c) //Lab!
{
    float U;
    float pi = 3.1415;
    U = 2*pi*c.radius;
    return U;


}


istream& operator>> (istream &i, point2D& p) //overloaded input operator for point2D
{
    cout << "Input Center:" << endl;
    cout << "Please input x and y coordinate: " << ends;
    return i >> p.x >> p.y ;


}

ostream& operator<< (ostream &o, point2D &p) //overloaded output operator for point2D
{
    return o << "(" << p.x << "," << p.y << ")" ;


}

point2D operator+ (const point2D& P1,const point2D& P2 ) //as point1 and point2, so it wont get confused by struct circle
{

    //task 4;
    point2D sum;
    sum.x = P1.x + P2.x;
    sum.y = P1.y + P2.y;
    return sum;


}

istream& operator>> (istream &n, circle &c) //task 6
{
    n >> c.center;
    cout << "Please input radius: " << ends;
    n >> c.radius;



    if(c.radius < 0)
    {
        cerr << "Error in operator>>: negative radius, sign changed\n";
        c.radius = (-c.radius); // does *1 counts as pointer ?
    }

    return n;

}


ostream& operator<< (ostream &t, circle &c) // Task 7
{

    return t << "center= " << c.center << ", radius= " << c.radius << ", circumference=  " << circumference(c) << endl;
}


circle operator+ (circle &c, point2D &p) //Task 8
{

    circle sum0;
    sum0.center=c.center+p;
    return sum0;
}

circle operator+(circle &c, const float k)
{
    circle sum2;
    c.radius + k;
    return sum2;
}

float operator/ (circle &c, const float l) //Lab
{
    float div;
    div = c.radius / l;
    return div;


}

bool operator== (const point2D& P1,const point2D& P2)
{

//    if((P1.x == P1.y) && (P2.x == P2.y)) //Why does this work like this??
    return ((P1.x == P1.y) && (P2.x == P2.y));

}

bool operator!= (const point2D& P1,const point2D& P2)
{
    return ((P1.x != P1.y) || (P2.x != P2.y));

}

bool operator== (circle &c1 , circle &c2)
{
    return ((c1.center == c2.center) && (c1.radius == c2.radius));

}

bool operator!= (circle &c1, circle &c2)
{

    return ((c1.center != c2.center) || (c1.radius != c2.radius));

}

bool operator> (circle &c3, circle &c4) //Lab!!
{
    return ((circumference(c3)) > (circumference(c4)));

}


bool operator>= (circle &c3, circle &c4) //Lab!!
{
    return ((circumference(c3)) >= (circumference(c4)));

}



int main()
{
    point2D point;
    point={1.0,1.0};
    circle c;


    struct circle C[12];
    C[0] = {0, 0, 1};


    for (int a=1; a<3; a++)
    {
        cin >> c;
        C[a]={{c.center},c.radius};
    }

    for (int a=0; a<3; a++)
    {
        cout << "C[" << a << "] = " << C[a] << endl;
    }




   cout << "By adding point (1,1) to C[0] to c[2] assign the results to C[3] to C[5]\n" << endl;

   for (int a=0; a<3; a++)
    {
        cout << "C[" << a << "] = " << C[a] << endl;
    }



   for (int a=3; a<6; a++) //for +(1,1)
   {
       c.center=C[a-3].center;
       c.radius=C[a-3].radius;
       C[a]={{c.center + point} ,c.radius};
       cout << "C[" << a << "] = " << C[a] << endl;
   }

//   Radius part

   float k;
   cout << "input value to get added to the radius of c[3] to c{5]:" << ends;
   cin >> k;

   for (int a=3; a<6; a++) //for input radius
   {
       c.center=C[a].center;
       c.radius=C[a].radius;
       C[a]={{c.center} ,c.radius + k};
       cout << "C[" << a << "] = " << C[a] << endl;
   }


   //14-8

   cout << "Compare Circles:" << endl;

   if (C[0] == C[1])
   {
       cout << "C[0] and C[1] are equal" << endl;
   }
   else
   {
       cout << "C[0] and C[1] are not equal" << endl;
   }

   if (C[1] != C[2])
   {
       cout << "C[1] and C[2] are not equal" << endl;
   }
   else
   {
       cout << "C[1] and C[2] are equal" << endl;
   }

   //LAB!!

   float l;
   cout << "\n\ninput value to divide by the radius of each circle :" << ends;
   cin >> l;


   if(l < 0) //Error message
   {
       cerr << "\n!! error in operator/: divisor with non positive value, division with sign changed value instead or radius set to 0 !!\n" << endl;
       l = -1*l;
   }


   for(int a = 0; a < 6; a++) //to make the divided circle values equal to the last 6 arrays
   {
       c.center = C[a].center;
       c.radius = C[a].radius;
       C[a+6] = {C[a].center, C[a].radius / l};
   }


   for(int a = 0; a < 12; a++) // output all 12 circles
   {
       cout << "C[" << a << "] = " << C[a] << endl;
   }


   for(int a = 0; a < 12; a++) //Compare circles with C[0]
   {
       if(C[a] > C[0])
       {
           cout << "C[" << a << "] > C[0] is true. " << endl;
       }
       else
       {
           cout << "C[" << a << "] > C[0] is false. " << endl;
       }

       if(C[a] >= C[0])
       {
           cout << "C[" << a << "] >= C[0] is true. " << endl;
       }
       else
       {
           cout << "C[" << a << "] >= C[0] is false. " << endl;
       }
   }




return 0;
}
