#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{
public:
    string name;
    double weight;
    double wholesale_price;
    double retail_price;
    double profit_per_kg;
    double total_profit;

    Item(string n, double w, double wp, double rp){
        name = n;
        weight = w;
        wholesale_price = wp;
        retail_price = rp;
        profit_per_kg = retail_price - (wholesale_price / w);
        total_profit = profit_per_kg * w;
    }
    void display(){
        cout << "Name:" << name
             << ", Bundle Weight: " << weight
             << ", Wholesale Price: " << wholesale_price
             << ", Retail/Kg: " << retail_price
             << ", Profit/Kg: " << profit_per_kg
             << ", Total Profit: " << total_profit << endl;
    }
};

bool Compare(Item a, Item b){
    return a.profit_per_kg > b.profit_per_kg;
}

void FractionalKnapsack(vector<Item> itemList, int n, double capacity){
    sort(itemList.begin(), itemList.end(), Compare);

    cout << "Sorted items by Profit/kg: " << endl;
    for(Item i : itemList) i.display();
    cout << "\nSelected Items: " << endl;

    double profit = 0;
    int i = 0;

    while(capacity > 0 && i < n){
        if(itemList[i].weight <= capacity){
            profit += itemList[i].total_profit;
            capacity -= itemList[i].weight;
            itemList[i].display();
        }else{
            double weight_taken = capacity;
            double p = weight_taken * itemList[i].profit_per_kg;
            profit += p;
            cout << "Name:" << itemList[i].name
                 << ", Weight: " << weight_taken
                 << ", Profit: " << p
                 << ", Profit/Kg: " << itemList[i].profit_per_kg << endl;
            capacity = 0;
        }
        i++;
    }
    cout << "\nMaximum Profit: " << profit << endl;
}

int main(){
    vector<Item> products = {
        Item("Rice", 100, 4000, 55),
        Item("Sugar", 200, 9000, 62),
        Item("Wheat", 350, 7000, 30),
        Item("Onion", 250, 12000, 80)
    };

    int n = products.size();
    double w_capacity = 600;
    FractionalKnapsack(products, n, w_capacity);
    return 0;
}
