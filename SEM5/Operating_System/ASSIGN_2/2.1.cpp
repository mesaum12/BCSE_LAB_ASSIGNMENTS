#include<bits/stdc++.h>
using namespace std;
#define TIMEQUANTUM 25
//creating a Process class for uniquely representing each process and its attributes
class Process
{
   public:
   int choice;
   int job_id,priority,arrival_time;
   queue<int> burst_time,io_time;
   int current_time_io;//To track the current time of I/O process for each of the process
   int total_burst_time;
    Process(int id,int p=0,int ch=1)
    {
       job_id=id;
       total_burst_time=0;
       choice=ch;
       if (choice==2)
       priority=p;
    }
    bool operator< (const Process &p) const{
        if (choice==1)
        return current_time_io>p.current_time_io;
        else if(choice==2)
        return priority<p.priority;
        else return current_time_io>p.current_time_io;
    }
   
};
void Read_Process_Data(string filename,queue<pair<Process,int> > &Arrival_Time,int &n,unordered_map<int ,int > &Arrival_Time_Map,unordered_map<int,int> &mp)
{
   ifstream file;
   file.open(filename);
   string current_word;
   vector<int> v;
   
   while (file >> current_word)
   {
        if(current_word=="-1"){
            n++;//tracks the number of processes read till now 
            int id=v[0];
            Process p(id);
            bool flag=true;
            for(int i=3;i<v.size();i++){
                if(flag)
                {
                    p.burst_time.push(v[i]);//store in the cpu-burst queue
                    p.total_burst_time+=v[i];// add the total burst time for the process
                }
                else p.io_time.push(v[i]); //else push to the i/o queue
                flag=!flag;
            }
            Arrival_Time.push({p,v[2]});//pair (process p,arrivaltime for process p)
            Arrival_Time_Map[p.job_id]=v[2]; //store the arrival time for the process p
            mp[p.job_id]=p.total_burst_time; // store the total burst time for process p 
            v.clear();
        }else
            v.push_back(stoi(current_word));
    }
	file.close(); //reading over , close the file now 

}
void First_Come_First_Serve(string filename)
{
    //defining the necessary data structures for the algorithm
    Process current_process(-1);
    queue<pair<Process,int> > Process_Arrival_Queue;
    unordered_map<int ,int > Completion_Time;
    unordered_map<int ,int > Arrival_Time_Map;
    unordered_map<int,int> mp;
    priority_queue<Process> Input_Output;
    queue<Process> ready_queue;
    int n=0;
    
    Read_Process_Data(filename,Process_Arrival_Queue,n,Arrival_Time_Map,mp);
    

    for(int current_time=0;;){

        while(!Process_Arrival_Queue.empty() && Process_Arrival_Queue.front().second<=current_time){
            ready_queue.push(Process_Arrival_Queue.front().first);
            Process_Arrival_Queue.pop();
        }

        while(!Input_Output.empty() && Input_Output.top().current_time_io<=current_time){
            if(Input_Output.top().burst_time.size()==0){
                Completion_Time[Input_Output.top().job_id]=current_time;
            }else
                ready_queue.push(Input_Output.top());
            Input_Output.pop();
        }

        if(!ready_queue.empty()){
            current_process=ready_queue.front();
            ready_queue.pop();
            current_time+=current_process.burst_time.front();
            current_process.burst_time.pop();
            if(current_process.io_time.size()==0){
                Completion_Time[current_process.job_id]=current_time;
            }else if(current_process.io_time.size()){
                current_process.current_time_io=current_time+current_process.io_time.front();
                current_process.io_time.pop();
                Input_Output.push(current_process);
            }
        }
        else
            current_time++;
        
        if(ready_queue.size()==0 && Input_Output.size()==0){
            break;
        }
    }

    float avg_turnaround_time=0,avg_waiting_time=0;

    for(auto itr:Completion_Time)
    {  
      
       int value1=itr.second-Arrival_Time_Map[itr.first];
       int value2=value1-mp[itr.first];
       cout<<"JobId:"<<itr.first<<" Turnaround Time:"<<value1<<" Waiting Time:"<<value2<<"\n";
       avg_turnaround_time+=value1;
       avg_waiting_time+=value2;
       
    }

    cout<<"The average turnaround time is :"<<avg_turnaround_time/n<<"\n";
    cout<<"The average waiting time is :"<<avg_waiting_time/n<<"\n";
    
}
void Priority_Scheduling(string filename)
{
    Process current_process(-1,-1, 2);//passing the choice 2 for the overloading of the boolean operator

    queue<pair<Process,int>> Process_Arrival_Queue;
    unordered_map<int,int> Completion_Time;
    vector<Process> Input_Output; 
    priority_queue<Process> ready_queue;//priority queue instead of normal queue
    unordered_map<int ,int > Arrival_Time_Map;
    unordered_map<int,int> mp;

    int n=0;

    Read_Process_Data(filename,Process_Arrival_Queue,n,Arrival_Time_Map,mp);

    for(int current_time=0;;){
        vector<Process> temp;
        for(int j=0;j<Input_Output.size();j++){
            if(Input_Output[j].current_time_io<current_time){
                if(Input_Output[j].burst_time.size()==0)
                    Completion_Time[Input_Output[j].job_id]=current_time;
                else
                    ready_queue.push(Input_Output[j]);
            }else
                temp.push_back(Input_Output[j]);
        }
        Input_Output=temp;
        if(ready_queue.size()){
            current_process=ready_queue.top();
            ready_queue.pop();
            current_process.burst_time.front()-=1;
            if(current_process.burst_time.front()==0){
                current_process.burst_time.pop();
                if(current_process.io_time.size()==0)Completion_Time[current_process.job_id]=current_time;
                else{
                    current_process.current_time_io=current_time+current_process.io_time.front();
                    current_process.io_time.pop();
                    Input_Output.push_back(current_process);
                }
            }else
                ready_queue.push(current_process);    
        }
        while(!Process_Arrival_Queue.empty() && Process_Arrival_Queue.front().second<=current_time){
            ready_queue.push(Process_Arrival_Queue.front().first);
            Process_Arrival_Queue.pop();
        }
        current_time++;
        if(ready_queue.size()==0 && Input_Output.size()==0){
            break;
        }
    }
    
    float avg_turnaround_time=0,avg_waiting_time=0;

    for(auto itr:Completion_Time)
    {
       //cout<<"\n";
       int value1=itr.second-Arrival_Time_Map[itr.first];
       int value2=value1-mp[itr.first];
       cout<<"JobId:"<<itr.first<<" Turnaround Time:"<<value1<<" Waiting Time:"<<value2<<"\n";
       avg_turnaround_time+=value1;
       avg_waiting_time+=value2;
       //cout<<"\n";
    }
    cout<<"The average turnaround time is :"<<avg_turnaround_time/n<<"\n";
    cout<<"The average waiting time is :"<<avg_waiting_time/n<<"\n";

}
void Round_Robin(string filename)
{
   Process current_process(-1);
   queue<pair<Process,int>> Process_Arrival_Queue;
   unordered_map<int,int> Completion_Time;
   unordered_map<int ,int > Arrival_Time_Map;
   unordered_map<int,int> mp;
   priority_queue<Process> Input_Output;
   queue<Process> ready_queue;
   int n=0;

   Read_Process_Data(filename,Process_Arrival_Queue,n,Arrival_Time_Map,mp);

   for(int i=0;;){
        while(!Process_Arrival_Queue.empty() && Process_Arrival_Queue.front().second<=i){
            ready_queue.push(Process_Arrival_Queue.front().first);
            Process_Arrival_Queue.pop();
        }
        while(!Input_Output.empty() && Input_Output.top().current_time_io<=i){
            if(Input_Output.top().burst_time.size()==0){
                Completion_Time[Input_Output.top().job_id]=i;
            }else
                ready_queue.push(Input_Output.top());
            Input_Output.pop();
        }
        if(ready_queue.size()){
            current_process=ready_queue.front();
            ready_queue.pop();
            if(current_process.burst_time.front()<=TIMEQUANTUM){
                i+=current_process.burst_time.front();
                current_process.burst_time.pop();
                if(current_process.io_time.size()==0){
                    Completion_Time[current_process.job_id]=i;
                }else if(current_process.io_time.size()){
                    current_process.current_time_io=i+current_process.io_time.front();
                    current_process.io_time.pop();
                    Input_Output.push(current_process);
                }
            }else{
                i+=TIMEQUANTUM;
                current_process.burst_time.front()-=TIMEQUANTUM;
                while(!Process_Arrival_Queue.empty() && Process_Arrival_Queue.front().second<=i){
                    ready_queue.push(Process_Arrival_Queue.front().first);
                    Process_Arrival_Queue.pop();
                }
                ready_queue.push(current_process);
            }
        }else
            i++;
        if(ready_queue.size()==0 && Input_Output.size()==0){
            break;
        }
    }
    float avg_turnaround_time=0,avg_waiting_time=0;

    for(auto itr:Completion_Time)
    {
       //cout<<"\n";
       int value1=itr.second-Arrival_Time_Map[itr.first];
       int value2=value1-mp[itr.first];
       cout<<"JobId:"<<itr.first<<" Turnaround Time:"<<value1<<" Waiting Time:"<<value2<<"\n";
       avg_turnaround_time+=value1;
       avg_waiting_time+=value2;
       //cout<<"\n";
    }
    cout<<"The average turnaround time is :"<<avg_turnaround_time/n<<"\n";
    cout<<"The average waiting time is :"<<avg_waiting_time/n<<"\n";

}
int main()
{
    string filename="ProcessDataSample.txt";
    //Case 1 : First Come First Serve Algorithm
    cout<<"-------First Come First Serve -------\n";
    First_Come_First_Serve(filename);
    
    cout<<"\n";
    //Case 2:  Priority Scheduling Algorithm
    cout<<"---------Priority Scheduling -------\n";
    Priority_Scheduling(filename);
    cout<<"\n";
    //Case 3:  Round Robin Scheduling Algorithm
    
    cout<<"---------Round Robin--------\n";
    Round_Robin(filename);
    return 0;
}
