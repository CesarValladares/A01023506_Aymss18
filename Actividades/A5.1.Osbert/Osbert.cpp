#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paint{
private:
    string Author;
    float price;
public:
    Paint(string A, int P){
        Author = A;
        price = P;
    }

    string getAuthor()
    {
        return Author;
    }
    int getPrice(){
        return price;
    }
    void getInfo(){
        cout << Author << endl;
        cout << price << endl;|
    }
};

class Offer  {
    Offer(Paint p);
    float crateoffer(){
        float x = p.getPrice();
        return x - x/10;
    }
};

class Gallery : Paint{

    int NumberP; 
    vector<Paint> G;

    Gallery(){
        NumberP = 0;
    }

    void newPaint(Paint A){

        G.push(A);
    }
    void ShowGallery(){
        if (G.size() == 0){
            cout << "No hay pinturas" << endl;
        }else{
            for(int i = 0; i < G.size(); i++){
                G[i].getInfo(); 
                cout << endl;
            }
        }
    }
};

class Auction{
private: 
    Paint P;
    float price;
    date Date;
public:
    Auction(Paint p, float c, date d){
        P = p; 
        price = c; 
        Date = date;
    }

    void getPinturas(){
        P.getInfo();
    }

    float getPrice(){
        return price;
    }

    date getDate(){
        return date;
    }
}

int main(){

    

    return 0;
}
