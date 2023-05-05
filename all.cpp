// pratical 1 : BFS and DFS


// BFS
// #include<iostream>
// using namespace std;


// void prepareAdjList(unordered_map<int,set<int>> &adj, vector<pair<int, int>> &edges){
//     for(int i=0; i<edges.size(); i++){
//         int u = edges[i].first;
//         int v = edges[i].second;

//         adj[u].insert(v);
//         adj[v].insert(u);
//     }
// }


// void bfs(unordered_map<int, set<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node){
//     queue<int> q;

//     q.push(node);
//     visited[node] = 1;

//     while(!q.empty()){
//         int frontnode = q.front();
//         q.pop();

//         // store frontnode in ans
//         ans.push_back(frontnode);

//         // traverse all adjacent nodes
//         for(auto i : adj[frontnode]){
            
//             // if not visited
//             if(!visited[i]){
//                 q.push(i);
//                 visited[i] = 1;         
//             }
//         }
//     }
// }

// vector<int> BFS(int vertex, vector<pair<int, int>> edges){
//     vector<int> ans;

//     unordered_map<int,set<int>> adj;
//     unordered_map<int,bool> visited;

//     prepareAdjList(adj, edges);

//     // as it is disconnected we need to traverse all compoments
//     for(int i=0; i<vertex; i++){
//         if(!visited[i]){
//             bfs(adj, visited, ans, i);
//         }
//     }
//     return ans;
// }

// int main(){
//     int v;
//     cin>> v;
//     vector<pair<int,int>>edges(v);
//     for(int i=0;i<v;i++){
//         int x,y;
//         cin>> x >>y;
//         edges[i].first=x;
//         edges[i].second=y;
//     }
//     vector<int>ans=BFS(v,edges);
//     for(auto it:ans){
//         cout<<it<<" ";
//     }
// }





// DFS
// #include<bits/stdc++.h> 

// using namespace std ;

// void makeadj(unordered_map<int,set<int>> &adj, vector<vector<int>> &edges){
//     for(int i=0; i<edges.size(); i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].insert(v);
//         adj[v].insert(u);
//     }
// }


// void dfs(int node, 
//         unordered_map<int,bool> &visited, 
//         unordered_map<int,set<int>> &adj, 
//         vector<int> &component){

//         // store the node in component
//         component.push_back(node);
//         visited[node] = true;

//         // for every connected node a recursive call will be made
//         for(auto i: adj[node]){
//             if(!visited[i]){
//                 dfs(i, visited, adj, component);
//             }
//         }
// }


// vector<vector<int>> depthFirstSearch(int V, vector<vector<int>> &edges){
//     unordered_map<int,set<int>> adj;
//     unordered_map<int,bool> visited;
//     vector<vector<int>> ans;

//     makeadj(adj, edges);

//     // for all nodes call dfs if not visited
//     for(int i=0; i<V; i++){
//         vector<int> component;
//         if(!visited[i]){
//             dfs(i, visited, adj, component);
//             ans.push_back(component);
//         }
//     }
//     return ans;

// }


// int main(){
//     int v;
//     cout<<"Enter number of vertices: ";
//     cin >> v;
//     vector<vector<int>> edges(v);
//     for (int i = 0; i < v; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         edges[i].push_back(x);
//         edges[i].push_back(y);
//     }
//     vector<vector<int>> ans = depthFirstSearch(v, edges);
//     for (auto it : ans)
//     {
//         for (auto x : it)
//         {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }




// PRATICAL 2: Water Jugs
// #include <bits/stdc++.h>
// using namespace std;


// void printpath(map<pair<int, int>,pair<int,int>>& m,  pair<int,int>t){
//     if(t.first==0 && t.second==0){
//         cout<<0<<" "<<0<<endl;
//         return;
//     }
//     printpath(m,m[t]);
//     cout<<t.first<<" "<<t.second<<endl;
// }

// void DFS(int a, int b, int target,
//             // for mapping two pair , eg (0,0) to (4,0)
//             map<pair<int, int>,pair<int,int >>&m,
//             map<pair<int, int>,bool> &visited,
//             pair<int,int>t,
//             bool &solve)
// {

//     if(solve)return;

//     if(t.first>a||t.first<0 || t.second>b || t.second<0 )return;

//     if(t.first==target || t.second==target){
//         solve=true;
//         printpath(m,t);
//             if (t.first == target) {
//                 if (t.second != 0)
//                     cout << t.first << " " << 0 << endl;
//             }
//             else {
//                 if (t.first != 0)
//                     cout << 0 << " " << t.second << endl;
//             }
//             return;
//     }

//     visited[{t.first,t.second}] = 1;


//         // filling only jug b to its full capacity
//         if(!visited[{t.first,b}]){
//             m[{t.first,b}]=t;
//             DFS(a,b,target,m,visited,{t.first,b},solve);
//         }

//         // filling only jug a to its full capacity
//         if(!visited[{a,t.second}]){
//             m[{a,t.second}]=t;
//             DFS(a,b,target,m,visited,{a,t.second},solve);
//         }

//         // filling from jug a to b, to b's full capacity
//         int d= b-t.second;
//         if(t.first>=d){  //checking if a has d liter water to fill till b's capacity
//             int c=t.first-d;
//             if(!visited[{c,b}]){
//                 m[{c,b}]=t;
//                 DFS(a,b,target,m,visited,{c,b},solve);
//             }
//         }
//         else{
//             // if a has water but is not sufficient to fill till b's capacity
//             int c=t.first+t.second;
//             // checking if previously visited or not
//             if(!visited[{0,c}]){
//                 m[{0,c}]=t;
//                 DFS(a,b,target,m,visited,{0,c},solve);
//             }
//         }


//         // filling from jug b to a, to a's full capacity
//         d=a-t.first;
//         if(t.second>=d){ //checking if b has d liter water to fill till a's capacity
//             int c=t.second-d;
//             if(!visited[{a,c}]){
//                 m[{a,c}]=t;
//                 DFS(a,b,target,m,visited,{a,c},solve);
//             }
//         }
//         else{
//             // if b has water but is not sufficient to fill till a's capacity
//             int c=t.first+t.second;
//             if(!visited[{c,0}]){
//                 m[{c,0}]=t;
//                 DFS(a,b,target,m,visited,{c,0},solve);
//             }
//         }


//         //removing all water from jug b
//         if(!visited[{t.first,0}]){
//             m[{t.first,0}]=t;
//             DFS(a,b,target,m,visited,{t.first,0},solve);
//         }

//         // removing all water from jug a
//         if(!visited[{0,t.second}]){
//             m[{0,t.second}]=t;
//             DFS(a,b,target,m,visited,{0,t.second},solve);
//         }
// }




// void BFS(int a, int b, int target)
// {
//     map<pair<int, int>, pair<int, int>> m;
//     map<pair<int, int>, bool> visited;
//     queue<pair<int, int>> q;
//     q.push({0, 0});
//     visited[{0, 0}] = 1;
//     bool isSolvable=false;

//     while(!q.empty()){

//         pair<int,int> t=q.front();
//         q.pop();
        
//         if(t.first>a||t.first<0 || t.second>b || t.second<0 )continue;


//         if(t.first==target|| t.second==target){
//             isSolvable=true;

//             printpath(m,t);
//             if (t.first == target) {
//                 if (t.second != 0)
//                     cout << t.first << " " << 0 << endl;
//             }
//             else {
//                 if (t.first != 0)
//                     cout << 0 << " " << t.second << endl;
//             }
//             return;
//         }

//         // filling only jug b
//         if(!visited[{t.first,b}]){
//             q.push({t.first,b});
//             m[{t.first,b}]=t;
//             visited[{t.first,b}]=1;
//         }

//         // filling only in jug a
//         if(!visited[{a,t.second}]){
//             q.push({a,t.second});
//             m[{a,t.second}]=t;
//             visited[{a,t.second}]=1;
//         }

//         // jug a  to b
//         int d= b-t.second;
//         if(t.first>=d){
//             int c=t.first-d;
//             if(!visited[{c,b}]){
//                 q.push({c,b});
//                 m[{c,b}]=t;
//                 visited[{c,b}]=1;
//             }
//         }
//         else{
//             int c=t.first+t.second;
//             // checking if previously visited or not
//             if(!visited[{0,c}]){
//                 q.push({0,c});
//                 m[{0,c}]=t;
//                 visited[{0,c}]=1;
//             }
//         }


