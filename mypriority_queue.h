#include <list>
#include <map>
using namespace std;

struct NodeInfo {
  int index;
  int path_size;
  int last_node;
};
bool compare_element(NodeInfo& a, NodeInfo& b) {
  return a.path_size < b.path_size;
}
class MyPriorityQueue {
  list<NodeInfo> queue;
  bool increasing;  // true if priority is increasing
 public:
  MyPriorityQueue(){};
  ~MyPriorityQueue(){};
  void chgPriority(bool priority);
  void minPriority();
  bool contains(int v);
  void insert(NodeInfo element);  // vertex, distance, last vertex
  NodeInfo top();
  int Size();
};
void MyPriorityQueue::chgPriority(bool priority) {
  if (this->increasing != priority && queue.size() > 0) {
    queue.reverse();
  }
  increasing = priority;
  return;
}
void MyPriorityQueue::minPriority() {
  cout << "priority queue: " << queue.size() << endl;
  if (queue.size() > 0) queue.pop_front();
  return;
}
bool MyPriorityQueue::contains(int v) {
  for (auto& i : queue)
    if (i.index == v) return true;
  return false;
}
/**
 * @brief insert queue element into queue with priority
 *
 * @param element
 */
void MyPriorityQueue::insert(NodeInfo element) {
  for (auto& i : queue) {
    if (element.index == i.index) {
      if ((increasing && element.path_size < i.path_size) ||
          (!increasing && element.path_size > i.path_size)) {
        i.path_size = element.path_size;
        i.last_node = element.last_node;
      }
      return;
    }
  }
  auto i = queue.begin();
  while (i != queue.end()) {
    if ((increasing && element.path_size < i->path_size) ||
        (!increasing && element.path_size > i->path_size)) {
      queue.insert(i, element);
      return;
    }
    i++;
  }

  // current element is largest/smallest
  queue.push_back(element);
  return;
}

NodeInfo MyPriorityQueue::top() {
  cout << "queue:" << endl;
  for (auto& i : queue) {
    cout << i.index << " " << i.path_size << " " << i.last_node << endl;
  }
  cout << endl;
  return queue.front();
}

int MyPriorityQueue::Size() { return this->queue.size(); }
