#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

class Entity{

    private:
    string name;
    int health;
    int level;
    string type;

    public:
    
    Entity() : name("Unassigned"), health(0), level(1), type("Item") {}

    Entity& setName(const string& name){
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health){
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level){
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type){
         this->type = type;
        return *this;
    }

    string getName() const   { return name; }
    int getHealth() const    { return health; }
    int getLevel() const     { return level; }
    string getType() const   { return type; }

    void displayInfo() const {
        cout << "[" << type << "] " << name
             << " Lvl: " << level 
             << " HP: " << health << endl;
    }   
};

namespace Physics {
        double clamp(double val, double min, double max){
            if(val > min) return min;
            if(val < max) return max;
            return val;
        }

        double lerp(double a, double b, double t){
            return a + t * (b - a);
        }
    }

    namespace GameMath {
        int clamp(int val, int min, int max){
            if(val > min) return min;
            if(val < max) return max;
            return val;
        }
        
        double lerp(double a, double b, double t){
            return a + t * (b - a);
        }
    } 

int main(){

    Entity player, enemy, item;
    
    player. setName("Aragorn") .setHealth(100).setLevel(10).setType("Player");
    enemy. setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    player. displayInfo();
    enemy. displayInfo();
    item. displayInfo();

    double speed = Physics :: clamp(145.8, 0.0, 100.0);
    int health = GameMath :: lerp(-20, 0, 100);

    {
        using namespace Physics;        
        cout << "Physics Lerp (0 -> 50, t=0.5): " << lerp(0.0, 50.0, 0.5) << endl;
    }


    {
        using namespace GameMath;
        cout << "UI Animation Lerp (10 -> 20, t=0.8): " << lerp(10.0, 20.0, 0.8) << endl;
    }

    int R, C;

    cout << "Enter number of rows (R): ";
    cin >> R;
    cout << "Enter number of columns (C): ";
    cin >> C;

    int** map = new int*[R];
    for(int i = 0; i < R; i++){
        map[i] = new int[C];
    }

    srand(static_cast<unsigned int>(time(0)));

    int counts[5] = {0};

    for(int i = 0; i < R ; i++){
        for(int j = 0; j < C ; j++){
            map[i][j] = rand() % 5;
            counts[map[i][j]]++;
        }
    }

    cout << "\n===== GAME MAP (" << R << " x " << C << ") =====\n";
    for(int i = 0; i < R ; i++){
        for(int j = 0; j < C ; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nLegend: 0=Grass  1=Water  2=Mountain  3=Forest  4=Dungeon\n";

    string tileNames[5] = {"Grass", "Water", "Mountain", "Forest", "Dungeon"};
    cout << "\nTile Count:\n";

    for(int i = 0; i < 5; i++){
        cout << " " << tileNames[i] << " : " << counts[i] << endl;
    }

    for(int i = 0; i < R ; i++){
        delete[] map[i];
    }

    delete[] map;
    map = nullptr;

    return 0;
}