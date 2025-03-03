class Progression {             // a generic progression
public:
    Progression(long f = 0)     // constructor
        : first(f), cur(f) { }
    virtual ~Progression() {};  // destructor
    void printProgression(int n); // print the first n values
protected:
    virtual long firstValue();  // reset
    virtual long nextValue();   // advance
protected:
    long first;                 // first value
    long cur;                   // current value
};



class ArithProgression : public Progression {
public:
    ArithProgression(long i = 1);

protected:
    virtual long nextValue();

protected:
    long inc;
};



class GeoProgression : public Progression {
public:
    GeoProgression(long b = 2);

protected:
    virtual long nextValue();

protected:
    long base;
};



class FiboProgression : public Progression {
public: 
    FiboProgression(long f = 0, long s = 1);

protected:
    virtual long firstValue();
    virtual long nextValue();

protected:
    long second;
    long prev;
};
