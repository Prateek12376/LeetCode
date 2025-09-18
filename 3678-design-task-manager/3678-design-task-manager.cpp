class TaskManager {
    unordered_map<int,int> taskId_userId;     // taskId -> userId
    unordered_map<int,int> taskId_priority;   
    map<int,set<pair<int,int>>> priority_taskId_userId;
    // key = -priority, value = set of { -taskId, userId }

public:
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i=0;i<n;i++){
            int UID = tasks[i][0];
            int TID = tasks[i][1];
            int priority = tasks[i][2];
            taskId_userId[TID] = UID;
            taskId_priority[TID] = priority;   
            priority_taskId_userId[-priority].insert({-TID, UID});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskId_userId[taskId] = userId;
        taskId_priority[taskId] = priority;    
        priority_taskId_userId[-priority].insert({-taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        int UID = taskId_userId[taskId];
        int oldPriority = taskId_priority[taskId];  
        taskId_priority[taskId] = newPriority;      

        priority_taskId_userId[-oldPriority].erase({-taskId, UID});
        if (priority_taskId_userId[-oldPriority].empty()) {
            priority_taskId_userId.erase(-oldPriority);
        }
        priority_taskId_userId[-newPriority].insert({-taskId, UID});
    }
    
    void rmv(int taskId) {
        int UID = taskId_userId[taskId];
        int priority = taskId_priority[taskId];   

        priority_taskId_userId[-priority].erase({-taskId, UID});
        if (priority_taskId_userId[-priority].empty()) {
            priority_taskId_userId.erase(-priority);
        }
        taskId_userId.erase(taskId);             
        taskId_priority.erase(taskId);           
    }
    
    int execTop() {
        if (priority_taskId_userId.empty()) {
            return -1;
        }
        auto it = priority_taskId_userId.begin();
        auto p = *it->second.begin();  // { -taskId, userId }
        int TID = -p.first;
        int UID = p.second;
        int priority = taskId_priority[TID];     

        priority_taskId_userId[-priority].erase(p);
        if (priority_taskId_userId[-priority].empty()) {
            priority_taskId_userId.erase(-priority);
        }
        taskId_userId.erase(TID);                 
        taskId_priority.erase(TID);              

        return UID;
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */