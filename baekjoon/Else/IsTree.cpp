//
//  IsTree.cpp
//  test
//
//  Created by 신기열 on 03/04/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    
    set<int> tree;
    //vector<int> edge;
    
    int edgeNum = 0, NodeNum = 0;
    //int RootNum = 0;

    vector<int> ans;
    
    //int t = 0;

    while(1){
        
        int child, parent;
        scanf("%d %d", &parent, &child);
        
        
        if(parent < 0 && child < 0){
            break;
        }
        
        if(parent == 0 && child == 0){

            NodeNum = (int)tree.size();
            
            if(NodeNum == edgeNum + 1 || NodeNum == 0){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
 
            tree.clear();
            NodeNum = 0;
            edgeNum = 0;
        }
        
        else{
            
            tree.insert(child);
            tree.insert(parent);

            edgeNum++;

        }
    }
    
      for(int i = 0; i < (int)ans.size(); i++){
        if(ans[i] == 1){
            cout << "Case " << i + 1 << " is a tree." << '\n';
        }
        else if(ans[i] == 0){
            cout << "Case " << i + 1 << " is not a tree." << '\n';
        }
    }
    
    
    return 0;
}
