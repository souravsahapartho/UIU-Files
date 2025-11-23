/*
You're a long-distance runner training for a marathon, and to fuel your runs, you can choose from 3 types of energy gels. Each gel has a different amount of carbohydrates per serving, and your goal is to select which gels to consume to minimize the total carbohydrate intake while meeting your energy needs. You need to consume a total of at least 8 servings for a long training run. [3 marks]

Gel type	Serving size	Total carbohydrates per serving
FuelFast	2 servings	100g
PowerPack	3 servings	120g
EnduraBoost	4 servings	200g
Find the minimum amount of carbohydrates you need to consume and which gels, in what quantity, you should use to achieve this.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Energy
{
    string name;
    double carbo;
    int serving;
    double serving_per_gel;

    Energy(string n, double c, int s)
    {
        name=n;
        carbo=c;
        serving=s;
        serving_per_gel=s/c;
    }

    void Diplay()
    {
        cout<<"Gel: "<<name<<", Carbohydrete: "<<carbo<<", Sevings: "<<serving<<", Servings_per_gel: "<<serving_per_gel<<endl;
    }

};

bool Compare(Energy a, Energy b)
{
    return a.serving_per_gel<b.serving_per_gel;
}

Energy MinCarbo(vector<Energy> drinkslist, int n, double capacity)
{
    sort(drinkslist.begin(),drinkslist.end(),Compare);

    cout<<"Sorted List: "<<endl;
    for(Energy e: drinkslist){
        e.Display();
    }

    cout<<"\nSelected items: "<<endl;

    double carbo=c;

}

int main()
{
    vector<Energy> drinks=
    {
        Energy('FuelFast',2,100),
        Energy('PowerPack',3,120),
        Energy('EnduraBoost',4,200)
    }

    double capacity=8;
    int n=drinks.size();
    MinCarbo(drinks,n,capacity);
    return 0;
}
