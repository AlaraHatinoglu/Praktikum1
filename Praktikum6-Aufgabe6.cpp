
#include <iostream>
#include <iomanip>


using namespace std;



//**** Task 1 ****//

enum struct Frequency : char
{
    once, daily, weekly, monthly
};

ostream& operator<<(ostream& out, const Frequency &f)
{
    switch(f)
   {int freq;
   case Frequency::monthly:
      return out << " monthly ";

   case Frequency::weekly:
      return out << " weekly ";

   case Frequency::daily:
      return out << " daily ";

   case Frequency::once:
      return out << " ";
   }
}

istream& operator>>(istream& in, const Frequency &f)
{

    cout << " frequency input:\n(o) once\n(d) daily\n(m) monthly\n(w) weekly\nyour choice:" << ends;
    in >> f;

}

//**** Task 2 ****//

class CO2Emission
{
private:
    int *next; //private pointer attribute named next to build up a list of CO2 emissions.

public:
    CO2Emission()
    {
        int *next = nullptr;

    }

public:
    virtual ~CO2Emission()
    {
        cout << "destructor CO2Emission: done" << endl;
    }

public:
    get_next()
    {
        return *next;
    }

public:
    set_next(int *ptr)
    {
        *next = *ptr;
    }

public:
    virtual float get_co2() = 0;

public:
    virtual void print() = 0;

};

//**** Task 3 ****//

class Transport:public CO2Emission
{
private:
    float km;

private:
    Frequency fr;

public:
    Transport()
    {

        cout << "transport distance kilometers: ";
        cin >> km;
    }

public:
    Transport(float kilom, Frequency fre = Frequency::once)
    {
        km = kilom;
        fr = fre;
    }

public:
    virtual ~Transport()
    {
        cout << " destructor Transport: " << fr << " " << km << " km done" << endl;

    }

private:
     float virtual get_co2_pkm() = 0;

public:
    float get_co2()
    {
        char f;
        int fr;
        if (f == 'o')
        {
            fr = 1;
        }
        else if( f == 'd')
        {
            fr = 365;
        }
        else if( f == 'w')
        {
            fr = 52;

        }
        else if( f == 'm')
        {
            fr = 12;
        }




        float getco2;
        getco2 = Transport::km * get_co2_pkm()* fr;
        return getco2;
    }

public:
    void print()
    {
        cout << "transport" << fr << fixed << setprecision(1) << km << "(emission value per person = " << fixed << setprecision(3) << get_co2_pkm() << " pkm) CO2 emission = " << fixed << setprecision(1) << get_co2() << endl;
    }

};

//**** Task 4 ****//

class Bus:public Transport
{

private:
    bool local_transport;

public:
    Bus()
    {
        cout << "\nBus travel data input: \n(1) local transport \n(2) long distance" << endl;
        cout << "Your choice: " << ends;
        int a;
        cin >> a;

        if (a == 1)
        {
            local_transport = true;
        }
        else if (a == 2)
        {
            local_transport = false;

        }
        else
        {
            cerr << "Please select a valid choice!" << endl;
        }
    }

public:
    Bus(bool l_transport, float kmeter):

        local_transport(l_transport),
        Transport(kmeter)
   {}

private:
    float get_co2_pkm()
    {
        float co2;
        if(local_transport == true) //if it is local transport co2 emission is 0.111
        {
            co2 = 0.111;
            return co2;

        }

        else if(local_transport == false)
        {
            co2 = 0.036; //if it is not local transport co2 emission is 0.036
            return co2;

        }
    }


public:
    void print()
{


    if(local_transport == true)
        {
            cout << "Bus travel local";
            Transport::print();
        }

        else if (local_transport == false)
        {
            cout << "Bus travel long distance: ";
            Transport::print();
        }
}

public:
    virtual ~Bus()
{

    cout << "  destructor Bus: ";
    Transport::print();

}

};



class Car:public Transport
{

private:
    float l_fuel_km;

public:
    Car()
    {
        cout << "\nPassenger car travel data input: " << endl;
        cout << "Consumption liter petrol per 100 kilometers: ";
        cin >> l_fuel_km;
    }


public:
    Car(float lit_fuel_km, float kilomt)
    {
        l_fuel_km = lit_fuel_km;
        Transport(km);
    }



private:
    float get_co2_km()
    {
        float fuel;
        fuel = (l_fuel_km/100) * 2.3;
        return fuel;
    }

public:
    void print()
    {
        cout << "passenger car travel: " << endl;
        Transport::print();

    }

};


class Flight: public Transport
{

public:

