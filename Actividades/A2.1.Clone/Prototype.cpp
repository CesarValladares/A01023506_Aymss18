class Prototype
{
public:
    virtual Prototype* clone() = 0;

};

class Concrete1 : public Prototype
{
public:
    Prototype* clone()
    {
        return new Concrete1(*this);
    }
    
};

int main()
{
    Concrete1* C1 = new Concrete1;
    return 0; 
}