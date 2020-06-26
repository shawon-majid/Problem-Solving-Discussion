//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define PI acos(-1)
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef vector< int > vi;

typedef struct{
    string name;
    int total_ponints; 
    int games_played; 
    int wins;          
    int ties;
    int losses;
    int goal_difference; // baki
    int goal_scored;
    int goal_against;
}team_profile;

string tolower_str(string str)
{
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        ans += tolower(str[i]);
    }
    return ans;
}

int string_to_num(string s){
    int ans = 0;
    if(s.size() == 1){
        ans = s[0] - 48;
    }
    else{
        ans = 0;
        for(int i = 0, p = s.size()-1; i < s.size(); i++, p--){
            ans += (s[i] - '0')*round(pow(10, p));
        }
    }
    return ans;
}

bool compare(team_profile a, team_profile b){
    if(a.total_ponints == b.total_ponints){
        if(a.wins == b.wins){
            if(a.goal_difference == b.goal_difference){
                if(a.goal_scored == b.goal_scored){
                    if(a.games_played == b.games_played){
                        return tolower_str(a.name)  < tolower_str(b.name);
                    }
                    else return a.games_played < b.games_played;
                }
                else return a.goal_scored > b.goal_scored;
            }
            else return a.goal_difference > b.goal_difference;
        }
        else return a.wins > b.wins;
    }
    else return a.total_ponints > b.total_ponints;
}


int main()
{
    
    int T;
    cin >> T;
    getchar(); 
    while(T--) {
        
        string tournament_name;
        getline(cin, tournament_name);
        cout << tournament_name << endl;
        int number_of_teams;
        cin >> number_of_teams;
        vector <team_profile> teams(number_of_teams);
        getchar();
        for(int i = 0; i < number_of_teams; i++){
            getline(cin, teams[i].name);
        }
        int number_of_matches;
        cin >> number_of_matches;
        getchar();
        for(int c = 0; c < number_of_matches; c++){
            string str, team1 = "", team2 = "", sc1 = "", sc2 = "";
            int score1, score2, track;
            getline(cin, str);
            // take the first team name;
            for(int i = 0; i < str.size(); i++){
                if(str[i] != '#'){
                    team1 += str[i];
                }
                else{
                    track = i;
                    break;
                }
            }
            //take the score1
            for(int i = track+1; i < str.size(); i++){
                if(str[i] != '@'){
                    sc1 += str[i];
                }
                else{
                    track = i;
                    break;
                }
            }
            score1 = string_to_num(sc1);
            // take the score2
            for(int i = track+1; i < str.size(); i++){
                if(str[i] != '#'){
                    sc2 += str[i];
                }
                else{
                    track = i;
                    break;
                }
            }
            score2 = string_to_num(sc2);
            // take the last team
            for(int i = track+1; i < str.size(); i++){
                team2 += str[i];
            }
          
            bool win1 = false, win2 = false;
            if(score1 > score2){
                win1 = true;
                win2 = false;
            }
            else if(score2 > score1){
                win2 = true;
                win1 = false;
            }
            //find team1;

            for(int i = 0; i < teams.size(); i++){
                if(team1 == teams[i].name){
                    teams[i].games_played++;
                    teams[i].goal_scored += score1;
                    teams[i].goal_against += score2;
                    if(win1 && !win2){
                        teams[i].wins++;
                    }
                    else if(!win1 && win2){
                        teams[i].losses++;
                    }
                    else teams[i].ties++;
                }
                
            }
            // find team2;
            for(int i = 0; i < teams.size(); i++){
                if(team2 == teams[i].name){
                    teams[i].games_played++;
                    teams[i].goal_scored += score2;
                    teams[i].goal_against += score1;
                    if(!win1 && win2){
                        teams[i].wins++;
                    }
                    else if(win1 && !win2){
                        teams[i].losses++;
                    }
                    else teams[i].ties++;
                }
            }
            
        }
        for(int i = 0; i < teams.size(); i++){
            teams[i].total_ponints = (teams[i].wins*3) + (teams[i].ties);
            teams[i].goal_difference = teams[i].goal_scored - teams[i].goal_against;
        }

        sort(all(teams), compare);

        for(int i = 0; i < teams.size(); i++){
            cout << i+1 << ") "<<teams[i].name <<" " <<teams[i].total_ponints <<"p, "<<teams[i].games_played<<"g ("<<teams[i].wins<<"-"<<teams[i].ties<<"-"<<teams[i].losses<<"), "<< teams[i].goal_difference << "gd (" <<teams[i].goal_scored<<"-"<<teams[i].goal_against<<")"<< endl;  
        }

        if(T != 0)  cout << endl;
         
    }



    return 0;
}
