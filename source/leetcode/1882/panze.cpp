#define ull unsigned long long

struct Server {
  int idx;
  int priority;
  
  friend bool operator<(const Server &lhs, const Server &rhs) {
    return (lhs.priority != rhs.priority) ? (lhs.priority > rhs.priority) : (lhs.idx > rhs.idx);
  }
};

struct Worker {
  Server server;
  ull end_clock;
  
  friend bool operator<(const Worker &lhs, const Worker &rhs) {
    return lhs.end_clock > rhs.end_clock;
  }
};

class Solution {
public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    ull clock = 0;
    priority_queue<Server> idle_servers;
    priority_queue<Worker> workers;
    
    for (int i = 0; i < servers.size(); ++i) {
      idle_servers.push({i, servers[i]});
    }
    
    vector<int> ret;
    for (const auto &task : tasks) {
      if (idle_servers.empty()) {
        clock = workers.top().end_clock;
      }
      
      while (!workers.empty() && workers.top().end_clock <= clock) {
        idle_servers.push(workers.top().server);
        workers.pop();
      }
      
      auto server = idle_servers.top();
      idle_servers.pop();

      ret.push_back(server.idx);

      workers.push({server, clock + task});
      clock++;     
    }

    return ret;
  }
};