/***********************************************************************
Matr.-Nr:                     3117193
Nachname/Surname:             Ciyrak
Vorname/Given name:           Alara
Uni-Email:                    Alara.Ciyrak@stud.uni-due.de
Studiengang/Course of studis: Computer Engineering
***********************************************************************/



#include <iomanip>
#include <iostream>
#include <string>


using namespace std;


struct bus
{
    int c_pass;
    int max_pass;
    float t_time;

};

struct stop
{
    string stopname;
    int notimes; //Number of times that the bus stopped at the station
    int gotOn;
    int gotOff;
    float travel_time;
    stop *next;
};

stop *head=nullptr;

void init(bus &bus1){

    bus1.c_pass = 0;
    bus1.max_pass = 0;
    bus1.t_time = 0; //total time

}


void output(bus &bus1)
{

    cout << "bus data: "<< "total: " << bus1.t_time << " min "<< "  passengers: actual: " << bus1.c_pass << " maximum in simulation: " << bus1.max_pass << "\n" << endl;

}


stop* generate_stop(string stopname)

{

    stop *new_stop=new stop;
    new_stop->stopname = stopname;
    new_stop->notimes = 0;
    new_stop->gotOn = 0;
    new_stop->gotOff = 0;
    new_stop->travel_time= (1+rand() %3);
    return new_stop;
}

stop * generate_circular_line(int n)
{
    stop* start= generate_stop("Bus Stop " + to_string(1));
    stop* temp=start;

    for(int f=2; f<=n; f++){

        stop *new_stop= generate_stop("Bus Stop " + to_string(f));
        temp ->next=new_stop;
        temp=new_stop;
    }
temp ->next=start;
return start;

}

void output (stop &new_stop)
{
    cout << new_stop.stopname << "\tto next: "<< new_stop.travel_time<< " min" << "   sums: off: " << new_stop.gotOff << "\ton: " << new_stop.gotOn << "\tstops: " << new_stop.notimes << endl;
}


void output_whole_line(stop& new_stop)
{

    stop *temp=  &new_stop;
    do{
    output(*temp);
    temp=temp->next;

}
while(temp!=& new_stop);
}

void *simulate_get_on_off (bus &bus1, stop * new_stop, int getOff, int getOn )
{


    if(getOff > bus1.c_pass )
        getOff = bus1.c_pass;



    bus1.c_pass-=getOff;
    bus1.c_pass+=getOn;
    bus1.max_pass+=getOn;
    bus1.t_time+=new_stop->travel_time;

    new_stop->gotOn+=getOn;
    new_stop->gotOff+=getOff;
    new_stop->notimes++;



    cout << "simulate " << new_stop->stopname << ":\t getting off: " << getOff << " getting on: " << getOn << endl;
    output(*new_stop);



}


float get_duration_of_line(stop *a)
{

float time;

if(a != nullptr && (a->next !=  a))
{
   stop *time1 = a;

   do
   {
       time+=time1->travel_time;
       a = a->next;
   }

   while(time1 != a);
}


return time;

}





int main()
{

    int n;
    cout << "Eingabe Anzahl Haltestellen / input number of bus stops:" << ends;
    cin >> n;
    stop*new_stop= generate_circular_line(n);
    bus bus1;
    init(bus1);
    stop* a = generate_circular_line(n);


    char z;

    do
   {

       cout << "\nSimulation Ring-Buslinie     / Simulation Bus Circular Line" << endl;
       cout << "0 Ende                       / end" << endl;
       cout << "1 Daten Bus anzeigen         / show data of bus" << endl;
       cout << "2 alle Haltestellen ausgeben / show all bus stops" << endl;
       cout << "3 simuliere Stops            / simulate bus stops" << endl;
       cout << "4 Dauer einer Ring-Runde     / duration of a circular round" << endl;
       cout << ">>" << ends;
       cin >> z;

    switch(z)
    {
       case '0' : break;

       case '1' : output(bus1);
                  break;

       case '2' :{
                  output_whole_line(*new_stop);
                  break;

           };

       case '3' :{
               cout << "Eingabe Anzahl Haltestellen / input number of bus stops:" << ends;
               cin >> n;
           for (int i = 0; i < n; i++)
                { simulate_get_on_off (bus1, new_stop ,(1+rand() %9), (1+rand() %9));
                new_stop=new_stop->next;

                 }
                 break;
                 }

       case '4' :{
           bus bus1;
           stop new_stop;
           get_duration_of_line(a);



           cout << "Duration of circular line: " <<  get_duration_of_line(a) << " min" << endl;



           break;
       }



       default:    cout << "Please select a valid choice!" << endl;
       }
       }
       while(z != '0');

}
