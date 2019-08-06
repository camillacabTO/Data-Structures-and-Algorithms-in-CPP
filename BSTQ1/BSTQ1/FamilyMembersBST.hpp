//
//  FamilyMembersBST.hpp
//  BSTQ1
//
//  Created by Camila Barros on 2019-07-23.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#ifndef FamilyMembersBST_hpp
#define FamilyMembersBST_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;




struct Family_Member {
    int age;
    float height;
    string name;
    Family_Member* left;
    Family_Member* right;
};

Family_Member* AddMember(Family_Member* root,int ag, float he, string na);
Family_Member* CreateMember(int ag, float he, string na);
void PreorderPrint(Family_Member* root);
void InOrderPrint(Family_Member* root);
void PostOrderPrint(Family_Member* root);
bool Search(Family_Member* root, string na);
void PrintNode(Family_Member* node);
Family_Member* FindMin(Family_Member* root);
Family_Member* Delete(Family_Member *root, string na);
Family_Member* UpdateName(Family_Member* root, string Cna, string Nna);
Family_Member* UpdateAge(Family_Member* root, string na, int Nag);
Family_Member* UpdateHeight(Family_Member* root, string na, float Nhe);



#endif /* FamilyMembersBST_hpp */
