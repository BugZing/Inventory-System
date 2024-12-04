#include<iostream>
using namespace std;

int const MAXHEALTH = 100, MAXMANA = 100, MAXARMOUR = 100;
// platyer stats
int playerStats[] = {50,50,0};
int playerInput = 0;

// for inventory
int maxInventory = 0, curInventory = 0, maxInventoryBack =0;

// items description and purpose
string item[] = {"Health Potion", "Mana Potion", "Poison", "Armour"};
string itemDesc[] = {"Heals your health for 25", "Replenish your mana for 25", "Damages your health for 10", "Adds your armour for 10"};
int itemQty[] = {5,4,15,1};


// functions for inventory
int Showinventory();
int showStats();
int inventoryTask();
int showDesc();
int discardItem();

int main()
{
    maxInventory = sizeof(item)/sizeof(item[0]) - 1;
    
    showStats();
    return 0;
}


int ShowInventory()
{
    system("cls");
    curInventory = 0;
    cout << "YOUR INVENTORY \n"
    << "name / quantiy\n";

    do{
    cout << curInventory << ". " << item[curInventory] << ": " << itemQty[curInventory] << endl;
    curInventory++;
    }
    while (maxInventory >= curInventory);
    
    maxInventoryBack = maxInventory +1;
    cout << maxInventoryBack << ". Back\n";
    
    cout<< "Which do you pick?\n>";
    cin >> playerInput;
    curInventory = playerInput;
    
    if(0<= playerInput && maxInventory >= playerInput)
    {
        inventoryTask();
    }
    else if(maxInventoryBack == playerInput){
        showStats();    
    }
    else{
        cout << "!! Please insert a given whole number !!\n";
        system("pause");
        
        showInventory();
        }

}

int showStats()
{
    system("cls");
    
    cout <<"YOUR STATS\n"
    << "Health: " << playerStats[0] << endl
    << "Mana: " << playerStats[1] << endl
    << "Armour: " << playerStats[2] << endl;
    system("pause");
    
    showInventory();
}

int inventoryTask()
{
    system("cls");
    
    cout <<    "What do you want to do?\n1. Read description\n2. Use\n3. Discard\n4. Back\n>";
    cin >>    playerInput;
    
    switch(playerInput){
        case 1:
        cout << showDesc();
        break;
        case 2:
        cout << playerInput;
        break;
        case 3:
        cout << discardItem();
        break;
        case 4:
        cout << showInventory();
        break;
        default:
        cout << "!! Please input a valid number !!\n";
        system("pause");
        inventoryTask();
    }
    
    }
    
    
    int showDesc(){
        system("cls");
        cout << item[curInventory] << endl <<  "Description: " << itemDesc[curInventory] << endl << "In stock: " << itemQty[curInventory] << endl <<    endl;
        system("pause");
        showInventory();
    }
    
    int discardItem(){
        system("cls");
        if(0 < itemQty[curInventory]){
            itemQty[curInventory] -= 1;
            cout << "You had discarded your " << item[curInventory] << endl;
        }
        else if(0 == itemQty[curInventory]){
            cout <<  "You do not have any " << item[curInventory] << " in your inventory.\n";
            
            }
            
        system("pause");
        showStats();
    }