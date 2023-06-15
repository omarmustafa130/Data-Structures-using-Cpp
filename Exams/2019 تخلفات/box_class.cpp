//Q1
class BOX
{
    private:
        double x,y,z;
    public:
        BOX(double x_, double y_, double z_);
        double GetOuterSurfaceArea();
        bool isCube();
        bool operator==(BOX B2);
        double operator+(BOX B2);
        double L2C();

};

BOX::BOX(double x_, double y_, double z_) : x(x_), y(y_), z(z_)
{}

double BOX::GetOuterSurfaceArea()
{
    return (2*x*y + 2*y*z + 2*x*z);
}

bool BOX::isCube()
{
    return (x==y && x==z);
}

bool BOX::operator==(BOX B2)
{
    return ((x*y*z) == (B2.x*B2.y*B2.z));
}


double BOX::operator+(BOX B2)
{
    double vol1 = 1.0;
    double vol2 = 1.0;
    double vol3 = 1.0;
    vol1*= (x+B2.x);
    vol1*=y>B2.y? y:B2.y;
    vol1*=z>B2.z? z:B2.z;

    vol2*= (y+B2.y);
    vol2*=x>B2.x? x:B2.x;
    vol2*=z>B2.z? z:B2.z;

    vol3*= (z+B2.z);
    vol3*=x>B2.x? x:B2.x;
    vol3*=z>B2.z? z:B2.z;

    double min = vol1;
    if(vol2 < min)
    {
        min = vol2;
    }
    if(vol3 < min)
    {
        min = vol3;
    }
    return min;
}

double BOX::L2C()
{
    double max = x;
    double max2 = y; double max3 = z;
    double temp;
    double edgeLength = 0.0;

    if(max2>max)
    {
        temp = max;
        max = max2;
        max2 = temp;
    }

    if(max3>max)
    {
        temp = max;
        max = max3;
        max3 = temp;
    }

    if(max3>max2)
    {
        temp = max2;
        max2 = max3;
        max3 = temp;
    }

    edgeLength = max/2;
    if(edgeLength<=max2 && edgeLength<=max3)
    {
        return edgeLength;
    }
    else
    {
        edgeLength = max2/2;
        if(edgeLength<=max3)
        {
            return edgeLength;
        }
        else
        {
            edgeLength = max3/2;
            return edgeLength;
        }
    }
}