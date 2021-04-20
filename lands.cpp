#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
            
        case FOREST:
            return new Forest;
            break;
            
        case DESERT:
            return new Desert;
            break;
            
        case MOUNTAIN:
            return new Mountain;
            break;
            
        case GLACIER:
            return new Glacier;
            break;
            
        case OASIS:
            return new Oasis;
            break;
            
        case VILLAGE:
            return new Village;
            break;
            
        case RIVER:
            return new River;
            break;
            
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(p.getThirst() + 1);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    
    if(chance >= 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    
    if(chance >= 10 && chance <= 49){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 2);
    }
    
    
    if(chance < 10){
        description = "You are attacked by two very large bears!";
        p.setHealth(p.getHealth() - 4);
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    int chance = rand() % 100;
    
    if(chance > 50){
        description = "You spent too much time in the desert caused dehydration";
        p.setThirst(p.getThirst() - 2);
        return description;
    }
    
    
    if(chance <= 50){
        description = "You were able to get some water from a cactus to fulfill your thirst ";
        p.setThirst(p.getThirst() + 2);
    }

    return description;
}

string Mountain::getShortDescription(){
    return "Mountain";
}

string Mountain::getLongDescription(){
    return "You have found a mountain with abundace of food but be aware you might have to take treacherous trails to get the food";
}

string Mountain::visit(Player& p){
    
    int chance = rand() % 100;
    string description;
    
    if(chance > 50){
        description = "LUCKY!!! You found food at the foot of the mountain";
        p.setHunger(p.getHunger() + 2);
        return description;
    }
    
    
    if(chance >= 0 && chance <= 25 ){
        description = "You had to take a difficult trail to obtain the food. You are now thirsty after the difficult trail ";
        p.setHunger(p.getHunger() + 2);
        p.setThirst(p.getThirst() - 4);
    }
    
    
    if(chance >= 26 && chance <= 50){
        description = "You were able to fulfill your hunger but encontered a lion.";
        p.setHunger(p.getHunger() + 2);
        p.setHealth(p.getHealth() - 4);
    }
    
    
    return description;
}

string Glacier::getShortDescription(){
    return "Glacier";
}

string Glacier::getLongDescription(){

    return "You have arrived at a beautiful glacier with fresh, crystal clear water but beware the the temperature is freezing cold";
}

string Glacier::visit(Player& p){
    
    int chance = rand() % 100;
    string description;
    
    if(chance > 70){
        description = "You were able to replenish your thirst";
        p.setThirst(p.getThirst() + 1);
        return description;
    }
    
    
    if(chance >= 0 && chance <= 25 ){
        description = "You were able to replenish your thirst but lost a little health because it was too cold";
        p.setHealth(p.getHealth() - 3);
        p.setThirst(p.getThirst() + 1);
    }

    
    return description;
}

string Oasis::getShortDescription(){
    return "Oasis";
}

string Oasis::getLongDescription(){

    return "You have entered an abonded oasis full of water. There are no predators so you can replenish not only your thist but your health as well ";
}

string Oasis::visit(Player& p){
    
    string description = "You were able to replenish your thirst and health";
    p.setThirst(p.getThirst() + 1);
    p.setHealth(p.getHealth() + 1);
    return description;
}

string Village::getShortDescription(){
    return "Village";
}

string Village::getLongDescription(){

    return "You have entered into a village";
}

string Village::visit(Player& p){
    
    int chance = rand() % 100;
    string description;
    
    if(chance >= 50){
        description = "You reached a village full of people and they were glad to see you here. The people gave you everything you needed to continue with your journey.";
        p.setThirst(p.getThirst() + 1);
        p.setHunger(p.getHunger() + 1);
        p.setHealth(p.getHealth() + 1);
        return description;
    }
    
    
    if(chance >= 26 && chance <= 49 ){
        description = "The village was deserted and you found nothing.You are more tired now";
        p.setHealth(p.getHealth() - 4);
    }
    
    if(chance >= 0 && chance <= 25 ){
        description = "You ran into a group of people who stole your food and water";
        p.setThirst(p.getThirst() - 4);
        p.setHunger(p.getHunger() - 4);
    }
    
    return description;
}

string River::getShortDescription(){
    return "River";
}

string River::getLongDescription(){

    return "You are at the river which has the most amazing fish ever ";
}

string River::visit(Player& p){
    
    int chance = rand() % 100;
    string description;
    
    if(chance >= 50){
        description = "You were able to eat fish to your hearts content";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    
    if(chance >= 0 && chance <= 49 ){
        description = "You were attacked by a crocodile that was hiding inside the river";
        p.setHealth(p.getHealth() - 3);
    }

    
    return description;;
}