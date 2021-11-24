#include <iostream>
#include <list>
#include <iterator>

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
 public:
  MyPriorityQueue(){};
  ~MyPriorityQueue(){};
  void reset();
  void chgPriority(list<NodeInfo>::iterator itr);
  void minPriority();
  bool contains(int v);
  void insert(NodeInfo &element);  // vertex, distance, last vertex
  NodeInfo top();
  int Size();
};

void MyPriorityQueue::reset() {
    queue.clear();
    return;
}
void MyPriorityQueue::chgPriority(list<NodeInfo>::iterator itr) {
    if (queue.size()<2) return;

    for(auto i = queue.begin(); i != queue.end(); ++i){
        if (itr->path_size<i->path_size){
            swap(i,itr);
            return;
        }
    }
  return;
}
void MyPriorityQueue::minPriority() {
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
void MyPriorityQueue::insert(NodeInfo &element) {
  for (auto i = queue.begin(); i!=queue.end(); i++) {
    if (element.index == i->index) {
      if (element.path_size < i->path_size) {
        i->path_size = element.path_size;
        i->last_node = element.last_node;
        chgPriority(i);
      }
      return;
    }
  }

  // current element is largest/smallest
  queue.push_back(element);
  auto it = queue.end();
  chgPriority(--it);
  return;
}


NodeInfo MyPriorityQueue::top() {
  return queue.front();
}

int MyPriorityQueue::Size() { return static_cast<int>(this->queue.size()); }