//         // jug b to a
//         d=a-t.first;
//         if(t.second>=d){
//             int c=t.second-d;
//             if(!visited[{a,c}]){
//                 q.push({a,c});
//                 m[{a,c}]=t;
//                 visited[{a,c}]=1;
//             }
//         }
//         else{
//             int c=t.first+t.second;
//             if(!visited[{c,0}]){
//                 q.push({c,0});
//                 m[{c,0}]=t;
//                 visited[{c,0}]=1;
//             }
//         }


//         //removing all water from jug b
//         if(!visited[{t.first,0}]){
//             q.push({t.first,0});
//             m[{t.first,0}]=t;
//             visited[{t.first,0}]=1;
//         }

//         // removing all water from jug a
//         if(!visited[{0,t.second}]){
//             q.push({0,t.second});
//             m[{0,t.second}]=t;
//             visited[{0,t.second}]=1;
//         }
        
//     }

//     if(!isSolvable){
//         cout<<"NO SOLUTION"<<endl;
//     }
// }

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     int target;
//     cin >> target;

//     // BFS(m, n, target);

//     map<pair<int, int>, pair<int, int>>gg;
//     map<pair<int, int>, bool> visited;
//     bool solve=false;
//     DFS(m,n,target,gg,visited,{0,0},solve);
//     return 0;
// }




// pratical 3:  A star 
// #include <bits/stdc++.h>
// #define n 3
// const bool SUCCESS = true;
// using namespace std;
// using i64 = long long int;


// class state {
//   public:
//     int board[n][n], g, f;
//     state* came_from;
//     state () {
//       g = 0;
//       f = 0;
//       came_from = NULL;
//     }

//     static int heuristic (state from, state to) {
//       int ret = 0;
//       for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//           if (from.board[i][j] != to.board[i][j])
//             ret++;
//       return ret;
//     }

//     bool operator == (state a) {
//       for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//           if (this->board[i][j] != a.board[i][j])
//             return false;
//       return true;
//     }

//     void print () {
//       for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++)
//           cout << board[i][j] << " ";
//         cout << endl;
//       }
//       cout << "g = " << g << " | f = " << f << endl;
//     }
// };


// vector <state> output;
// bool lowerF (state a, state b) {
//   return a.f < b.f;
// }

// bool isinset (state a, vector <state> b) {
//   for (int i = 0; i < b.size(); i++)
//     if (a == b[i])
//       return true;
//   return false;
// }

// void addNeighbor (state current, state goal, int newi, int newj, int posi, int posj, vector <state>& openset, vector <state> closedset) {
//   state newstate = current;
//   swap (newstate.board[newi][newj], newstate.board[posi][posj]);
//   if (!isinset(newstate, closedset) && !isinset(newstate, openset)) {
//       newstate.g = current.g + 1;
//       newstate.f = newstate.g + state :: heuristic(newstate, goal);
//       state* temp = new state();
//       *temp = current;
//       newstate.came_from = temp;
//       openset.push_back(newstate);
//   }
// }

// void neighbors (state current, state goal, vector <state>& openset, vector <state>& closedset) {
//   int i, j, posi ,posj;
//   for (i = 0; i < n; i++)
//     for (j = 0; j < n; j++)
//       if (current.board[i][j] == 0) {
//         posi = i;
//         posj = j;
//         break;
//       }
//   i = posi, j = posj;
//   if (i - 1 >= 0)
//     addNeighbor(current, goal, i - 1, j, posi, posj, openset, closedset);
//   if (i + 1 < n)
//     addNeighbor(current, goal, i + 1, j, posi, posj, openset, closedset);
//   if (j + 1 < n)
//     addNeighbor(current, goal, i, j + 1, posi, posj, openset, closedset);
//   if (j - 1 >= 0)
//     addNeighbor(current, goal, i, j - 1, posi, posj, openset, closedset);
// }

// bool reconstruct_path(state current, vector<state> &came_from) {
//     state *temp = &current;
//     while(temp != NULL) {
//         came_from.push_back(*temp);
//         temp = temp->came_from;
//     }
//     return SUCCESS;
// }

// bool astar (state start, state goal) {
//   vector <state> openset;
//   vector <state> closedset;
//   state current;
//   start.g = 0;
//   start.f = start.g + state :: heuristic(start, goal);
//   openset.push_back(start);
//   while (!openset.empty()) {
//     sort(openset.begin(), openset.end(), lowerF);
//     current = openset[0];
//     if (current == goal)
//       return reconstruct_path(current, output);
//     openset.erase(openset.begin());
//     closedset.push_back(current);
//     neighbors(current, goal, openset, closedset);
//   }
//   return !SUCCESS;
// }