    Flight()
    {
        cout << "\nFlight travel data input: " << endl;

    }

public:
    Flight(float kmt)
    {
        Transport(km);
    }

private:
    float get_co2_pkm()
    {
        float co2_e = 0.27;
        return co2_e;
    }


public:
    void print()
    {
        cout << "Flight travel: ";
        Transport::print();

    }

public:
    virtual ~Flight()
    {
        cout << "destructor Flight: done" << endl;
    }

};



class Train: public Transport
{

private:
    bool local_transport;
    bool one_way;

public:
    Train()
    {
        int a;
        int b;
        cout << "\nTrain travel data input:\n(1) local transport\n(2) long distance " << endl;
        cout << "your choice:" << ends;
        cin >> a;

        if (a == 1)
        {
            local_transport = true;
        }
        else if (a == 2)
        {
            local_transport = false;
        }
        else
        {
            cerr << "Please select a valid choice!" << endl;
        }


        cout << "\n(1) one-way\n(2) return" << endl;
        cout << "your choice:" << ends;
        cin >> b;

        if (b == 1)
        {
            one_way = true;
        }
        else if (b == 2)
        {
            one_way = false;
        }
        else
        {
            cerr << "Please select a valid choice!" << endl;
        }

    }

public:
    Train(bool local_t, float kmtr, bool OneWay=true)
    {
        local_transport = local_t;
        Transport(km);
        one_way=OneWay;

    }

private:
    float get_co2_pkm()
    {
        float co2_e;
       if (local_transport==true)
       {
           co2_e = 0.085;
       }
       else if (local_transport==false)
       {
           co2_e = 0.035;
       }
        return co2_e;
    }

public:
     float get_co2()
    {
        float co2;
        if (one_way == true)
        {
            co2 = get_co2_pkm() * km;
        }
        else if (one_way == false)
        {
            co2 = 2 * get_co2_pkm() * km ;
        }

        return co2;
    }


public:
    void print()
    {

        string oneway;
        if(one_way == true)
        {
            oneway = " one way";
        }
        else if (one_way == false)
        {
            oneway = "return";
        }

        if (local_transport == true)
        {
            cout << "Train travel local transport: " << endl;
            Transport::print();
        }
        else if(local_transport == false)
        {
            cout << "Train travel long distance: " << endl;
            Transport::print();
        }
    }


public:
    virtual ~Train()
    {
        cout << "  destructor Train: " << endl;
        Transport::print();
    }
};



class Cruise: public CO2Emission
{

private:
    float days;
    float sea_days;

public:
    Cruise()
    {
        cout << "\nCruise holiday data input: " << endl;
        cout << "Number of days of the whole cruise: ";
        cin >> days;

        cout << "Number of sea days: ";
        cin >> sea_days;
    }

public:
    Cruise(float d, float sd)
    {
        days = d;
        sea_days = sd;
    }

private:
    float get_co2_day(bool s_days)
    {
        float co2;
        if (s_days == true)
        {
            co2 = 280;
        }
        else if (s_days == false)
        {
            co2 = 190;

        }
        return co2;
    }


public:
    float get_co2()
    {
        float co2_t;
        float co2_s;
        float co2_h;

        co2_s = get_co2_day(true) * sea_days;
        co2_h = get_co2_day(false) * (days - sea_days);

        co2_t = co2_s + co2_h;
        return co2_t;

    }

public:
    void print()
    {
        cout << "Cruise holiday (without flights): " << fixed << setprecision(0)<< days << " days duration with " << fixed << setprecision(0)<< sea_days << " sea days " << "( sea day " << fixed << setprecision(3) << get_co2_day(true) << " kg CO2/pkm, harbour day "  << fixed << setprecision(3)<< get_co2_day(false) << " kg CO2/pkm) " <<  fixed << setprecision(1) <<get_co2() << " kg CO2" <<endl;

    }

public:
    virtual ~Cruise()
    {
        cout << "  destructor Cruise: " << endl;
        CO2Emission::print();

    }

};


class CO2Footprint
{
private:
    string name;
    CO2Emission *emissions;

public:
    CO2Footprint(string nm)
    {
        name = nm;
        CO2Emission *emissions = nullptr;
    }

public:
    ~CO2Footprint()
    {
        cout << "destructor for CO2Footprint for" << name << "started..." << endl;

        //loop for delete all list items

        //public destructor writing "destructor for CO2Footprint for" , the name and
        //"started..." onto the standard character output stream,
        //then in a loop deletes all list items on the heap one by one and writes
        //"destructor CO2Foodprint done" onto the standard character output stream at the end (see example below).

    }

public:
    string get_name()
    {

        return name;
    }


public:
    add(CO2Emission *point)
    {

       *point = *emissions;

    }

public:
    float get_sum_co2()
    {
        //In the body the carbon emissions
        //of all list elements shall be added and this sum value get returned.
    }

public:
    void print()
    {
        cout << "CO2 FOODPRINT FOR: " << name << ends;
        Transport::print();

        //the message print shall be sent to all objects in the list,
        //then the sum of all CO2 emissions shall be calculated and
        //written onto the standard character output stream after "TOTAL CO2 EMISSIONS: " in
        //the units kg and tons, each with 1 decimal place (see example below).

    }


};

