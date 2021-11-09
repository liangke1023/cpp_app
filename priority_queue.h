#include <list>
#include <map>
using namespace std;

class MyPriorityQueue {
  list<pair<int, int> > queue;
  bool increasing;  // true if priority is increasing
 public:
  MyPriorityQueue(){};
  ~MyPriorityQueue(){};
  void chgPriority(bool priority);
  void minPriority();
  bool contains(int v);
  void insert(pair<int, int> element);
  pair<int, int> top();
  int size();
};
void MyPriorityQueue::chgPriority(bool priority) {
  if (this->increasing != priority && queue.size() > 0) {
    queue.reverse();
  }
  increasing = priority;
  return;
}
void MyPriorityQueue::minPriority() {
  if (queue.size() > 0) queue.pop_front();
  return;
}
bool MyPriorityQueue::contains(int v) {
  for (auto& i : queue)
    if (i.first == v) return true;
  return false;
}
void MyPriorityQueue::insert(pair<int, int> element) {
  if (contains(element.first)) {
    for (auto& i : queue) {
      if (element.first == i.first) {
        i.second = element.second < i.second ? element.second : i.second;
        return;
      }
    }
  }
  auto itr = queue.begin();
  while (itr != queue.end()) {
    if (element.second < itr->second) queue.insert(itr, element);
    return;
  }
}