// int main () {
//   state start, goal;
//   freopen("in.txt", "r", stdin);
//   for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> start.board[i][j];
//   for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> goal.board[i][j];
//   if (astar(start, goal) == SUCCESS) {
//     for (int i = output.size() - 1; i >= 0; i--)
//       output[i].print();
//     cout << "success" << endl;
//   }
//   else cout << "fail" << endl;
//   return 0;
// }




// Pratical 4: 8-Puzzle bfs and dfs

// #include <bits/stdc++.h>
// using namespace std;

// typedef vector<vector<int>> vvi;

// vector<int> dc{1, -1, 0, 0};
// vector<int> dr{0, 0, -1, 1};

// void print(map<vvi, vvi> m, vvi temp, vvi s)
// {
//     vector<vvi> path;
//     while (temp != s)
//     {
//         path.push_back(temp);
//         temp = m[temp];
//     }
//     path.push_back(s);
//     reverse(path.begin(), path.end());

//     for (auto &temp : path)
//     {

//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 cout << temp[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//         cout << endl;
//         cout << endl;
//     }
// }

// void bfs(vector<vector<int>> &s, vector<vector<int>> &f)
// {
//     queue<vvi> q;
//     map<vvi, bool> visited;
//     map<vvi, vvi> m;
//     q.push(s);
//     visited[s] = 1;
//     while (!q.empty())
//     {
//         vvi temp = q.front();
//         q.pop();
//         if (temp == f)
//         {
//             print(m, temp, s);
//             return;
//         }
//         int r, c;
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 if (temp[i][j] == -1)
//                 {
//                     r = i;
//                     c = j;
//                     break;
//                 }
//             }
//         }
//         for (int i = 0; i < 4; i++)
//         {
//             int newR = r + dr[i];
//             int newC = c + dc[i];
//             if (newR < 0 || newR >= 3 || newC < 0 || newC >= 3)
//             {
//                 continue;
//             }
//             vvi child = temp;
//             swap(child[r][c], child[newR][newC]);
//             if (!visited[child])
//             {
//                 q.push(child);
//                 visited[child] = 1;
//                 m[child] = temp;
//             }
//         }
//     }
// }

// bool done = false ;

// void dfs(vector<vector<int>> &sori, vector<vector<int>> &s, vector<vector<int>> &f, map<vvi, vvi> &m, map<vvi, bool> &visited)
// {
//     if(done)
//         return ;
//     if (s == f)
//     {
//         print(m, f, sori);
//         done = true ;
//         return;
//     }

//     visited[s] = 1;
//     int r, c;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (s[i][j] == -1)
//             {
//                 r = i;
//                 c = j;
//                 break;
//             }
//         }
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         int newR = r + dr[i];
//         int newC = c + dc[i];
//         if (newR < 0 || newR >= 3 || newC < 0 || newC >= 3)
//         {
//             continue;
//         }
//         vvi child = s;
//         swap(child[r][c], child[newR][newC]);
//         if (!visited[child])
//         {
//             m[child] = s;
//             dfs(sori, child, f, m, visited);
//         }
//     }
// }

// int main()
// {
//     vector<vector<int>> s;
//     for (int i = 0; i < 3; i++)
//     {
//         vector<int> t;
//         for (int j = 0; j < 3; j++)
//         {
//             int x;
//             cin >> x;
//             t.push_back(x);
//         }
//         s.push_back(t);
//     }
//     vector<vector<int>> f;
//     for (int i = 0; i < 3; i++)
//     {
//         vector<int> t;
//         for (int j = 0; j < 3; j++)
//         {
//             int x;
//             cin >> x;
//             t.push_back(x);
//         }
//         f.push_back(t);
//     }
//     // bfs(s, f);
//     map<vvi, vvi> m;
//     map<vvi, bool> visited;
//     done = false ;
//     dfs(s, s, f, m, visited);
//     return 0;
// }





// Prolog


// % Box Problem
// getbox(1). getbox(2). getbox(3). getbox(4). getbox(5).
// box(1,black,3).
// box(2,black,1).
// box(3,white,1).
// box(4,black,2).
// box(5,white,3).
// owners(A,B,C,D,E):-
// getbox(A),getbox(B),getbox(C),getbox(D),getbox(E),
// A\=B,A\=C,A\=D,A\=E,
// B\=C,B\=D,B\=E,
// C\=D,C\=E,
// D\=E,
// box(A,ColorA,_),box(B,ColorA,_),
// box(D,ColorD,_),box(E,ColorD,_),
// box(C,_,SizeC),box(D,_,SizeC),
// box(E,_,SizeE),box(B,_,SizeB),
// SizeE<SizeB.




