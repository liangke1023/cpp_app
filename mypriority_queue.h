#include <list>
#include <map>
using namespace std;

class MyPriorityQueue {
  list<pair<int, pair<int, int> > > queue;
  bool increasing;  // true if priority is increasing
  int _size = 0;    //
 public:
  MyPriorityQueue(){};
  ~MyPriorityQueue(){};
  void chgPriority(bool priority);
  void minPriority();
  bool contains(int v);
  void insert(
      pair<int, pair<int, int> > element);  // vertex, distance, last vertex
  pair<int, pair<int, int> > top();
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
  _size--;
  return;
}
bool MyPriorityQueue::contains(int v) {
  for (auto& i : queue)
    if (i.first == v) return true;
  return false;
}
/**
 * @brief insert queue element into queue with priority
 *
 * @param element
 */
void MyPriorityQueue::insert(pair<int, pair<int, int> > element) {
  if (contains(element.first)) {
    for (auto& i : queue) {
      if (element.first == i.first) {
        if (increasing)
          i.second =
              element.second.first < i.second.first ? element.second : i.second;
        else
          i.second =
              element.second.first > i.second.first ? element.second : i.second;
        return;
      }
    }
  }
  auto itr = queue.begin();
  while (itr != queue.end()) {
    if (increasing) {
      if (element.second.first < itr->second.first) {
        queue.insert(itr, element);
        _size++;
        return;
      }
    } else {
      if (element.second.first > itr->second.first) {
        queue.insert(itr, element);
        _size++;
        return;
      }
    }
    itr++;
  }
  // current element is largest/smallest
  queue.push_back(element);
  _size++;
  return;
}

pair<int, pair<int, int> > MyPriorityQueue::top() { return queue.front(); }

int MyPriorityQueue::size() { return _size; }