class Power: public CO2Emission
{

private:
    float kWh;

public:
    Power()
    {
       cout << "power data input kilo Watt hours: " << ends;
       cin >> kWh;
    }

public:
    Power(float kilow)
    {
        kWh = kilow;
    }

public:
    virtual ~Power()
    {
        cout << " destructor Power: " << kWh << " kWh done" << endl;
    }

private:
    virtual float get_co2_kWh() = 0;

public:
    float get_co2()
    {
       //public member function named get_co2 without parameter and with a floating point number as return.
       //In the body, the product of the kilo-watt hours consumed and the respective emission value for one kilo-watt hour (via a call
       //to the previously defined member function) shall be calculated and returned.

    }

public:
    void print()
    {

        cout << "power" << fixed << setprecision(1) << kWh << fixed << setprecision(3)
        << get_co2_kWh() << fixed << setprecision(3)
        << get_co2() << endl;
    }

};






//****WIND****

class Wind: public Power
{


public:
    Wind()
    {
        cout << "wind power data input:" << endl;
    }

public:
    Wind(float kilow)
    {
        Power(kWh) = kilow;
    }

private:
    float get_co2_kWh()
    {
        float co2_e;
        co2_e = 0.086;
        return co2_e;
    }


public:
    virtual ~Wind()
    {
        cout << "  destructor Wind: " << ends;
        Power::print();
    }


public:
    void print()
    {
        cout << "wind" << ends;
        Power::print();
    }



};

//****COAL****

class Coal: public Power
{
private:
    bool anthracite;

public:
    Coal()
    {
        char a;
        cout << "\nCoal power data input:\ntype of coal:\n(a) anthracite coal\n(l) lignite\nyour choice:" << ends;
        cin >> a;

        if (a == 'a')
        {
            anthracite = true;
        }
        else if (a == 'l')
        {
            anthracite = false;
        }

        cout << "kilo Watt hours: " << ends;
        cin >> kWh;

    }

public:
    Coal(float kilow, bool ant = true)
    {
        kWh = kilow;
        anthracite = ant;
    }

private:
    float get_co2_kWh()
    {
        float co2_e;

        if (anthracite == true)
        {
            co2_e = 0.798;
        }
        else if (anthracite == false)
        {
            co2_e = 1.150;
        }

        return co2_e;
    }


public:
    virtual ~Coal()
    {
        cout << "  destructor Coal: " << ends;
        print();
    }


public:
    void print()
    {
        if (anthracite == true)
        {
            cout << "anthracite coal" << ends;
            Power::print();
        }
        else if (anthracite == false)
        {
            cout << "lignite power: " << ends;
            Power::print();
        }

    }


};




//**** INT MAIN ****//

int main()
{
    //before the start of the input menu, send a message
    //add to the object f each with a pointer as parameter
    //to a newly created object on the heap of the type Wind resp.
    //Coal with 2000 kWh power consumption as parameter in the constructor call.



    Wind *w2 = new Wind{220*8*0.150};
    w2->print();

    Coal *k2 = new Coal{264};
    k2->print();

    Bus *b2 = new Bus{true,2200};
    b2->print();

    Car *c2 = new Car{7.5, 5500};
    c2->print();


    Cruise *h2 = new Cruise {14,3};
    h2->print();


    Flight *f2 = new Flight{2669.9};
    f2->print();


    Train *t2 = new Train {false, 628.8, false};
    t2->print();



    CO2Footprint::add(b2,c2,h2,f2,t2);


    char a;
    do
    {
        cout << "CO2 footprint input for" << CO2Footprint::get_name() << endl;
        cout << "(e) end\n(b) bus transport\n(c) car transport\n(f) flight tranport\n(h) holiday cruise\n(t) train transport\n(w) power from wind\n(k) power from coal\n(p) print all\n>>" << ends;
        cin >> a;


        switch(a)
        {
        case 'e': break;

        case 'b': b2->print();
            break;

        case 'c': c2->print();
            break;

        case 'f': f2->print();
            break;

        case 'h': h2->print();
            break;

        case 't': t2->print();
            break;

        case 'w': w2->print();
            break;

        case 'k': k2->print();
            break;

        case 'p':
            {
        b2->print();
        c2->print();
        f2->print();
        h2->print();
        t2->print();
        w2->print();
        k2->print();
            break;
            }

        default:    cout << "Please select a valid choice!" << endl;

        }


    }
    while(a != 'e');


    return 0;
}