// %Monkey problem
// move(state(middle,onbox,middle,hasnot),
//    grasp,
//    state(middle,onbox,middle,has)).
// move(state(P,onfloor,P,H),
//    climb,
//    state(P,onbox,P,H)).
// move(state(P1,onfloor,P1,H),
//    drag(P1,P2),
//    state(P2,onfloor,P2,H)).
// move(state(P1,onfloor,B,H),
//    walk(P1,P2),
//    state(P2,onfloor,B,H)).
// canget(state(_,_,_,has)).
// canget(State1) :-
//    move(State1,_,State2),
//    canget(State2).



// %factorial of a number:
// fact(0,1).
// fact(N,X) :-
//     N > -1,
//     T is N-1,
//     fact(T,X1),
//     X is N*X1.



// %sum of n numbers:
// sum(1,1).
// sum(N,A):-
//     N > 0,
//     T is N-1,
//     sum(T,B),
//     A is N + B.



// %short n sum
// short_n_sum(N):-
//     X is (N*(N+1))/2,
//     write(X).



// %membership operation
// member(X,[X|_]).
// member(X,[_|T]) :- member(X,T).



// %length of a list
// list_len([],0).
// list_len([_|TAIL],N) :-
//     list_len(TAIL,N1),
//     N is N1+1.



// %reverse a list
// rev([],Z,Z).
// rev([H|T],Z,A) :-
//     rev(T,Z,[H|A]).






// 7) WAP to take any number from user and calculate the factorial of a number by using Prolog.
 

// factorial(0, 1).
// factorial(N, Result) :-
//     N > 0,
//     N1 is N - 1,
//     factorial(N1, Result1),
//     Result is N * Result1.
 
// main :-
//     write('Enter a number: '),
//     read(N),
//     factorial(N, Result),
//     write('The factorial of '), write(N), write(' is '), write(Result), nl.
 

// % Query - factorial(5, X).
 

// 8) WAP to solve Box Solver problem, which is given in the attached file

// %Ann and Bill have boxes with the same colour.
// %Don and Eric have boxes with the same colour.
// %Charlie and Don have boxes with the same size.
// %Eric's box is smaller than Bill's
 
// % Define numbers for each box
// getbox(1). getbox(2). getbox(3). getbox(4). getbox(5).
 
// % Define Box numbers, colour, size
// box(1,black,3).
// box(2,black,1).
// box(3,white,1).
// box(4,black,2).
// box(5,white,3).
 
// owners(A,B,C,D,E):-
//  getbox(A), getbox(B), getbox(C), getbox(D), getbox(E),
//  A\=B, A\=C, A\=D, A\=E,
//  B\=C, B\=D, B\=E,
//  C\=D, C\=E,
//  D\=E,
//  box(A,ColorA,_), box(B,ColorA,_),
//  box(D,ColorD,_), box(E,ColorD,_),
//  box(C,_,SizeC), box(D,_,SizeC),
//  box(E,_,SizeE), box(B,_,SizeB),
//  SizeE < SizeB.
 
// % Query - owners(Ann, Bill, Charlie, Don, Eric).
 

 

// 9) Given a prolog list find the length of the list and reverse its element.
 

// % Define the base case for the length predicate.
// % The length of an empty list is 0.
// my_length([], 0).
 
// % Define the recursive case for the length predicate.
// % The length of a list is 1 plus the length of its tail.
// my_length([_|Tail], Length) :-
//     my_length(Tail, Length1),
//     Length is Length1 + 1.
 
// % Define the base case for the reverse predicate.
// % The reverse of an empty list is an empty list.
// my_reverse([], []).
 
// % Define the recursive case for the reverse predicate.
// % The reverse of a list is the reverse of its tail followed by its head.
// my_reverse([Head|Tail], Reversed) :-
//     my_reverse(Tail, ReversedTail),
//     append(ReversedTail, [Head], Reversed).
 
// % Define a predicate that finds the length of a list and reverses its elements.
// my_length_and_reverse(List, Length, Reversed) :-
//     my_length(List, Length),
//     my_reverse(List, Reversed).
 

