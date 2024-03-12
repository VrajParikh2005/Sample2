#include<iostream>
using namespace std;

class Vector{
    private:
    int dimension;
    int *ptr;

    public:
    // Default constructor
    Vector(int d) : dimension(d)
    {
        ptr = new int(d);
        for(int i=0;i<d;i++)
        {
            ptr[i]=0;
        }
    }

    // Parameterised constructor
    Vector(int dim,int value[]) : dimension(dim)
    {
        ptr = new int(dim);
        for(int i=0;i<dim;i++)
        {
            ptr[i]=value[i];
        }
    }

    //Copy and parameterise constructor
    Vector(int d,int D,int value[],int add[]) : dimension(D+d)
    {
        int i,j;
        ptr = new int (D+d);
        for(int i=0;i<d;i++)
        {
            ptr[i]=value[i];
            j=i;
        }
        j+=1;
        int k;
        for(k=0;k<D;k++)
        {
            ptr[j]=add[k];
            j++;
        }
    }

    // Copy constructor
    Vector(Vector &t)
    {
        dimension=t.dimension;
        ptr = new int (dimension);
        for(int i=0;i<dimension;i++)
        {
            ptr[i]=t.ptr[i];
        }
    }

    void print()
    {
        for(int i=0;i<dimension;i++)
        {
            cout<<ptr[i]<<" ";
        }
        cout<<endl;
    }

    ~Vector()
    {
        delete[] ptr;
    }
};

int main()
{
    int d;
    cout<<"File edited";
    cout << "Enter the dimension of the vector: ";
    cin>>d;
    int value[d];
    cout << "Enter "<<d<<" elements which you want to insert in vector: ";
    for(int i=0;i<d;i++)
    {
        cin >> value[i];
    }

    Vector v1(d);
    cout<<"Elements of v1 vector: ";
    v1.print();

    Vector v2(d,value);
    cout<<"Elements of v2 vector: ";
    v2.print();

    Vector v3(v2);
    cout<<"Elements of v3 vector: ";
    v3.print();

    int D;
    cout<<"\nChange the dimension: ";
    cin>>D;
    int v[D];
    cout<<"Enter "<<D-d<<" elements which you want to add in vector: ";
    for(int i=0;i<D-d;i++)
    {
        cin>> v[i];
    }
    Vector v4(d,D-d,value,v);
    cout<<"Elements of v4 vector: ";
    v4.print();
    return 0;
}
