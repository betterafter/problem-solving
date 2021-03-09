#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 1   2   3
// 4   5   6
// 7   8   9
// *   0   #
string solution(vector<int> numbers, string hand) {

    string answer = "";

    pair<int, int> left, right;
    left = make_pair(0, 3);
    right = make_pair(2, 3);

    for(int i = 0 ; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            if(numbers[i] == 1){
                left = make_pair(0, 0);
            }
            else if(numbers[i] == 4){
                left = make_pair(0, 1);
            }
            else if(numbers[i] == 7){
                left = make_pair(0, 2);
            }
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            if(numbers[i] == 3){
                right = make_pair(2, 0);
            }
            else if(numbers[i] == 6){
                right = make_pair(2, 1);
            }
            else if(numbers[i] == 9){
                right = make_pair(2, 2);
            }
        }
        else if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0){
            // 1, 0
            if(numbers[i] == 2){
                // 왼쪽이 더 가까울 때 
                if(abs(1 - left.first) + abs(0 - left.second) < abs(1 - right.first) + abs(0 - right.second)){
                    answer += "L";
                    left = make_pair(1, 0);
                }
                else if(abs(1 - left.first) + abs(0 - left.second) > abs(1 - right.first) + abs(0 - right.second)){
                    answer += "R";
                    right = make_pair(1, 0);
                }
                else{
                    if(hand == "left"){
                        answer += "L";
                        left = make_pair(1, 0);
                    }
                    else{
                        answer += "R";
                        right = make_pair(1, 0);
                    }
                }
            }
            // 1, 1
            else if(numbers[i] == 5){
                if(abs(1 - left.first) + abs(1 - left.second) < abs(1 - right.first) + abs(1 - right.second)){
                    answer += "L";
                    left = make_pair(1, 1);
                }
                else if(abs(1 - left.first) + abs(1 - left.second) > abs(1 - right.first) + abs(1 - right.second)){
                    answer += "R";
                    right = make_pair(1, 1);
                }
                else{
                    if(hand == "left"){
                        answer += "L";
                        left = make_pair(1, 1);
                    }
                    else{
                        answer += "R";
                        right = make_pair(1, 1);
                    }
                }
            }
            // 1, 2
            else if(numbers[i] == 8){
                if(abs(1 - left.first) + abs(2 - left.second) < abs(1 - right.first) + abs(2 - right.second)){
                    answer += "L";
                    left = make_pair(1, 2);
                }
                else if(abs(1 - left.first) + abs(2 - left.second) > abs(1 - right.first) + abs(2 - right.second)){
                    answer += "R";
                    right = make_pair(1, 2);
                }
                else{
                    if(hand == "left"){
                        answer += "L";
                        left = make_pair(1, 2);
                    }
                    else{
                        answer += "R";
                        right = make_pair(1, 2);
                    }
                }
            }
            // 1, 3
            else if(numbers[i] == 0){
                if(abs(1 - left.first) + abs(3 - left.second) < abs(1 - right.first) + abs(3 - right.second)){
                    answer += "L";
                    left = make_pair(1, 3);
                }
                else if(abs(1 - left.first) + abs(3 - left.second) > abs(1 - right.first) + abs(3 - right.second)){
                    answer += "R";
                    right = make_pair(1, 3);
                }
                else{
                    if(hand == "left"){
                        answer += "L";
                        left = make_pair(1, 3);
                    }
                    else{
                        answer += "R";
                    right = make_pair(1, 3);
                    }
                }
            }
        }
        cout << "(" << left.first << "," << left.second << ')' << "         ";
        cout << "(" << right.first << "," << right.second << ')' << '\n';
    }

    return answer;

}


int main(){

    vector<int> numbers;
    string hand;

    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(9);
    numbers.push_back(5);

    hand = "right";
    cout << solution(numbers, hand);

    return 0;
}