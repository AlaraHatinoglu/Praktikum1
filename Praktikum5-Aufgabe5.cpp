/*********
Matr.-Nr:                     3117193
Nachname/Surname:             Ciyrak
Vorname/Given name:           Alara
Uni-Email:                    Alara.Ciyrak@stud.uni-due.de
Studiengang/Course of studis: Computer Engineering
*********/


#include <iostream>
#include <iomanip>



using namespace std;


//****CLASS BUS****//



class Bus
{
private:
    bool local_transport; //option (1) = true POINT 1
    float km; //Point 2

public:
    Bus() //Point 3
    {
        cout << "\nBus travel data input: \n(1) local transport \n(2) long distance" << endl;
        cout << "Your choice: " << ends;
        int a;
        cin >> a;

        if (a == 1)
        {
            local_transport = true;
            cout << "kilometers: " << ends;
            cin >> km;

        }
        else if (a == 2)
        {
            local_transport = false;
            cout << "kilometers: " << ends;
            cin >> km;
        }
        else
        {
            cerr << "Please select a valid choice!" << endl;
        }


    }

public:
    Bus(bool l_transport, float kmeter) //point 4
    {
        local_transport = l_transport;
        km = kmeter;



    }

private:
    float get_co2_pkm() //co2 emission per km POINT 5
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
    float get_co2() // Point 6
    {
        float pkm;
        pkm = (get_co2_pkm() * km);
        return pkm;
    }


public:
    void print()
{


    if(local_transport == true)
        {
            cout << "Bus travel local transport: " << fixed << setprecision(1) << km << " km " << "(" << fixed << setprecision(3) << get_co2_pkm() << " kg CO2/pkm) " <<  fixed << setprecision(1) << get_co2() << " kg CO2" << endl;
        }

        else if (local_transport == false)
        {
            cout << "Bus travel long distance: " << fixed << setprecision(1) << km << " km " << "(" << fixed << setprecision(3) << get_co2_pkm() << " kg CO2/pkm) " << fixed << setprecision(1) << get_co2() << " kg CO2" << endl;
        }
}

};



//****CLASS CAR****//



class Car
{

private:
    float l_fuel_km;  // liters consumption of fuel per 100 kilometers.
    float km;  // number of kilometers driven




public:
    Car()
    {
        cout << "\nPassenger car travel data input: " << endl;
        cout << "Consumption liter petrol per 100 kilometers: ";
        cin >> l_fuel_km;

        cout << "Kilometers: " << ends;
        cin >> km;
    }


public:
    Car(float lit_fuel_km, float kilometer)
    {
        l_fuel_km = lit_fuel_km;
        km = kilometer;
    }



private:
    float get_co2_km() //POINT 5 formulas are wrong
    {
        // consuption is 2.3kg for every 100 km, which means 0.023kg per km

        float fuel;
        fuel = (l_fuel_km/100) * 2.3;
        return fuel;


    }



public:
    float get_co2()
    {
        float co2;
        co2 = get_co2_km() * km;
        return co2;

    }

public:
    void print()
    {
        cout << "passenger car travel: " << fixed << setprecision(1) << km << " km " << "(" << fixed << setprecision(3) << get_co2_km() << " kg CO2/pkm) " <<  fixed << setprecision(1) << get_co2() << " kg CO2" << endl;

    }

};


//****CLASS CRUISE****

class Cruise
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

};


//****CLASS FLIGHT****

class Flight
{
private:
    float km;

public:

    Flight()
    {
        cout << "\nFlight travel data input: " << endl;
        cout << "Kilometers:" << ends;
        cin >> km;

    }

public:
    Flight(float kmt)
    {
        km = kmt;
    }

private:
    float get_co2_pkm() //is it supposed to be like this?
    {
        float co2_e = 0.27;
        return co2_e;
    }

public:
    float get_co2()
    {
        float co2;
        co2 = km * get_co2_pkm();
        return co2;
    }

public:
    void print()
    {
        cout << "Flight travel: " << fixed << setprecision(1) << km << " km ("  << fixed << setprecision(3) << get_co2_pkm() << " kg CO2/pkm) " << fixed << setprecision(1) << get_co2() << " kg CO2" << endl;

    }

};


