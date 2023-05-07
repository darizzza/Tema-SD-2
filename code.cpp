#include <bits/stdc++.h>
using namespace std;

struct nod
{
    int key;
    nod *parinte;
    char color;
    nod *st;
    nod *dr;
};

struct tree
{
    nod *radacina;
};
tree *rbtree;

void RotatieSt(nod *x){
    nod *y=x->dr;
    x->dr=y->st;
    if(y->st!=nullptr)
        y->st->parinte=x;
    y->parinte=x->parinte;
    if(x->parinte==nullptr)
        rbtree->radacina=y;
    else if(x==x->parinte->st)
        x->parinte->st=y;
        else
            x->parinte->dr=y;
}

void RotatieDr(nod *x){
    nod *y=x->st;
    x->st=y->dr;
    if(y->dr!=nullptr)
        y->dr->parinte=x;
    y->parinte=x->parinte;
    if(x->parinte==nullptr)
        rbtree->radacina=y;
    else if(x==x->parinte->dr)
        x->parinte->dr=y;
        else
            x->parinte->st=y;
    y->dr=x;
    x->parinte=y;
}

nod *Cautare(int cheie){
    nod *x=rbtree->radacina;
    while(x!=nullptr &&x->key!=cheie)
        if(cheie<x->key)
            x=x->st;
        else
            x=x->dr;
    return x;
}

void FixareNod(nod *x){
    while(x->parinte != nullptr && x->parinte->color == 'R'){
        if(x->parinte == x->parinte->parinte->st){
            nod *y = x->parinte->parinte->dr;
            if(y != nullptr && y->color == 'R'){
                x->parinte->color = 'B';
                y->color = 'B';
                x->parinte->parinte->color = 'R';
                x = x->parinte->parinte;
            }
            else{
                if(x == x->parinte->dr){
                    x = x->parinte;
                    RotatieSt(x);
                }
                x->parinte->color = 'B';
                x->parinte->parinte->color = 'R';
                RotatieDr(x->parinte->parinte);
            }
        }
        else{
            nod *y = x->parinte->parinte->st;
            if(y != nullptr && y->color == 'R'){
                x->parinte->color = 'B';
                y->color = 'B';
                x->parinte->parinte->color = 'R';
                x = x->parinte->parinte;
            }
            else{
                if(x == x->parinte->st){
                    x = x->parinte;
                    RotatieDr(x);
                }
                x->parinte->color = 'B';
                x->parinte->parinte->color = 'R';
                RotatieSt(x->parinte->parinte);
            }
        }
    }
    rbtree->radacina->color = 'B';
}

void Inserare(int cheie){
    nod *nou=new nod;
    nou->key=cheie;
    nou->st=nullptr;
    nou->dr=nullptr;
    nou->color='R';
    if(rbtree->radacina==nullptr){
        rbtree->radacina=nou;
        nou->color='B';
        return;
    }
    nod *parinte=nullptr;
    nod *curent=rbtree->radacina;
    while(curent!=nullptr){
        parinte=curent;
        if(cheie<curent->key)
            curent=curent->st;
        else if(cheie>curent->key)
            curent=curent->dr;
        else{
            cout<<"Cheia exista in arbore.";
            return;
        }
    }

    nou->parinte=parinte;
    if(cheie<parinte->key)
        parinte->st=nou;
    else
        parinte->dr=nou;
    FixareNod(nou);
}

nod *Minim(nod *x){
    while(x->st!=nullptr)
        x=x->st;
    return x;
}


int main()
{

}
