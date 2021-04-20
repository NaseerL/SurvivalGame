#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"

using namespace std;

enum PlayerChoice {NORTH, SOUTH, EAST, WEST};

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

bool getPlayerInput(PlayerChoice &playerChoice){
    
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if(input == "n" || input == "north"){
        playerChoice = NORTH;
    } else if(input == "s" || input == "south"){
        playerChoice = SOUTH;
    } else if(input == "e" || input == "east"){
        playerChoice = EAST;
    } else if(input == "w" || input == "west"){
        playerChoice = WEST;
    } else {
        cout << "Invalid input." << endl;
        return false;
    }
    
    return true;
}


int main(){
    
    int score = 0;
    const unsigned int MAP_SIZE = 20;
    Player player(Player::DEFAULT_HEALTH, 
                  Player::DEFAULT_HUNGER, 
                  Player::DEFAULT_THIRST, 
                  MAP_SIZE/2, MAP_SIZE/2);
    
    //Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            map[i][j] = getRandomLand();
            
        }
    }
    
    cout << "You wake up in a " << 
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << endl;
        
    while(player.getHealth() >= 0 && player.getHunger() >= 0 && player.getThirst() >= 0){
        
        
        
        score = score + 1;
        
        // Give description of surroundings
        int x = player.getX();
        int y = player.getY();
        
        cout << map[x][y]->getLongDescription() << endl << endl;
        cout << map[x][y]->visit(player) << endl << endl;
        
        cout << x << "," << y << endl;
        
        if (player.getHealth() >= 1 && player.getHunger() >= 1 && player.getThirst() >= 1){
            cout << player.printStats() << endl << endl;
        }else {
            break;
        }
        
        // TODO: Handle boundry conditions
        cout << "To the north you see a " << map[x][y + 1]->getShortDescription() << endl;
        cout << "To the south you see a " << map[x][y - 1]->getShortDescription() << endl;
        cout << "To the east you see a " << map[x + 1][y]->getShortDescription() << endl;
        cout << "To the west you see a " << map[x - 1][y]->getShortDescription() << endl;
        
      
        PlayerChoice playerChoice;
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice){
            case NORTH:
                player.setY(player.getY() + 1);
                break;
            case SOUTH:
                player.setY(player.getY() - 1);
                break;
            case EAST:
                player.setX(player.getX() + 1);
                break;
            case WEST:
                player.setX(player.getX() - 1);
                break;
            default:
                cout << "Invalid input found: " << playerChoice << endl;
                break;
        }
        
            clearTerminal();

        
        if (player.getX() >= 19){
            
            player.setX(1);
            
            }else if (player.getX() <= 0) {
            
            player.setX(18);
        }
        if (player.getY() >= 19){
            
            player.setY(1);
            
        }else if (player.getY() <= 0){
            
            player.setY(18);
        }

    }
   
   
    
    if (player.getHealth() <= 0){
        
        cout << "The player health bar has reached to 0. You lose  " << endl;
        
    } else if(player.getThirst() <= 0){
        
        cout << "The player Thirst bar has reached to 0. You lose " << endl;
        
    } else if(player.getHunger() <= 0){
        
        cout << "The player hunger bar has reached to 0. You lose " << endl;
    }
    
    cout << "Your score: "<< score << endl;
    
    return 0;
}