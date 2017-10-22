// To execute C++, please define "int main()" 
 #include <iostream>
 #include <vector>
 #include <unordered_map>
 #include <algorithm>
 using namespace std;

 unordered_map<int, vector<int>> create_adjacency_lists(const vector<vector<string>>& employees, const vector<vector<string>>& friendships) {
   unordered_map<int, vector<int>> m;
   unordered_map<int, vector<int>>::iterator it;
   unordered_map<int, vector<int>>::iterator it2;
   for(unsigned int i=0;i<friendships.size();i++){
        int t=stoi(friendships[i][0]);     
        it=m.find(t);
        if(it==m.end()){
          std::vector <int > k;
          k.push_back(stoi(friendships[i][1]));
          m[t]=k;
          k.clear();          
        }else{
          //cout<<it->first;
          it->second.push_back(stoi(friendships[i][1]));
        }
        t=stoi(friendships[i][1]);
        it=m.find(t);
        if(it==m.end()){
          std::vector <int > k;k.push_back(stoi(friendships[i][0]));
          m[t]=k;
          k.clear(); 
        }else{
          //cout<<it->first;
          it->second.push_back(stoi(friendships[i][0]));
        }
        //cout<<friendships[i][0]<<" "<<friendships[i][1]<<endl; 
   
   }
  for(unsigned int i=0;i<employees.size();i++){
    if(m.find(stoi(employees[i][0]))==m.end()){
      std::vector <int> k;
      m[stoi(employees[i][0])]=k;
    }
    else{
      continue;
    }
  }
  for(it=m.begin();it!=m.end();it++){
    cout<<it->first;
    for(int i=0;i<it->second.size();i++){
        cout<<" "<<it->second[i];
    }
    cout<<endl;
  }

   return {m};
  }
 
 
 /* START TEST CASES
#  * You can add test cases in the three functions below: employeesInputs(),
#  * friendshipsInputs(), and expectedOutputs(). Each test case input/expected output
#  * should correspond to the same index in the respective lists returned.
*/
 
 const vector<vector<vector<string>>> employees_inputs = {
   {
     {"1", "Richard", "Engineering"},
     {"2", "Erlich", "HR"},
     {"3", "Monica", "Business"},
     {"4", "Dinesh", "Engineering"},
     {"6", "Carla", "Engineering"},
     {"9", "Laurie", "Directors"}
   },
 };
 const vector<vector<vector<string>>> friendships_inputs = {
  {
     {"1", "2"},
     {"1", "3"},
     {"1", "6"},
     {"2", "4"}
   },
 };
 
 const vector<unordered_map<int, vector<int>>> expected_outputs = {
  {
     {1, {2, 3, 6}},
     {2, {1, 4}},
     {3, {1}},
     {4, {2}},
     {6, {1}},
     {9, {}}
   },
 };
 
 // END TEST CASES
 
 // DO NOT MODIFY MAIN()
 int main() {
   for (size_t i = 0; i < employees_inputs.size(); i++) {
     if (create_adjacency_lists(employees_inputs[i], friendships_inputs[i]) == expected_outputs[i]) {
       cout << "Pass" << endl;
     } else {
       cout << "Fail" << endl;
     }
  }
 }
 