// % Query - my_length_and_reverse([1, 2, 3, 4], Length, Reversed).
 

// Alternate - 
// reverse_list_length(List, RevList, Len) :-
//     length(List, Len),
//     reverse(List, RevList).
 

// % Query - reverse_list_length([1,2,3,4],RevList,Len).
 

 

// 10) Construct a prolog program to find the sum of the following series 1+2+3+4------ +10
 
// % Define the base case for the sum predicate.
// % The sum of an empty list is 0.
// sum([], 0).
 
// % Define the recursive case for the sum predicate.
// % The sum of a list is the head of the list plus the sum of its tail.
// sum([Head|Tail], Sum) :-
//     sum(Tail, Sum1),
//     Sum is Sum1 + Head.
 
// % Define a predicate that generates the list of numbers to sum.
// generate_list(1, [1]).
// generate_list(N, List) :-
//     N > 1,
//     N1 is N - 1,
//     generate_list(N1, List1),
//     append(List1, [N], List).
 
// % Define a predicate that calculates the sum of the series 1+2+3+...+N.
// series_sum(N, Sum) :-
//     generate_list(N, List),
//     sum(List, Sum).
 

// % Query - series_sum(10, Sum).
 

// Alternate - 
// sum_arithmetic_series(Start, Diff, NumTerms, Sum) :-
//     Last is Start + (NumTerms - 1) * Diff,
//     Sum is NumTerms * (Start + Last) / 2.
 
// % Query -  sum_arithmetic_series(1,1,10,Sum).
 

 

// 11) Write a program to solve the Monkey Banana problem.
 

// move(state(middle,onbox,middle,hasnot),
//    grasp,
//    state(middle,onbox,middle,has)).
// move(state(P,onfloor,P,H),
//    climb,
//    state(P,onbox,P,H)).
// move(state(P1,onfloor,P1,H),
//    drag(P1,P2),
//    state(P2,onfloor,P2,H)).
// move(state(P1,onfloor,B,H),
//    walk(P1,P2),
//    state(P2,onfloor,B,H)).
// canget(state(_,_,_,has)).
// canget(State1) :-
//    move(State1,_,State2),
//    canget(State2).
// % Query - canget(state(atdoor,onfloor,atwindow,hasnot)).
// % trace



// Pratical: ANN
// import pandas as pd
// import numpy as np
// import tensorflow as tf
// from tensorflow import keras
// from sklearn.model_selection import train_test_split
// from sklearn.metrics import mean_squared_error

// # load data
// train_df = pd.read_csv('train.csv')
// test_df = pd.read_csv('test.csv')

// # preprocess data
// # drop columns with high percentage of missing values
// train_df = train_df.drop(['Alley', 'PoolQC', 'Fence', 'MiscFeature'], axis=1)
// test_df = test_df.drop(['Alley', 'PoolQC', 'Fence', 'MiscFeature'], axis=1)

// # fill missing values
// train_df.fillna(train_df.mean(), inplace=True)
// test_df.fillna(test_df.mean(), inplace=True)

// # convert categorical features to numerical
// train_df = pd.get_dummies(train_df)
// test_df = pd.get_dummies(test_df)

// # align train and test data
// train_labels = train_df['SalePrice']
// train_df, test_df = train_df.align(test_df, join='inner', axis=1)

// # split data into train and validation sets
// X_train, X_val, y_train, y_val = train_test_split(train_df, train_labels, test_size=0.2, random_state=42)

// # build ANN model
// model = keras.Sequential([
//     keras.layers.Dense(128, activation='relu', input_shape=(X_train.shape[1],)),
//     keras.layers.Dense(64, activation='relu'),
//     keras.layers.Dense(1)
// ])


// Model compilation is an activity performed after writing the statements in a model and before training starts. 
// It checks for format errors, and defines the loss function, the optimizer or learning rate, and the metrics.
// # compile the model
// model.compile(loss='mean_squared_error',
//               optimizer='adam',
//               metrics=['accuracy', 'mean_squared_error'])

// # train the model
// history = model.fit(X_train, y_train,
//                     epochs=10,
//                     batch_size=32,
//                     verbose=1,
//                     validation_data=(X_val, y_val))

// # evaluate model performance on training set
// train_pred = model.predict(X_train)
// train_mse = mean_squared_error(y_train, train_pred)
// train_acc = model.evaluate(X_train, y_train, verbose=0)[1]

