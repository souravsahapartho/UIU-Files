#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Drink
{
public:
    string name;
    double volume;
    double glucose;
    double glucose_per_Litre;

    Drink(string n, double v, double g)
    {
        name = n;
        volume = v;
        glucose = g;
        glucose_per_Litre = g / v;
    }
    void display()
    {
        cout << "Name: " << name
             << ", Volume: " << volume
             << ", Glucose: " << glucose
             << ", Glucose/Litre: " << glucose_per_Litre << endl;
    }
};

bool Compare(Drink a, Drink b)
{
    return a.glucose_per_Litre < b.glucose_per_Litre;
}

void MinGlucose(vector<Drink> list, int n, double volume)
{
    sort(list.begin(), list.end(), Compare);

    cout << "Sorted drinks by Glucose/Litre: " << endl;
    for (auto &d : list)
        d.display();
    cout << "\nSelected Drinks: " << endl;

    double total_glucose = 0;
    int i = 0;

    while (volume > 0 && i < n)
    {
        if (list[i].volume <= volume)
        {
            total_glucose += list[i].glucose;
            volume -= list[i].volume;
            list[i].display();
        }
        else
        {
            double volume_taken = volume;
            double g = volume_taken * list[i].glucose_per_Litre;
            total_glucose += g;
            cout << "Name: " << list[i].name
                 << ", Volume: " << volume_taken
                 << ", Glucose:" << g
                 << ", Glucose/Litre:" << list[i].glucose_per_Litre << endl;
            volume = 0;
        }
        i++;
    }
    cout << "\nMinimum glucose to consume: " << total_glucose << " gm" << endl;
}

int main()
{
    vector<Drink> drinks = {
        Drink("Galxose-D", 3, 75),
        Drink("GlucoMax", 4, 80),
        Drink("Sting", 5, 150)};

    double total_volume = 6;
    MinGlucose(drinks, drinks.size(), total_volume);
    return 0;
}
