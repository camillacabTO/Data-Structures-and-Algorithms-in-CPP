//
//  FamilyMembersBST.cpp
//  BSTQ1
//
//  Created by Camila Barros on 2019-07-23.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include "FamilyMembersBST.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Family_Member* CreateMember(int ag, float he, string na){
    Family_Member* newMember = new Family_Member();
    newMember->age = ag;
    newMember->height = he;
    newMember->name = na;
    newMember->left = newMember->right = NULL;
    return newMember;
}

Family_Member* AddMember(Family_Member* root,int ag, float he, string na){
    if(root == NULL){
        root = CreateMember(ag,he, na);
    } else if (na.compare(root->name) < 0){
        root->left = AddMember(root->left,ag, he, na);
    } else {
        root->right = AddMember(root->right,ag, he, na);
    }
    return root;
}

void PreorderPrint(Family_Member* root){
    if(root == NULL) return;
    cout << root->name << endl;
    cout << root->age << endl;
    cout << root->height << endl;
    PreorderPrint(root->left);
    PreorderPrint(root->right);
}

void InOrderPrint(Family_Member* root){
    if(root == NULL) return;
    InOrderPrint(root->left);
    cout << root->name << endl;
    cout << root->age << endl;
    cout << root->height << endl;
    InOrderPrint(root->right);
}

void PostOrderPrint(Family_Member* root){
    if(root == NULL) return;
    PostOrderPrint(root->left);
    PostOrderPrint(root->right);
    cout << root->name << endl;
    cout << root->age << endl;
    cout << root->height << endl;
}

bool Search(Family_Member* root, string na){
    if (root == NULL)
        return false;
    if (root->name == na){
        PrintNode(root);
        return true;
    }
    bool leftSide = Search(root->left, na);
    bool rightSide = Search(root->right, na);
    return leftSide || rightSide;
}

void PrintNode(Family_Member* node){
    cout << "Name: " << node->name << endl;
    cout << "Age: " << node->age << endl;
    cout << "Height: " << node->height << endl;
}

Family_Member* FindMin(Family_Member* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

Family_Member* Delete(Family_Member* root, string na){
    if(root == NULL) return root;
    else if(na.compare(root->name) < 0)
        root->left = Delete(root->left,na);
    else if(na.compare(root->name) > 0)
        root->right = Delete(root->right,na);
    else {
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        } else if (root->left == NULL){
            Family_Member* temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == NULL){
            Family_Member* temp = root;
            root = root->left;
            delete temp;
        } else {
            Family_Member* temp = FindMin(root->right);
            root->name = temp->name;
            root->age = temp->age;
            root->height = temp->height;
            root->right = Delete(root->right,temp->name);
        }
    }
    return root;
}

Family_Member* UpdateName(Family_Member* root, string Cna, string Nna){
    if(root == NULL) return root;
    else if(Cna.compare(root->name) < 0)
        root->left = UpdateName(root->left,Cna,Nna);
    else if(Cna.compare(root->name) > 0)
        root->right = UpdateName(root->right,Cna,Nna);
    else
        root->name = Nna;
    return root;
}

Family_Member* UpdateAge(Family_Member* root, string na, int Nag){
    if(root == NULL) return root;
    else if(na.compare(root->name) < 0)
        root->left = UpdateAge(root->left,na,Nag);
    else if(na.compare(root->name) > 0)
        root->right = UpdateAge(root->right,na,Nag);
    else
        root->age = Nag;
    return root;
}

Family_Member* UpdateHeight(Family_Member* root, string na, float Nhe){
    if(root == NULL) return root;
    else if(na.compare(root->name) < 0)
        root->left = UpdateHeight(root->left,na,Nhe);
    else if(na.compare(root->name) > 0)
        root->right = UpdateHeight(root->right,na,Nhe);
    else
        root->height = Nhe;
    return root;
}