//****CLASS TRAIN****

class Train
{

private:
    bool local_transport;
    bool one_way;
    float km;

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



        cout << "kilometers:" << ends;
        cin >> km;

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
    Train(bool local_t, float kmtr, bool OneWay=true) //Default parameter??
    {
        local_transport = local_t;
        km = kmtr;
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
            cout << "Train travel local transport: " << fixed << setprecision(1) << km << "km (" << oneway << ", " << fixed << setprecision(3) << get_co2_pkm() << "kg CO2/pkm) " << fixed << setprecision(1) << get_co2() << " kg CO2" << endl;
        }
        else if(local_transport == false)
        {
            cout << "Train travel long distance: " << fixed << setprecision(1) << km << "km (" << oneway << ", " << fixed << setprecision(3) << get_co2_pkm() << "kg CO2/pkm) " << fixed << setprecision(1) << get_co2() << " kg CO2" << endl;
        }


    }


};

//****WIND****

class Wind
{

private:
    float kWh;

public:
    Wind()
    {
        cout << "wind power data input:" << endl;
        cout << "kilo Watt hours:" << ends;
        cin >> kWh;
    }

public:
    Wind(float kilow)
    {
        kWh = kilow;
    }

private:
    float get_co2_kWh()
    {
        float co2_e;
        co2_e = 0.086;
        return co2_e;
    }

public:
    float get_co2()
    {
        float co2;
        co2 = get_co2_kWh() * kWh;
        return co2;
    }

public:
    void print()
    {
        cout << "wind power: " << fixed << setprecision(1) << kWh << " kWh (" << fixed << setprecision(3) << get_co2_kWh() << " kg CO2/kWh) " << fixed << setprecision(1) << get_co2() << " kg CO2" << endl;

    }



};

//****COAL****

class Coal
{
private:
    bool anthracite;
    float kWh;

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
    float get_co2()
    {
        float co2;
        co2 = get_co2_kWh() * kWh;
        return co2;
    }

public:
    void print()
    {
        if (anthracite == true)
        {
            cout << "anthracite coal power: " << fixed << setprecision(1) << kWh << " kWh (" << fixed << setprecision(3) << get_co2_kWh() << " kg CO2/kWh) " << fixed << setprecision(1) << get_co2() << " kg CO2" << endl;
        }
        else if (anthracite == false)
        {
            cout << "lignite power: " << fixed << setprecision(1) << kWh << " kWh (" << fixed << setprecision(3) << get_co2_kWh() << " kg CO2/kWh) " << fixed << setprecision(1) << get_co2() << " kg CO2" << endl;
        }

    }


};




//****INT MAIN****


int main()
{
    Wind w1;
    Wind *w2 = new Wind{220*8*0.150};
    w1.print();
    w2->print();

    Coal k1;
    Coal *k2 = new Coal{264};
    k1.print();
    k2->print();


    Bus b1;
    Bus *b2 = new Bus{true,2200};
    b1.print();
    b2->print();

    Car c1;
    Car *c2 = new Car{7.5, 5500};
    c1.print();
    c2->print();

    Cruise h1;
    Cruise *h2 = new Cruise {14,3};
    h1.print();
    h2->print();

    Flight f1;
    Flight *f2 = new Flight{2669.9};
    f1.print();
    f2->print();

    Train t1;
    Train *t2 = new Train {false, 628.8, false};
    t1.print();
    t2->print();


    float co2_sum = b1.get_co2()+ b2->get_co2() + c1.get_co2() + c2->get_co2() + h1.get_co2() + h2->get_co2() + f1.get_co2() + f2->get_co2() + t1.get_co2() + t2->get_co2() + w1.get_co2() + w2->get_co2() + k1.get_co2() + k2->get_co2();
    cout << "\nThe added total of all CO2 emissions is " << co2_sum << " kg = " << fixed << setprecision(1) << (co2_sum/1000) << " tons" << endl;


    cout << "\nBased purely on the CO2 absorption capacity of nature, each world citizen should currently afford a maximum of around 2.3 tons per year." << endl;

    return 0;


}
