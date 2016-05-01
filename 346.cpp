/*
346. Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
private:
    queue<int> qu;
    int avergeSize;
    double sum;
    
public:
    MovingAverage(int size):avergeSize(size),sum(0) {}

    double next(int val) {
        sum += val;
        qu.push(val);
        int queueSize = (int)qu.size();
        if(queueSize <= avergeSize){
            return sum / queueSize;
        }
        else{
            sum -= qu.front();
            qu.pop();
            return sum / avergeSize;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
