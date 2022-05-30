//TC: O(1)
//MC: number of strings
class Logger {
public:
    unordered_map<string, int> msgPrintTime;

    Logger() {
        msgPrintTime.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(msgPrintTime.count(message) and msgPrintTime[message]+10>timestamp){
            return false;
        }
        msgPrintTime[message] = timestamp;
      
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
