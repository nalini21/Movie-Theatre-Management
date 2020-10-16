#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<iterator>
using namespace std;
int main() {
    int t,j;
    cin>>t;
   unordered_map< string, vector<vector<int> > > screens;
    for(j=0;j<t;j++){
        string a,word;
        fflush(stdin);
        getline(cin,a);
        stringstream ss(a);
        vector<string> inp_str;
        //-------------
        string screen_name;
        int total_rows;
        int row_number;
        int seats_per_row;
        //-------------------
        while(ss>>word)
            inp_str.push_back(word);
        if(inp_str[0]=="add-screen"){
            int status = 0;
            screen_name = inp_str[1];
            if(screen_name == "")
                status = 1;
            total_rows = stoi(inp_str[2]);
            if(total_rows<=0)
                status = 1;
            seats_per_row = stoi(inp_str[3]);
            if(seats_per_row<=0)
                status = 1;
            vector< vector<int> > screen(total_rows);
            for(int i=0;i<total_rows;i++)    
                for(int k=0;k<seats_per_row;k++){
                    screen[i].push_back(0);
                }
            for(int i=4;i<inp_str.size();i++){
                int x = stoi(inp_str[i]);
                if(x > seats_per_row || x<= 0){
                    status = 1;
                    break;
                }
                for(int k=0;k<total_rows;k++){
                    screen[k][x-1]= -1;
                }
            }
            if(!status){
                screens.insert(make_pair(screen_name,screen));
                cout<<"success"<<endl;
            }
            else
                cout<<"failure"<<endl;
        }
        else if(inp_str[0]=="reserve-seat"){
            int status = 0;
            screen_name = inp_str[1];
            if(screens.find(screen_name)==screens.end())
                status = 1;
            row_number = stoi(inp_str[2]);
            if(!status){
                if(screens[screen_name].size() < row_number || row_number <= 0)
                    status = 1;
            }
            vector<int> res_seats;
            vector<int> unres_seats;
            for(int i=3;i<inp_str.size();i++){
                int x = stoi(inp_str[i]);
                if(x > screens[screen_name][0].size() || x<= 0){
                    status = 1;
                    break;
                }
                res_seats.push_back(x);
            }
            if(!status){
            for(int s=0;s<res_seats.size();s++){
                if(screens[screen_name][row_number-1][res_seats[s]-1]==0)
                    unres_seats.push_back(res_seats[s]);
                    //screens[screen_name][row_number-1][res_seats[s]-1]= -1;
                else{
                    status=1;
                    break;
                }
            }
            }
            if(!status){
                for(int s=0;s<unres_seats.size();s++){
                    screens[screen_name][row_number-1][unres_seats[s]-1]= -1;
                }
                cout<<"success"<<endl;
            }
            else
                cout<<"failure"<<endl;
        }
        // else if(inp_str[0]=="get-unreserved-seats"){
           
        // }
        // else if(inp_str[0]=="suggest-contiguous-seats"){
           
        // }
        // else{
        //     cout<<j<<"th instruction is invalid"<<endl;
        //     break;
        // }
    }  
     
        for(auto um: screens){
            vector< vector<int> > screen;
            cout<<endl<<um.first<<endl;
            screen = um.second;
            for(int i=0;i<screen.size();i++){
                for(int k=0;k<screen[0].size();k++){
                    cout<<screen[i][k]<<"   ";
                }
                cout<<endl;
            }
        }
    return 0;
}