// # evaluate model performance on validation set
// val_pred = model.predict(X_val)
// val_mse = mean_squared_error(y_val, val_pred)
// val_acc = model.evaluate(X_val, y_val, verbose=0)[1]

// # print results
// print('Training accuracy:', train_acc)
// print('Testing accuracy:', val_acc)
// print('mean squared error:', val_mse)

// # predict house prices for test set
// test_preds = model.predict(test_df)



// Practical: ANN on Heart
// import pandas as pd
// import numpy as np
// import tensorflow as tf
// from tensorflow import keras
// from sklearn.model_selection import train_test_split
// from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

// # load data
// df = pd.read_csv('Heart.csv')

// # preprocess data
// # drop rows with missing values
// df = df.dropna()

// # split data into features and target
// X = df.drop(['target'], axis=1)
// y = df['target']

// # normalize data
// X = (X - X.mean()) / X.std()

// # split data into train and validation sets
// X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)

// # build ANN model
// model = keras.Sequential([
//     keras.layers.Dense(128, activation='relu', input_shape=(X_train.shape[1],)),
//     keras.layers.Dense(64, activation='relu'),
//     keras.layers.Dense(1, activation='sigmoid')
// ])

// # compile the model
// model.compile(loss='binary_crossentropy',
//               optimizer='adam',
//               metrics=['accuracy', keras.metrics.Precision(), keras.metrics.Recall()])

// # train the model
// history = model.fit(X_train, y_train,
//                     epochs=10,
//                     batch_size=32,
//                     verbose=1,
//                     validation_data=(X_val, y_val))

// # evaluate model performance on validation set
// y_pred = model.predict(X_val)
// y_pred = np.round(y_pred).flatten()
// print('Accuracy:', accuracy_score(y_val, y_pred))
// print('Precision:', precision_score(y_val, y_pred))
// print('Recall:', recall_score(y_val, y_pred))
// print('F1-score:', f1_score(y_val, y_pred))



 
// Practical: CNN
// from google.colab import drive 
// drive.mount('/content/drive')

// import tensorflow as tf
// import numpy as np 
// import pandas as pd
// import matplotlib.pyplot as plt 
// import seaborn as sns


// df = pd.read_csv('/content/drive/MyDrive/Fashion/fashion-mnist_test.csv') 
// df1 = pd.read_csv('/content/drive/MyDrive/Fashion/fashion-mnist_train.csv')


// train = np.array(df1) 
// test = np.array(df)
// xtrain = train[:,1:]/255 
// ytrain = train[:,0]
// xtest = test[:,1:]/255 
// ytest = test[:,0]
// xtrain=xtrain.reshape(xtrain.shape[0],*(28,28,1)) 
// xtest=xtest.reshape(xtest.shape[0],*(28,28,1)) 



// from keras.models import Sequential
// from keras.layers import Conv2D, MaxPool2D, Flatten, Dense, Dropout


// model = Sequential()
// model.add(Conv2D(2048, (2,2), activation='relu', input_shape=(28,28,1)) ) 
// model.add(MaxPool2D(3,3))
// model.add(Conv2D(1024, (2,2), activation='relu') ) 
// model.add(MaxPool2D(2,2))
// model.add(Conv2D(512, (2,2), activation='relu') ) 
// model.add(MaxPool2D(2,2))
// model.add(Conv2D(128, (1,1), activation='relu') ) 
// model.add(MaxPool2D(1,1))
// model.add(Conv2D(64, (1,1), activation='relu') ) 
// model.add(Flatten())
// model.add(Dense(64, activation='relu')) 
// model.add(Dropout(0.1)) 
// model.add(Dense(32, activation='relu')) 
// model.add(Dropout(0.1)) 
// model.add(Dense(10, activation='softmax')) 
// model.summary()
// model.compile(loss='sparse_categorical_crossentropy', optimizer='Adam', metrics=['accuracy'])



// history = model.fit(xtrain, ytrain, batch_size=512, epochs=20, verbose=1)



// plt.plot(history.history['loss'])
// plt.plot(history.history['accuracy'])
// ypred =model.predict(xtest) 
// yclass = np.argmax(ypred, axis=1) 



// from sklearn.metrics import confusion_matrix, classification_report, accuracy_score 
// accuracy_score(ytest, yclass)






