#include<bits/stdc++.h>
using namespace std;
class Shop
{
private:
    int total_income;
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];


    int getter()
    {
        return this->total_income;
    }
    void setter(int income)
    {
        this->total_income += income;
    }
    Shop(int n,string name[],int price[],int quantity[])
    {
        this->total_income = 0;
        for(int i=0; i<n; i++)
        {
            this->product_name[i] = name[i];
            this->product_price[i] = price[i];
            this->product_quantity[i] = quantity[i];

        }

    }
    void upgrade_quantity(int n, int length)
    {
        this->product_quantity[length-1] -= n;
    }


};

Shop *inputShop(int n)
{
    string name;
    int price, quantity;
    string product_name[n];
    int product_price[n];
    int product_quantity[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Product "<<i+1<<" Name : ";
        cin>>name;
        cout<<"Product "<<i+1<<" Price : ";
        cin>>price;
        cout<<"Product "<<i+1<<" Quantity : ";
        cin>>quantity;
        product_name[i] = name;
        product_price[i] = price;
        product_quantity[i] = quantity;

    }
    Shop *myShop = new Shop(n,product_name,product_price,product_quantity);
    return myShop;
}

void print_details(Shop *shop,int n)
{
    cout<<"\t\t\tBUY PRODUCT"<<endl;
    cout<<"\t\t\t____________"<<endl;
    cout<<"Product Index : \t\t";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<"\t\t";
    }
    cout<<"\nProduct Name : \t\t\t";
    for(int i=0; i<n; i++)
    {
        cout<<shop->product_name[i]<<"\t\t";
    }
    cout<<"\nProduct Price : \t\t";
    for(int i=0; i<n; i++)
    {
        cout<<shop->product_price[i]<<"\t\t";
    }
    cout<<"\nProduct Quantity : \t\t";
    for(int i=0; i<n; i++)
    {
        cout<<shop->product_quantity[i]<<"\t\t";
    }
}
int price_counter(Shop *shop,int opt,int amount)
{

    int total = shop->product_price[opt-1]*amount;
    return total;

}

void buy_product(Shop *shop, int n)
{

    int opt,quantity;
    cout<<"\nWhich product do you want from 1 to "<<n<<" : ";
    cin>>opt;
    cout<<"What is the quantity that you want of "<<shop->product_name[opt-1]<<" : ";
    cin>>quantity;

    if(quantity <= shop->product_quantity[opt-1])
    {
        shop->upgrade_quantity(quantity,opt);
        int income = price_counter(shop,opt,quantity);
        shop->setter(income);
        cout<<"Total income is : "<<shop->getter()<<endl;
    }
    else
    {
        cout<<"This Quantity of this product is not available."<<endl;
    }
}



int main()
{
    int n;
    cout<<"Number of products : ";
    cin>>n;
    Shop *shop = inputShop(n);
    while(true)
    {
        print_details(shop,n);
        buy_product(shop,n);
    }

    return 0;
}
